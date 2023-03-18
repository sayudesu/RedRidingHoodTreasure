#include "EnemyStage1.h"
#include "SceneMain2.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

EnemyStage1::EnemyStage1():
	m_hFireBall(-1),//�摜�n���h��
	m_hBarre(-1),
	m_hEnemyImage(-1),
	m_hNeedle(-1),//�n�ʗp
	m_hTiles(-1),//�摜�`�b�v
	m_hCave(-1),//���A�摜�p
	m_hSoundSnail(-1),//�J�^�c�����T�E���h
	m_hSoundBarre(-1),//�M�T�E���h
	m_posLeft(0),
	m_posTop(0),
	m_posRight(0),
	m_posBottom(0),
	m_barrelLeft(0),//�M�T�C�Y
	m_barrelTop(0),
	m_barrelRight(0),
	m_barrelBottom(0),
	m_barrelSizePulsX(0),//�M�T�C�Y�ύX.X
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
	m_fireBallImagePosX(0),//�t�@�C�A�{�[���摜�ʒu
	m_fireBallImagePosY(0),
	m_fireImageDirection(0),
	m_barreImagePosX(0),//�M�i�C�m�V�V�j�摜�ʒu
	m_barreImageDirection(false),//�M�i���̂����j�摜�̕���
	m_barrelSpeed(0),
	m_fall(0),
	m_fallFireBall(0),
	m_fallenRange(0),
	m_fallenRange2(0),
	m_fallenCount(0),
	m_fallenCount2(0),
	m_frameCountBarreImage(0),//�M�i���̂����j�̉摜�`��p�t���[���J�E���g
	m_frameCountFireImage(0),
	m_ladderNum(0),
	m_rushCount(0),
	m_fallenUpSpeed(0.0f),
	m_fallenUpSpeed2(0.0f),
	m_getPos(0.0f),
	m_fireRad(0),//�t�@�C�A�{�[���p�x
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
	m_barrelPos(0.0f,0.0f),//�M
	m_fallenPos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_fallen2Pos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_chargePos(0.0f, 0.0f),//�`���[�W����G
	m_vec(0.0f,0.0f),
	m_playerPos(0.0f, 0.0f),
	m_playerSavePos(0.0f, 0.0f)
{
	m_isFirstMove = true;//��������
	m_isCanFallen = true;
	m_isCanFallen2 = true;
	//�t�@�C�A�{�[�������ʒu
	m_pos.x = Game::kScreenWidth - 400;
	m_pos.y = Game::kScreenHeight - 150;
	//�M�����ʒu
	m_barrelPos.x = Enemy1::kBossPosLeft;
	m_barrelPos.y = Enemy1::kBossPosTop;

	m_chargeSpeed = 10.0f;

	m_hFireBall = LoadGraph(Image::kEnemySnail);//�J�^�c����
	m_hBarre = LoadGraph(Image::kEnemyBarre);//���̂���
	m_hTiles = LoadGraph(Image::kMapTiles2);//�摜�`�b�v�i���A�p�j

	m_hEnemyImage = LoadGraph(Image::kEnemyFallen);//�����Ă���㩂������Ă�摜

	m_hNeedle = DerivationGraph(0, 160, 32 + 16, 32, m_hEnemyImage);//�n�ʉ摜����ꕔ�𒊏o
	m_hCave = DerivationGraph(272, 208, 128,160, m_hTiles);//�n�ʉ摜����ꕔ�𒊏o

	//�T�E���h�ǂݍ���
	m_hSoundSnail = LoadSoundMem(Sound::kSnail);//�����ނ�T�E���h
	m_hSoundBarre = LoadSoundMem(Sound::kBarreRun);//�M�i���̂����j
}

EnemyStage1::~EnemyStage1()
{
	DeleteGraph(m_hFireBall);//�����ނ�
	DeleteGraph(m_hBarre);//�C�m�V�V
	DeleteGraph(m_hEnemyImage);//�摜
	DeleteGraph(m_hNeedle);//�����Ă���G
	//�T�E���h���������
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
	BarrelMove();//�M�̓���
	fireBallMove();//�t�@�C�A�{�[���̓���
	EnemySoud();//�T�E���h
	npcPos();//�G�̃T�C�Y�擾
}
//�`��
void EnemyStage1::Draw()
{
	//�{�X(���A�ɕύX�G�̃X�|�[���ʒu)
	DrawExtendGraph(Enemy1::kBossPosLeft, Enemy1::kBossPosTop, Enemy1::kBossPosRight, Enemy1::kBossPosBottom,
		m_hCave, true);
	/*DrawBox(Enemy1::kBossPosLeft, Enemy1::kBossPosTop,
		Enemy1::kBossPosRight, Enemy1::kBossPosBottom, 0xffff00, false);*/

	//�G�l�~�[���̋�
	DrawRectRotaGraph(m_posLeft + 20 , m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//�摜��`��
	//DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//����m�F

	//�M
	DrawRectRotaGraph(m_barrelLeft + 20, m_barrelTop + 15 - 5,
		m_barreImagePosX, 0, 48, 32, 2, 0, m_hBarre, true, m_barreImageDirection);//�摜��`��
	//DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, false);//����m�F
	//��288
	//�c32
}
//�M�̓���
void EnemyStage1::BarrelMove()
{
	m_barrelPos.y += m_vec.y;//�d�͂̃x�N�g���p

	m_vec.y += 3.0f;//�d��

	m_frameCountBarreImage++;
	if (m_frameCountBarreImage == 3)//�R�t���[���Ɉ��摜��ύX
	{
		m_barreImagePosX += 48;
		m_frameCountBarreImage = 0;
}
	if (m_barreImagePosX >= 288)
	{
		m_barreImagePosX = 0;
	}

	if (m_fall == 3)//�n�ʂɓ���������
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x -= Enemy1::kBarrelSpeed;// * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
		m_barreImageDirection = false;//�摜�̕�����ύX
	}

	if (m_fall == 2)//�n�ʂɓ���������
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x += Enemy1::kBarrelSpeed;// * m_barrelSpeed;//���Ɉړ�
		m_barreImageDirection = true;//�摜�̕�����ύX

	}

	if (m_fall == 1)//�n�ʂɓ���������
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x -= Enemy1::kBarrelSpeed;// * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
		m_barreImageDirection = false;//�摜�̕�����ύX

	}

	if (m_barrelRight < 0)//�M����ʍ��ɏ�����ƍŏ��̈ʒu�ɖ߂��Ă���
	{
		m_barrelPos.x = Enemy1::kBossPosLeft + 50;
		m_barrelPos.y = Enemy1::kBossPosTop + 100;
	}
	else if (m_barrelRight > Game::kScreenWidth + 100)//�M����ʉE�ɏ�����ƍŏ��̈ʒu�ɖ߂��Ă���
	{
		m_barrelPos.x = Enemy1::kBossPosLeft + 50;
		m_barrelPos.y = Enemy1::kBossPosTop + 100;
	}

	if (m_fall == 0 && !m_isCourse)//�M���E�Ɉړ�����ꍇ
	{
		m_barrelPos.x -= Enemy1::kBarrelSpeed;
	}

	if (m_fall == 0 && m_isCourse)//�M�����Ɉړ�����ꍇ
	{
		m_barrelPos.x += Enemy1::kBarrelSpeed;
	}


}
//�����̓���
void EnemyStage1::fireBallMove()
{
	m_pos.y += 3.0f;//�d��

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

	if (!m_isFireBallCourse)//�E����
	{
		m_pos.x -= 5.0f;
		if (m_pos.x < 0)//������ύX����
		{
			//������ύX
			m_isFireBallCourse = true;//�ړ�������ύX
			m_fireImageDirection = true;//�摜�̕�����ύX
		}
	}
	else//������
	{
		m_pos.x += 5.0f;
		if (m_pos.x > Game::kScreenWidth)//������ύX����
		{
			//������ύX
			m_isFireBallCourse = false;//�ړ�������ύX
			m_fireImageDirection = false;//�摜�̕�����ύX
		}
	}

	if (m_fallFireBall == 2)//�n�ʂɓ���������
	{
		//m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_pos.y = static_cast<float>(m_getFireBallPos) + 10;//�v���C���[�̈ʒu���W
	}
}

//�G�̉�
void EnemyStage1::EnemySoud()
{
	//�T�E���h
	if (CheckSoundMem(m_hSoundSnail) == 0)//���Ă��Ȃ�������
	{
		PlaySoundMem(m_hSoundSnail, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(100, m_hSoundSnail);//���ʒ���
	}
	if (m_vec.y <= 3.0f)
	{
		if (CheckSoundMem(m_hSoundBarre) == 0)//���Ă��Ȃ�������
		{
			PlaySoundMem(m_hSoundBarre, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
			ChangeVolumeSoundMem(200, m_hSoundBarre);//���ʒ���
		}
	}
	///////////////////////////////////////////////////
	ChangeVolumeSoundMem(10, m_hSoundSnail);//���ʒ���
	ChangeVolumeSoundMem(10, m_hSoundBarre);//���ʒ���
}

//�G�̃L�������W�擾
void EnemyStage1::npcPos()
{
	//enemy�̍��W
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
	//�M
	m_barrelLeft = static_cast<int>(m_barrelPos.x);
	m_barrelTop = static_cast<int>(m_barrelPos.y + 5.0f);
	m_barrelRight = m_barrelLeft + 50;
	m_barrelBottom = m_barrelTop + 40;

}
