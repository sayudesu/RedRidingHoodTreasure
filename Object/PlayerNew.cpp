#include "SceneMain2.h"
#include "PlayerNew.h"
#include "PlayerAnimation.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"
#include "image.h"

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
	constexpr float kJump = -10.0f;
	// 重力
	constexpr float kGravity = 1.0f;

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
	m_playerLeft(0),
	m_playerTop(0),
	m_playerRight(0),
	m_playerBottom(0),
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
	m_frameCount(0),
	m_hierarchy(0),
	m_tip(0),
	m_gravity(0.0f),
	m_isRunMoveLeft(false),
	m_isRunMoveRight(false),
	m_isIdleMove(false),
	m_isAttackMove(false),
	m_isDamageMove(false),
	m_isJumpMove(false),
	m_isCrouchingMove(false),
	m_isHealthBer(false),
	m_isDead(false),
	m_isReset(false),
	m_isTitle(false),
	m_isGetSword(false),
	m_isAttack(false),
	m_isEnemyDead(false),
	m_isStopMove(false),
	m_isItemDrop(false),
	m_isFloorOne(false),
	m_isLadder(false),
	m_isLadderNow(false),
	m_isInvaliDown(false),
	m_isCharaDirection(false),
	m_isCharaIdleDirection(false),
	m_isStageClear(false),
	m_isStageClearChangeScene(false),
	m_isMenu(false),
	m_isItemTip(false),
	m_isItemDropTip(false),
	m_isUpTip(false),
	m_isGravity(false),
	m_isFall(false),
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
	m_isRushBlink(false)

{
	m_charaImagePos = 0;
	m_func = &PlayerNew::UpdateMove;
	m_pos.x = kPosX;
	m_pos.y = kPosY;

	m_hFxJump = LoadSoundMem(FX::kJump);//ジャンプサウンド読み込み
	m_hRun    = LoadSoundMem(FX::kRun);//攻撃サウンド読み込み
	m_hAttack = LoadSoundMem(FX::kAttack);//攻撃サウンド読み込み
	m_hDead   = LoadSoundMem(FX::kDead);//攻撃サウンド読み込み
	m_hLadder = LoadSoundMem(FX::kLadder);

}
//デストラクタ
PlayerNew::~PlayerNew()
{
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
	DrawBox(m_playerLeft, m_playerTop, m_playerRight, m_playerBottom, 0xaaaaaa, true);

	//アイドル状態
	//int a = LoadGraph(Image::kPlayerImageIdle);
	//int b = LoadGraph(Image::kPlayerImage);
	////DrawRectRotaGraph(m_playerLeft + 35, m_playerTop + 10, m_charaImageIdlePos, 0, 80, 80,1.5, 0, a, true, false);
	//DrawRectRotaGraph(m_playerLeft + 15, m_playerTop - 5, m_charaImagePos, 133, 112, 133, 1.5, 0, b, true, true);
	//DrawFormatString(100, 100, 0xffffff, "%d", m_charaImagePos);
	//横112
	//縦133
	// 
	//DrawGraph(m_playerLeft, m_playerTop, a, true);



	if (m_isAttack)
	{
		DrawBox(m_attackPlayerLeft, m_attackPlayerTop, m_attackPlayerRight, m_attackPlayerBottom, 0xffffff, true);
	}

	m_isAttack = false;
}
void PlayerNew::Animation()
{
	m_boxDropCount++;

	//if (m_boxDropCount >= 3)//画像をずらす
	//{
	//	m_charaImageIdlePos += 80;
	//	m_boxDropCount = 0;
	//}

	//if (m_charaImageIdlePos >= 1440)//画像が右まで表示されたら左に戻す
	//{
	//	m_charaImageIdlePos = 0;
	//}

	if (m_boxDropCount >= 3)//画像をずらす
	{
		m_charaImagePos += 112;
		m_boxDropCount = 0;
	}

	if (m_charaImagePos >= 1344)//画像が右まで表示されたら左に戻す
	{
		m_charaImagePos = 0;
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
	//移動
	if (CheckHitKey(KEY_INPUT_RIGHT)|| (m_padInput & PAD_INPUT_RIGHT))//右
	{
		
		m_CountRunSound++;
		if (m_CountRunSound >= 13)//13フレームに一度だけ足音を再生
		{
			PlaySoundMem(m_hRun, DX_PLAYTYPE_BACK);
			m_CountRunSound = 0;
		}
		m_pos.x += kMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) || (m_padInput & PAD_INPUT_LEFT))//左
	{
		m_CountRunSound++;
		if (m_CountRunSound >= 13)//13フレームに一度だけ足音を再生
		{
			PlaySoundMem(m_hRun, DX_PLAYTYPE_BACK);
			m_CountRunSound = 0;
		}
		m_pos.x -= kMoveSpeed;
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
void PlayerNew::OperationJump()
{
	//地面にいる場合&&梯子にいない場合
	//ジャンプ
	if (Pad::isTrigger(PAD_INPUT_2))//上
	{
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
//アップデート処理
void PlayerNew::UpdateMove()
{
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
		OperationJump();//操作::ジャンプ
		m_pos.y = m_getPos;//プレイヤーの位置座標
		m_isLadderNow = false;//プレイヤーは梯子に触っていない状態

	}

	//Animation();//キャラクターのアニメーション
	
	if (m_isStageClear)//ステージクリアかどうか
	{
		m_isStageClearChangeScene = true;//クリア
		DrawBox(Stage2::kGoalX, Stage2::kGoalY,Stage2::kGoalBottomX, Stage2::kGoalBottomY, GetColor(GetRand(255), GetRand(255), GetRand(255)), true);
	}

	if (m_isDamage||m_isDamageFallen||m_isDamageCharge)//攻撃をくらったからどうか
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
		}
		//printfDx("死亡\n");
	}
	if (m_isAttackHit)//攻撃をくらったからどうか
	{
		printfDx("Enemy死亡\n");
	}

	m_pos += m_vec;//プレイヤー位置

	//プレイヤーの座標
	m_playerLeft = static_cast<int>(m_pos.x);
	m_playerTop = static_cast<int>(m_pos.y);
	m_playerRight = m_playerLeft + 40;
	m_playerBottom = m_playerTop + 40;

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
	m_isDead = true;//死亡
}
