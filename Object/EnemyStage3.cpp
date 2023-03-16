#include "EnemyStage3.h"
#include "game.h"
#include "Image.h"
#include <DxLib.h>

EnemyStage3::EnemyStage3() :
	m_hFireBall(-1),//�摜�n���h��
	m_hBarre(),//�M�i���̂����摜�j
	m_maskHandle(),
	m_hEnemyImage(-1),
	m_hNeedle(-1),//�n�ʗp
	m_hTiles(-1),//�摜�`�b�v
	m_hCave(-1),//���A�摜�p
	m_hUpDown(-1),//�㉺�^����㩉摜
	m_posLeft(0),
	m_posTop(0),
	m_posRight(0),
	m_posBottom(0),
	m_barrelLeft(),//�M�T�C�Y
	m_barrelTop(),
	m_barrelRight(),
	m_barrelBottom(),
	m_barrelSizePulsX(0),//�M�T�C�Y�ύX.X
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
	m_upDownLeft(0),//�㉺�^�������
	m_upDownTop(0),
	m_upDownRight(0),
	m_upDownBottom(0),
	m_upDown2Left(0),//�㉺�^�������
	m_upDown2Top(0),
	m_upDown2Right(0),
	m_upDown2Bottom(0),
	m_upDown3Left(0),//�㉺�^�������
	m_upDown3Top(0),
	m_upDown3Right(0),
	m_upDown3Bottom(0),
	m_fireBallImagePosX(0),//�t�@�C�A�{�[���摜�ʒu
	m_fireBallImagePosY(0),
	m_upDownLeftImageX(0),//㩂̉摜�ʒu
	m_upDownLeftImageY(0),
	m_upDownLeft2ImageX(0),//㩂̉摜�ʒu
	m_upDownLeft2ImageY(0),
	m_upDownLeft3ImageX(0),//㩂̉摜�ʒu
	m_upDownLeft3ImageY(0),
	m_upDownRad(0),//㩊p�x
	m_fireImageDirection(0),
	m_barreImagePosX(),//�M�i�C�m�V�V�j�摜�ʒu
	m_barreImageDirection(),//�M�i���̂����j�摜�̕���
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
	m_frameCountBarreImage(),//�M�i���̂����j�̉摜�`��p�t���[���J�E���g
	m_frameCountFireImage(0),
	m_ladderNum(0),
	m_rushCount(0),
	m_fallenUpSpeed(0.0f),
	m_fallenUpSpeed2(0.0f),
	m_fallenUpSpeed3(0.0f),
	m_fallenUpSpeed4(0.0f),
	m_getPos(),
	m_fireRad(0),//�t�@�C�A�{�[���p�x
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
	m_isBarreMove(false),//2�̂̓G���������ǂ���
	m_isUpDown(false),//�㉺�ǂ���ɂ��邩
	m_isUpDown2(false),//�㉺�ǂ���ɂ��邩
	m_isUpDown3(false),//�㉺�ǂ���ɂ��邩
	m_isRush(false),
	m_isRushBlink(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(),//�M
	m_fallenPos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_fallen2Pos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_fallen3Pos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_fallen4Pos(0.0f, 0.0f),//�h�b�X���I�ȓz
	m_chargePos(0.0f, 0.0f),//�`���[�W����G
	m_upDownPos(0.0f, 0.0f),//�㉺�^�������
	m_upDown2Pos(0.0f, 0.0f),//�㉺�^�������
	m_upDown3Pos(0.0f, 0.0f),//�㉺�^�������
	m_vec(),
	m_playerPos(0.0f, 0.0f),
	m_playerSavePos(0.0f, 0.0f)
{
	m_isFirstMove = true;//��������
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

	//�t�@�C�A�{�[�������ʒu
	m_pos.x = Game::kScreenWidth - 400;
	m_pos.y = Game::kScreenHeight - 150;
	//�M�����ʒu
	for (int i = 0; i < 3; i++)
	{
		m_barrelPos[i].x = Enemy2::kBossPosLeft;
		m_barrelPos[i].y = Enemy2::kBossPosTop;
		m_vec[i] = {0.0f,0.0f};
	}
	//�ǂ�����
	m_fallenPos.x = Stage2::kBox2Xt;
	m_fallenPos.y = Stage2::kBoxBottom8Yf;
	//�ǂ�����2
	m_fallen2Pos.x = Stage2::kBox4Xt;
	m_fallen2Pos.y = Stage2::kBoxBottom8Yf;
	//�ǂ�����3
	m_fallen3Pos.x = Stage2::kBoxBottom5Xf;
	m_fallen3Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight / 2;
	//�ǂ�����4
	m_fallen4Pos.x = Stage2::kBoxBottom3Xf;
	m_fallen4Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight;
	//�`���[�W����G
	m_chargePos.x = Stage2::kBox1Xf;
	m_chargePos.y = Stage2::kBox1Yf - 50;

	m_chargeSpeed = 10.0f;


	m_upDownPos.x = 1000.0f + 50;
	m_upDownPos.y = Stage2::kBoxBottom4Yf + 15;

	m_upDown2Pos.x = 1000.0f - 250;
	m_upDown2Pos.y = Stage2::kBoxBottom4Yf + 15;

	m_upDown3Pos.x = 1000.0f - 550;
	m_upDown3Pos.y = Stage2::kBoxBottom4Yf + 15;

	m_hFireBall = LoadGraph(Image::kEnemySnail);//�J�^�c����
	for (int i = 0; i < 3; i++)
	{
		m_hBarre[i] = LoadGraph(Image::kEnemyBarre);//���̂���
		m_maskHandle[i] = LoadMask(Image::kEnemyBarre);

	}
	m_hTiles = LoadGraph(Image::kMapTiles2);//�摜�`�b�v�i���A�p�j
	m_hUpDown = LoadGraph(Image::kEnemyFireBall);//�

	m_hEnemyImage = LoadGraph(Image::kEnemyFallen);//�����Ă���㩂������Ă�摜

	m_hNeedle = DerivationGraph(0, 160, 32 + 16, 32, m_hEnemyImage);//�n�ʉ摜����ꕔ�𒊏o
	m_hCave = DerivationGraph(272, 208, 128, 160, m_hTiles);//�n�ʉ摜����ꕔ�𒊏o
}

EnemyStage3::~EnemyStage3()
{
	DeleteGraph(m_hFireBall);//�����ނ�
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(m_hBarre[i]);//�C�m�V�V
	}
	DeleteGraph(m_hEnemyImage);//�摜
	DeleteGraph(m_hNeedle);//�����Ă���G

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
	BarrelMove();//�M�̓���
	fireBallMove();//�t�@�C�A�{�[���̓���
	falleMove();//�h�b�X������
	ChargeMove();//�`���[�W�G�l�~�[�̓���
	UpDownMove();//�㉺�^�������
	npcPos();//�G�̃T�C�Y�擾
}
//�`��
void EnemyStage3::Draw()
{
	//�{�X(���A�ɕύX�G�̃X�|�[���ʒu)
	DrawExtendGraph(Enemy2::kBossPosLeft, Enemy2::kBossPosTop, Enemy2::kBossPosRight, Enemy2::kBossPosBottom,
		m_hCave, true);

	//�G�l�~�[���̋�
	DrawRectRotaGraph(m_posLeft + 20, m_posTop + 15,
		m_fireBallImagePosX, m_fireBallImagePosY, 48, 32, 1.3, m_fireRad, m_hFireBall, true, m_fireImageDirection);//�摜��`��

	//�M
	//DrawRectRotaGraph(m_barrelLeft[0] + 20, m_barrelTop[0] + 15 - 5,
	//	m_barreImagePosX[0], 0, 48, 32, 2, 0, m_hBarre[0], true, m_barreImageDirection);//�摜��`��

	//DrawRectRotaGraph(m_barrelLeft[1] + 20, m_barrelTop[1] + 15 - 5,
	//	m_barreImagePosX[1], 0, 48, 32, 2, 0, m_hBarre[1], true, false);//�摜��`��

	//DrawRectRotaGraph(m_barrelLeft[2] + 20, m_barrelTop[2] + 15 - 5,
	//	m_barreImagePosX[2], 0, 48, 32, 2, 0, m_hBarre[2], true, false);//�摜��`��

	for (int i = 0; i < 3; i++)
	{
		DrawRectRotaGraph(m_barrelLeft[i] + 20, m_barrelTop[i] + 15 - 5,
			m_barreImagePosX[i], 0, 48, 32, 2, 0, m_hBarre[i], true, m_barreImageDirection[i]);//�摜��`��
	}
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
	//�㉺�^�������
	DrawRectRotaGraph(
		m_upDown2Left + 14, m_upDown2Top + 15,
		m_upDownLeft2ImageX, m_upDownLeft2ImageY, 100, 100,
		1, m_upDownRad,
		m_hUpDown, true, false);
	//�㉺�^�������
	DrawRectRotaGraph(
		m_upDown3Left + 14, m_upDown3Top + 15,
		m_upDownLeft3ImageX, m_upDownLeft3ImageY, 100, 100,
		1, m_upDownRad,
		m_hUpDown, true, false);

#if true		
	DrawBox(Enemy2::kBossPosLeft, Enemy2::kBossPosTop,
		Enemy2::kBossPosRight, Enemy2::kBossPosBottom, 0xffff00, false);
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, false);//����m�F
	DrawBox(m_barrelLeft[0], m_barrelTop[0], m_barrelRight[0], m_barrelBottom[0], 0xffff00, false);//����m�F
	//�ǂ�����
	DrawBox(m_fallenLeft, m_fallenTop, m_fallenRight, m_fallenBottom, 0xffff00, false);
	//�ǂ�����2
	DrawBox(m_fallen2Left, m_fallen2Top, m_fallen2Right, m_fallen2Bottom, 0xffff00, false);
	//�ǂ�����3
	DrawBox(m_fallen3Left, m_fallen3Top, m_fallen3Right, m_fallen3Bottom, 0x00ff00, false);
	//�ǂ�����4
	DrawBox(m_fallen4Left, m_fallen4Top, m_fallen4Right, m_fallen4Bottom, 0xffff00, false);
	DrawBox(m_upDownLeft, m_upDownTop, m_upDownRight, m_upDownBottom, 0xffffff, false);
	DrawBox(m_upDown2Left, m_upDown2Top, m_upDown2Right, m_upDown2Bottom, 0xffffff, false);
	DrawBox(m_upDown3Left, m_upDown3Top, m_upDown3Right, m_upDown3Bottom, 0xffffff, false);
	//�ǂ�����͈�
	DrawBox(m_fallenRangeLeft, m_fallenRangeTop, m_fallenRangeRight, m_fallenRangeBottom, 0xffff00, false);
	//�ǂ�����2�͈�
	DrawBox(m_fallenRange2Left, m_fallenRange2Top, m_fallenRange2Right, m_fallenRange2Bottom, 0xffff00, false);
	//�ǂ�����3�͈�
	DrawBox(m_fallenRange3Left, m_fallenRange3Top, m_fallenRange3Right, m_fallenRange3Bottom, 0x00ff00, false);
	//�ǂ�����4�͈�
	DrawBox(m_fallenRange4Left, m_fallenRange4Top, m_fallenRange4Right, m_fallenRange4Bottom, 0x00ff00, false);
#endif
}
//�M�̓���
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
		m_vec[i].y += 10.0f;//�d��
		m_barrelPos[i].y += m_vec[i].y;//�d�͂̃x�N�g���p
	

		m_frameCountBarreImage[i]++;
		if (m_frameCountBarreImage[i] == 3)//�R�t���[���Ɉ��摜��ύX
		{
			m_barreImagePosX[i] += 48;
			m_frameCountBarreImage[i] = 0;
		}
		if (m_barreImagePosX[i] >= 288)
		{
			m_barreImagePosX[i] = 0;
		}
	
		if (m_fall[i] == 5)//�n�ʂɓ���������
		{
			m_isCourse[i] = false;
			m_vec[i].y = 0.0f;//���ɗ����Ȃ��悤��
			m_barrelPos[i].y = m_getPos[i];//�v���C���[�̈ʒu���W
			if (i == 0)
			{
				m_barrelPos[i].x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
			}

		}
		if (m_fall[i] == 4)//�n�ʂɓ���������
		{
			m_isCourse[i] = true;
			m_vec[i].y = 0.0f;//���ɗ����Ȃ��悤��
			m_barrelPos[i].y = m_getPos[i];//�v���C���[�̈ʒu���W
			m_barrelPos[0].x += Enemy2::kBarrelSpeed * m_barrelSpeed;//���Ɉړ�
			m_barreImageDirection[i] = true;//�摜�̕�����ύX
		}

		if (m_fall[i] == 3)//�n�ʂɓ���������
		{
			m_isCourse[i] = false;
			m_vec[i].y = 0.0f;//���ɗ����Ȃ��悤��
			m_barrelPos[i].y = m_getPos[i];//�v���C���[�̈ʒu���W
			m_barrelPos[0].x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
			m_barreImageDirection[i] = false;//�摜�̕�����ύX
		}

		if (m_fall[i] == 2)//�n�ʂɓ���������
		{
			m_isCourse[i] = true;
			m_vec[i].y = 0.0f;//���ɗ����Ȃ��悤��
			m_barrelPos[i].y = m_getPos[i];//�v���C���[�̈ʒu���W
			m_barrelPos[0].x += Enemy2::kBarrelSpeed * m_barrelSpeed;//���Ɉړ�
			m_barreImageDirection[i] = true;//�摜�̕�����ύX

		}

		if (m_fall[i] == 1)//�n�ʂɓ���������
		{
			m_isCourse[i] = false;
			m_vec[i].y = 0.0f;//���ɗ����Ȃ��悤��
			m_barrelPos[i].y = m_getPos[i];//�v���C���[�̈ʒu���W
			m_barrelPos[0].x -= Enemy2::kBarrelSpeed * m_barrelSpeed;//�Ƃ肠�����E�Ɉړ�
			m_barreImageDirection[i] = false;//�摜�̕�����ύX

		}

		if (m_barrelPos[i].x < 0|| m_barrelPos[i].x > Game::kScreenWidth + 100||
			m_barrelPos[i].y < 0|| m_barrelPos[i].y > Game::kScreenHeight)//�M����ʍ��ɏ�����ƍŏ��̈ʒu�ɖ߂��Ă���
		{
			m_barrelPos[i].x = Enemy2::kBossPosLeft + 50;
			m_barrelPos[i].y = Enemy2::kBossPosTop + 100;
		}

	}
}
//�����̓���
void EnemyStage3::fireBallMove()
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
void EnemyStage3::falleMove()
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

	//�O�̖�
	if (m_isCanFallen3)//�����̈ʒu�ɂ��邩�ǂ���
	{
		if (m_fallenRange == 3)//�͈͓���������
		{
			m_isFallenDrop3 = true;
			m_isCanFallen3 = false;
		}

	}

	if (m_isFallenDrop3)//�������̗h���
	{
		m_fallenCount3++;//�k���鎞��
		//�h���

		m_fallen3Pos.x = Stage2::kBoxBottom5Xf + GetRand(10);
		m_fallen3Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight / 2 + GetRand(10);
	}

	if (m_fallenCount3 >= 45)//������J�E���g
	{
		m_isFallenDrop3 = false;
		//�����J�n
		m_fallenUpSpeed3 = 10.0f;//��������ŏ���������
		m_fallen3Pos.y += m_fallenUpSpeed3;//�����X�s�[�h

		if (m_fallen3Pos.y >= Stage2::kBox4Yt)//������ꏊ����
		{
			m_isFallenUp3 = true;//��ɖ߂�����
		}
	}

	if (m_isFallenUp3)//�V��
	{
		m_fallenUpSpeed3 = 15.0f;//��������ŏ���������
		m_fallen3Pos.y -= m_fallenUpSpeed3;

		if (m_fallen3Pos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount3 = 0;//�J�E���g���Z�b�g
			m_isFallenUp3 = false;
			m_isCanFallen3 = true;//�ēx�����邽�߂̏���

			m_fallen3Pos.x = Stage2::kBoxBottom5Xf;
			m_fallen3Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight / 2;
		}
	}

	//�l�̖�
	if (m_isCanFallen4)//�����̈ʒu�ɂ��邩�ǂ���
	{
		if (m_fallenRange == 4)//�͈͓���������
		{
			m_isFallenDrop4 = true;
			m_isCanFallen4 = false;
		}

	}

	if (m_isFallenDrop4)//�������̗h���
	{
		m_fallenCount4++;//�k���鎞��
		//�h���
		m_fallen4Pos.x = Stage2::kBoxBottom3Xf + GetRand(10);
		m_fallen4Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight + GetRand(10);
	}

	if (m_fallenCount4 >= 45)
	{
		m_isFallenDrop4 = false;
		//�����J�n
		m_fallenUpSpeed4 = 10.0f;//��������ŏ���������
		m_fallen4Pos.y += m_fallenUpSpeed4;//�����X�s�[�h
		if (m_fallen4Pos.y >= Stage2::kBox4Yt)//������ꏊ����
		{
			m_isFallenUp4 = true;//��ɖ߂�����
		}
	}

	if (m_isFallenUp4)//�V��
	{
		m_fallenUpSpeed4 = 15.0f;//��������ŏ���������
		m_fallen4Pos.y -= m_fallenUpSpeed4;

		if (m_fallen4Pos.y <= Stage2::kBoxBottom8Yf)
		{
			m_fallenCount4 = 0;//�J�E���g���Z�b�g
			m_isFallenUp4 = false;
			m_isCanFallen4 = true;//�ēx�����邽�߂̏���

			m_fallen4Pos.x = Stage2::kBoxBottom3Xf;
			m_fallen4Pos.y = Stage2::kBoxBottom8Yf - Stage2::kBoxHeight;
		}
	}

}
//�G�ɓːi����
void EnemyStage3::ChargeMove()
{
	//�v���C���[�ɓːi����
	Vec2 toPlayer{ 0.0f,0.0f };

	toPlayer.x = m_playerPos.x - m_chargePos.x;
	toPlayer.y = m_playerPos.y - m_chargePos.y;

	//m_length = toPlayer.length();//�������擾

	toPlayer = toPlayer.normalize();//���K��
	

	m_chargePos += toPlayer * m_chargeSpeed;//�v���C���[�̕����ɒ����ňړ�

}

void EnemyStage3::UpDownMove()
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
			if(m_upDownRad <= DX_PI + DX_PI)m_upDownRad++;
			else{
				m_upDownRad = DX_PI;
			}
			m_upDownLeftImageY = 0;//��ԏ�ɖ߂�
		}

	}

	if (!m_isUpDown2)//��ɂ���ꍇ
	{
		m_upDown2Pos.y += 3;
		if (m_upDown2Pos.y == Stage2::kBox4Yt - 15)//���ɓ��B�����ꍇ
		{
			m_isUpDown2 = true;
		}
	}
	else
	{
		m_upDown2Pos.y -= 3;
		if (m_upDown2Pos.y == Stage2::kBoxBottom4Yf + 15 - 15)//���ɓ��B�����ꍇ
		{
			m_isUpDown2 = false;
		}

	}

	if (m_upDownLeft2ImageX <= 400)m_upDownLeft2ImageX += 100;//X��400�ɂȂ�܂ŌJ��Ԃ�
	else {

		m_upDownLeft2ImageX = 0;//�摜�ʒu���E�ɖ߂�
		if (m_upDownLeft2ImageY <= 400)m_upDownLeft2ImageY += 100;//Y��400�ɂȂ�܂ŌJ��Ԃ�
		else {
			if (m_upDownRad <= DX_PI + DX_PI)m_upDownRad++;
			else {
				m_upDownRad = DX_PI;
			}
			m_upDownLeft2ImageY = 0;//��ԏ�ɖ߂�
		}

	}

	if (!m_isUpDown3)//��ɂ���ꍇ
	{
		m_upDown3Pos.y += 3;
		if (m_upDown3Pos.y == Stage2::kBox4Yt - 15)//���ɓ��B�����ꍇ
		{
			m_isUpDown3 = true;
		}
	}
	else
	{
		m_upDown3Pos.y -= 3;
		if (m_upDown3Pos.y == Stage2::kBoxBottom4Yf + 15 - 15 - 15)//���ɓ��B�����ꍇ
		{
			m_isUpDown3 = false;
		}

	}

	if (m_upDownLeft3ImageX <= 400)m_upDownLeft3ImageX += 100;//X��400�ɂȂ�܂ŌJ��Ԃ�
	else {

		m_upDownLeft3ImageX = 0;//�摜�ʒu���E�ɖ߂�
		if (m_upDownLeft3ImageY <= 400)m_upDownLeft3ImageY += 100;//Y��400�ɂȂ�܂ŌJ��Ԃ�
		else {
			if (m_upDownRad <= DX_PI + DX_PI)m_upDownRad++;
			else {
				m_upDownRad = DX_PI;
			}
			m_upDownLeft3ImageY = 0;//��ԏ�ɖ߂�
		}

	}

	//printfDx("%d\n", m_upDownRad);

}
//�G�̃L�������W�擾
void EnemyStage3::npcPos()
{
	//enemy�̍��W
	m_posLeft = m_pos.x;
	m_posTop = m_pos.y;
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

	//�M
	for (int i = 0; i < 3; i++)
	{
		m_barrelLeft[i] = m_barrelPos[i].x;
		m_barrelTop[i] = m_barrelPos[i].y + 5.0f;
		m_barrelRight[i] = m_barrelLeft[i] + 50;
		m_barrelBottom[i] = m_barrelTop[i] + 40;
	}

	//�h�b�X��
	m_fallenLeft = m_fallenPos.x;
	m_fallenTop = m_fallenPos.y;
	m_fallenRight = m_fallenLeft + 150 - 10;
	m_fallenBottom = m_fallenTop + 10;
	//�h�b�X����������
	m_fallenRangeLeft = 1110;
	m_fallenRangeTop = 550;
	m_fallenRangeRight = m_fallenRangeLeft + 250;
	m_fallenRangeBottom = m_fallenRangeTop + 120;
	//�h�b�X��2
	m_fallen2Left = m_fallen2Pos.x;
	m_fallen2Top = m_fallen2Pos.y;
	m_fallen2Right = m_fallen2Left + 150 - 10;
	m_fallen2Bottom = m_fallen2Top + 10;
	//�h�b�X��2��������
	m_fallenRange2Left = 1110 + 150 + 150;
	m_fallenRange2Top = 550;
	m_fallenRange2Right = m_fallenRange2Left + 250;
	m_fallenRange2Bottom = m_fallenRange2Top + 120;

	//�h�b�X��3
	m_fallen3Left = m_fallen3Pos.x;
	m_fallen3Top = m_fallen3Pos.y;
	m_fallen3Right = m_fallen3Left + 150 - 10;
	m_fallen3Bottom = m_fallen3Top + 10;
	//�h�b�X��3��������
	m_fallenRange3Left = 1110 - 150 - 150 - 10;
	m_fallenRange3Top = 550;
	m_fallenRange3Right = m_fallenRange3Left + 250;
	m_fallenRange3Bottom = m_fallenRange3Top + 120;

	//�h�b�X��4
	m_fallen4Left = m_fallen4Pos.x;
	m_fallen4Top = m_fallen4Pos.y;
	m_fallen4Right = m_fallen4Left + 150 - 10;
	m_fallen4Bottom = m_fallen4Top + 10;
	//�h�b�X��4��������
	m_fallenRange4Left = 1110 - 150 - 150 - 150 - 150 - 10;
	m_fallenRange4Top = 550;
	m_fallenRange4Right = m_fallenRange4Left + 250;
	m_fallenRange4Bottom = m_fallenRange4Top + 120;

	//�`���[�W�G�l�~�[
	m_chargeLeft = m_chargePos.x;
	m_chargeTop = m_chargePos.y;
	m_chargeRight = m_chargeLeft + 30;
	m_chargeBottom = m_chargeTop + 30;
	//�㉺�^�������
	m_upDownLeft = m_upDownPos.x;
	m_upDownTop = m_upDownPos.y;
	m_upDownRight = m_upDownLeft + 30;
	m_upDownBottom = m_upDownTop + 30;

	//�㉺�^�������
	m_upDown2Left = m_upDown2Pos.x;
	m_upDown2Top = m_upDown2Pos.y;
	m_upDown2Right = m_upDown2Left + 30;
	m_upDown2Bottom = m_upDown2Top + 30;

	//�㉺�^�������
	m_upDown3Left = m_upDown3Pos.x;
	m_upDown3Top = m_upDown3Pos.y;
	m_upDown3Right = m_upDown3Left + 30;
	m_upDown3Bottom = m_upDown3Top + 30;
}