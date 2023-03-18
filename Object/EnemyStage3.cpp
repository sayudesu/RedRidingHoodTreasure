#include "EnemyStage3.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

EnemyStage3::EnemyStage3() :
	m_hFireBall(-1),//画像ハンドル
	m_hBarre(),//樽（いのしし画像）
	m_maskHandle(),
	m_hEnemyImage(-1),
	m_hNeedle(-1),//地面用
	m_hTiles(-1),//画像チップ
	m_hCave(-1),//洞窟画像用
	m_hUpDown(-1),//上下運動の罠画像
	m_posLeft(0),
	m_posTop(0),
	m_posRight(0),
	m_posBottom(0),
	m_barrelLeft(),//樽サイズ
	m_barrelTop(),
	m_barrelRight(),
	m_barrelBottom(),
	m_barrelSizePulsX(0),//樽サイズ変更.X
	m_fallenLeft(0),
	m_fallenTop(0),
	m_fallenRight(0),
	m_fallenBottom(0),
	m_fallen2Left(0),
	m_fallen2Top(0),
	m_fallen2Right(0),
	m_fallen2Bottom(0),
	m_fallen3Left(0),
	m_fallen3Top(0),
	m_fallen3Right(0),
	m_fallen3Bottom(0),
	m_fallen4Left(0),
	m_fallen4Top(0),
	m_fallen4Right(0),
	m_fallen4Bottom(0),
	m_fallenRangeLeft(0),
	m_fallenRangeTop(0),
	m_fallenRangeRight(0),
	m_fallenRangeBottom(0),
	m_fallenRange2Left(0),
	m_fallenRange2Top(0),
	m_fallenRange2Right(0),
	m_fallenRange2Bottom(0),
	m_fallenRange3Left(0),
	m_fallenRange3Top(0),
	m_fallenRange3Right(0),
	m_fallenRange3Bottom(0),
	m_fallenRange4Left(0),
	m_fallenRange4Top(0),
	m_fallenRange4Right(0),
	m_fallenRange4Bottom(0),
	m_chargeLeft(0),
	m_chargeTop(0),
	m_chargeRight(0),
	m_chargeBottom(0),
	m_upDownLeft(0),//上下運動する罠
	m_upDownTop(0),
	m_upDownRight(0),
	m_upDownBottom(0),
	m_upDown2Left(0),//上下運動する罠
	m_upDown2Top(0),
	m_upDown2Right(0),
	m_upDown2Bottom(0),
	m_upDown3Left(0),//上下運動する罠
	m_upDown3Top(0),
	m_upDown3Right(0),
	m_upDown3Bottom(0),
	m_fireBallImagePosX(0),//ファイアボール画像位置
	m_fireBallImagePosY(0),
	m_upDownLeftImageX(0),//罠の画像位置
	m_upDownLeftImageY(0),
	m_upDownLeft2ImageX(0),//罠の画像位置
	m_upDownLeft2ImageY(0),
	m_upDownLeft3ImageX(0),//罠の画像位置
	m_upDownLeft3ImageY(0),
	m_upDownRad(0),//罠角度
	m_fireImageDirection(0),
	m_barreImagePosX(),//樽（イノシシ）画像位置
	m_barreImageDirection(),//樽（いのしし）画像の方向
	m_barrelSpeed(0),
	m_fall(),
	m_fallFireBall(0),
	m_fallenRange(0),
	m_fallenRange2(0),
	m_fallenRange3(0),
	m_fallenRange4(0),
	m_fallenCount(0),
	m_fallenCount2(0),
	m_fallenCount3(0),
	m_fallenCount4(0),
	m_frameCountBarreImage(),//樽（いのしし）の画像描画用フレームカウント
	m_frameCountFireImage(0),
	m_ladderNum(0),
	m_rushCount(0),
	m_fallenUpSpeed(0.0f),
	m_fallenUpSpeed2(0.0f),
	m_fallenUpSpeed3(0.0f),
	m_fallenUpSpeed4(0.0f),
	m_getPos(),
	m_fireRad(0),//ファイアボール角度
	m_chargeSpeed(0.0f),
	m_length(0.0f),
	m_getFireBallPos(0),
	m_isFirstMove(false),
	m_isCourse(),
	m_isFireBallCourse(false),
	m_isFallenDrop(false),
	m_isCanFallen(false),
	m_isFallenDrop2(false),
	m_isCanFallen2(false),
	m_isFallenDrop3(false),
	m_isCanFallen3(false),
	m_isFallenDrop4(false),
	m_isCanFallen4(false),
	m_isFallenUp(false),
	m_isFallenUp2(false),
	m_isFallenUp3(false),
	m_isFallenUp4(false),
	m_isBarreMove(false),//2体の敵が動くかどうか
	m_isUpDown(false),//上下どちらにいるか
	m_isUpDown2(false),//上下どちらにいるか
	m_isUpDown3(false),//上下どちらにいるか
	m_isRush(false),
	m_isRushBlink(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(),//樽
	m_fallenPos(0.0f, 0.0f),//ドッスン的な奴
	m_fallen2Pos(0.0f, 0.0f),//ドッスン的な奴
	m_fallen3Pos(0.0f, 0.0f),//ドッスン的な奴
	m_fallen4Pos(0.0f, 0.0f),//ドッスン的な奴
	m_chargePos(0.0f, 0.0f),//チャージする敵
	m_upDownPos(0.0f, 0.0f),//上下運動する罠
	m_upDown2Pos(0.0f, 0.0f),//上下運動する罠
	m_upDown3Pos(0.0f, 0.0f),//上下運動する罠
	m_vec(),
	m_playerPos(0.0f, 0.0f),
	m_playerSavePos(0.0f, 0.0f)
{
	m_isFirstMove = true;//初動動作
	m_isCanFallen = true;
	m_isCanFallen2 = true;
	m_isCanFallen3 = true;
	m_isCanFallen4 = true;

	for (int i = 0; i < 3; i++)
	{
		m_barrelLeft[i] = 0;
		m_barrelTop[i] = 0;
		m_barrelRight[i] = 0;
		m_barrelBottom[i] = 0;
		m_getPos[i] = 0;
		m_fall[i] = 0;
		m_barreImagePosX[i] = 0;
		m_barreImageDirection[i] = false;
		m_isCourse[i] = false;
		m_frameCountBarreImage[i] = 0;
	}

	//ファイアボール初期位置
	m_pos.x = Game::kScreenWidth - 400;
	m_pos.y = Game::kScreenHeight - 150;
	//樽初期位置
	for (int i = 0; i < 3; i++)
	{
		m_barrelPos[i].x = Enemy2::kBossPosLeft;
		m_barrelPos[i].y = Enemy2::kBossPosTop;
		m_vec[i] = {0.0f,0.0f};
	}
	//どっすん
	m_fallenPos.x = Stage2::kBox2Xt;
	m_fallenPos.y = Stage2::kBoxBottom8Yf;
	//どっすん2
	m_fallen2Pos.x = Stage2::kBox4Xt;
	m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//どっすん3
	m_fallen3Pos.x = Stage2::kBoxBottom5Xf;
	m_fallen3Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight / 2;
	//どっすん4
	m_fallen4Pos.x = Stage2::kBoxBottom3Xf;
	m_fallen4Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight;
	//チャージする敵
	m_chargePos.x = Stage2::kBox1Xf;
	m_chargePos.y = Stage2::kBox1Yf - 50;

	m_chargeSpeed = 10.0f;


	m_upDownPos.x = 1000.0f + 50;
	m_upDownPos.y = Stage2::kBoxBottom4Yf + 15;

	m_upDown2Pos.x = 1000.0f - 250 + 10;
	m_upDown2Pos.y = Stage2::kBoxBottom4Yf + 15;

	m_upDown3Pos.x = 1000.0f - 550;
	m_upDown3Pos.y = Stage2::kBoxBottom4Yf + 15;

	m_hFireBall = LoadGraph(Image::kEnemySnail);//カタツムリ
	for (int i = 0; i < 3; i++)
	{
		m_hBarre[i] = LoadGraph(Image::kEnemyBarre);//いのしし
		m_maskHandle[i] = LoadMask(Image::kEnemyBarre);

	}
	m_hTiles = LoadGraph(Image::kMapTiles2);//画像チップ（洞窟用）
	m_hUpDown = LoadGraph(Image::kEnemyFireBall);//罠

	m_hEnemyImage = LoadGraph(Image::kEnemyFallen);//落ちてくる罠が入ってる画像

	m_hNeedle = DerivationGraph(0, 160, 32 + 16, 32, m_hEnemyImage);//地面画像から一部を抽出
	m_hCave = DerivationGraph(272, 208, 128, 160, m_hTiles);//地面画像から一部を抽出
}

EnemyStage3::~EnemyStage3()
{
	DeleteGraph(m_hFireBall);//かたつむり
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(m_hBarre[i]);//イノシシ
	}
	DeleteGraph(m_hEnemyImage);//画像
	DeleteGraph(m_hNeedle);//落ちてくる敵

	DeleteMaskScreen();
}

void EnemyStage3::Init()
{
}

void EnemyStage3::End()
{
}

void EnemyStage3::Update()
{
	BarrelMove();//樽の動き
	fireBallMove();//ファイアボールの動き
	falleMove();//ドッスン動き
	ChargeMove();//チャージエネミーの動き
	UpDownMove();//上下運動する罠
	npcPos();//敵のサイズ取得
}
//描画
void EnemyStage3::Draw()
{
	//ボス(洞窟に変更敵のスポーン位置)
	DrawExtendGraph(Enemy2::kBossPosLeft, Enemy2::kBossPosTop, Enemy2::kBossPosRight, Enemy2::kBossPosBottom,
		m_hCave, true);

	//エネミー炎の玉
	DrawRectRotaGraph(m_posLeft + 20, m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//画像を描画

	//樽
	//DrawRectRotaGraph(m_barrelLeft[0] + 20, m_barrelTop[0] + 15 - 5,
	//	m_barreImagePosX[0], 0, 48, 32, 2, 0, m_hBarre[0], true, m_barreImageDirection);//画像を描画

	//DrawRectRotaGraph(m_barrelLeft[1] + 20, m_barrelTop[1] + 15 - 5,
	//	m_barreImagePosX[1], 0, 48, 32, 2, 0, m_hBarre[1], true, false);//画像を描画

	//DrawRectRotaGraph(m_barrelLeft[2] + 20, m_barrelTop[2] + 15 - 5,
	//	m_barreImagePosX[2], 0, 48, 32, 2, 0, m_hBarre[2], true, false);//画像を描画

	for (int i = 0; i < 3; i++)
	{
		DrawRectRotaGraph(m_barrelLeft[i] + 20, m_barrelTop[i] + 15 - 5,
			m_barreImagePosX[i], 0, 48, 32, 2, 0, m_hBarre[i], true, m_barreImageDirection[i]);//画像を描画
	}
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

	DrawRectRotaGraph(
		m_fallen3Left + 30, m_fallen3Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallen3Left + 30 + 45, m_fallen3Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallen3Left + 30 + 45 + 45, m_fallen3Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);

	DrawRectRotaGraph(
		m_fallen4Left + 30, m_fallen4Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallen4Left + 30 + 45, m_fallen4Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);
	DrawRectRotaGraph(
		m_fallen4Left + 30 + 45 + 45, m_fallen4Top + 15,
		0, 0, 32 + 16, 32,
		1, DX_PI,
		m_hNeedle, true, false
	);

	//チャージエネミー
	if (!m_isRushBlink)//止まってる間は見えない
	{
		//DrawBox(m_chargeLeft, m_chargeTop, m_chargeRight, m_chargeBottom, 0xffff00, false);
	}

	//罠
	//上下運動する罠
	DrawRectRotaGraph(
		m_upDownLeft + 14, m_upDownTop + 15,
		m_upDownLeftImageX, m_upDownLeftImageY, 100, 100,
		1, m_upDownRad,
		m_hUpDown, true, false);
	//上下運動する罠
	DrawRectRotaGraph(
		m_upDown2Left + 14, m_upDown2Top + 15,
		m_upDownLeft2ImageX, m_upDownLeft2ImageY, 100, 100,
		1, m_upDownRad,
		m_hUpDown, true, false);
	//上下運動する罠
	DrawRectRotaGraph(
		m_upDown3Left + 14, m_upDown3Top + 15,
		m_upDownLeft3ImageX, m_upDownLeft3ImageY, 100, 100,
		1, m_upDownRad,
		m_hUpDown, true, false);

#if false		
	DrawBox(Enemy2::kBossPosLeft, Enemy2::kBossPosTop,
		Enemy2::kBossPosRight, Enemy2::kBossPosBottom, 0xffff00, false);
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//判定確認
	DrawBox(m_barrelLeft[0], m_barrelTop[0], m_barrelRight[0], m_barrelBottom[0], 0xffff00, false);//判定確認
	//どっすん
	DrawBox(m_fallenLeft, m_fallenTop, m_fallenRight, m_fallenBottom, 0xffff00, false);
	//どっすん2
	DrawBox(m_fallen2Left, m_fallen2Top, m_fallen2Right, m_fallen2Bottom, 0xffff00, false);
	//どっすん3
	DrawBox(m_fallen3Left, m_fallen3Top, m_fallen3Right, m_fallen3Bottom, 0x00ff00, false);
	//どっすん4
	DrawBox(m_fallen4Left, m_fallen4Top, m_fallen4Right, m_fallen4Bottom, 0xffff00, false);
	DrawBox(m_upDownLeft, m_upDownTop, m_upDownRight, m_upDownBottom, 0xffffff, false);
	DrawBox(m_upDown2Left, m_upDown2Top, m_upDown2Right, m_upDown2Bottom, 0xffffff, false);
	DrawBox(m_upDown3Left, m_upDown3Top, m_upDown3Right, m_upDown3Bottom, 0xffffff, false);
	//どっすん範囲
	DrawBox(m_fallenRangeLeft, m_fallenRangeTop, m_fallenRangeRight, m_fallenRangeBottom, 0xffff00, false);
	//どっすん2範囲
	DrawBox(m_fallenRange2Left, m_fallenRange2Top, m_fallenRange2Right, m_fallenRange2Bottom, 0xffff00, false);
	//どっすん3範囲
	DrawBox(m_fallenRange3Left, m_fallenRange3Top, m_fallenRange3Right, m_fallenRange3Bottom, 0x00ff00, false);
	//どっすん4範囲
	DrawBox(m_fallenRange4Left, m_fallenRange4Top, m_fallenRange4Right, m_fallenRange4Bottom, 0x00ff00, false);
#endif
}
//樽の動き
void EnemyStage3::BarrelMove()
{

	int num = 3;
	for (int i = 0; i < num; i++)
	{
		if (i != 0)
		{
			m_barrelPos[1].x -= 8.0f;//GetRand(10);
			m_barrelPos[2].x -= 9.0f;//GetRand(10);
		}
		m_vec[i].y += 10.0f;//重力
		m_barrelPos[i].y += m_vec[i].y;//重力のベクトル用
	

		m_frameCountBarreImage[i]++;
		if (m_frameCountBarreImage[i] == 3)//３フレームに一回画像を変更
		{
			m_barreImagePosX[i] += 48;
			m_frameCountBarreImage[i] = 0;
		}
		if (m_barreImagePosX[i] >= 288)
		{
			m_barreImagePosX[i] = 0;
		}
	
		if (m_fall[i] == 5)//地面に当たったら
		{
			m_isCourse[i] = false;
			m_vec[i].y = 0.0f;//下に落ちないように
			m_barrelPos[i].y = m_getPos[i];//プレイヤーの位置座標
			if (i == 0)
			{
				m_barrelPos[i].x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
			}

		}
		if (m_fall[i] == 4)//地面に当たったら
		{
			m_isCourse[i] = true;
			m_vec[i].y = 0.0f;//下に落ちないように
			m_barrelPos[i].y = m_getPos[i];//プレイヤーの位置座標
			m_barrelPos[0].x += Enemy2::kBarrelSpeed * m_barrelSpeed;//左に移動
			m_barreImageDirection[i] = true;//画像の方向を変更
		}

		if (m_fall[i] == 3)//地面に当たったら
		{
			m_isCourse[i] = false;
			m_vec[i].y = 0.0f;//下に落ちないように
			m_barrelPos[i].y = m_getPos[i];//プレイヤーの位置座標
			m_barrelPos[0].x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
			m_barreImageDirection[i] = false;//画像の方向を変更
		}

		if (m_fall[i] == 2)//地面に当たったら
		{
			m_isCourse[i] = true;
			m_vec[i].y = 0.0f;//下に落ちないように
			m_barrelPos[i].y = m_getPos[i];//プレイヤーの位置座標
			m_barrelPos[0].x += Enemy2::kBarrelSpeed * m_barrelSpeed;//左に移動
			m_barreImageDirection[i] = true;//画像の方向を変更

		}

		if (m_fall[i] == 1)//地面に当たったら
		{
			m_isCourse[i] = false;
			m_vec[i].y = 0.0f;//下に落ちないように
			m_barrelPos[i].y = m_getPos[i];//プレイヤーの位置座標
			m_barrelPos[0].x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//とりあえず右に移動
			m_barreImageDirection[i] = false;//画像の方向を変更

		}

		if (m_barrelPos[i].x < 0|| m_barrelPos[i].x > Game::kScreenWidth + 100||
			m_barrelPos[i].y < 0|| m_barrelPos[i].y > Game::kScreenHeight)//樽が画面左に消えると最初の位置に戻っていく
		{
			m_barrelPos[i].x = Enemy2::kBossPosLeft + 50;
			m_barrelPos[i].y = Enemy2::kBossPosTop + 100;
		}

	}
}
//炎球の動き
void EnemyStage3::fireBallMove()
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
void EnemyStage3::falleMove()
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
		m_fallenPos.x = static_cast<float>(Stage2::kBox2Xt + GetRand(10));
		m_fallenPos.y = static_cast<float>(Stage2::kBoxBottom8Yf + GetRand(10));
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
		m_fallen2Pos.x = static_cast<float>(Stage2::kBox4Xt + GetRand(10));
		m_fallen2Pos.y = static_cast<float>(Stage2::kBoxBottom8Yf + GetRand(10));
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

	//三体目
	if (m_isCanFallen3)//初期の位置にいるかどうか
	{
		if (m_fallenRange == 3)//範囲内だったら
		{
			m_isFallenDrop3 = true;
			m_isCanFallen3 = false;
		}

	}

	if (m_isFallenDrop3)//落ちもの揺れる
	{
		m_fallenCount3++;//震える時間
		//揺れる

		m_fallen3Pos.x = static_cast<float>(Stage2::kBoxBottom5Xf + GetRand(10));
		m_fallen3Pos.y = static_cast<float>(Stage2::kBoxBottom8Yf - Stage2::kBoxHeight / 2 + GetRand(10));
	}

	if (m_fallenCount3 >= 45)//落ちるカウント
	{
		m_isFallenDrop3 = false;
		//落下開始
		m_fallenUpSpeed3 = 10.0f;//今だけ後で書き換える
		m_fallen3Pos.y += m_fallenUpSpeed3;//落下スピード

		if (m_fallen3Pos.y >= Stage2::kBox4Yt)//落ちる場所制限
		{
			m_isFallenUp3 = true;//上に戻す処理
		}
	}

	if (m_isFallenUp3)//天井
	{
		m_fallenUpSpeed3 = 15.0f;//今だけ後で書き換える
		m_fallen3Pos.y -= m_fallenUpSpeed3;

		if (m_fallen3Pos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount3 = 0;//カウントリセット
			m_isFallenUp3 = false;
			m_isCanFallen3 = true;//再度落ちるための処理

			m_fallen3Pos.x = Stage2::kBoxBottom5Xf;
			m_fallen3Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight / 2;
		}
	}

	//四体目
	if (m_isCanFallen4)//初期の位置にいるかどうか
	{
		if (m_fallenRange == 4)//範囲内だったら
		{
			m_isFallenDrop4 = true;
			m_isCanFallen4 = false;
		}

	}

	if (m_isFallenDrop4)//落ちもの揺れる
	{
		m_fallenCount4++;//震える時間
		//揺れる
		m_fallen4Pos.x = static_cast<float>(Stage2::kBoxBottom3Xf + GetRand(10));
		m_fallen4Pos.y = static_cast<float>(Stage2::kBoxBottom8Yf - Stage2::kBoxHeight + GetRand(10));
	}

	if (m_fallenCount4 >= 45)
	{
		m_isFallenDrop4 = false;
		//落下開始
		m_fallenUpSpeed4 = 10.0f;//今だけ後で書き換える
		m_fallen4Pos.y += m_fallenUpSpeed4;//落下スピード
		if (m_fallen4Pos.y >= Stage2::kBox4Yt)//落ちる場所制限
		{
			m_isFallenUp4 = true;//上に戻す処理
		}
	}

	if (m_isFallenUp4)//天井
	{
		m_fallenUpSpeed4 = 15.0f;//今だけ後で書き換える
		m_fallen4Pos.y -= m_fallenUpSpeed4;

		if (m_fallen4Pos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount4 = 0;//カウントリセット
			m_isFallenUp4 = false;
			m_isCanFallen4 = true;//再度落ちるための処理

			m_fallen4Pos.x = Stage2::kBoxBottom3Xf;
			m_fallen4Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight;
		}
	}

}
//敵に突進する
void EnemyStage3::ChargeMove()
{
	//プレイヤーに突進する
	Vec2 toPlayer{ 0.0f,0.0f };

	toPlayer.x = m_playerPos.x - m_chargePos.x;
	toPlayer.y = m_playerPos.y - m_chargePos.y;

	//m_length = toPlayer.length();//長さを取得

	toPlayer = toPlayer.normalize();//正規化
	

	m_chargePos += toPlayer * m_chargeSpeed;//プレイヤーの方向に直線で移動

}

void EnemyStage3::UpDownMove()
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

	if(m_upDownLeftImageX <= 400)m_upDownLeftImageX += 100;//Xが400になるまで繰り返す
	else{

		m_upDownLeftImageX = 0;//画像位置を右に戻す
		if (m_upDownLeftImageY <= 400)m_upDownLeftImageY += 100;//Yが400になるまで繰り返す
		else{
			if(m_upDownRad <= static_cast<int>(DX_PI + DX_PI))m_upDownRad++;
			else{
				m_upDownRad = static_cast<int>(DX_PI);
			}
			m_upDownLeftImageY = 0;//一番上に戻す
		}

	}

	if (!m_isUpDown2)//上にいる場合
	{
		m_upDown2Pos.y += 3;
		if (m_upDown2Pos.y == Stage2::kBox4Yt - 15)//下に到達した場合
		{
			m_isUpDown2 = true;
		}
	}
	else
	{
		m_upDown2Pos.y -= 3;
		if (m_upDown2Pos.y == Stage2::kBoxBottom4Yf + 15 - 15)//下に到達した場合
		{
			m_isUpDown2 = false;
		}

	}

	if (m_upDownLeft2ImageX <= 400)m_upDownLeft2ImageX += 100;//Xが400になるまで繰り返す
	else {

		m_upDownLeft2ImageX = 0;//画像位置を右に戻す
		if (m_upDownLeft2ImageY <= 400)m_upDownLeft2ImageY += 100;//Yが400になるまで繰り返す
		else {
			if (m_upDownRad <= static_cast<int>(DX_PI + DX_PI))m_upDownRad++;
			else {
				m_upDownRad = static_cast<int>(DX_PI);
			}
			m_upDownLeft2ImageY = 0;//一番上に戻す
		}

	}

	if (!m_isUpDown3)//上にいる場合
	{
		m_upDown3Pos.y += 3;
		if (m_upDown3Pos.y == Stage2::kBox4Yt - 15)//下に到達した場合
		{
			m_isUpDown3 = true;
		}
	}
	else
	{
		m_upDown3Pos.y -= 3;
		if (m_upDown3Pos.y == Stage2::kBoxBottom4Yf + 15 - 15 - 15)//下に到達した場合
		{
			m_isUpDown3 = false;
		}

	}

	if (m_upDownLeft3ImageX <= 400)m_upDownLeft3ImageX += 100;//Xが400になるまで繰り返す
	else {

		m_upDownLeft3ImageX = 0;//画像位置を右に戻す
		if (m_upDownLeft3ImageY <= 400)m_upDownLeft3ImageY += 100;//Yが400になるまで繰り返す
		else {
			if (m_upDownRad <= static_cast<int>(DX_PI + DX_PI))m_upDownRad++;
			else {
				m_upDownRad = static_cast<int>(DX_PI);
			}
			m_upDownLeft3ImageY = 0;//一番上に戻す
		}

	}

	//printfDx("%d\n", m_upDownRad);

}
//敵のキャラ座標取得
void EnemyStage3::npcPos()
{
	//enemyの座標
	m_posLeft = static_cast<int>(m_pos.x);
	m_posTop = static_cast<int>(m_pos.y);
	m_posRight = m_posLeft + 40;
	m_posBottom = m_posTop + 30;

	for (int i = 0; i < 3; i++)
	{
		if (m_isCourse[i])
		{
			m_barrelSizePulsX = 150;
		}
		else
		{
			m_barrelSizePulsX = 0;
		}
	}

	//樽
	for (int i = 0; i < 3; i++)
	{
		m_barrelLeft[i] = static_cast<int>(m_barrelPos[i].x);
		m_barrelTop[i] = static_cast<int>(m_barrelPos[i].y + 5.0f);
		m_barrelRight[i] = m_barrelLeft[i] + 50;
		m_barrelBottom[i] = m_barrelTop[i] + 40;
	}

	//ドッスン
	m_fallenLeft = static_cast<int>(m_fallenPos.x);
	m_fallenTop = static_cast<int>(m_fallenPos.y);
	m_fallenRight = m_fallenLeft + 150 - 10;
	m_fallenBottom = m_fallenTop + 10;
	//ドッスン反応判定
	m_fallenRangeLeft = 1110;
	m_fallenRangeTop = 550;
	m_fallenRangeRight = m_fallenRangeLeft + 250;
	m_fallenRangeBottom = m_fallenRangeTop + 120;
	//ドッスン2
	m_fallen2Left = static_cast<int>(m_fallen2Pos.x);
	m_fallen2Top = static_cast<int>(m_fallen2Pos.y);
	m_fallen2Right = m_fallen2Left + 150 - 10;
	m_fallen2Bottom = m_fallen2Top + 10;
	//ドッスン2反応判定
	m_fallenRange2Left = 1110 + 150 + 150;
	m_fallenRange2Top = 550;
	m_fallenRange2Right = m_fallenRange2Left + 250;
	m_fallenRange2Bottom = m_fallenRange2Top + 120;

	//ドッスン3
	m_fallen3Left = static_cast<int>(m_fallen3Pos.x);
	m_fallen3Top = static_cast<int>(m_fallen3Pos.y);
	m_fallen3Right = m_fallen3Left + 150 - 10;
	m_fallen3Bottom = m_fallen3Top + 10;
	//ドッスン3反応判定
	m_fallenRange3Left = 1110 - 150 - 150 - 10;
	m_fallenRange3Top = 550;
	m_fallenRange3Right = m_fallenRange3Left + 250;
	m_fallenRange3Bottom = m_fallenRange3Top + 120;

	//ドッスン4
	m_fallen4Left = static_cast<int>(m_fallen4Pos.x);
	m_fallen4Top = static_cast<int>(m_fallen4Pos.y);
	m_fallen4Right = m_fallen4Left + 150 - 10;
	m_fallen4Bottom = m_fallen4Top + 10;
	//ドッスン4反応判定
	m_fallenRange4Left = 1110 - 150 - 150 - 150 - 150 - 10;
	m_fallenRange4Top = 550;
	m_fallenRange4Right = m_fallenRange4Left + 250;
	m_fallenRange4Bottom = m_fallenRange4Top + 120;

	//チャージエネミー
	m_chargeLeft = static_cast<int>(m_chargePos.x);
	m_chargeTop = static_cast<int>(m_chargePos.y);
	m_chargeRight = m_chargeLeft + 30;
	m_chargeBottom = m_chargeTop + 30;
	//上下運動する罠
	m_upDownLeft = static_cast<int>(m_upDownPos.x);
	m_upDownTop = static_cast<int>(m_upDownPos.y);
	m_upDownRight = m_upDownLeft + 30;
	m_upDownBottom = m_upDownTop + 30;

	//上下運動する罠
	m_upDown2Left = static_cast<int>(m_upDown2Pos.x);
	m_upDown2Top = static_cast<int>(m_upDown2Pos.y);
	m_upDown2Right = m_upDown2Left + 30;
	m_upDown2Bottom = m_upDown2Top + 30;

	//上下運動する罠
	m_upDown3Left = static_cast<int>(m_upDown3Pos.x);
	m_upDown3Top = static_cast<int>(m_upDown3Pos.y);
	m_upDown3Right = m_upDown3Left + 30;
	m_upDown3Bottom = m_upDown3Top + 30;
}
