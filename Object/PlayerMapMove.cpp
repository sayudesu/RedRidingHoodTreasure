#include "SceneMain.h"
#include "SceneResult.h"
#include "PlayerMapMove.h"
#include "Enemy.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"

//定数
namespace
{
	constexpr int kmapSize = 250;

	constexpr double kPlayerSize = 1.4;
	//プレイヤーの初期座標
	constexpr float kPosX = 0.0f;
	constexpr float kPosY = static_cast<float>(Game::kScreenHeight) - 50.0f -300.0f;//デバック用に-300移動
	//動く速さ
	constexpr float kMoveSpeed = 17.0f; //もっと下げたほうが面白い！修正待ち
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

	////////////////////
	///*地面　2座標*///
	////////////////////
	constexpr int kGroundSecondX = 100;
	constexpr int kGroundSecondY = Game::kScreenHeight - 40 - 160;
	constexpr int kGroundSecondBottomX = Game::kScreenWidth;
	constexpr int kGroundSecondBottomY = kGroundSecondY + 20;
	
	////////////////////
	///*地面　3座標*///
	////////////////////
	constexpr int kGroundThirdX = 0;
	constexpr int kGroundThirdY = kGroundSecondY - 125;
	constexpr int kGroundThirdBottomX = Game::kScreenWidth - 100;
	constexpr int kGroundThirdBottomY = kGroundThirdY + 20;

	////////////////////
	///*地面　4座標*////
	////////////////////
	constexpr int kGroundFourthX = 100;
	constexpr int kGroundFourthY = kGroundThirdY - 125;
	constexpr int kGroundFourthBottomX = Game::kScreenWidth;
	constexpr int kGroundFourthBottomY = kGroundFourthY + 20;

	////////////////////
	///*はしご 1座標*///
	////////////////////
	constexpr int kLadderX = Game::kScreenWidth - 100;
	constexpr int kLadderY = kGroundSecondY - 10;
	constexpr int kLadderXBottom = Game::kScreenWidth - 90;
	constexpr int kLadderYBottom = kGroundSecondY + 80;
	
	////////////////////
	///*はしご 2座標*///
	////////////////////
	constexpr int kLadderSecondX = 150;
	constexpr int kLadderSecondY = kGroundThirdY - 10;
	constexpr int kLadderBottomSecondX = kLadderSecondX + 10;
	constexpr int kLadderBottomSecondY = kLadderSecondY + 80;

	////////////////////
	///*はしご 3座標*///
	////////////////////
	constexpr int kLadderThirdX = Game::kScreenWidth - 150;
	constexpr int kLadderThirdY = kGroundFourthY - 10;
	constexpr int kLadderBottomThirdX = kLadderThirdX + 10;
	constexpr int kLadderBottomThirdY = kLadderThirdY + 80;

	////////////////////
	///*　　ゴール　*///
	////////////////////

	constexpr int kGoalX = Game::kScreenWidth - 100;
	constexpr int kGoalY = 550;
	constexpr int kGoalBottomX = kGoalX + 50;
	constexpr int kGoalBottomY = kGoalY + 80;

	////////////////////////
	///*アイテムボックス*///
	///////////////////////
	constexpr int kBoxPosX = Game::kScreenWidth / 2 + 300;
	constexpr int kBoxPosY = Game::kScreenHeight - 100;
	constexpr int kBoxPosBottomX = 50;
	constexpr int kBoxPosBottomY = 50;

}
//コンストラクタ
PlayerMapMove::PlayerMapMove() :
	m_hPlayer             (-1),
	m_hPlayerIdle         (-1),
	m_hPlayerLighting     (-1),
	m_hHealthBer          (-1),
	m_hMapFirst			  (-1),
	m_hMapSecond		  (-1),
	m_hMapThird		      (-1),
	m_hMapFourth		  (-1),
	m_hMapFifth			  (-1),
	m_hMapChip			  (-1),
	m_hMapChipSecond	  (-1),
	m_playerLeft		  (0),
	m_playerTop           (0),
	m_playerRight		  (0),
	m_playerBottom        (0),
	m_charaImagePos		  (0),
	m_charaImageIdlePos   (0),
	m_charaImageAttackPos (0),
	m_charaImageDamagePos (0),
	m_charaImageJumpPos   (0),
	m_charaImageCrouching (0),
	m_count				  (0),
	m_boxPosX			  (0),
	m_boxPosY             (0),
	m_boxPosBottomX       (0),
	m_boxPosBottomY       (0),
	m_stagingBoxX         (0),
	m_stagingBoxY         (0),
	m_stagingBoxBottomX   (0),
	m_stagingBoxBottomY   (0),
	m_playerHealthBer     (0),
	m_playerHealthBerCount(0),
	m_playerHealthSizeX   (0),
	m_playerHealthSizeY   (0),
	m_boxDropCount        (0),
	m_frameCount          (0),
	m_hierarchy           (0),
	m_tip				  (0),
	m_gravity(0.0f),
	m_isRunMoveLeft       (false),
	m_isRunMoveRight      (false),
	m_isIdleMove          (false),
	m_isAttackMove		  (false),
	m_isDamageMove		  (false),
	m_isJumpMove		  (false),
	m_isCrouchingMove     (false),
	m_isHealthBer         (false),
	m_isDead			  (false),
	m_isReset			  (false),
	m_isTitle			  (false),
	m_isGetSword          (false),
	m_isAttack			  (false),
	m_isEnemyDead		  (false),
	m_isStopMove		  (false),
	m_isItemDrop          (false),
	m_isFloorOne          (false),
	m_isLadder            (false),
	m_isInvaliDown        (false),
	m_isCharaDirection    (false),
	m_isCharaIdleDirection(false),
	m_isStageClear		  (false),
	m_isMenu              (false),
	m_isItemTip			  (false),
	m_isItemDropTip		  (false),
	m_isUpTip			  (false),
	m_playerSize     (0.0f, 0.0f),
	m_pos            (0.0f, 0.0f),
	m_imagePos       (0.0f, 0.0f),
	m_imageBalancePos(0.0f, 0.0f),
	m_underPos       (0.0f, 0.0f),
	m_attackPos	     (0.0f, 0.0f),
	m_attackBottomPos(0.0f, 0.0f),
	m_vec            (0.0f, 0.0f),
	m_pEnemy(nullptr)

{
	m_charaImagePos = (1344 - kCharaImageRightPos);
	m_func = &PlayerMapMove::UpdateMove;
	m_pEnemy = new Enemy;

}
//デストラクタ
PlayerMapMove::~PlayerMapMove()
{
	delete m_pEnemy;
}
//初期化
void PlayerMapMove::Init()
{

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
}
//メモリの開放
void PlayerMapMove::End()
{

}
//アップデート処理
void PlayerMapMove::Update()
{
	if (GetLifeEnemy() && GetEnemyMove())
	{
		m_pEnemy->Update();
	}
	else
	{
		printfDx("Enemy is Dead");
	}
	(this->*m_func)();
}
//描画
void PlayerMapMove::Draw()
{
	DrawMap();
	
	if(!m_isGetSword)
	{
	
		if (m_boxDropCount < 120)//アイテムを揺れて描画
		{
			m_stagingBoxX = GetRand(10), m_stagingBoxY = GetRand(10);
			m_stagingBoxBottomX = GetRand(10), m_stagingBoxBottomY = GetRand(10);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, GetRand(255));
			//m_boxPosY++;//ゆっくり下に落とす
		}
		else
		{
			m_stagingBoxX = 0;
			m_stagingBoxY = 0;
			m_stagingBoxBottomX = 0;
			m_stagingBoxBottomY = 0;
		}
		DrawBox(m_boxPosX + m_stagingBoxX, m_boxPosY + m_stagingBoxY, m_boxPosBottomX + m_stagingBoxBottomX, m_boxPosBottomY + m_stagingBoxBottomY, 0x00ff00, true);//アイテムボックス
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//体力の量表示
	if(!m_isHealthBer)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(static_cast<int>(m_pos.x) - 35, static_cast<int>(m_pos.y) - 30, static_cast<int>(m_pos.x) - 35 + 75, static_cast<int>(m_pos.y) - 30 + 10, 0xff0000, true);
		DrawExtendGraph(static_cast<int>(m_pos.x) - 35, static_cast<int>(m_pos.y) - 30, m_playerHealthSizeX + static_cast<int>(m_pos.x) - 35 + 75, m_playerHealthSizeY + static_cast<int>(m_pos.y) - 30 + 10,m_hHealthBer,true);
		DrawBox(static_cast<int>(m_pos.x) - 35, static_cast<int>(m_pos.y) - 30, static_cast<int>(m_pos.x) - 35 + 75, static_cast<int>(m_pos.y) - 30 + 10, 0xffffff, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//キャラクター
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	for (int i = 0; i < 4 ; i++)
	{
		DrawRotaGraph(static_cast<int>(m_pos.x) - 3 + GetRand(5), static_cast<int>(m_pos.y) + 20 + GetRand(5), 3, 0, m_hPlayerLighting, true, false);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (m_isIdleMove && !m_isAttackMove && !m_isDamageMove && !m_isJumpMove && !m_isCrouchingMove)//何もしない
	{
		
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + static_cast<int>(m_imageBalancePos.x),
			static_cast<int>(m_imagePos.y) + static_cast<int>(m_imageBalancePos.y),
			m_charaImageIdlePos, 0, 80, 80, kPlayerSize, 0, m_hPlayerIdle, true, m_isCharaIdleDirection);

	}
	else if (m_isRunMoveRight && !m_isAttackMove || m_isRunMoveLeft && !m_isAttackMove && !m_isDamageMove && !m_isJumpMove && !m_isCrouchingMove)//走る
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x), static_cast<int>(m_imagePos.y),
			m_charaImagePos, 133, 112, 133, kPlayerSize, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//剣攻撃
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageAttackPos, 1197, 112, 133, kPlayerSize, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isDamageMove && !m_isCrouchingMove)//攻撃を受けたら
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageDamagePos, 1330, 112, 133, kPlayerSize, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isJumpMove && !m_isCrouchingMove)//ジャンプをしたら
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageJumpPos, 399, 112, 133, kPlayerSize, 0, m_hPlayer, true, m_isCharaDirection);
	}

	if(m_isCrouchingMove)
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageCrouching, 532, 112, 133, kPlayerSize, 0, m_hPlayer, true, m_isCharaDirection);
	}

	//死んだ場合のメニュー画面
	if (m_isDead)
	{
		int x = 650;
		int y = 400;
		int bx = x + 550;
		int by = y + 300;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//透過
		DrawBox(x, y, bx, by, 0x0000ff, true);//背景
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawBox(x,y,bx,by,0xffffff,false);//枠
		DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 2 - 100, "あなたは死にました", 0xff0000);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 30, "受け入れる", 0xffffff);
		DrawString(Game::kScreenWidth / 2 + 50, Game::kScreenHeight  / 2 - 30, "受け入れる", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200 + 35, Game::kScreenHeight / 2, "Y", 0xffffff);
		DrawString(Game::kScreenWidth / 2 + 50 + 40, Game::kScreenHeight  / 2, "Y", 0xffffff);
	}

	//メニュー画面
	if (m_isMenu)
	{
		int x = 650;
		int y = 400;
		int bx = x + 550;
		int by = y + 300;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//透過
		DrawBox(x, y, bx, by, 0x0000ff, true);//背景
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawBox(x, y, bx, by, 0xffffff, false);//枠

		DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 2 - 100, "メインメニュー", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 30, "タイトルに戻る:: Z ", 0xffffff);
		DrawString(Game::kScreenWidth / 2 + 50, Game::kScreenHeight / 2 - 30,  "ゲームを閉じる:: Q ", 0xffffff);

	}
	//ヒントを表示
	DrawTip();

	////////////////////
	///*判定の確認用*///
	////////////////////
#if true	

	//キャラクター
	DrawBox(m_playerLeft, m_playerTop, m_playerRight, m_playerBottom, 0xff0000, false);

	if (m_isAttack)
	{
		DrawBox(static_cast<int>(m_attackPos.x), static_cast<int>(m_attackPos.y),
			static_cast<int>(m_attackBottomPos.x), static_cast<int>(m_attackBottomPos.y), 0x0000ff, false);
	}

	//printfDx("%f\n", m_pos.y);
	printfDx("%d\n", m_playerHealthBer);

#endif
}
//操作
void PlayerMapMove::Operation()
{
	//入力判定
	Pad::update();

	m_isCrouchingMove = false;
	m_isRunMoveRight = false;//右に動いているかどうか
	m_isRunMoveLeft = false;//左に動いているかどうか
	m_isIdleMove = true;//動いているかどうか

	//移動
	if (CheckHitKey(KEY_INPUT_RIGHT) && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//右
	{
		m_pos.x += kMoveSpeed;
		m_underPos.x += kMoveSpeed;
		m_isCharaDirection = true;//画像反転
		m_isRunMoveRight = true;
		m_isIdleMove = false;
		m_isCharaIdleDirection = false;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//左
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
		m_isCharaDirection = false;//画像反転
		m_isRunMoveLeft = true;
		m_isIdleMove = false;
		m_isCharaIdleDirection = true;
	}

	//アップダウン
	if (CheckHitKey(KEY_INPUT_UP) && CheckHit() == 1 && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//梯子上り
	{
		m_vec.y = 0.0f;
		m_pos.y -= kMoveSpeed;
		m_isIdleMove = false;
	
	} 
	if(m_isInvaliDown && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)
	{
		if (CheckHitKey(KEY_INPUT_DOWN) && CheckHit() == 1)//梯子下り
		{
			m_vec.y = 0.0f;
			m_pos.y += kMoveSpeed;
			m_isIdleMove = false;
		}
	}

	//ジャンプ
	if (Pad::isTrigger(KEY_INPUT_UP) && CheckHit() == 0 && !m_isAttackMove && !m_isDamageMove)//上
	{
		if (FieldJudgement() == 1 ||
			FieldJudgement() == 2)//地面にいる状態の場合
		{
			printfDx("ジャンプ\n");
			m_vec.y = kJump;//ジャンプ開始
			m_isJumpMove = true;
			//m_isIdleMove = false;
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_isCrouchingMove = true;
	}

	//攻撃
	if(m_isGetSword && !m_isDamageMove && !m_isCrouchingMove)
	{
		if(CheckHitKey(KEY_INPUT_V))
		{
			m_isAttackMove = true;
		}
	}

	//ポーズメニュー
	if (CheckHitKey(KEY_INPUT_P))
	{
		m_isStopMove = false;
		//m_isEnemyDead = false;
		m_isMenu = true;
		m_func = &PlayerMapMove::MenuStop;
	}
		
}
//アニメーション
void PlayerMapMove::Condition()
{	

	if (m_isCharaIdleDirection)
	{
		m_imageBalancePos.x = -20;
		m_imageBalancePos.y = 20;
	}
	else
	{
		m_imageBalancePos.x = 20;
		m_imageBalancePos.y = 20;
	}

	//アイドル状態
	if(m_isIdleMove)
	{
		m_frameCount++;
		if(m_frameCount >= kAnimationFrame)
		{
			m_charaImageIdlePos += 80;
			m_frameCount = 0;
		}
		if (m_charaImageIdlePos == 1440)
		{
			m_charaImageIdlePos = 0;
		}
	}
	
	//右に移動アニメーション
	if(m_isRunMoveRight)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImagePos -= kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 0)
		{
			m_charaImagePos = (1344 - kCharaImageRightPos);
		}
	}

	//左に移動アニメーション
	if(m_isRunMoveLeft)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImagePos -= kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 0)
		{
			m_charaImagePos = (1344 - kCharaImageRightPos);
		}
	}

	//攻撃を受けた場合
	if (m_isDamageMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageDamagePos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if(m_charaImageDamagePos == kCharaImageRightPos * 7)
		{
			m_charaImageDamagePos = 0;
	
			m_isDamageMove = false;

		}
	}

	//ジャンプした場合
	if (m_isJumpMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageJumpPos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImageJumpPos == kCharaImageRightPos * 12)
		{
			m_charaImageJumpPos = 0;

			if (FieldJudgement() == 1 || FieldJudgement() == 2)
			{
				m_isJumpMove = false;
			}
		}
	}

	if (m_isCrouchingMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageCrouching += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImageCrouching >= kCharaImageRightPos)
		{
			m_charaImageCrouching = kCharaImageRightPos;
	
		}
	}
	else
	{
		m_isCrouchingMove = false;
	}

	//攻撃アニメーション（剣）
	if (m_isAttackMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageAttackPos += kCharaImageRightPos;
			m_frameCount = 0;
			m_isAttack = true;
		}
		if (m_charaImageAttackPos >= 1344)
		{
			m_charaImageAttackPos = 0;
			m_isAttackMove = false;//攻撃をしているかどうか
			m_isAttack = false;
		}
	}
	else
	{
		m_charaImageAttackPos = 0;
	}

}
//地面との判定
int PlayerMapMove::FieldJudgement()
{
	m_isInvaliDown = false;

	if (CheckHit() == 1)//梯子の判定
	{
		return 0;
	}

	//4階の判定
	if ((kGroundFourthBottomX > m_pos.x - 25) &&
		(kGroundFourthX < m_pos.x + 25))
	{
		if ((kGroundFourthBottomY > m_pos.y) &&
			(kGroundFourthY < m_pos.y + 60))
		{
			m_pos.y = kGroundFourthY - 50;// -m_playerSize.y;
			m_isInvaliDown = true;//下に移動できない
			return 1;
		}
	}
	//3階の判定
	if ((kGroundThirdBottomX > m_pos.x - 25) &&
		(kGroundThirdX < m_pos.x + 25))
	{
		if ((kGroundThirdBottomY > m_pos.y) &&
			(kGroundThirdY < m_pos.y + 60))
		{
			m_pos.y = kGroundThirdY - 50;// -m_playerSize.y;
			m_isInvaliDown = true;//下に移動できない
			return 1;
		}
	}
	//2階の判定
	if ((kGroundSecondBottomX > m_pos.x - 25) &&
		(kGroundSecondX       < m_pos.x + 25))
	{
		if ((kGroundSecondBottomY > m_pos.y) &&
			(kGroundSecondY       < m_pos.y + 60))
		{
			m_pos.y = kGroundSecondY - 50;// -m_playerSize.y;
			m_isInvaliDown = true;//下に移動できない
			return 1;
		}
	}
#if false			
	//1階の判定
	if ((Game::kScreenWidth > m_playerLeft) &&
		(0                     < m_playerRight))
	{
		if ((kGround > m_playerTop) &&
			(700              < m_playerBpttom))
		{

			m_pos.y = kGround - 45 - m_playerSize.y;
			printfDx("地面判定\n");
			m_isInvaliDown = true;//下に移動できない
			return 1;

		}
	}
#else
	//1階
	if ((Game::kScreenWidth + 1 > m_pos.x - 25) &&
		(0                      < m_pos.x + 25))
	{
		if ((Game::kScreenHeight - 20 > m_pos.y + 10) &&
			(Game::kScreenHeight - 40 < m_pos.y + 60))
		{

			m_pos.y = Game::kScreenHeight - 40 - 50 - m_playerSize.y;
	
			m_isInvaliDown = true;//下に移動できない
			printfDx("地面判定\n");
			return 1;

		}
	}
#endif

	return 0;
}
//キャラクターとはしごの判定
int PlayerMapMove::CheckHit()
{
#if true	

	//3階梯子
	if ((kLadderBottomThirdX > m_playerLeft) &&
		(kLadderThirdX < m_playerRight))
	{
		if ((kLadderBottomThirdY > m_playerTop) &&
			(kLadderThirdY < m_playerBottom))
		{
			m_isFloorOne = true;
			m_isInvaliDown = true;
			m_count++;
			//1フレームだけで代入する（予定
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
			}
			return 1;
		}
	}
	//2階梯子
	if ((kLadderBottomSecondX > m_playerLeft) &&
		(kLadderSecondX < m_playerRight))
	{
		if ((kLadderBottomSecondY > m_playerTop) &&
			(kLadderSecondY < m_playerBottom))
		{
			m_isFloorOne = true;
			m_isInvaliDown = true;
			m_count++;
			//1フレームだけで代入する（予定
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
			}
			return 1;
		}
	}
	//1階梯子
	if ((kLadderXBottom > m_playerLeft) &&
		(kLadderX < m_playerRight))
	{
		if ((kLadderYBottom > m_playerTop) &&
			(kLadderY < m_playerBottom))
		{
			
			m_isFloorOne = true;
			m_isInvaliDown = true;
			m_count++;
			//1フレームだけで代入する（予定
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
			}
			if (m_isUpTip)
			{
				m_tip = 3;
			}
			return 1;
		}
	}
#else
	if ((kLadderXBottom > m_pos.x - 25) &&
		(kLadderX < m_pos.x + 25))
	{
		if ((kLadderYBottom > m_pos.y + 10) &&
			(kLadderY < m_pos.y + 60))
		{
			m_isFloorOne = true;
			m_isInvaliDown = true;
			m_count++;
			//1フレームだけで代入する（予定
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
			}

			/*
			if (static_cast<int>(m_pos.y) <= 680)
			{
				m_hierarchy = 1;
			}

			if (static_cast<int>(m_pos.y) <= 580)
			{
				m_hierarchy = 2;
			}
			*/
			return 1;
		}
	}
#endif	
	m_isFloorOne = false;
	m_count = 0;

	return 0;
}
//アイテムボックスの判定
void PlayerMapMove::BoxJudgement()
{
	if ((m_boxPosBottomX > m_playerLeft) &&
		((m_boxPosX < m_playerRight)))
	{
		if ((m_boxPosBottomY > m_playerTop) &&
			(m_boxPosY < m_playerBottom))
		{
			//printfDx("ボックス判定\n");
			m_isItemDrop = true;
			if (m_boxDropCount >= 120)
			{
				m_isGetSword = true;//アイテムボックス非表示
				m_boxDropCount = 0;

				if(m_isItemTip){
					m_tip = 1;
				}
			}

		}
	}
}
//敵とプレイヤーの判定
bool PlayerMapMove::EnemyHit()
{			
	if (GetLifeEnemy())
	{
		if ((m_pEnemy->GetSizeBottom().x > m_playerLeft) &&
			(m_pEnemy->GetSize().x < m_playerRight))
		{
			if ((m_pEnemy->GetSizeBottom().y > m_playerTop) &&
				(m_pEnemy->GetSize().y < m_playerBottom))
			{
				if (m_isGetSword)
				{
					if (m_isItemDropTip) {
						m_tip = 2;
					}
					m_boxPosX = static_cast<int>(m_pos.x);
					m_boxPosY = static_cast<int>(m_pos.y) - 80;
					m_boxPosBottomX = m_boxPosX + 50;
					m_boxPosBottomY = m_boxPosY + 50;

					m_isGetSword = false;//アイテムボックスドロップ
				}

				m_isDamageMove = true;//ダメージアニメーション再生
				return true;
			}
		}
	}

	return false;
}
//敵との攻撃当たり判定
bool PlayerMapMove::AttackHit()
{
	if(m_isAttack)
	{
		if ((m_pEnemy->GetSizeBottomHit().x > m_attackPos.x) &&
			(m_pEnemy->GetSizeHit().x < m_attackBottomPos.x))
		{
			if ((m_pEnemy->GetSizeBottomHit().x > m_attackPos.y) &&
				(m_pEnemy->GetSizeHit().y < m_attackBottomPos.y))
			{
				m_isEnemyDead = false;
				printfDx("攻撃をした");
				return true;
			}
		}
	}
	return false;
}
//プレイヤーとゴールの当たり判定
bool PlayerMapMove::CheckGoal()
{
	if ((kGoalBottomX > m_playerLeft) &&
		(kGoalX < m_playerRight))
	{
		if ((kGoalBottomY > m_playerTop) &&
			(kGoalY < m_playerBottom))
		{
			m_func = &PlayerMapMove::Goal;
			return true;
		}
	}
	return false;
}
//プレイヤーの体力を管理
void PlayerMapMove::HealthControl()
{
	m_playerHealthBerCount += 1;
	if (m_playerHealthBerCount == 1)
	{
		m_playerHealthBer -= 20;
		m_playerHealthSizeX -= 20;
	}

	if (m_playerHealthBer <= 0)
	{
		m_playerHealthBer = 1;
		printfDx("死亡\n");
		m_playerHealthSizeX = 0;
		m_isHealthBer = true;
		//ポーズメニュー

		m_func = &PlayerMapMove::DeathMenu;
		
	}
	
}
//マップを描画
void PlayerMapMove::DrawMap()
{
	//////////////////////////////////////
	//*　　　　　マップ背景　　　　　　*//
	//////////////////////////////////////
	DrawExtendGraph(0,0,  Game::kScreenWidth,Game::kScreenHeight,  m_hMapFirst , true);
	DrawExtendGraph(-10 + GetRand(10), 0 + GetRand(5), Game::kScreenWidth + GetRand(10), Game::kScreenHeight + GetRand(5), m_hMapSecond, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMapThird , true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMapFourth, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMapFifth, true);

	//////////////////////////////////////
	//*　　　　　　ゴール　　　　　　　*//
	//////////////////////////////////////

	DrawBox(kGoalX, kGoalY, kGoalBottomX, kGoalBottomY, 0x000000, true);


	//////////////////////////////////////
	//*　　　　　マップチップ　　　　　*//
	//////////////////////////////////////
	
		//2階の梯子
	DrawRectExtendGraph(
		kLadderThirdX - 50, kLadderThirdY, kLadderBottomThirdX + 20, kLadderBottomThirdY + 60,
		683, 400, 21 + 10, 80 + 10,
		m_hMapChipSecond, true);

	//2階の梯子
	DrawRectExtendGraph(
		kLadderSecondX - 50, kLadderSecondY, kLadderBottomSecondX + 20, kLadderBottomSecondY + 60,
		683, 400, 21 + 10, 80 + 10,
		m_hMapChipSecond, true);

	//1階の梯子
	DrawRectExtendGraph(
		kLadderX - 50, kLadderY, kLadderXBottom + 20, kLadderYBottom + 60,
		683, 400, 21 + 10, 80 + 10,
		m_hMapChipSecond, true);

	//4階
	DrawRectExtendGraph(
		kGroundFourthX, kGroundFourthY,
		kGroundFourthBottomX, kGroundFourthBottomY,
		16, 224, 160, 32,
		m_hMapChip, true);

	//3階
	DrawRectExtendGraph(
		kGroundThirdX, kGroundThirdY,
		kGroundThirdBottomX, kGroundThirdBottomY,
		16, 224, 160, 32,
		m_hMapChip, true);
	//2階
	DrawRectExtendGraph(
		kGroundSecondX, kGroundSecondY,
		kGroundSecondBottomX, kGroundSecondBottomY,
		16, 224, 160, 32,
		m_hMapChip, true);
	//1階
	DrawRectExtendGraph(
		0, Game::kScreenHeight - 40, Game::kScreenWidth + 1, Game::kScreenHeight - 20,
		16, 224, 160, 32,
		m_hMapChip, true);


	//////////////////////////////////////
	//*地面は下から順番に数えていきます*//
	//////////////////////////////////////

	//梯子3
	DrawBox(kLadderThirdX, kLadderThirdY, kLadderBottomThirdX, kLadderBottomThirdY, 0xff0000, true);
	//     　 left,  　　top,  　　 right,   　　　bottom,
	//梯子2
	DrawBox(kLadderSecondX, kLadderSecondY, kLadderBottomSecondX, kLadderBottomSecondY, 0xff0000, true);
	//     　 left,  　　top,  　　 right,   　　　bottom,
	//梯子1
	DrawBox(kLadderX, kLadderY, kLadderXBottom, kLadderYBottom, 0xff0000, true);
	//     　 left,  　　top,  　　 right,   　　　bottom,

	//地面3
	DrawBox(kGroundThirdX, kGroundThirdY,
		kGroundThirdBottomX, kGroundThirdBottomY, 0x00ff00, false);

	//地面3
	DrawBox(kGroundThirdX, kGroundThirdY,
		kGroundThirdBottomX, kGroundThirdBottomY, 0x00ff00, false);

	//地面2
	DrawBox(kGroundSecondX, kGroundSecondY,
		kGroundSecondBottomX, kGroundSecondBottomY, 0x00ff00, false);

	//地面１
	DrawBox(0, Game::kScreenHeight - 40, Game::kScreenWidth + 1, Game::kScreenHeight - 20, 0x00ff00, false);
}
//ヒントを表示
void PlayerMapMove::DrawTip()
{
	//武器入手
	if (m_tip == 1)
	{
		int x = 650;
		int y = 400;
		int bx = x + 550;
		int by = y + 300;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//透過
		DrawBox(x, y, bx, by, 0x0000ff, true);//背景
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawBox(x, y, bx, by, 0xffffff, false);//枠
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 100, "あなたは近接武器を入手しました", 0x6FFFBF);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2, "V　を入力することで攻撃できます", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 + 100, "SPACE 押して ゲームに戻る", 0xffffff);
		m_isItemTip = false;
	}
	//アイテムをドロップ
	if (m_tip == 2)
	{
		int x = 650;
		int y = 400;
		int bx = x + 550;
		int by = y + 300;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//透過
		DrawBox(x, y, bx, by, 0x0000ff, true);//背景
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawBox(x, y, bx, by, 0xffffff, false);//枠
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 100, "せっかく入手したアイテムを落としてしまった！", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2, "もう一度アイテムに当たると使うことができる！", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 + 100, "SPACE 押して ゲームに戻る", 0xffffff);
		m_isItemDropTip = false;
	}
	//梯子を移動
	if (m_tip == 3)
	{
		int x = 650;
		int y = 400;
		int bx = x + 550;
		int by = y + 300;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//透過
		DrawBox(x, y, bx, by, 0x0000ff, true);//背景
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawBox(x, y, bx, by, 0xffffff, false);//枠
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 100, "ツタを利用して上下に移動しよう！", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2, "十字キー上下で移動できる！", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 + 100, "SPACE 押して ゲームに戻る", 0xffffff);
		m_isUpTip = false;
	}
}

//アップデート処理
void PlayerMapMove::UpdateMove()
{	
	//clsDx();
	if(FieldJudgement() == 0)
	{
		//重力
		m_vec.y += m_gravity;	
	}

	if(CheckHit() == 1)
	{
		m_vec.y = 0.0f;
	}

	m_playerLeft = static_cast<int>(m_pos.x) - 15;
	m_playerTop = static_cast<int>(m_pos.y)+ 10;
	m_playerRight = m_playerLeft + 40;
	m_playerBottom = m_playerTop + 40;
	
	//プレイヤー攻撃範囲
	if (m_isCharaDirection)
	{
		m_attackPos.x = m_pos.x - 20.0f;
		m_attackPos.y = m_pos.y - 20.0f;
		m_attackBottomPos.x = m_attackPos.x + 60.0f;
		m_attackBottomPos.y = m_attackPos.y + 70.0f;
	}
	else
	{
		m_attackPos.x = m_pos.x - 40.0f;
		m_attackPos.y = m_pos.y - 20.0f;
		m_attackBottomPos.x = m_attackPos.x + 60.0f;
		m_attackBottomPos.y = m_attackPos.y + 70.0f;
	}


	//プレイヤー位置
	m_imagePos = m_pos;
	m_pos      += m_vec;
	m_underPos += m_vec;

	////////////////////
	////*当たり判定*////
	///////////////////
	//はしご
	CheckHit();
	//地面
	FieldJudgement();
	//アイテム
	BoxJudgement();
	//攻撃
	AttackHit();
	if (!m_isGetSword)
	{
		m_boxDropCount++;

	}

	if (m_boxDropCount >= 120)
	{
		m_boxDropCount = 120;
		
	}
	
	//敵との当たり判定
	EnemyHit();
	if(!m_isHealthBer)
	{
		if(EnemyHit())
		{
			//m_boxDropCount++;
			HealthControl();
		}
		else
		{
			m_playerHealthBerCount = 0;
		}
	}
	//ゴール確認
	CheckGoal();
	//操作
	Operation();
	//状態（動き）
	Condition();

	if (m_tip == 1 ||m_tip == 2 || m_tip == 3)
	{
		m_func = &PlayerMapMove::Description;
	}
}
//ポーズ画面
void PlayerMapMove::MenuStop()
{
	if (CheckHitKey(KEY_INPUT_O))
	{
		m_isMenu = false;
		m_isStopMove = true;
		m_func = &PlayerMapMove::UpdateMove;
	}
	if (CheckHitKey(KEY_INPUT_Z))
	{
		m_isTitle = true;
		/*
		m_isMenu = false;
		m_isReset = true;
		*/
	}
	if (CheckHitKey(KEY_INPUT_Q))
	{
		/*
		m_isMenu = false;
		m_isTitle = true;
		*/
		DxLib_End();
	}
}
//死んだ場合のMenu
void PlayerMapMove::DeathMenu()
{
	m_isDead = true;
	
	if (CheckHitKey(KEY_INPUT_Y))
	{
		m_isReset = true;
	}
	
}
//ゴールに到達した場合
void PlayerMapMove::Goal()
{
	m_pos.x = kGoalX + 30;
	m_imagePos.x = kGoalX + 30;
	m_pos.y -= 8.0f;
	m_imagePos.y -= 8.0f;
	//上まで行くとマップ移動
	if (m_pos.y <= 0.0f)
	{
		DrawString(300, 300, "移動", 0xffffff);
		m_isStageClear = true;
	}
}

void PlayerMapMove::Description()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_tip = 10;
		m_func = &PlayerMapMove::UpdateMove;
	}

}
