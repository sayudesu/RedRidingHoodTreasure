#include "Collision.h"
#include "PlayerNew.h"
#include "DrawMapStage2.h"
#include "EnemyStage1.h"
#include "game.h"
#include <Dxlib.h>

//���O���
namespace
{
	constexpr float kGravity = 1.0f;
	constexpr float kGravityZero = 0.0f;
	constexpr float kPlayerPosY = 50.0f;
	constexpr float kPlayerPosPulsY = 1.0f;

	constexpr float kEnemyPosY = 40.0f;
}
//�R���X�g���N�^
Collision::Collision():
	m_posY(0.0f),
	m_enemyPosY(0),
	m_landingPos(0.0f),
	m_enemyFireBallPosY(0),
	m_isPlayerPos(false),
	m_pPlayer(nullptr),
	m_pMap(nullptr),
	m_pEnemy(nullptr)
{
	m_pPlayer = new PlayerNew;
	m_pMap = new DrawMapStage2;
	m_pEnemy = new EnemyStage1;
	m_landingPos = 70.0f;
}
//�f�X�g���N�^
Collision::~Collision()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pEnemy;
}
//������
void Collision::Init()
{
	//m_pPlayer->Init();
}
//�X�V
void Collision::Update()
{
	m_pPlayer->Update();

	m_pEnemy->Update();

	m_pPlayer->GetScaffold(HitObject()); //�d��.y
	m_pPlayer->GetLadder(HItLadder());   //�ʒu.y.z
	m_pPlayer->GetPos(m_posY);           //�ʒu.y
	m_pPlayer->GetGoal(HitGoal());       //�S�[���������ǂ���
	m_pPlayer->GetEnemyHit(HitEnemy());  //�G�l�~�[���v���C���[���U������
	m_pPlayer->GetEnemyFallenHit(HitFallen());  //�G�l�~�[���v���C���[���U������
	m_pPlayer->GetPlayerHit(HitPlayer());//�v���C���[���G�l�~�[���U���������ǂ���


	m_pEnemy->GetHitFall(HitEnemyObject()); //�d��.y
	m_pEnemy->GetEnemyLadder(HItEnemyLadder());   //�ʒu.y
	m_pEnemy->GetPos(m_enemyPosY);           //�ʒu.y
	//���ʃG�l�~�[����
	m_pEnemy->GetHitFireBallFall(HitEnemyFireBall()); //�d��.y
	m_pEnemy->GetFireBallPos(m_enemyFireBallPosY); //�ʒu.y
	//������G�l�~�[����
	m_pEnemy->GetFallenRange(HitFallenRange());//�͈͂ɓ����Ă��邩�ǂ���
	m_pEnemy->GetFallenRange2(HitFallenRange());//�͈͂ɓ����Ă��邩�ǂ���
	//�v���C���[��x.y���W
	m_pEnemy->GetPlayerPos(m_pPlayer->GetkPlayerPos());
	m_pEnemy->GetRush(m_isPlayerPos);
	m_pPlayer->GetEnemyChageHit(HitCharge());//�v���C���[�ƃ`���[�W�G�l�~�[�̓����蔻��
	
}
//�`��
void Collision::Draw()
{
	m_pEnemy->Draw();
}
//�n�ʂ̔���
bool Collision::HitObject()
{
	//1�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Y - kPlayerPosY + kPlayerPosPulsY;

			return true;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Y - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Y - kPlayerPosY + kPlayerPosPulsY;
				- Stage2::kBoxStep;
			return true;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Y - kPlayerPosY + kPlayerPosPulsY;
				- Stage2::kBoxStep - Stage2::kBoxStep;
			return true;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Y - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Y - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Y - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Y - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//2�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::koxBottom1Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//4�i��
	if ((Stage2::kBoxBottom5Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//3�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Yt - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Yt - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Yt - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Yt - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Yt - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//4�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Yf - kPlayerPosY + kPlayerPosPulsY;
			m_isPlayerPos = true;//�ːi��L���ɂ���
			return true;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Yf - kPlayerPosY + kPlayerPosPulsY;
			m_isPlayerPos = true;//�ːi��L���ɂ���
			return true;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Yf - kPlayerPosY + kPlayerPosPulsY;
			m_isPlayerPos = true;//�ːi��L���ɂ���
			return true;
		}
	}

	//5�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1YFi - kPlayerPosY + kPlayerPosPulsY;
			m_isPlayerPos = false;//�ːi�𖳌��ɂ���
			return true;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	
	DrawBox(static_cast<int>(m_pPlayer->GetPlayerLeft()), static_cast<int>(m_pPlayer->GetPlayerTop()),
		static_cast<int>(m_pPlayer->GetPlayerRight()), static_cast<int>(m_pPlayer->GetPlayerBottom()), 0x00ff00, true);
	return false;
}

//��q�̔���
bool Collision::HItLadder()
{
	//��K�̔���
	if ((Stage2::kLadderBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder1Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	//��K�̔���
	if ((Stage2::kLadderBottom2X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder2X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom2Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder2Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	//�O�K�̔���
	if ((Stage2::kLadderBottom3X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder3X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom3Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder3Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	//�O�K�̔���
	if ((Stage2::kLadderBottom4X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder4X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom4Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder4Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	return false;
}

//�G����q�ɓ������Ă��邩�ǂ���
int Collision::HItEnemyLadder()
{
	//�O�K�̔���
	if ((Stage2::kLadderBottom3X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kLadder3X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kLadderBottom3Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kLadder3Y < m_pEnemy->GetBarrelBottom()))
		{
			return 4;
		}
	}

	return 0;
}

//���ƒn�ʂ̓����蔻��
int Collision::HitEnemyFireBall()
{
	//2�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox1Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::koxBottom1Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox1Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox1Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox2Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom2Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox2Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox2Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox3Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom3Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox3Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox3Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox4Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom4Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox4Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox4Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox5Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom5Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox5Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox5Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox6Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom6Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox6Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox6Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox7Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom7Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox7Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox7Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8Xs > m_pEnemy->GetLeft()) &&
		(Stage2::kBox8Xs < m_pEnemy->GetRight()))
	{
		if ((Stage2::kBoxBottom8Ys > m_pEnemy->GetTop()) &&
			(Stage2::kBox8Ys < m_pEnemy->GetBottom()))
		{
			m_enemyFireBallPosY = Stage2::kBox8Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}

	return 0;
}

//�S�[������
bool Collision::HitGoal()
{
	if ((Stage2::kGoalBottomX > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kGoalX < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kGoalBottomY > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kGoalY < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}
	return false;
}

//�v���C���[�ƃG�l�~�[�̓����蔻��::�G�l�~�[���v���C���[���U��
bool Collision::HitEnemy()
{
	//���̒e
	if ((m_pEnemy->GetRight() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetLeft() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetBottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetTop() < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}
	//�M
	if ((m_pEnemy->GetBarrelRight() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetBarrelLeft() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetBarrelBottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetBarrelTop() < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}
	return false;
}

//�v���C���[�ƃG�l�~�[�̓����蔻��::�v���C���[���G�l�~�[���U��
bool Collision::HitPlayer()
{
	if ((m_pEnemy->GetRight() > m_pPlayer->GetAttackPlayerLeft()) &&
		(m_pEnemy->GetLeft() < m_pPlayer->GetAttackPlayerRight()))
	{
		if ((m_pEnemy->GetBottom() > m_pPlayer->GeAttacktPlayerTop()) &&
			(m_pEnemy->GetTop() < m_pPlayer->GetAttackPlayerBottom()))
		{
			return true;
		}
	}

	return false;

}

//�n�ʂ̔���
int Collision::HitEnemyObject()
{
	//1�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox1X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom1Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox1Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox1Y - kEnemyPosY + kPlayerPosPulsY;

			return 1;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox2X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom2Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox2Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox2Y - kEnemyPosY + kPlayerPosPulsY;
			return 1;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox3X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom3Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox3Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3Y - kEnemyPosY + kPlayerPosPulsY;
			-Stage2::kBoxStep;
			return 1;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox4X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom4Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox4Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox4Y - kEnemyPosY + kPlayerPosPulsY;
			-Stage2::kBoxStep - Stage2::kBoxStep;
			return 1;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox5X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom5Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox5Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox5Y - kEnemyPosY + kPlayerPosPulsY;
			return 1;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox6X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom6Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox6Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox6Y - kEnemyPosY + kPlayerPosPulsY;
			return 1;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox7X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom7Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox7Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox7Y - kEnemyPosY + kPlayerPosPulsY;
			return 1;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8X > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox8X < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom8Y > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox8Y < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox8Y - kEnemyPosY + kPlayerPosPulsY;
			return 1;
		}
	}

	//2�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox1Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::koxBottom1Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox1Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox1Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox2Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom2Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox2Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox2Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox3Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom3Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox3Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox4Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom4Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox4Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox4Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox5Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom5Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox5Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox5Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox6Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom6Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox6Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox6Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox7Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom7Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox7Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox7Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8Xs > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox8Xs < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom8Ys > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox8Ys < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox8Ys - kEnemyPosY + kPlayerPosPulsY;
			return 2;
		}
	}

	//3�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox1Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom1Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox1Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox1Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox2Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom2Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox2Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox2Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox3Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom3Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox3Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox4Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom4Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox4Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox4Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox5Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom5Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox5Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox5Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox6Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom6Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox6Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox6Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox7Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom7Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox7Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox7Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8Xt > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox8Xt < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom8Yt > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox8Yt < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox8Yt - kEnemyPosY + kPlayerPosPulsY;
			return 3;
		}
	}

	//4�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox1Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom1Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox1Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox1Yf - kEnemyPosY + kPlayerPosPulsY;	
			return 4;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox2Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom2Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox2Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox2Yf - kEnemyPosY + kPlayerPosPulsY;	
			return 4;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox3Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom3Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox3Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3Yf - kEnemyPosY + kPlayerPosPulsY;	
			return 4;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox4Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom4Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox4Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox4Yf - kEnemyPosY + kPlayerPosPulsY;
			return 4;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox5Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom5Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox5Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox5Yf - kEnemyPosY + kPlayerPosPulsY;
			return 4;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox6Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom6Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox6Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox6Yf - kEnemyPosY + kPlayerPosPulsY;
			return 4;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox7Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom7Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox7Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox7Yf - kEnemyPosY + kPlayerPosPulsY;
			return 4;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8Xf > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox8Xf < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom8Yf > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox8Yf < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox8Yf - kEnemyPosY + kPlayerPosPulsY;
			return 4;
		}
	}

	//5�K�̔���///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox1XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom1YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox1YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox1YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//1�i��
	if ((Stage2::kBoxBottom2XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox2XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom2YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox2YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox2YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//2�i��
	if ((Stage2::kBoxBottom3XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox3XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom3YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox3YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//3�i��
	if ((Stage2::kBoxBottom4XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox4XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom4YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox4YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox4YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//4�i��
	if ((Stage2::kBoxBottom5XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox5XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom5YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox5YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox5YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//5�i��
	if ((Stage2::kBoxBottom6XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox6XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom6YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox6YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox6YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//6�i��
	if ((Stage2::kBoxBottom7XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox7XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom7YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox7YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox7YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}
	//7�i��
	if ((Stage2::kBoxBottom8XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox8XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom8YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox8YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox8YFi - kEnemyPosY + kPlayerPosPulsY;
			return 5;
		}
	}

	return 0;
}

//������G�͈̔�
int Collision::HitFallenRange()
{
	if ((m_pEnemy->GetFallenRangeRight() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetFallenRangeLeft() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetFallenRangeBottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetFallenRangeTop() < m_pPlayer->GetPlayerBottom()))
		{
			return 1;
		}
	}

	if ((m_pEnemy->GetFallenRange2Right() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetFallenRange2Left() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetFallenRange2Bottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetFallenRange2Top() < m_pPlayer->GetPlayerBottom()))
		{
			return 2;
		}
	}

	return 0;
}

//�������ƃv���C���[�̔���
bool Collision::HitFallen()
{

	if ((m_pEnemy->GetFallenRight() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetFallenLeft() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetFallenBottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetFallenTop() < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	if ((m_pEnemy->GetFallen2Right() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetFallen2Left() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetFallen2Bottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetFallen2Top() < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	return false;
}

//�������ƃv���C���[�̔���
bool Collision::HitCharge()
{
	if ((m_pEnemy->GetChargeRight() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetChargeLeft() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetChargeBottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetChargeTop() < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	return false;
}