#include "EnemyStage1.h"
#include "SceneMain2.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

EnemyStage1::EnemyStage1():
	m_hFireBall(-1),//画像ハンドル
	m_hBarre(-1),
	m_hEnemyImage(-1),
	m_hNeedle(-1),//地面用
	m_hTiles(-1),//画像チップ
	m_hCave(-1),//洞窟画像用
	m_hSoundSnail(-1),//カタツムリサウンド
	m_hSoundBarre(-1),//樽サウンド
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
	m_barrelPos.x = Enemy1::kBossPosLeft;
	m_barrelPos.y = Enemy1::kBossPosTop;

	m_chargeSpeed = 10.0f;

	m_hFireBall = LoadGraph(Image::kEnemySnail);//カタツムリ
	m_hBarre = LoadGraph(Image::kEnemyBarre);//いのしし
	m_hTiles = LoadGraph(Image::kMapTiles2);//画像チップ（洞窟用）

	m_hEnemyImage = LoadGraph(Image::kEnemyFallen);//落ちてくる罠が入ってる画像

	m_hNeedle = DerivationGraph(0, 160, 32 + 16, 32, m_hEnemyImage);//地面画像から一部を抽出
	m_hCave = DerivationGraph(272, 208, 128,160, m_hTiles);//地面画像から一部を抽出

	//サウンド読み込み
	m_hSoundSnail = LoadSoundMem(Sound::kSnail);//かたつむりサウンド
	m_hSoundBarre = LoadSoundMem(Sound::kBarreRun);//樽（いのしし）
}

EnemyStage1::~EnemyStage1()
{
	DeleteGraph(m_hFireBall);//かたつむり
	DeleteGraph(m_hBarre);//イノシシ
	DeleteGraph(m_hEnemyImage);//画像
	DeleteGraph(m_hNeedle);//落ちてくる敵
	//サウンドメモリ解放
	DeleteSoundMem(m_hSoundSnail);
	DeleteSoundMem(m_hSoundBarre);
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
	EnemySoud();//サウンド
	npcPos();//敵のサイズ取得
}
//描画
void EnemyStage1::Draw()
{
	//ボス(洞窟に変更敵のスポーン位置)
	DrawExtendGraph(Enemy1::kBossPosLeft, Enemy1::kBossPosTop, Enemy1::kBossPosRight, Enemy1::kBossPosBottom,
		m_hCave, true);
	/*DrawBox(Enemy1::kBossPosLeft, Enemy1::kBossPosTop,
		Enemy1::kBossPosRight, Enemy1::kBossPosBottom, 0xffff00, false);*/

	//エネミー炎の玉
	DrawRectRotaGraph(m_posLeft + 20 , m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//画像を描画
	//DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//判定確認

	//樽
	DrawRectRotaGraph(m_barrelLeft + 20, m_barrelTop + 15 - 5,
		m_barreImagePosX, 0, 48, 32, 2, 0, m_hBarre, true, m_barreImageDirection);//画像を描画
	//DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, false);//判定確認
	//横288
	//縦32
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

	if (m_fall == 3)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy1::kBarrelSpeed;// * m_barrelSpeed;//とりあえず右に移動
		m_barreImageDirection = false;//画像の方向を変更
	}

	if (m_fall == 2)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += Enemy1::kBarrelSpeed;// * m_barrelSpeed;//左に移動
		m_barreImageDirection = true;//画像の方向を変更

	}

	if (m_fall == 1)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy1::kBarrelSpeed;// * m_barrelSpeed;//とりあえず右に移動
		m_barreImageDirection = false;//画像の方向を変更

	}

	if (m_barrelRight < 0)//樽が画面左に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy1::kBossPosLeft + 50;
		m_barrelPos.y = Enemy1::kBossPosTop + 100;
	}
	else if (m_barrelRight > Game::kScreenWidth + 100)//樽が画面右に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy1::kBossPosLeft + 50;
		m_barrelPos.y = Enemy1::kBossPosTop + 100;
	}

	if (m_fall == 0 && !m_isCourse)//樽が右に移動する場合
	{
		m_barrelPos.x -= Enemy1::kBarrelSpeed;
	}

	if (m_fall == 0 && m_isCourse)//樽が左に移動する場合
	{
		m_barrelPos.x += Enemy1::kBarrelSpeed;
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

	if (!m_isFireBallCourse)//右動き
	{
		m_pos.x -= 5.0f;
		if (m_pos.x < 0)//向きを変更する
		{
			//方向を変更
			m_isFireBallCourse = true;//移動方向を変更
			m_fireImageDirection = true;//画像の方向を変更
		}
	}
	else//左動き
	{
		m_pos.x += 5.0f;
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

//敵の音
void EnemyStage1::EnemySoud()
{
	//サウンド
	if (CheckSoundMem(m_hSoundSnail) == 0)//鳴っていなかったら
	{
		PlaySoundMem(m_hSoundSnail, DX_PLAYTYPE_BACK);//サウンドを再生
		ChangeVolumeSoundMem(100, m_hSoundSnail);//音量調整
	}
	if (m_vec.y <= 3.0f)
	{
		if (CheckSoundMem(m_hSoundBarre) == 0)//鳴っていなかったら
		{
			PlaySoundMem(m_hSoundBarre, DX_PLAYTYPE_BACK);//サウンドを再生
			ChangeVolumeSoundMem(200, m_hSoundBarre);//音量調整
		}
	}
	///////////////////////////////////////////////////
	ChangeVolumeSoundMem(10, m_hSoundSnail);//音量調整
	ChangeVolumeSoundMem(10, m_hSoundBarre);//音量調整
}

//敵のキャラ座標取得
void EnemyStage1::npcPos()
{
	//enemyの座標
	m_posLeft = static_cast<int>(m_pos.x);
	m_posTop = static_cast<int>(m_pos.y);
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
	m_barrelLeft = static_cast<int>(m_barrelPos.x);
	m_barrelTop = static_cast<int>(m_barrelPos.y + 5.0f);
	m_barrelRight = m_barrelLeft + 50;
	m_barrelBottom = m_barrelTop + 40;

}
