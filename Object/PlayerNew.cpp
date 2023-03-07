#include "SceneMain2.h"
#include "PlayerNew.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"
#include "image.h"
#include <cassert>

//定数
namespace
{
	constexpr int kmapSize = 250;

	constexpr double kPlayerSize = 1.4;
	//プレイヤーの初期座標
	constexpr float kPosX = 0.0f;
	constexpr float kPosY = static_cast<float>(Game::kScreenHeight) - 50.0f - 300.0f;//デバック用に-300移動
	//動く速さ
	constexpr float kMoveSpeed = 5.0f;
	// ジャンプ力
	constexpr float kJump = -11.0f;
	// 重力
	constexpr float kGravity = 0.9f;

	//地面の高さY軸
	constexpr int kGround = 700;

	constexpr int kCharaImageLeftPos = -112; //左移動
	constexpr int kCharaImageRightPos = 112; //右移動

	//アニメーションフレーム数
	constexpr int kAnimationFrame = 3;

}

//コンストラクタ
PlayerNew::PlayerNew() :
	m_hPlayer(-1),//画像
	m_hPlayerIdle(-1),//何もしていない状態
	m_hPlayerLighting(-1),
	m_hHealthBer(-1),
	m_hAttack(-1),//サウンド
	m_hFxJump(-1),
	m_hLadder(-1),
	m_hRun(-1),
	m_hDead(-1),
	m_CountRunSound(-1),
	m_CountLadderSound(-1),
	m_hMapFirst(-1),
	m_hMapSecond(-1),
	m_hMapThird(-1),
	m_hMapFourth(-1),
	m_hMapFifth(-1),
	m_hMapChip(-1),
	m_hMapChipSecond(-1),
	m_padInput(0),
	m_playerLeft(0),//プレイヤー判定用
	m_playerTop(0),
	m_playerRight(0),
	m_playerBottom(0),
	m_scoreLeft(0),//スコア判定用
	m_scoreTop(0),
	m_scoreRight(0),
	m_scoreBottom(0),
	m_attackPlayerLeft(0),
	m_attackPlayerTop(0),
	m_attackPlayerRight(0),
	m_attackPlayerBottom(0),
	m_charaImagePos(0),
	m_charaImageIdlePos(0),
	m_charaImageAttackPos(0),
	m_charaImageDamagePos(0),
	m_charaImageJumpPos(0),
	m_charaImageCrouching(0),
	m_charaImageDeadPosX(0),//プレイヤーが死んだ場合のアニメション
	m_charaImageDeadPosY(0),
	m_charaImageLeft(0),//プレイヤー画像での位置
	m_charaImageTop(0),
	m_charaImageRigth(0),
	m_charaImageBottom(0),
	m_count(0),
	m_boxPosX(0),
	m_boxPosY(0),
	m_boxPosBottomX(0),
	m_boxPosBottomY(0),
	m_stagingBoxX(0),
	m_stagingBoxY(0),
	m_stagingBoxBottomX(0),
	m_stagingBoxBottomY(0),
	m_playerHealthBer(0),
	m_playerHealthBerCount(0),
	m_playerHealthSizeX(0),
	m_playerHealthSizeY(0),
	m_boxDropCount(0),
	m_frameCount1(0),//フレームカウント
	m_frameCount2(0),
	m_frameCount3(0),
	m_frameCountDead(0),//死んだらそのあとカウント
	m_deadCount(0),
	m_hierarchy(0),
	m_tip(0),
	m_tempScreenH(0),
	m_gravity(0.0f),
	m_isRunMove(false),//アニメーション関連bool
	m_isStopMove(false),
	m_isIdleMove(false),
	m_isAttackMove(false),
	m_isDamageMove(false),
	m_isJumpMove(false),
	m_isCrouchingMove(false),
	m_isJumpImagePos(false),//ジャンプ画像位置
	m_playerRad(0),//プレイヤーの角度
	m_isHealthBer(false),
	m_isDead(false),
	m_isReset(false),
	m_isTitle(false),
	m_isGetSword(false),
	m_isAttack(false),
	m_isEnemyDead(false),
	m_isItemDrop(false),
	m_isFloorOne(false),
	m_isLadder(false),
	m_isLadderNow(false),
	m_isInvaliDown(false),
	m_isCharaDirection(false),
	m_isCharaIdleDirection(false),
	m_isStageClear(false),
	m_isStageClearChangeScene(false),//ステージをクリアしたら
	m_isStageDeadChangeScene(false),//死んだら
	m_isMenu(false),
	m_isItemTip(false),
	m_isItemDropTip(false),
	m_isUpTip(false),
	m_isGravity(false),
	m_isFall(false),
	m_isMenuDraw(false),//メニュー画面を表示しているかどうか
	m_playerSize(0.0f, 0.0f),
	m_pos(0.0f, 0.0f),
	m_imagePos(0.0f, 0.0f),
	m_imageBalancePos(0.0f, 0.0f),
	m_underPos(0.0f, 0.0f),
	m_attackPos(0.0f, 0.0f),
	m_attackBottomPos(0.0f, 0.0f),
	m_vec(0.0f, 0.0f),
	m_isDamage(false),
	m_isDamageFallen(false),
	m_getPos(0.0f),
	m_isAttackHit(false),
	m_isDamageCharge(false),
	m_isRushBlink(false),
	m_trapHit(0)//トラップに当たって死ぬ

{
	m_charaImagePos = 0;
	m_func = &PlayerNew::UpdateMove;
	m_pos.x = kPosX;
	m_pos.y = kPosY;

	m_isCharaIdleDirection = true;//プレイヤー右向き

	//画像位置をセット右下座標
	m_charaImageRigth = 112;
	m_charaImageBottom = 133;
	m_charaImageDeadPosY = m_charaImageBottom * 9;

	m_hPlayer = LoadGraph(Image::kPlayerImage);		   //プレイヤー画像読み込み
	m_hPlayerIdle = LoadGraph(Image::kPlayerImageIdle);//プレイヤーアイドル状態画像読み込み

	m_hFxJump = LoadSoundMem(FX::kJump);  //ジャンプサウンド読み込み
	m_hRun    = LoadSoundMem(FX::kRun);   //攻撃サウンド読み込み
	m_hAttack = LoadSoundMem(FX::kAttack);//攻撃サウンド読み込み
	m_hDead   = LoadSoundMem(FX::kDead);  //攻撃サウンド読み込み
	m_hLadder = LoadSoundMem(FX::kLadder);//梯子上りサウンド読み込み

	int sw, sh, bit;//画面幅　画面高さ　ビット数
	GetScreenState(&sw, &sh, &bit);//幅と高さ取得しておく
	m_tempScreenH = MakeScreen(sw, sh);//加工用画面
	assert(m_tempScreenH >= 0);//作れなかったらここで停止する

}
//デストラクタ
PlayerNew::~PlayerNew()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);


	//サウンドメモリ開放
	DeleteSoundMem(m_hFxJump);
	DeleteSoundMem(m_hRun);
	DeleteSoundMem(m_hLadder);
	DeleteSoundMem(m_hAttack);
	DeleteSoundMem(m_hDead);

}
//初期化
void PlayerNew::Init()
{
	/*
	m_hierarchy = 1;
	m_playerHealthBer = 100;

	m_boxDropCount = 120;

	m_boxPosX = kBoxPosX;
	m_boxPosY = kBoxPosY;
	m_boxPosBottomX = m_boxPosX + kBoxPosBottomX;
	m_boxPosBottomY = m_boxPosY + kBoxPosBottomY;

	m_pos.x = kPosX;
	m_pos.y = kPosY;

	m_underPos.x = m_pos.x + 50;
	m_underPos.y = m_pos.y + 100;

	m_gravity = kGravity;
	
	m_isEnemyDead = true;
	m_isStopMove = true;
	m_isItemTip = true;
	m_isItemDropTip = true;
	m_isUpTip = true;

	GetGraphSizeF(m_hPlayer, &m_playerSize.x, &m_playerSize.y);
	*/
	// 再生形式をファイルからストリーム再生する、に設定
//SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	//m_hFxJump = LoadSoundMem(FX::kJump);
	// 音量の設定
	//ChangeVolumeSoundMem(255, m_hFxJump);
}
//メモリの開放
void PlayerNew::End()
{

}
//アップデート処理
void PlayerNew::Update()
{

	if (m_isStageClear)//ステージクリアかどうか
	{
		m_isStageClearChangeScene = true;
	}
	//Draw();
	(this->*m_func)();
}
//描画
void PlayerNew::Draw()
{

	DrawBox(m_playerLeft, m_playerTop, m_playerRight, m_playerBottom, 0xffffff, false);

	if (m_isRunMove || m_isJumpMove)//動いていいる場合の画像
	{
		DrawRectRotaGraph(m_playerLeft + 15, m_playerTop - 5,
			m_charaImageLeft + m_charaImagePos, m_charaImageTop, m_charaImageRigth, m_charaImageBottom,
			1.5, m_playerRad, m_hPlayer, true, m_isCharaDirection);
		//画像の１キャラ分の大きさ
		//横112
		//縦133
	}
	else if (m_isStopMove)//止まっている場合の画像
	{
		DrawRectRotaGraph(m_imagePos.x + m_imageBalancePos.x, m_imagePos.y + 10.0f,
			m_charaImageIdlePos, 0, 80, 80,
			1.5, m_playerRad, m_hPlayerIdle, true, m_isCharaIdleDirection);
		//画像の１キャラ分の大きさ
		//横80
		//縦80
	}

	if (m_isAttack)//攻撃した場合の画像（未実装）
	{
		DrawBox(m_attackPlayerLeft, m_attackPlayerTop, m_attackPlayerRight, m_attackPlayerBottom, 0xffffff, true);
	}

	m_isAttack = false;//攻撃していない

	if (m_isDead)//死んでいる画面
	{
		DrawRectRotaGraph(Game::kScreenWidth/2,Game::kScreenHeight/2 - 300,
			m_charaImageLeft + m_charaImageDeadPosX, m_charaImageTop + m_charaImageDeadPosY, m_charaImageRigth, m_charaImageBottom,
			20, m_playerRad, m_hPlayer, true, m_isCharaDirection);
	}


}
//アニメーションを再生
void PlayerNew::Animation()
{
	if (m_isStopMove)//動いていない場合
	{
		m_frameCount1++;
		if (m_frameCount1 >= 3)//画像をずらす
		{
			m_charaImageIdlePos += 80;
			m_frameCount1 = 0;
		}

		if (m_charaImageIdlePos >= 1440)//画像が右まで表示されたら左に戻す
		{
			m_charaImageIdlePos = 0;
		}
	}
	else
	{
		m_frameCount1 = 0;
		m_charaImageIdlePos = 0;
	}

	if (m_isJumpMove)//ジャンプアニメーション
	{
		
		if (m_isJumpImagePos)//画像位置をジャンプに変更
		{
			m_charaImageTop = 133 * 3;//画像位置をずらす
			m_isJumpImagePos = false;
		}

		m_frameCount3++;//１フレームカウント
		if (m_frameCount3 >= 2)//画像をずらす
		{
			m_charaImagePos += 112;//画像を１１２ピクセル動かす
			m_frameCount3 = 0;//カウントリセット
		}

		if (m_charaImagePos >= 1344)//画像が右まで表示されたら左に戻す
		{
			m_charaImagePos = 0;//画像位置を右にリセット
		}
	}
	else if (m_isRunMove)//左右に動いている場合
	{
		//走り画像位置に変更
		if (m_isRunImagePos)
		{
			m_charaImageTop = 133;
			m_isRunImagePos = false;
		}

		m_frameCount2++;
		if (m_frameCount2 >= 2)//画像をずらす
		{
			m_charaImagePos += 112;
			m_frameCount2 = 0;
		}

		if (m_charaImagePos >= 1344)//画像が右まで表示されたら左に戻す
		{
			m_charaImagePos = 0;
		}
	}
	else//ジャンプアニメーションを再生していない場合
	{
		m_frameCount2 = 0;//使っていない間はカウントリセット
		m_frameCount3 = 0;//使っていない間はカウントリセット
		m_charaImagePos = 0;//使っていない間は位置をリセット
	}

}
//プレイヤーの行動範囲
void PlayerNew::PlayerPosSet()
{
	if (m_pos.x < 0.0f) m_pos.x = 1.0f;
	if (m_pos.x > Game::kScreenWidth ) m_pos.x = static_cast<float>(Game::kScreenWidth) - 1.0f;
	if (m_pos.y < 0.0f) m_pos.y = 1.0f;
	if (m_pos.y > Game::kScreenHeight) m_pos.y = static_cast<float>(Game::kScreenHeight) - 1.0f;
}
//操作全体
void PlayerNew::Operation()
{
	OperationStandard();//基本操作
	OperationAttack();//攻撃操作
	OperationJump();//ジャンプ操作
	OperationLadder();//梯子での操作
}
//基本操作
void PlayerNew::OperationStandard()
{
	m_imagePos = m_pos; //画像用の座標
	m_isRunMove = false;//動いていない場合は非表示
	m_isStopMove = true;//動いてない場合は表示
	//移動
	if (CheckHitKey(KEY_INPUT_RIGHT)|| (m_padInput & PAD_INPUT_RIGHT))//右
	{
		m_isRunMove = true;            //走っているプレイヤーを表示
		m_isRunImagePos = true;//走っている場合の画像位置
		m_isCharaIdleDirection = false;//プレイヤーの向きを変更
		m_isCharaDirection = true;     //プレイヤーの向きを変更
		m_isStopMove = false;          //動いていたら非表示
		m_CountRunSound++;             //サウンド再生までカウント
		if (m_CountRunSound >= 25)     //13フレームに一度だけ足音を再生
		{
			PlaySoundMem(m_hRun, DX_PLAYTYPE_BACK);
			m_CountRunSound = 0;
		}
		m_pos.x += kMoveSpeed;//座標を移動
	}
	if (CheckHitKey(KEY_INPUT_LEFT) || (m_padInput & PAD_INPUT_LEFT))//左
	{
		m_isRunMove = true;           //走っているプレイヤーを表示
		m_isRunImagePos = true;//走っている場合の画像位置
		m_isCharaIdleDirection = true;//プレイヤーの向きを変更
		m_isCharaDirection = false;   //プレイヤーの向きを変更
		m_isStopMove = false;         //動いていたら非表示
		m_CountRunSound++;            //サウンド再生までカウント
		if (m_CountRunSound >= 25)    //13フレームに一度だけ足音を再生
		{
			PlaySoundMem(m_hRun, DX_PLAYTYPE_BACK);
			m_CountRunSound = 0;
		}

		
		m_pos.x -= kMoveSpeed;//座標を移動

	}

	if (!m_isCharaIdleDirection)//プレイヤーの画像の位置を調整する
	{
		m_imageBalancePos.x = + 35.0f;//画像を右にずらす
	}
	else
	{
		m_imageBalancePos.x = +0.0f;
	}
}
//攻撃操作
void PlayerNew::OperationAttack()
{
	//m_isAttack = false;//攻撃停止
	if (Pad::isTrigger(PAD_INPUT_1))//攻撃
	{
		printfDx("攻撃\n");
		PlaySoundMem(m_hAttack, DX_PLAYTYPE_BACK);
		//プレイヤーの攻撃範

		m_isAttack = true;//攻撃開始
	}
}
//ジャンプ操作
void PlayerNew::OperationJump()////地面にいる場合&&梯子にいない場合
{
	//ジャンプ
	if (Pad::isTrigger(PAD_INPUT_2))//上
	{
		m_isJumpMove = true;//ジャンプアニメーション再生
		m_isJumpImagePos = true;//ジャンプ画像位置
		PlaySoundMem(m_hFxJump, DX_PLAYTYPE_BACK);
		m_vec.y = 0.0f;
		m_vec.y = kJump;//ジャンプ開始
	}
}
//梯子操作
void PlayerNew::OperationLadder()
{
	if (CheckHitKey(KEY_INPUT_UP) || (m_padInput & PAD_INPUT_UP))
	{
		m_isLadderNow = true;//プレイヤーが梯子に触る
		m_CountLadderSound++;
		if (m_CountLadderSound >= 13)
		{
			PlaySoundMem(m_hLadder, DX_PLAYTYPE_BACK);
			m_CountLadderSound = 0;
		}
		m_pos.y -= kMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) || (m_padInput & PAD_INPUT_DOWN))
	{
		m_isLadderNow = true;//プレイヤーが梯子に触る
		m_CountLadderSound++;
		if (m_CountLadderSound >= 13)
		{
			PlaySoundMem(m_hLadder, DX_PLAYTYPE_BACK);
			m_CountLadderSound = 0;
		}
		m_pos.y += kMoveSpeed;
	}
	if (m_isLadderNow)//プレイヤーが梯子に触っている場合
	{
		m_vec.x = 0.0f;//ベクトルをリセット
		m_vec.y = 0.0f;
	}
}
void PlayerNew::Score()
{
	//printfDx("%d\n",m_score);
}

//アップデート処理
void PlayerNew::UpdateMove()
{

	Score();//スコア表示

	Animation();//アニメーション
	Pad::update();//入力判定
	m_padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);//ジョイパッドの入力状態を得る
	OperationStandard();//操作::移動
	
	PlayerPosSet();//移動可能範囲

	OperationAttack();//攻撃

	if (!m_isFall)//地面に当たっていなかったら
	{
		//重力
		m_vec.y += kGravity;

	}

	if (m_isLadder)//梯子にいる場合
	{
		OperationLadder();//操作::梯子移動
	}
	else if (m_isFall)//地面に当たっていたら
	{
		m_vec.y = 0.0f;
		m_pos.y = m_getPos;//プレイヤーの位置座標
		m_isLadderNow = false;//プレイヤーは梯子に触っていない状態
		m_isJumpMove = false;//ジャンプ（落下）アニメーションを再生しない
		OperationJump();//操作::ジャンプ

	}

	//Animation();//キャラクターのアニメーション
	
	if (m_isStageClear)//ステージクリアかどうか
	{
		m_isStageClearChangeScene = true;//クリア
		DrawBox(Stage2::kGoalX, Stage2::kGoalY,Stage2::kGoalBottomX, Stage2::kGoalBottomY, GetColor(GetRand(255), GetRand(255), GetRand(255)), true);
	}

	if (m_isDamage||m_isDamageFallen||m_isDamageCharge|| m_trapHit == 1)//攻撃をくらったからどうか
	{
		//PlaySoundMem(m_hDead, DX_PLAYTYPE_NORMAL);//死んだ場合のサウンド再生

		if(CheckSoundMem(m_hDead) == 0)//音でなくなったら
		{
			if (m_isDamage)//火の玉敵
			{
				printfDx("Player死亡\n");
				m_func = &PlayerNew::UpdateDead;//死亡シーン切り替え
			}
			if (m_isDamageFallen)//落ちモノ敵
			{
				printfDx("PlayerFallen死亡\n");
				m_func = &PlayerNew::UpdateDead;//死亡シーン切り替え
			}
			if (m_isDamageCharge && m_isRushBlink)//見えている間に当たると死ぬ敵
			{
				printfDx("PlayerChage死亡\n");
				m_func = &PlayerNew::UpdateDead;//死亡シーン切り替え
			}
			if (m_trapHit == 1)
			{
				printfDx("トラップで死亡\n");
				m_func = &PlayerNew::UpdateDead;//死亡シーン切り替え
			}
		}
		//printfDx("死亡\n");
	}
	if (m_isAttackHit)//攻撃をくらったからどうか
	{
		printfDx("Enemy死亡\n");
	}

	m_pos += m_vec;//プレイヤー位置

	//プレイヤーの座標
	m_playerLeft   = static_cast<int>(m_pos.x);
	m_playerTop    = static_cast<int>(m_pos.y);
	m_playerRight  = m_playerLeft + 30;
	m_playerBottom = m_playerTop + 40;

	//if (!m_isFall)
	//{
	//	//プレイヤーの座標
	//	m_playerLeft = static_cast<int>(m_pos.x);
	//	m_playerTop += 10;
	//	m_playerRight = m_playerLeft + 30;
	//	m_playerBottom = m_playerTop + 40;
	//}
	//スコア判定座標
	//m_scoreLeft   = m_playerLeft;
	//m_scoreTop    = m_playerBottom;
	//m_scoreRight  = m_scoreLeft;
	//m_scoreBottom = m_scoreTop;

	if(m_isAttack)//プレイヤーが攻撃した時の範囲
	{
		m_attackPlayerLeft = m_playerLeft - 10;
		m_attackPlayerTop = m_playerTop - 10;
		m_attackPlayerRight = m_playerRight + 10;
		m_attackPlayerBottom = m_playerBottom + 10;
	}
	else//攻撃していない場合の範囲
	{
		m_attackPlayerLeft   = - 10;
		m_attackPlayerTop    = - 10;
		m_attackPlayerRight  = + 10;
		m_attackPlayerBottom = + 10;
	}


}

void PlayerNew::UpdateDead()
{
	//SetDrawScreen(DX_SCREEN_BACK);
	//DrawGraph(100, 100, m_tempScreenH, false);
	//GraphFilter(m_tempScreenH, DX_GRAPH_FILTER_GAUSS, 16, 1400);
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 32);

	m_isDead = true;//死亡判定で動きを強制停止
	m_frameCountDead++;
	if (m_frameCountDead >= 20)//アニメーションを20フレームに1コマで再生
	{
		m_charaImageDeadPosX += 112;//画像112ドットを右に動かす
		m_frameCountDead = 0;//カウントをリセット
	}

	if (m_charaImageDeadPosX >= 112 + 112)//アニメーションの再生に制限をかける
	{
		m_charaImageDeadPosX = 112 + 112;//表示画像を固定
		m_deadCount++;//シーンを切り替えるまでカウント
	}

	if (m_deadCount == 60)//60フレームゲームを停止
	{
		m_isStageDeadChangeScene = true;//シーンを切り替える
	
		m_deadCount = 0;//カウントリセット
	}
}
