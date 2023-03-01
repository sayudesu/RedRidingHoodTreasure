#include "EnemyStage1.h"
#include "SceneMain2.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

namespace Enemy
{

	//ボスの位置
	constexpr int kBossPosLeft = Game::kScreenWidth - 300;
	constexpr int kBossPosTop = 200;
	constexpr int kBossPosRight = kBossPosLeft + 100;
	constexpr int kBossPosBottom = kBossPosTop + 100;

	constexpr float kBarrelSpeed = 8.0f;


}

EnemyStage1::EnemyStage1():
	m_hFireBall(-1),//画像ハンドル
	m_hBarre(-1),
	m_posLeft(0),
	m_posTop(0),
	m_posRight(0),
	m_posBottom(0),
	m_barrelLeft(0),//樽サイズ
	m_barrelTop(0),
	m_barrelRight(0),
	m_barrelBottom(0),
	m_barrelSizePulsX(0),//樽サイズ変更.X
	m_fallenLeft(0),
	m_fallenTop(0),
	m_fallenRight(0),
	m_fallenBottom(0),
	m_fallen2Left(0),
	m_fallen2Top(0),
	m_fallen2Right(0),
	m_fallen2Bottom(0),
	m_fallenRangeLeft(0),
	m_fallenRangeTop(0),
	m_fallenRangeRight(0),
	m_fallenRangeBottom(0),
	m_fallenRange2Left(0),
	m_fallenRange2Top(0),
	m_fallenRange2Right(0),
	m_fallenRange2Bottom(0),
	m_chargeLeft(0),
	m_chargeTop(0),
	m_chargeRight(0),
	m_chargeBottom(0),
	m_fireBallImagePosX(0),//ファイアボール画像位置
	m_fireBallImagePosY(0),
	m_fireImageDirection(0),
	m_barreImagePosX(0),//樽（イノシシ）画像位置
	m_barreImageDirection(false),//樽（いのしし）画像の方向
	m_barrelSpeed(0),
	m_fall(0),
	m_fallFireBall(0),
	m_fallenRange(0),
	m_fallenRange2(0),
	m_fallenCount(0),
	m_fallenCount2(0),
	m_frameCountBarreImage(0),//樽（いのしし）の画像描画用フレームカウント
	m_frameCountFireImage(0),
	m_ladderNum(0),
	m_rushCount(0),
	m_fallenUpSpeed(0.0f),
	m_fallenUpSpeed2(0.0f),
	m_getPos(0.0f),
	m_fireRad(0),//ファイアボール角度
	m_chargeSpeed(0.0f),
	m_length(0.0f),
	m_getFireBallPos(0),
	m_isFirstMove(false),
	m_isCourse(false),
	m_isFireBallCourse(false),
	m_isFallenDrop(false),
	m_isCanFallen(false),
	m_isFallenDrop2(false),
	m_isCanFallen2(false),
	m_isFallenUp(false),
	m_isFallenUp2(false),
	m_isRush(false),
	m_isRushBlink(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(0.0f,0.0f),//樽
	m_fallenPos(0.0f, 0.0f),//ドッスン的な奴
	m_fallen2Pos(0.0f, 0.0f),//ドッスン的な奴
	m_chargePos(0.0f, 0.0f),//チャージする敵
	m_vec(0.0f,0.0f),
	m_playerPos(0.0f, 0.0f),
	m_playerSavePos(0.0f, 0.0f)
{
	m_isFirstMove = true;//初動動作
	m_isCanFallen = true;
	m_isCanFallen2 = true;
	//ファイアボール初期位置
	m_pos.x = Game::kScreenWidth - 400;
	m_pos.y = Game::kScreenHeight - 150;
	//樽初期位置
	m_barrelPos.x = Enemy::kBossPosLeft;
	m_barrelPos.y = Enemy::kBossPosTop;
	//どっすん
	m_fallenPos.x = Stage2::kBox2Xt;
	m_fallenPos.y = Stage2::kBoxBottom8Yf;
	//どっすん2
	m_fallen2Pos.x = Stage2::kBox4Xt;
	m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//チャージする敵
	m_chargePos.x = Stage2::kBox1Xf;
	m_chargePos.y = Stage2::kBox1Yf - 50;

	m_chargeSpeed = 10.0f;

	m_hFireBall = LoadGraph(Image::kEnemySnail);
	m_hBarre = LoadGraph(Image::kEnemyBarre);

}

EnemyStage1::~EnemyStage1()
{
	DeleteGraph(m_hFireBall);
	DeleteGraph(m_hBarre);
}

void EnemyStage1::Init()
{
}

void EnemyStage1::End()
{
}

void EnemyStage1::Update()
{
	BarrelMove();//樽の動き
	fireBallMove();//ファイアボールの動き
	falleMove();//ドッスン動き
	ChargeMove();//チャージエネミーの動き
	npcPos();//敵のサイズ取得
}
//描画
void EnemyStage1::Draw()
{
	//エネミー炎の玉
	DrawRectRotaGraph(m_posLeft + 20 , m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//画像を描画
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//判定確認

	//樽
	DrawRectRotaGraph(m_barrelLeft + 20, m_barrelTop + 15,
		m_barreImagePosX, 0, 48, 32, 2, 0, m_hBarre, true, m_barreImageDirection);//画像を描画
	DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, false);//判定確認
	//横288
	//縦32

	//ボス
	DrawBox(Enemy::kBossPosLeft, Enemy::kBossPosTop,
		Enemy::kBossPosRight, Enemy::kBossPosBottom, 0xffff00, true);
	//どっすん
	DrawBox(m_fallenLeft, m_fallenTop, m_fallenRight, m_fallenBottom, 0xffff00, true);
	//どっすん2
	DrawBox(m_fallen2Left, m_fallen2Top, m_fallen2Right, m_fallen2Bottom, 0xffff00, true);
	//チャージエネミー
	if (m_isRushBlink)//止まってる間は見えない
	{
		DrawBox(m_chargeLeft, m_chargeTop, m_chargeRight, m_chargeBottom, 0xffff00, false);
	}
#if false	
	//どっすん範囲
	DrawBox(m_fallenRangeLeft, m_fallenRangeTop, m_fallenRangeRight, m_fallenRangeBottom, 0xffff00, false);
	//どっすん2範囲
	DrawBox(m_fallenRange2Left, m_fallenRange2Top, m_fallenRange2Right, m_fallenRange2Bottom, 0xffff00, false);
#endif
}
//樽の動き
void EnemyStage1::BarrelMove()
{
	m_barrelPos.y += m_vec.y;//重力のベクトル用

	m_vec.y += 3.0f;//重力

	m_frameCountBarreImage++;
	if (m_frameCountBarreImage == 3)//３フレームに一回画像を変更
	{
		m_barreImagePosX += 48;
		m_frameCountBarreImage = 0;
}
	if (m_barreImagePosX >= 288)
	{
		m_barreImagePosX = 0;
	}

	if (m_fall == 5)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
	}
	else if (m_fall == 4)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += Enemy::kBarrelSpeed * m_barrelSpeed;//左に移動
		m_barreImageDirection = true;//画像の方向を変更
	}

	if (m_fall == 3)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
		m_barreImageDirection = false;//画像の方向を変更
	}

	if (m_fall == 2)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += Enemy::kBarrelSpeed * m_barrelSpeed;//左に移動
		m_barreImageDirection = true;//画像の方向を変更

	}

	if (m_fall == 1)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
		m_barreImageDirection = false;//画像の方向を変更

	}

	if (m_barrelRight < 0)//樽が画面左に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy::kBossPosLeft;
		m_barrelPos.y = Enemy::kBossPosTop;
	}
	else if (m_barrelRight > Game::kScreenWidth + 100)//樽が画面右に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy::kBossPosLeft;
		m_barrelPos.y = Enemy::kBossPosTop;
	}

	if (m_fall == 0 && !m_isCourse)//樽が右に移動する場合
	{
		m_barrelPos.x -= Enemy::kBarrelSpeed;
	}

	if (m_fall == 0 && m_isCourse)//樽が左に移動する場合
	{
		m_barrelPos.x += Enemy::kBarrelSpeed;
	}


}
//炎球の動き
void EnemyStage1::fireBallMove()
{
	m_pos.y += 3.0f;//重力

	m_frameCountFireImage++;
	if (m_frameCountFireImage == 3)
	{
		m_fireBallImagePosX += 48;
		m_frameCountFireImage = 0;
	}
	if (m_fireBallImagePosX >= 384) 
	{
		m_fireBallImagePosX = 0;
	}

	//ファイアボールの画像調整
	//m_fireBallImagePosX += 100;//画像を右まで動かす

	//if (m_fireBallImagePosX >= 800)//画像表示を右まで行ったらY軸を１画像下に下げる
	//{
	//	m_fireBallImagePosX = 0;//一番左までリセット
	//	m_fireBallImagePosY += 100;//表示する画像を１画像分下に下げる

	//}
	//if (m_fireBallImagePosY >= 700 && m_fireBallImagePosX >= 500)//Y軸下まで行ったら画像を一番上まで戻す
	//{
	//	m_fireBallImagePosX = 0;//一番左までリセット
	//	m_fireBallImagePosY = 0;//Y軸で画像を一番上の画像に戻す

	//}

	if (!m_isFireBallCourse)//右動き
	{
		m_pos.x -= 8.0f;
		if (m_pos.x < 0)//向きを変更する
		{
			//方向を変更
			m_isFireBallCourse = true;//移動方向を変更
			m_fireImageDirection = true;//画像の方向を変更
		}
	}
	else//左動き
	{
		m_pos.x += 8.0f;
		if (m_pos.x > Game::kScreenWidth)//向きを変更する
		{
			//方向を変更
			m_isFireBallCourse = false;//移動方向を変更
			m_fireImageDirection = false;//画像の方向を変更
		}
	}

	if (m_fallFireBall == 2)//地面に当たったら
	{
		//m_vec.y = 0.0f;//下に落ちないように
		m_pos.y = static_cast<float>(m_getFireBallPos) + 10;//プレイヤーの位置座標
	}
}
//どっすん動き
void EnemyStage1::falleMove()
{
	//一体目
	if (m_isCanFallen)//初期の位置にいるかどうか
	{
		if (m_fallenRange == 1)//範囲内だったら
		{
			m_isFallenDrop = true;
			m_isCanFallen = false;
		}

	}

	if (m_isFallenDrop)//落ちもの揺れる
	{
		m_fallenCount++;//震える時間
		//揺れる
		m_fallenPos.x = Stage2::kBox2Xt + GetRand(10);
		m_fallenPos.y = Stage2::kBoxBottom8Yf  + GetRand(10);
	}

	if (m_fallenCount >= 45)
	{
		m_isFallenDrop = false;
		//落下開始
		m_fallenUpSpeed = 10.0f;//今だけ後で書き換える
		m_fallenPos.y += m_fallenUpSpeed;//落下スピード
		if (m_fallenPos.y >= Stage2::kBox2Yt)//落ちる場所制限
		{
			m_isFallenUp = true;//上に戻す処理
		}
	}
	
	if (m_isFallenUp)//天井
	{
		m_fallenUpSpeed = 15.0f;//今だけ後で書き換える
		m_fallenPos.y -= m_fallenUpSpeed;

		if (m_fallenPos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount = 0;//カウントリセット
			m_isFallenUp = false;
			m_isCanFallen = true;//再度落ちるための処理

			m_fallenPos.x = Stage2::kBox2Xt;
			m_fallenPos.y = Stage2::kBoxBottom8Yf;
		}
	}
	
	//二体目
	if (m_isCanFallen2)//初期の位置にいるかどうか
	{
		if (m_fallenRange == 2)//範囲内だったら
		{
			m_isFallenDrop2 = true;
			m_isCanFallen2 = false;
		}

	}

	if (m_isFallenDrop2)//落ちもの揺れる
	{
		m_fallenCount2++;//震える時間
		//揺れる
		m_fallen2Pos.x = Stage2::kBox4Xt + GetRand(10);
		m_fallen2Pos.y = Stage2::kBoxBottom8Yf + GetRand(10);
	}

	if (m_fallenCount2 >= 45)
	{
		m_isFallenDrop2 = false;
		//落下開始
		m_fallenUpSpeed2 = 10.0f;//今だけ後で書き換える
		m_fallen2Pos.y += m_fallenUpSpeed2;//落下スピード
		if (m_fallen2Pos.y >= Stage2::kBox4Yt)//落ちる場所制限
		{
			m_isFallenUp2 = true;//上に戻す処理
		}
	}

	if (m_isFallenUp2)//天井
	{
		m_fallenUpSpeed2 = 15.0f;//今だけ後で書き換える
		m_fallen2Pos.y -= m_fallenUpSpeed2;

		if (m_fallen2Pos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount2 = 0;//カウントリセット
			m_isFallenUp2 = false;
			m_isCanFallen2 = true;//再度落ちるための処理

			m_fallen2Pos.x = Stage2::kBox4Xt;
			m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
		}
	}


	////二体目
	//if (m_isCanFallen2)//初期の位置にいるかどうか
	//{
	//	if (m_fallenRange == 2)//範囲内だったら
	//	{
	//		m_isFallenDrop2 = true;
	//		m_isCanFallen2 = false;
	//	}
	//}

	//if (m_isFallenDrop2)//落ちもの揺れる
	//{
	//	m_fallenCount2++;//震える時間
	//	//揺れる
	//	m_fallen2Pos.x = Stage2::kBox4Xt + GetRand(10);
	//	m_fallen2Pos.y = Stage2::kBoxBottom8Yf + GetRand(10);

	//	if (m_fallenCount2 >= 30)//3秒後
	//	{
	//		//ポジションをリセット
	//		m_fallen2Pos.x = Stage2::kBox4Xt;
	//		m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//	}
	//}

	//if (m_fallenCount2 >= 45)
	//{
	//	m_isFallenDrop2 = false;
	//	//落下開始
	//	m_fallen2Pos.y += 10;//落下スピード
	//	if (m_fallen2Pos.y >= Stage2::kBox4Yt)//落ちる場所制限
	//	{
	//		m_fallenCount2 = 0;//カウントリセット

	//		//初期ポジションに戻す
	//		m_fallen2Pos.x = Stage2::kBox4Xt;
	//		m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//		m_isCanFallen2 = true;

	//	}
	//}
}
//敵に突進する
void EnemyStage1::ChargeMove()
{
	if (m_isRush)//動けるかどうか
	{

		//プレイヤーに突進する
		Vec2 toPlayer{ 0.0f,0.0f };

		m_rushCount++;
		if (m_rushCount == 1)
		{
			m_playerSavePos = m_playerPos;//少し前のプレイヤー座標を取得する
			//m_chargeSpeed
			//m_chargeSpeed = 30.0f;
		}
		if (m_rushCount >= 120)
		{
			m_isRushBlink = true;
			toPlayer.x = m_playerSavePos.x - m_chargePos.x;
			toPlayer.y = m_playerSavePos.y - m_chargePos.y;

			m_length = toPlayer.length();//長さを取得
			
			toPlayer = toPlayer.normalize();//正規化
			//m_chargeSpeed = 0.0f;

		}

		m_chargePos += toPlayer * m_chargeSpeed;//プレイヤーの方向に直線で移動

		/*
		if (m_length >= m_chargePos.length())
		{
			printfDx("%f\n", m_playerSavePos.length());
		//	printfDx("%f\n", m_length);
			m_rushCount = 0;
			m_isRushBlink = false;
		}
		*/
		/*
		if (static_cast<int>(m_playerSavePos.x) == m_chargeLeft)
		{
			toPlayer.x = 0.0f;
			toPlayer.y = 0.0f;
			m_chargeSpeed = 0.0f;
		}
		*/
		if (m_rushCount == 120 * 2)//追跡できる時間をリセット
		{
			m_rushCount = 0;
			m_isRushBlink = false;
		}
		

		DrawFormatString(100, 45, 0xffffff, "プレイヤーまでの距離 %f", toPlayer);
	}
	else//違う階層にいる場合
	{
		m_isRushBlink = false;//違う階層にいる場合は判定なし
	}

	//printfDx("%d\n", m_chargeLeft);
	DrawFormatString(100,0,0xffffff,    "敵の右上座標         m_chargeLeft   -> %d", m_chargeLeft);
	DrawFormatString(100, 15, 0xffffff, "プレイヤー右上座標   m_playerSavePos-> %f", m_playerSavePos.x);
	DrawFormatString(100, 30, 0xffffff, "プレイヤーまでの距離 m_length       -> %f", m_length);

}
//敵のキャラ座標取得
void EnemyStage1::npcPos()
{
	//enemyの座標
	m_posLeft = m_pos.x;
	m_posTop = m_pos.y;
	m_posRight = m_posLeft + 40;
	m_posBottom = m_posTop + 30;


	if (m_isCourse)
	{
		m_barrelSizePulsX = 150;
	}
	else
	{
		m_barrelSizePulsX = 0;
	}

	//樽
	m_barrelLeft = m_barrelPos.x;
	m_barrelTop = m_barrelPos.y;
	m_barrelRight = m_barrelLeft + 50;
	m_barrelBottom = m_barrelTop + 40;

	//ドッスン
	m_fallenLeft = m_fallenPos.x;
	m_fallenTop = m_fallenPos.y;
	m_fallenRight = m_fallenLeft  + 150;
	m_fallenBottom = m_fallenTop  +10;
	//ドッスン反応判定
	m_fallenRangeLeft =1110;
	m_fallenRangeTop = 550;
	m_fallenRangeRight = m_fallenRangeLeft+ 250;
	m_fallenRangeBottom = m_fallenRangeTop + 120;
	//ドッスン2
	m_fallen2Left = m_fallen2Pos.x;
	m_fallen2Top = m_fallen2Pos.y;
	m_fallen2Right = m_fallen2Left + 150;
	m_fallen2Bottom = m_fallen2Top + 10;
	//ドッスン2反応判定
	m_fallenRange2Left = 1110 + 150 + 150;
	m_fallenRange2Top = 550;
	m_fallenRange2Right = m_fallenRange2Left + 250;
	m_fallenRange2Bottom = m_fallenRange2Top + 120;

	//チャージエネミー
	m_chargeLeft = m_chargePos.x;
	m_chargeTop = m_chargePos.y;
	m_chargeRight = m_chargeLeft + 30;
	m_chargeBottom = m_chargeTop + 30;
}
