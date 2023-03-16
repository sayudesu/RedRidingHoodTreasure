#include "SceneMain.h"
#include "SceneResult.h"
#include "Player.h"
#include "Enemy.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"
//�萔
namespace
{
	//�v���C���[�̏������W
	constexpr float kPosX = 100.0f;//20.0f;
	constexpr float kPosY = 0.0f;//700.0f;
	//��������
	constexpr float kMoveSpeed = 3.0f;
	// �W�����v��
	constexpr float kJump = -11.0f;
	// �d��
	constexpr float kGravity = 0.8f;

	//�n�ʂ̍���Y��
	constexpr int kGround = 700;

	constexpr int kCharaImageLeftPos = -112; //���ړ�
	constexpr int kCharaImageRightPos = 112; //�E�ړ�

	//�A�j���[�V�����t���[����
	constexpr int kAnimationFrame = 3;

	////////////////////
	///*�n�ʁ@3���W*///
	////////////////////
	constexpr int kGroundThirdX = 0;
	constexpr int kGroundThirdY = 380 - 10;
	constexpr int kGroundThirdBottomX = Game::kScreenWidth / 2 + 100;
	constexpr int kGroundThirdBottomY = kGroundThirdY + 20;

	////////////////////
	///*�n�ʁ@�Q���W*///
	////////////////////
	constexpr int kGroundSecondX = Game::kScreenWidth / 2;
	constexpr int kGroundSecondY = 520 + 10;
	constexpr int kGroundSecondBottomX = Game::kScreenWidth - 120;
	constexpr int kGroundSecondBottomY = kGroundSecondY + 20;

	////////////////////
	///*�͂��� �Q���W*///
	////////////////////
	constexpr int kLadderSecondX = Game::kScreenWidth / 2 + 120;
	constexpr int kLadderSecondY = 380 - 10;
	constexpr int kLadderBottomSecondX = kLadderSecondX + 10;
	constexpr int kLadderBottomSecondY = kLadderSecondY + 100;

	////////////////////
	///*�͂����P���W*///
	////////////////////
	constexpr int kLadderX = Game::kScreenWidth - 100;
	constexpr int kLadderY = 500;
	constexpr int kLadderXBottom = Game::kScreenWidth - 90;
	constexpr int kLadderYBottom = Game::kScreenHeight - 70;

	////////////////////////
	///*�A�C�e���{�b�N�X*///
	///////////////////////
	constexpr int kBoxPosX = 200;
	constexpr int kBoxPosY = 550;
	constexpr int kBoxPosBottomX = 200 + 50;
	constexpr int kBoxPosBottomY = 550 + 50;

}
//�R���X�g���N�^
Player::Player() :
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
	m_playerBpttom        (0),
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
	m_isItemDrop          (false),
	m_isFloorOne          (false),
	m_isLadder            (false),
	m_isInvaliDown        (false),
	m_isCharaDirection    (false),
	m_isCharaIdleDirection(false),
	m_playerSize     (0.0f, 0.0f),
	m_pos            (0.0f, 0.0f),
	m_imagePos       (0.0f, 0.0f),
	m_imageBalancePos(0.0f, 0.0f),
	m_underPos       (0.0f, 0.0f),
	m_vec            (0.0f, 0.0f),
	m_pEnemy      (nullptr),
	m_pSceneResult(nullptr)
{
	m_charaImagePos = (1344 - kCharaImageRightPos);
	m_func = &Player::UpdateMove;
	m_pEnemy = new Enemy;
}
//�f�X�g���N�^
Player::~Player()
{
	delete m_pEnemy;
	delete m_pSceneResult;
}
//������
void Player::Init()
{

	m_hierarchy = 1;
	m_playerHealthBer = 100;

	m_boxDropCount = 120;

	m_boxPosX = kBoxPosX;
	m_boxPosY = kBoxPosY;
	m_boxPosBottomX = kBoxPosBottomX;
	m_boxPosBottomY = kBoxPosBottomY;

	m_pos.x = kPosX;
	m_pos.y = kPosY;

	m_underPos.x = m_pos.x + 50;
	m_underPos.y = m_pos.y + 100;

	m_gravity = kGravity;

	GetGraphSizeF(m_hPlayer, &m_playerSize.x, &m_playerSize.y);
}
//�������̊J��
void Player::End()
{

}
//�A�b�v�f�[�g����
void Player::Update()
{
	m_pEnemy->Update();
	(this->*m_func)();
}
//�`��
void Player::Draw()
{
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);

	//////////////////////////////////////
	//*�@�@�@�@�@�}�b�v�w�i�@�@�@�@�@�@*//
	//////////////////////////////////////
	DrawExtendGraph(0,0,  Game::kScreenWidth,Game::kScreenHeight,  m_hMapFirst , true);
	DrawExtendGraph(-10 + GetRand(10), 0 + GetRand(5), Game::kScreenWidth + GetRand(10), Game::kScreenHeight + GetRand(5), m_hMapSecond, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMapThird , true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMapFourth, true);
	DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hMapFifth, true);

	//////////////////////////////////////
	//*�@�@�@�@�@�}�b�v�`�b�v�@�@�@�@�@*//
	//////////////////////////////////////

	//3�K
	DrawRectExtendGraph(
		kGroundThirdX, kGroundThirdY,
		kGroundThirdBottomX, kGroundThirdBottomY,
		16, 224, 160, 32,
		m_hMapChip, true);
	//2�K
	DrawRectExtendGraph(
		kGroundSecondX, kGroundSecondY,
		kGroundSecondBottomX, kGroundSecondBottomY,
		16, 224, 160, 32,
		m_hMapChip, true);
	//1�K
	DrawRectExtendGraph(
		0, 700, Game::kScreenWidth + 1, kGround + 20 + 1,
		16, 224, 160, 32,
		m_hMapChip, true);

	/////�����r���I�I�I/////////////////
	/////�����r���I�I�I/////////////////
	/////�����r���I�I�I/////////////////
	//1�K�̒�q
	DrawRectExtendGraph(
		kLadderX- 50, kLadderY, kLadderXBottom + 20, kLadderYBottom + 60,
		683, 400, 21 + 10, 80 + 10 ,
		m_hMapChipSecond, true);
	//////////////////////////////////////
	//*�n�ʂ͉����珇�Ԃɐ����Ă����܂�*//
	//////////////////////////////////////
	
	//�n��3
	DrawBox(kGroundThirdX, kGroundThirdY,
		kGroundThirdBottomX, kGroundThirdBottomY, 0x00ff00, false);

	//��q2
	DrawBox(kLadderSecondX, kLadderSecondY, kLadderBottomSecondX, kLadderBottomSecondY, 0xff0000, true);
	//     �@ left,  �@�@top,  �@�@ right,   �@�@�@bottom,

	//�n��2
	DrawBox(kGroundSecondX, kGroundSecondY,
			kGroundSecondBottomX, kGroundSecondBottomY, 0x00ff00, false);

	//��q1
	//DrawBox(kLadderX, kLadderY, kLadderXBottom, kLadderYBottom, 0xff0000, false);
	//     �@ left,  �@�@top,  �@�@ right,   �@�@�@bottom,
	 
	//�n�ʂP
	DrawBox(0, 700, Game::kScreenWidth + 1, kGround + 20 + 1, 0x00ff00, false);

	//DrawLine(Game::kScreenWidth / 2, 520, Game::kScreenWidth - 120, 520, 0xffffff);//2
	//DrawLine(0, kGround, Game::kScreenWidth, kGround, 0xffffff);//1
	
	
	if(!m_isGetSword)
	{
		if (m_boxDropCount < 120)
		{
			m_stagingBoxX = GetRand(10), m_stagingBoxY = GetRand(10);
			m_stagingBoxBottomX = GetRand(10), m_stagingBoxBottomY = GetRand(10);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, GetRand(255));
		}
		else
		{
			m_stagingBoxX = 0;
			m_stagingBoxY = 0;
			m_stagingBoxBottomX = 0;
			m_stagingBoxBottomY = 0;
		}
		DrawBox(m_boxPosX + m_stagingBoxX, m_boxPosY + m_stagingBoxY, m_boxPosBottomX + m_stagingBoxBottomX, m_boxPosBottomY + m_stagingBoxBottomY, 0x00ff00, true);//�A�C�e���{�b�N�X
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�̗̗͂ʕ\��
	if(!m_isHealthBer)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(static_cast<int>(m_pos.x) - 35, static_cast<int>(m_pos.y) - 30,
			static_cast<int>(m_pos.x) - 35 + 75, static_cast<int>(m_pos.y) - 30 + 10, 0xff0000, true);
		DrawExtendGraph(static_cast<int>(m_pos.x) - 35, static_cast<int>(m_pos.y) - 30,
			m_playerHealthSizeX + m_pos.x - 35 + 75, m_playerHealthSizeY + m_pos.y - 30 + 10,m_hHealthBer,true);
		DrawBox(m_pos.x - 35, m_pos.y - 30, m_pos.x - 35 + 75, m_pos.y - 30 + 10, 0xffffff, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�L�����N�^�[
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	for (int i = 0; i < 4 ; i++)//�w�i���C�g
	{
		DrawRotaGraph(static_cast<int>(m_pos.x) - 3 + GetRand(5), static_cast<int>(m_pos.y) + 20 + GetRand(5)
			, 3, 0, m_hPlayerLighting, true, false);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (m_isIdleMove && !m_isAttackMove && !m_isDamageMove && !m_isJumpMove && !m_isCrouchingMove)//�������Ȃ�
	{

		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + static_cast<int>(m_imageBalancePos.x),
			static_cast<int>(m_imagePos.y) + static_cast<int>(m_imageBalancePos.y),
			m_charaImageIdlePos, 0, 80, 80, 2, 0, m_hPlayerIdle, true, m_isCharaIdleDirection);

	}
	else if (m_isRunMoveRight && !m_isAttackMove || m_isRunMoveLeft && !m_isAttackMove && !m_isDamageMove && !m_isJumpMove && !m_isCrouchingMove)//����
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x), static_cast<int>(m_imagePos.y),
			m_charaImagePos, 133, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//���U��
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageAttackPos, 1197, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isDamageMove && !m_isCrouchingMove)//�U�����󂯂���
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageDamagePos, 1330, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isJumpMove && !m_isCrouchingMove)//�W�����v��������
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageJumpPos, 399, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}

	if(m_isCrouchingMove)//���Ⴊ��
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageCrouching, 532, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}

	//���񂾏ꍇ�̃��j���[���
	if (m_isDead)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//����
		DrawBox(350, 200, 300 + 600, 200 + 300, 0x0000ff, true);//�w�i
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawBox(350,200,300 + 600,200 + 300,0xffffff,false);//�g
		DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 2 - 100, "���Ȃ��͎��ɂ܂���", 0xff0000);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2 - 30, "�󂯓����", 0xffffff);
		DrawString(Game::kScreenWidth / 2 + 50, Game::kScreenHeight  / 2 - 30, "�󂯓���Ȃ�", 0xffffff);
		DrawString(Game::kScreenWidth / 2 - 200 + 35, Game::kScreenHeight / 2, "Y", 0xffffff);
		DrawString(Game::kScreenWidth / 2 + 50 + 40, Game::kScreenHeight  / 2, "N", 0xffffff);
	}


	DrawString(0, 0, "�Q�[���v���C", 0xffffff);
	DrawString(200,100,"P�������ăf�o�b�N�p���Z�b�g",0xffffff);

	////////////////////
	///*����̊m�F�p*///
	////////////////////
#if true	
	//�L�����N�^�[
	DrawBox(m_playerLeft, m_playerTop, m_playerRight, m_playerBpttom, 0xff0000, false);
	//DrawBox(m_pos.x - 25, m_pos.y + 10, m_pos.x + 25, m_pos.y + 60, 0xff0000, false);
	//DrawBox(m_playerLeft, m_playerTop, m_playerRight, m_playerBpttom, 0xffff00, false);

	//printfDx("%f\n", m_pos.y);
	printfDx("%d\n", m_playerHealthBer);

#endif
}
//����
void Player::Operation()
{
	//���͔���
	Pad::update();

	m_isCrouchingMove = false;
	m_isRunMoveRight = false;//�E�ɓ����Ă��邩�ǂ���
	m_isRunMoveLeft = false;//���ɓ����Ă��邩�ǂ���
	m_isIdleMove = true;//�����Ă��邩�ǂ���

	//�ړ�
	if (CheckHitKey(KEY_INPUT_RIGHT) && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//�E
	{
		m_pos.x += kMoveSpeed;
		m_underPos.x += kMoveSpeed;
		m_isCharaDirection = true;//�摜���]
		m_isRunMoveRight = true;
		m_isIdleMove = false;
		m_isCharaIdleDirection = false;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//��
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
		m_isCharaDirection = false;//�摜���]
		m_isRunMoveLeft = true;
		m_isIdleMove = false;
		m_isCharaIdleDirection = true;
	}

	//�A�b�v�_�E��
	if (CheckHitKey(KEY_INPUT_UP) && CheckHit() == 1 && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//��q���
	{
		m_vec.y = 0.0f;
		m_pos.y -= kMoveSpeed;
		m_isIdleMove = false;
	
	} 
	if(m_isInvaliDown && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)
	{
		if (CheckHitKey(KEY_INPUT_DOWN) && CheckHit() == 1)//��q����
		{
			m_vec.y = 0.0f;
			m_pos.y += kMoveSpeed;
			m_isIdleMove = false;
		}
	}

	//�W�����v
	if (Pad::isTrigger(KEY_INPUT_UP) && CheckHit() == 0 && !m_isAttackMove && !m_isDamageMove)//��
	{
		if (FieldJudgement() == 1 ||
			FieldJudgement() == 2)//�n�ʂɂ����Ԃ̏ꍇ
		{
			printfDx("�W�����v\n");
			m_vec.y = kJump;//�W�����v�J�n
			m_isJumpMove = true;
			//m_isIdleMove = false;
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_isCrouchingMove = true;
	}

	//�U��
	if(m_isGetSword && !m_isDamageMove && !m_isCrouchingMove)
	{
		if(CheckHitKey(KEY_INPUT_V))
		{
			m_isAttackMove = true;
		}
	}

	//�|�[�Y���j���[
	if (CheckHitKey(KEY_INPUT_P))
	{
		m_func = &Player::MenuStop;
	}
		
}
//�A�j���[�V����
void Player::Condition()
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

	//�A�C�h�����
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
	
	//�E�Ɉړ��A�j���[�V����
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

	//���Ɉړ��A�j���[�V����
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

	//�U�����󂯂��ꍇ
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

	//�W�����v�����ꍇ
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
	//�n�ʂɂ���ꍇ�̂��Ⴊ��
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

	//�U���A�j���[�V�����i���j
	if (m_isAttackMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageAttackPos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImageAttackPos >= 1344)
		{
			m_charaImageAttackPos = 0;
			m_isAttackMove = false;//�U�������Ă��邩�ǂ���
		}
	}
	else
	{
		m_charaImageAttackPos = 0;
	}

}
//�n�ʂƂ̔���
int Player::FieldJudgement()
{
	m_isInvaliDown = false;

	if (CheckHit() == 1)//��q�̔���
	{
		return 0;
	}

	//3�K�̔���
	if ((kGroundThirdBottomX > m_pos.x - 25) &&
		(kGroundThirdX < m_pos.x + 25))
	{
		if ((kGroundThirdBottomY > m_pos.y) &&
			(kGroundThirdY < m_pos.y + 60))
		{
			m_pos.y = kGroundThirdY - 50 - m_playerSize.y;
			m_isInvaliDown = true;//���Ɉړ��ł��Ȃ�
			return 1;
		}
	}
	//2�K�̔���
	if ((kGroundSecondBottomX > m_pos.x - 25) &&
		(kGroundSecondX       < m_pos.x + 25))
	{
		if ((kGroundSecondBottomY > m_pos.y) &&
			(kGroundSecondY       < m_pos.y + 60))
		{
			m_pos.y = 530 - 50 - m_playerSize.y;
			m_isInvaliDown = true;//���Ɉړ��ł��Ȃ�
			return 1;
		}
	}
#if false		
	//1�K�̔���
	if ((Game::kScreenWidth + 1 > m_playerLeft) &&
		(0                     < m_playerRight))
	{
		if ((kGround + 20 + 1 > m_playerTop) &&
			(700              < m_playerBpttom))
		{

			m_pos.y = kGround - 50 - m_playerSize.y;
			printfDx("�n�ʔ���\n");
			m_isInvaliDown = true;//���Ɉړ��ł��Ȃ�
			return 1;

		}
	}
#else
	if ((Game::kScreenWidth + 1 > m_pos.x - 25) &&
		(0                      < m_pos.x + 25))
	{
		if ((kGround + 20 + 1 > m_pos.y + 10) &&
			(700              < m_pos.y + 60))
		{

			m_pos.y = kGround - 50 - m_playerSize.y;
	
			m_isInvaliDown = true;//���Ɉړ��ł��Ȃ�
			printfDx("�n�ʔ���\n");
			return 1;

		}
	}
#endif

	return 0;
}
//�L�����N�^�[�Ƃ͂����̔���
int Player::CheckHit()
{
#if true	

	//2�K��q
	if ((kLadderBottomSecondX > m_playerLeft) &&
		(kLadderSecondX < m_playerRight))
	{
		if ((kLadderBottomSecondY > m_playerTop) &&
			(kLadderSecondY < m_playerBpttom))
		{
			m_isFloorOne = true;
			m_isInvaliDown = true;
			m_count++;
			//1�t���[�������ő������i�\��
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
			}
			return 1;
		}
	}

	//1�K��q
	if ((kLadderXBottom > m_playerLeft) &&
		(kLadderX < m_playerRight))
	{
		if ((kLadderYBottom > m_playerTop) &&
			(kLadderY < m_playerBpttom))
		{
			m_isFloorOne = true;
			m_isInvaliDown = true;
			m_count++;
			//1�t���[�������ő������i�\��
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
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
			//1�t���[�������ő������i�\��
			if (m_count == 1)
			{
				//m_pos.x = (10 + kLadderX);
			}
			return 1;
		}
	}
#endif	
	m_isFloorOne = false;
	m_count = 0;

	return 0;
}
//�A�C�e���{�b�N�X�̔���
void Player::BoxJudgement()
{
#if true	
	if ((m_boxPosBottomX > m_playerLeft) &&
		((m_boxPosX < m_playerRight)))
	{
		if ((m_boxPosBottomY > m_playerTop) &&
			(m_boxPosY < m_playerBpttom))
		{
			//printfDx("�{�b�N�X����\n");
			m_isItemDrop = true;
			if (m_boxDropCount >= 120)
			{
				m_isGetSword = true;//�A�C�e���{�b�N�X��\��
				m_boxDropCount = 0;

			}

		}
	}
#else 
	if ((m_boxPosBottomX > m_pos.x - 25) &&
		((m_boxPosX < m_pos.x + 25)))
	{
		if ((m_boxPosBottomY > m_pos.y + 10) &&
			(m_boxPosY < m_pos.y + 60))
		{
			//printfDx("�{�b�N�X����\n");
			m_isItemDrop = true;
			if (m_boxDropCount >= 120)
			{
				m_isGetSword = true;//�A�C�e���{�b�N�X��\��
				m_boxDropCount = 0;

			}

		}
	}
#endif
}
//�G�ƃv���C���[�̔���
bool Player::EnemyHit()
{			
	if ((m_pEnemy->GetSizeBottom().x > m_playerLeft) &&
		(m_pEnemy->GetSize().x < m_playerRight))
	{
		if ((m_pEnemy->GetSizeBottom().y > m_playerTop) &&
			(m_pEnemy->GetSize().y < m_playerBpttom))
		{
			if (m_isGetSword)
			{

				m_boxPosX = static_cast<int>(m_pos.x);
				m_boxPosY = static_cast<int>(m_pos.y) - 80;
				m_boxPosBottomX = m_boxPosX + 50;
				m_boxPosBottomY = m_boxPosY + 50;

				m_isGetSword = false;//�A�C�e���{�b�N�X�h���b�v
			}

			m_isDamageMove = true;//�_���[�W�A�j���[�V�����Đ�
			return true;
		}
	}

	return false;
}
//�v���C���[�̗̑͂��Ǘ�
void Player::HealthControl()
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
		printfDx("���S\n");
		m_playerHealthSizeX = 0;
		m_isHealthBer = true;
		//�|�[�Y���j���[

		m_func = &Player::DeathMenu;
		
	}
	
}
//�A�b�v�f�[�g����
void Player::UpdateMove()
{	
	clsDx();

	if(FieldJudgement() == 0)
	{
		//�d��
		m_vec.y += m_gravity;	
	}

	if(CheckHit() == 1)
	{
		m_vec.y = 0.0f;
	}
	
	m_playerLeft = static_cast<int>(m_pos.x) - 25;
	m_playerTop = static_cast<int>(m_pos.y) + 10;
	m_playerRight = static_cast<int>(m_pos.x) + 25;
	m_playerBpttom = static_cast<int>(m_pos.y) + 60;
	
	//�v���C���[�ʒu
	m_imagePos = m_pos;
	m_pos      += m_vec;
	m_underPos += m_vec;

	////////////////////
	////*�����蔻��*////
	///////////////////
	//�͂���
	CheckHit();
	//�n��
	FieldJudgement();
	//�A�C�e��
	BoxJudgement();
	if (!m_isGetSword)
	{
		m_boxDropCount++;

	}

	if (m_boxDropCount >= 120)
	{
		m_boxDropCount = 120;
		
	}
	//�G�Ƃ̓����蔻��
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

	//����
	Operation();
	//��ԁi�����j
	Condition();
}
//�|�[�Y���
void Player::MenuStop()
{
	printfDx("�|�[�Y��\n");
	printfDx("�~�Ϗ��u\n");
	if (CheckHitKey(KEY_INPUT_O))
	{
		m_func = &Player::UpdateMove;
	}
	m_isDead = true;
	if (CheckHitKey(KEY_INPUT_Y))
	{
		m_isReset = true;
	}
	if (CheckHitKey(KEY_INPUT_N))
	{
		m_isTitle = true;
	}
}
//���񂾏ꍇ��Menu
void Player::DeathMenu()
{
	m_isDead = true;
	if (CheckHitKey(KEY_INPUT_Y))
	{
		m_isReset = true;
	}
	if (CheckHitKey(KEY_INPUT_N))
	{
		m_isTitle = true;
	}
}
