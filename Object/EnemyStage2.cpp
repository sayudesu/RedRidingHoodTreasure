#include "EnemyStage2.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

EnemyStage2::EnemyStage2() :
	m_hFireBall(-1),//�摜�n���h��
	m_hBarre(-1),
	m_hEnemyImage(-1),
	m_hNeedle(-1),//�n�ʗp
	m_hTiles(-1),//�摜�`�b�v
	m_hCave(-1),//���A�摜�p
	m_hUpDown(-1),//�㉺�^����㩉摜
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
	m_upDownLeft(0),//�㉺�^�������
	m_upDownTop(0),
	m_upDownRight(0),
	m_upDownBottom(0),
	m_fireBallImagePosX(0),//�t�@�C�A�{�[���摜�ʒu
	m_fireBallImagePosY(0),
	m_upDownLeftImageX(0),//㩂̉摜�ʒu
	m_upDownLeftImageY(0),
	m_upDownRad(0),//㩊p�x
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
	m_isUpDown(false),//�㉺�ǂ���ɂ��邩
	m_isRush(false),
	m_isRushBlink(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(0.0f, 0.0f),//�M
	m_fallenPos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_fallen2Pos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_chargePos(0.0f, 0.0f),//�`���[�W����G
	m_upDownPos(0.0f, 0.0f),//�㉺�^�������
	m_vec(0.0f, 0.0f),
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
	m_barrelPos.x = Enemy2::kBossPosLeft;
	m_barrelPos.y = Enemy2::kBossPosTop;
	//�ǂ�����
	m_fallenPos.x = Stage2::kBox2Xt;
	m_fallenPos.y = Stage2::kBoxBottom8Yf;
	//�ǂ�����2
	m_fallen2Pos.x = Stage2::kBox4Xt;
	m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//�`���[�W����G
	m_chargePos.x = Stage2::kBox1Xf;
	m_chargePos.y = Stage2::kBox1Yf - 50;

	m_chargeSpeed = 10.0f;


	m_upDownPos.x = 1000.0f;
	m_upDownPos.y = Stage2::kBoxBottom4Yf + 15;

	m_hFireBall = LoadGraph(Image::kEnemySnail);//�J�^�c����
	m_hBarre = LoadGraph(Image::kEnemyBarre);//���̂���
	m_hTiles = LoadGraph(Image::kMapTiles2);//�摜�`�b�v�i���A�p�j
	m_hUpDown = LoadGraph(Image::kEnemyFireBall);//�

	m_hEnemyImage = LoadGraph(Image::kEnemyFallen);//�����Ă���㩂������Ă�摜

	m_hNeedle = DerivationGraph(0, 160, 32 + 16, 32, m_hEnemyImage);//�n�ʉ摜����ꕔ�𒊏o
	m_hCave = DerivationGraph(272, 208, 128, 160, m_hTiles);//�n�ʉ摜����ꕔ�𒊏o
}

EnemyStage2::~EnemyStage2()
{
	DeleteGraph(m_hFireBall);//�����ނ�
	DeleteGraph(m_hBarre);//�C�m�V�V
	DeleteGraph(m_hEnemyImage);//�摜
	DeleteGraph(m_hNeedle);//�����Ă���G
}

void EnemyStage2::Init()
{
}

void EnemyStage2::End()
{
}

void EnemyStage2::Update()
{
	BarrelMove();//�M�̓���
	fireBallMove();//�t�@�C�A�{�[���̓���
	falleMove();//�h�b�X������
	ChargeMove();//�`���[�W�G�l�~�[�̓���
	UpDownMove();//�㉺�^�������
	npcPos();//�G�̃T�C�Y�擾
}
//�`��
void EnemyStage2::Draw()
{
	//�{�X(���A�ɕύX�G�̃X�|�[���ʒu)
	DrawExtendGraph(Enemy2::kBossPosLeft, Enemy2::kBossPosTop, Enemy2::kBossPosRight, Enemy2::kBossPosBottom,
		m_hCave, true);


	//�G�l�~�[���̋�
	DrawRectRotaGraph(m_posLeft + 20, m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//�摜��`��

	//�M
	DrawRectRotaGraph(m_barrelLeft + 20, m_barrelTop + 15 - 5,
		m_barreImagePosX, 0, 48, 32, 2, 0, m_hBarre, true, m_barreImageDirection);//�摜��`��
	//��288
	//�c32


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

	//�`���[�W�G�l�~�[
	if (!m_isRushBlink)//�~�܂��Ă�Ԃ͌����Ȃ�
	{
		//DrawBox(m_chargeLeft, m_chargeTop, m_chargeRight, m_chargeBottom, 0xffff00, false);
	}

	//�
	//�㉺�^�������
	DrawRectRotaGraph(
		m_upDownLeft + 14, m_upDownTop + 15,
		m_upDownLeftImageX, m_upDownLeftImageY, 100, 100,
		1, m_upDownRad,
		m_hUpDown, true, false);

#if false	
	DrawBox(Enemy2::kBossPosLeft, Enemy2::kBossPosTop,
		Enemy2::kBossPosRight, Enemy2::kBossPosBottom, 0xffff00, false);
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//����m�F
	DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, false);//����m�F
	//�ǂ�����
	DrawBox(m_fallenLeft, m_fallenTop, m_fallenRight, m_fallenBottom, 0xffff00, false);
	//�ǂ�����2
	DrawBox(m_fallen2Left, m_fallen2Top, m_fallen2Right, m_fallen2Bottom, 0xffff00, false);
	//�ǂ�����͈�
	DrawBox(m_fallenRangeLeft, m_fallenRangeTop, m_fallenRangeRight, m_fallenRangeBottom, 0xffff00, false);
	//�ǂ�����2�͈�
	DrawBox(m_fallenRange2Left, m_fallenRange2Top, m_fallenRange2Right, m_fallenRange2Bottom, 0xffff00, false);
	DrawBox(m_upDownLeft, m_upDownTop, m_upDownRight, m_upDownBottom, 0xffffff, false);
#endif
}
//�M�̓���
void EnemyStage2::BarrelMove()
{
	m_barrelPos.y += m_vec.y;//�d�͂̃x�N�g���p

	m_vec.y += 5.0f;//�d��

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

	if (m_fall == 5)//�n�ʂɓ���������
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
	}
	else if (m_fall == 4)//�n�ʂɓ���������
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x += Enemy2::kBarrelSpeed * m_barrelSpeed;//���Ɉړ�
		m_barreImageDirection = true;//�摜�̕�����ύX
	}

	if (m_fall == 3)//�n�ʂɓ���������
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
		m_barreImageDirection = false;//�摜�̕�����ύX
	}

	if (m_fall == 2)//�n�ʂɓ���������
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x += Enemy2::kBarrelSpeed * m_barrelSpeed;//���Ɉړ�
		m_barreImageDirection = true;//�摜�̕�����ύX

	}

	if (m_fall == 1)//�n�ʂɓ���������
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//���ɗ����Ȃ��悤��
		m_barrelPos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_barrelPos.x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
		m_barreImageDirection = false;//�摜�̕�����ύX

	}

	if (m_barrelRight < 0)//�M����ʍ��ɏ�����ƍŏ��̈ʒu�ɖ߂��Ă���
	{
		m_barrelPos.x = Enemy2::kBossPosLeft + 50;
		m_barrelPos.y = Enemy2::kBossPosTop + 100;
	}
	else if (m_barrelRight > Game::kScreenWidth + 100)//�M����ʉE�ɏ�����ƍŏ��̈ʒu�ɖ߂��Ă���
	{
		m_barrelPos.x = Enemy2::kBossPosLeft + 50;
		m_barrelPos.y = Enemy2::kBossPosTop + 100;
	}

	if (m_fall == 0 && !m_isCourse)//�M���E�Ɉړ�����ꍇ
	{
		m_barrelPos.x -= Enemy2::kBarrelSpeed;
	}

	if (m_fall == 0 && m_isCourse)//�M�����Ɉړ�����ꍇ
	{
		m_barrelPos.x += Enemy2::kBarrelSpeed;
	}


}
//�����̓���
void EnemyStage2::fireBallMove()
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
		m_pos.x -= 8.0f;
		if (m_pos.x < 0)//������ύX����
		{
			//������ύX
			m_isFireBallCourse = true;//�ړ�������ύX
			m_fireImageDirection = true;//�摜�̕�����ύX
		}
	}
	else//������
	{
		m_pos.x += 8.0f;
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
//�ǂ����񓮂�
void EnemyStage2::falleMove()
{
	//��̖�
	if (m_isCanFallen)//�����̈ʒu�ɂ��邩�ǂ���
	{
		if (m_fallenRange == 1)//�͈͓���������
		{
			m_isFallenDrop = true;
			m_isCanFallen = false;
		}

	}

	if (m_isFallenDrop)//�������̗h���
	{
		m_fallenCount++;//�k���鎞��
		//�h���
		m_fallenPos.x = Stage2::kBox2Xt + GetRand(10);
		m_fallenPos.y = Stage2::kBoxBottom8Yf + GetRand(10);
	}

	if (m_fallenCount >= 45)
	{
		m_isFallenDrop = false;
		//�����J�n
		m_fallenUpSpeed = 10.0f;//��������ŏ���������
		m_fallenPos.y += m_fallenUpSpeed;//�����X�s�[�h
		if (m_fallenPos.y >= Stage2::kBox2Yt)//������ꏊ����
		{
			m_isFallenUp = true;//��ɖ߂�����
		}
	}

	if (m_isFallenUp)//�V��
	{
		m_fallenUpSpeed = 15.0f;//��������ŏ���������
		m_fallenPos.y -= m_fallenUpSpeed;

		if (m_fallenPos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount = 0;//�J�E���g���Z�b�g
			m_isFallenUp = false;
			m_isCanFallen = true;//�ēx�����邽�߂̏���

			m_fallenPos.x = Stage2::kBox2Xt;
			m_fallenPos.y = Stage2::kBoxBottom8Yf;
		}
	}

	//��̖�
	if (m_isCanFallen2)//�����̈ʒu�ɂ��邩�ǂ���
	{
		if (m_fallenRange == 2)//�͈͓���������
		{
			m_isFallenDrop2 = true;
			m_isCanFallen2 = false;
		}

	}

	if (m_isFallenDrop2)//�������̗h���
	{
		m_fallenCount2++;//�k���鎞��
		//�h���
		m_fallen2Pos.x = Stage2::kBox4Xt + GetRand(10);
		m_fallen2Pos.y = Stage2::kBoxBottom8Yf + GetRand(10);
	}

	if (m_fallenCount2 >= 45)
	{
		m_isFallenDrop2 = false;
		//�����J�n
		m_fallenUpSpeed2 = 10.0f;//��������ŏ���������
		m_fallen2Pos.y += m_fallenUpSpeed2;//�����X�s�[�h
		if (m_fallen2Pos.y >= Stage2::kBox4Yt)//������ꏊ����
		{
			m_isFallenUp2 = true;//��ɖ߂�����
		}
	}

	if (m_isFallenUp2)//�V��
	{
		m_fallenUpSpeed2 = 15.0f;//��������ŏ���������
		m_fallen2Pos.y -= m_fallenUpSpeed2;

		if (m_fallen2Pos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount2 = 0;//�J�E���g���Z�b�g
			m_isFallenUp2 = false;
			m_isCanFallen2 = true;//�ēx�����邽�߂̏���

			m_fallen2Pos.x = Stage2::kBox4Xt;
			m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
		}
	}


	////��̖�
	//if (m_isCanFallen2)//�����̈ʒu�ɂ��邩�ǂ���
	//{
	//	if (m_fallenRange == 2)//�͈͓���������
	//	{
	//		m_isFallenDrop2 = true;
	//		m_isCanFallen2 = false;
	//	}
	//}

	//if (m_isFallenDrop2)//�������̗h���
	//{
	//	m_fallenCount2++;//�k���鎞��
	//	//�h���
	//	m_fallen2Pos.x = Stage2::kBox4Xt + GetRand(10);
	//	m_fallen2Pos.y = Stage2::kBoxBottom8Yf + GetRand(10);

	//	if (m_fallenCount2 >= 30)//3�b��
	//	{
	//		//�|�W�V���������Z�b�g
	//		m_fallen2Pos.x = Stage2::kBox4Xt;
	//		m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//	}
	//}

	//if (m_fallenCount2 >= 45)
	//{
	//	m_isFallenDrop2 = false;
	//	//�����J�n
	//	m_fallen2Pos.y += 10;//�����X�s�[�h
	//	if (m_fallen2Pos.y >= Stage2::kBox4Yt)//������ꏊ����
	//	{
	//		m_fallenCount2 = 0;//�J�E���g���Z�b�g

	//		//�����|�W�V�����ɖ߂�
	//		m_fallen2Pos.x = Stage2::kBox4Xt;
	//		m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//		m_isCanFallen2 = true;

	//	}
	//}
}
//�G�ɓːi����
void EnemyStage2::ChargeMove()
{
	//�v���C���[�ɓːi����
	Vec2 toPlayer{ 0.0f,0.0f };

	toPlayer.x = m_playerPos.x - m_chargePos.x;
	toPlayer.y = m_playerPos.y - m_chargePos.y;

	//m_length = toPlayer.length();//�������擾

	toPlayer = toPlayer.normalize();//���K��
	

	m_chargePos += toPlayer * m_chargeSpeed;//�v���C���[�̕����ɒ����ňړ�

}

void EnemyStage2::UpDownMove()
{
	if (!m_isUpDown)//��ɂ���ꍇ
	{
		m_upDownPos.y += 3;
		if (m_upDownPos.y == Stage2::kBox4Yt - 15)//���ɓ��B�����ꍇ
		{
			m_isUpDown = true;
		}
	}
	else
	{
		m_upDownPos.y -= 3;
		if (m_upDownPos.y == Stage2::kBoxBottom4Yf + 15)//���ɓ��B�����ꍇ
		{
			m_isUpDown = false;
		}

	}

	if(m_upDownLeftImageX <= 400)m_upDownLeftImageX += 100;//X��400�ɂȂ�܂ŌJ��Ԃ�
	else{

		m_upDownLeftImageX = 0;//�摜�ʒu���E�ɖ߂�
		if (m_upDownLeftImageY <= 400)m_upDownLeftImageY += 100;//Y��400�ɂȂ�܂ŌJ��Ԃ�
		else{
			if(m_upDownRad <= static_cast<int>(DX_PI + DX_PI))m_upDownRad++;
			else{
				m_upDownRad = static_cast<int>(DX_PI);
			}
			m_upDownLeftImageY = 0;//��ԏ�ɖ߂�
		}
			
	}

}
//�G�̃L�������W�擾
void EnemyStage2::npcPos()
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

	//�h�b�X��
	m_fallenLeft = static_cast<int>(m_fallenPos.x);
	m_fallenTop = static_cast<int>(m_fallenPos.y);
	m_fallenRight = m_fallenLeft + 150;
	m_fallenBottom = m_fallenTop + 10;
	//�h�b�X����������
	m_fallenRangeLeft = 1110;
	m_fallenRangeTop = 550;
	m_fallenRangeRight = m_fallenRangeLeft + 250;
	m_fallenRangeBottom = m_fallenRangeTop + 120;
	//�h�b�X��2
	m_fallen2Left = static_cast<int>(m_fallen2Pos.x);
	m_fallen2Top = static_cast<int>(m_fallen2Pos.y);
	m_fallen2Right = m_fallen2Left + 150;
	m_fallen2Bottom = m_fallen2Top + 10;
	//�h�b�X��2��������
	m_fallenRange2Left = 1110 + 150 + 150;
	m_fallenRange2Top = 550;
	m_fallenRange2Right = m_fallenRange2Left + 250;
	m_fallenRange2Bottom = m_fallenRange2Top + 120;

	//�`���[�W�G�l�~�[
	m_chargeLeft = static_cast<int>(m_chargePos.x);
	m_chargeTop = static_cast<int>(m_chargePos.y);
	m_chargeRight = m_chargeLeft + 30;
	m_chargeBottom = m_chargeTop + 30;
	//�㉺�^�������
	m_upDownLeft = static_cast<int>(m_upDownPos.x);
	m_upDownTop = static_cast<int>(m_upDownPos.y);
	m_upDownRight = m_upDownLeft + 30;
	m_upDownBottom = m_upDownTop + 30;
}
