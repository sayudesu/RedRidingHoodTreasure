#include "EnemyStage2.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

EnemyStage2::EnemyStage2() :
	m_hFireBall(-1),//画像ハンドル
	m_hBarre(-1),
	m_hEnemyImage(-1),
	m_hNeedle(-1),//地面用
	m_hTiles(-1),//画像チップ
	m_hCave(-1),//洞窟画像用
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
	m_upDownLeft(0),//上下運動する罠
	m_upDownTop(0),
	m_upDownRight(0),
	m_upDownBottom(0),
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
	m_isUpDown(false),//上下どちらにいるか
	m_isRush(false),
	m_isRushBlink(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(0.0f, 0.0f),//樽
	m_fallenPos(0.0f, 0.0f),//ドッスン的な奴
	m_fallen2Pos(0.0f, 0.0f),//ドッスン的な奴
	m_chargePos(0.0f, 0.0f),//チャージする敵
	m_upDownPos(0.0f, 0.0f),//上下運動する罠
	m_vec(0.0f, 0.0f),
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
	m_barrelPos.x = Enemy2::kBossPosLeft;
	m_barrelPos.y = Enemy2::kBossPosTop;
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


	m_upDownPos.x = 1000.0f;
	m_upDownPos.y = Stage2::kBoxBottom4Yf + 15;

	m_hFireBall = LoadGraph(Image::kEnemySnail);//カタツムリ
	m_hBarre = LoadGraph(Image::kEnemyBarre);//いのしし
	m_hTiles = LoadGraph(Image::kMapTiles2);//画像チップ（洞窟用）

	m_hEnemyImage = LoadGraph(Image::kEnemyFallen);//落ちてくる罠が入ってる画像

	m_hNeedle = DerivationGraph(0, 160, 32 + 16, 32, m_hEnemyImage);//地面画像から一部を抽出
	m_hCave = DerivationGraph(272, 208, 128, 160, m_hTiles);//地面画像から一部を抽出
}

EnemyStage2::~EnemyStage2()
{
	DeleteGraph(m_hFireBall);//かたつむり
	DeleteGraph(m_hBarre);//イノシシ
	DeleteGraph(m_hEnemyImage);//画像
	DeleteGraph(m_hNeedle);//落ちてくる敵
}

void EnemyStage2::Init()
{
}

void EnemyStage2::End()
{
}

void EnemyStage2::Update()
{
	BarrelMove();//樽の動き
	fireBallMove();//ファイアボールの動き
	falleMove();//ドッスン動き
	ChargeMove();//チャージエネミーの動き
	UpDownMove();//上下運動する罠
	npcPos();//敵のサイズ取得
}
//描画
void EnemyStage2::Draw()
{
	//ボス(洞窟に変更敵のスポーン位置)
	DrawExtendGraph(Enemy2::kBossPosLeft, Enemy2::kBossPosTop, Enemy2::kBossPosRight, Enemy2::kBossPosBottom,
		m_hCave, true);
	DrawBox(Enemy2::kBossPosLeft, Enemy2::kBossPosTop,
		Enemy2::kBossPosRight, Enemy2::kBossPosBottom, 0xffff00, false);

	//エネミー炎の玉
	DrawRectRotaGraph(m_posLeft + 20, m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//画像を描画
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//判定確認

	//樽
	DrawRectRotaGraph(m_barrelLeft + 20, m_barrelTop + 15 - 5,
		m_barreImagePosX, 0, 48, 32, 2, 0, m_hBarre, true, m_barreImageDirection);//画像を描画
	DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, false);//判定確認
	//横288
	//縦32


	DrawRectRotaGraph(
		m_fallenLeft + 30, m_fallenTop + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallenLeft + 30 + 45, m_fallenTop + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallenLeft + 30 + 45 + 45, m_fallenTop + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	//どっすん
	DrawBox(m_fallenLeft, m_fallenTop, m_fallenRight, m_fallenBottom, 0xffff00, false);

	DrawRectRotaGraph(
		m_fallen2Left + 30, m_fallen2Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallen2Left + 30 + 45, m_fallen2Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallen2Left + 30 + 45 + 45, m_fallen2Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	//どっすん2
	DrawBox(m_fallen2Left, m_fallen2Top, m_fallen2Right, m_fallen2Bottom, 0xffff00, false);

	//チャージエネミー
	if (!m_isRushBlink)//止まってる間は見えない
	{
		DrawBox(m_chargeLeft, m_chargeTop, m_chargeRight, m_chargeBottom, 0xffff00, false);
	}

	//罠
	//上下運動する罠
	DrawBox(m_upDownLeft, m_upDownTop, m_upDownRight, m_upDownBottom, 0xffffff, true);

#if false	
	//どっすん範囲
	DrawBox(m_fallenRangeLeft, m_fallenRangeTop, m_fallenRangeRight, m_fallenRangeBottom, 0xffff00, false);
	//どっすん2範囲
	DrawBox(m_fallenRange2Left, m_fallenRange2Top, m_fallenRange2Right, m_fallenRange2Bottom, 0xffff00, false);
#endif
}
//樽の動き
void EnemyStage2::BarrelMove()
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
		m_barrelPos.x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
	}
	else if (m_fall == 4)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += Enemy2::kBarrelSpeed * m_barrelSpeed;//左に移動
		m_barreImageDirection = true;//画像の方向を変更
	}

	if (m_fall == 3)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
		m_barreImageDirection = false;//画像の方向を変更
	}

	if (m_fall == 2)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += Enemy2::kBarrelSpeed * m_barrelSpeed;//左に移動
		m_barreImageDirection = true;//画像の方向を変更

	}

	if (m_fall == 1)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
		m_barreImageDirection = false;//画像の方向を変更

	}

	if (m_barrelRight < 0)//樽が画面左に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy2::kBossPosLeft + 50;
		m_barrelPos.y = Enemy2::kBossPosTop + 100;
	}
	else if (m_barrelRight > Game::kScreenWidth + 100)//樽が画面右に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy2::kBossPosLeft + 50;
		m_barrelPos.y = Enemy2::kBossPosTop + 100;
	}

	if (m_fall == 0 && !m_isCourse)//樽が右に移動する場合
	{
		m_barrelPos.x -= Enemy2::kBarrelSpeed;
	}

	if (m_fall == 0 && m_isCourse)//樽が左に移動する場合
	{
		m_barrelPos.x += Enemy2::kBarrelSpeed;
	}


}
//炎球の動き
void EnemyStage2::fireBallMove()
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
void EnemyStage2::falleMove()
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
		m_fallenPos.y = Stage2::kBoxBottom8Yf + GetRand(10);
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
void EnemyStage2::ChargeMove()
{
	//プレイヤーに突進する
	Vec2 toPlayer{ 0.0f,0.0f };

	toPlayer.x = m_playerPos.x - m_chargePos.x;
	toPlayer.y = m_playerPos.y - m_chargePos.y;

	//m_length = toPlayer.length();//長さを取得

	toPlayer = toPlayer.normalize();//正規化
	

	m_chargePos += toPlayer * m_chargeSpeed;//プレイヤーの方向に直線で移動

}
void EnemyStage2::UpDownMove()
{
	if (!m_isUpDown)//上にいる場合
	{
		m_upDownPos.y += 3;
		if (m_upDownPos.y == Stage2::kBox4Yt - 15)//下に到達した場合
		{
			m_isUpDown = true;
		}
	}
	else
	{
		m_upDownPos.y -= 3;
		if (m_upDownPos.y == Stage2::kBoxBottom4Yf + 15)//下に到達した場合
		{
			m_isUpDown = false;
		}

	}
}
//敵のキャラ座標取得
void EnemyStage2::npcPos()
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
	m_barrelTop = m_barrelPos.y + 5.0f;
	m_barrelRight = m_barrelLeft + 50;
	m_barrelBottom = m_barrelTop + 40;

	//ドッスン
	m_fallenLeft = m_fallenPos.x;
	m_fallenTop = m_fallenPos.y;
	m_fallenRight = m_fallenLeft + 150;
	m_fallenBottom = m_fallenTop + 10;
	//ドッスン反応判定
	m_fallenRangeLeft = 1110;
	m_fallenRangeTop = 550;
	m_fallenRangeRight = m_fallenRangeLeft + 250;
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
	//上下運動する罠
	m_upDownLeft = m_upDownPos.x;
	m_upDownTop = m_upDownPos.y;
	m_upDownRight = m_upDownLeft + 30;
	m_upDownBottom = m_upDownTop + 30;
}
