#include "SceneMain2.h"
#include "PlayerNew.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"
#include "image.h"
#include <cassert>

//�萔
namespace
{
	constexpr int kmapSize = 250;

	constexpr double kPlayerSize = 1.4;
	//�v���C���[�̏������W
	constexpr float kPosX = 150.0f;
	constexpr float kPosY = static_cast<float>(Game::kScreenHeight) - 50.0f;//�f�o�b�N�p��-300�ړ�
	//��������
	constexpr float kMoveSpeed = 5.0f;
	// �W�����v��
	constexpr float kJump = -11.5f;
	// �d��
	constexpr float kGravity = 0.9f;

	//�n�ʂ̍���Y��
	constexpr int kGround = 700;

	constexpr int kCharaImageLeftPos = -112; //���ړ�
	constexpr int kCharaImageRightPos = 112; //�E�ړ�

	//�A�j���[�V�����t���[����
	constexpr int kAnimationFrame = 3;

}

//�R���X�g���N�^
PlayerNew::PlayerNew() :
	m_hPlayer(-1),//�摜
	m_hPlayerIdle(-1),//�������Ă��Ȃ����
	m_hPlayerLighting(-1),
	m_hHealthBer(-1),
	m_hAttack(-1),//�T�E���h
	m_hFxJump(-1),
	m_hLadder(-1),
	m_hRun(-1),
	m_hDead(-1),
	m_CountRunSound(-1),
	m_CountLadderSound(-1),
	m_hMapFirst(-1),
	m_hMapSecond(-1),
	m_hMapThird(-1),
	m_hMapFourth(-1),
	m_hMapFifth(-1),
	m_hMapChip(-1),
	m_hMapChipSecond(-1),
	m_padInput(0),
	m_playerLeft(0),//�v���C���[����p
	m_playerTop(0),
	m_playerRight(0),
	m_playerBottom(0),
	m_scoreLeft(0),//�X�R�A����p
	m_scoreTop(0),
	m_scoreRight(0),
	m_scoreBottom(0),
	m_attackPlayerLeft(0),
	m_attackPlayerTop(0),
	m_attackPlayerRight(0),
	m_attackPlayerBottom(0),
	m_charaImagePos(0),
	m_charaImageIdlePos(0),
	m_charaImageAttackPos(0),
	m_charaImageDamagePos(0),
	m_charaImageJumpPos(0),
	m_charaImageCrouching(0),
	m_charaImageDeadPosX(0),//�v���C���[�����񂾏ꍇ�̃A�j���V����
	m_charaImageDeadPosY(0),
	m_charaImageLeft(0),//�v���C���[�摜�ł̈ʒu
	m_charaImageTop(0),
	m_charaImageRigth(0),
	m_charaImageBottom(0),
	m_score(0),
	m_count(0),
	m_boxPosX(0),
	m_boxPosY(0),
	m_boxPosBottomX(0),
	m_boxPosBottomY(0),
	m_stagingBoxX(0),
	m_stagingBoxY(0),
	m_stagingBoxBottomX(0),
	m_stagingBoxBottomY(0),
	m_playerHealthBer(0),
	m_playerHealthBerCount(0),
	m_playerHealthSizeX(0),
	m_playerHealthSizeY(0),
	m_boxDropCount(0),
	m_frameCount1(0),//�t���[���J�E���g
	m_frameCount2(0),
	m_frameCount3(0),
	m_frameCountDead(0),//���񂾂炻�̂��ƃJ�E���g
	m_isDeadSound(false),//���񂾍ۂɃT�E���h���Đ�����
	m_deadCount(0),
	m_hierarchy(0),
	m_tip(0),
	m_tempScreenH(0),
	m_gravity(0.0f),
	m_playerColorSize(0.0f),
	m_isRunMove(false),//�A�j���[�V�����֘Abool
	m_isStopMove(false),
	m_isIdleMove(false),
	m_isAttackMove(false),
	m_isDamageMove(false),
	m_isJumpMove(false),
	m_isCrouchingMove(false),
	m_isJumpImagePos(false),//�W�����v�摜�ʒu
	m_playerRad(0),//�v���C���[�̊p�x
	m_isHealthBer(false),
	m_isDead(false),
	m_isReset(false),
	m_isTitle(false),
	m_isGetSword(false),
	m_isAttack(false),
	m_isEnemyDead(false),
	m_isItemDrop(false),
	m_isFloorOne(false),
	m_isLadder(false),
	m_isLadderNow(false),
	m_isInvaliDown(false),
	m_isCharaDirection(false),
	m_isCharaIdleDirection(false),
	m_isStageClear(false),
	m_isStageClearChangeScene(false),//�X�e�[�W���N���A������
	m_isStageDeadChangeScene(false),//���񂾂�
	m_isMenu(false),
	m_isItemTip(false),
	m_isItemDropTip(false),
	m_isUpTip(false),
	m_isGravity(false),
	m_isFall(false),
	m_isMenuDraw(false),//���j���[��ʂ�\�����Ă��邩�ǂ���
	m_playerSize(0.0f, 0.0f),
	m_pos(0.0f, 0.0f),
	m_imagePos(0.0f, 0.0f),
	m_imageBalancePos(0.0f, 0.0f),
	m_underPos(0.0f, 0.0f),
	m_attackPos(0.0f, 0.0f),
	m_attackBottomPos(0.0f, 0.0f),
	m_vec(0.0f, 0.0f),
	m_isDamage(false),
	m_isDamageFallen(false),
	m_getPos(0.0f),
	m_isAttackHit(false),
	m_isDamageCharge(false),
	m_isRushBlink(false),
	m_isRunImagePos(false),
	m_trapHit(0)//�g���b�v�ɓ������Ď���

{
	m_charaImagePos = 0;
	m_func = &PlayerNew::UpdateMove;
	m_pos.x =kPosX; //Game::kScreenWidth / 2; 
	m_pos.y = kPosY; //0;

	//�摜�ʒu���Z�b�g�E�����W
	m_charaImageRigth = 112;
	m_charaImageBottom = 133;
	m_charaImageDeadPosY = m_charaImageBottom * 9;

	m_playerColorSize = 500.0f * 2;

	m_hPlayer = LoadGraph(Image::kPlayerImage);		   //�v���C���[�摜�ǂݍ���
	m_hPlayerIdle = LoadGraph(Image::kPlayerImageIdle);//�v���C���[�A�C�h����ԉ摜�ǂݍ���

	m_hFxJump = LoadSoundMem(Sound::kJump);  //�W�����v�T�E���h�ǂݍ���
	m_hRun    = LoadSoundMem(Sound::kRun);   //�U���T�E���h�ǂݍ���
	m_hAttack = LoadSoundMem(Sound::kAttack);//�U���T�E���h�ǂݍ���
	m_hDead   = LoadSoundMem(Sound::kDead);  //���S�T�E���h�ǂݍ���
	m_hLadder = LoadSoundMem(Sound::kLadder);//��q���T�E���h�ǂݍ���

	int sw, sh, bit;//��ʕ��@��ʍ����@�r�b�g��
	GetScreenState(&sw, &sh, &bit);//���ƍ����擾���Ă���
	m_tempScreenH = MakeScreen(sw, sh);//���H�p���
	assert(m_tempScreenH >= 0);//���Ȃ������炱���Œ�~����

}
//�f�X�g���N�^
PlayerNew::~PlayerNew()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);


	//�T�E���h�������J��
	DeleteSoundMem(m_hFxJump);
	DeleteSoundMem(m_hRun);
	DeleteSoundMem(m_hLadder);
	DeleteSoundMem(m_hAttack);
	DeleteSoundMem(m_hDead);

}
//������
void PlayerNew::Init()
{
	/*
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
	*/
	// �Đ��`�����t�@�C������X�g���[���Đ�����A�ɐݒ�
//SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	//m_hFxJump = LoadSoundMem(FX::kJump);
	// ���ʂ̐ݒ�
	//ChangeVolumeSoundMem(255, m_hFxJump);
}
//�������̊J��
void PlayerNew::End()
{

}
//�A�b�v�f�[�g����
void PlayerNew::Update()
{
	//if (m_isStageClear)//�X�e�[�W�N���A���ǂ���
	//{
	//	m_isStageClearChangeScene = true;
	//}
	//Draw();
	(this->*m_func)();
}
//�`��
void PlayerNew::Draw()
{

	SetDrawBlendMode(DX_BLENDMODE_ADD,30);
	DrawCircleAA(static_cast<int>(m_pos.x) + 20, static_cast<int>(m_pos.y), m_playerColorSize, 32, 0xffffff, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
	if (m_isRunMove || m_isJumpMove)//�����Ă�����ꍇ�̉摜
	{
		DrawRectRotaGraph(m_playerLeft + 15, m_playerTop - 5,
			m_charaImageLeft + m_charaImagePos, m_charaImageTop, m_charaImageRigth, m_charaImageBottom,
			1.5, m_playerRad, m_hPlayer, true, m_isCharaDirection);
		//�摜�̂P�L�������̑傫��
		//��112
		//�c133
	}
	else if (m_isStopMove)//�~�܂��Ă���ꍇ�̉摜
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + static_cast<int>(m_imageBalancePos.x), static_cast<int>(m_imagePos.y + 10.0f),
			m_charaImageIdlePos, 0, 80, 80,
			1.5, m_playerRad, m_hPlayerIdle, true, m_isCharaIdleDirection);
		//�摜�̂P�L�������̑傫��
		//��80
		//�c80
	}

	if (m_isDead)//����ł�����
	{
		DrawRectRotaGraph(Game::kScreenWidth/2,Game::kScreenHeight/2 - 300,
			m_charaImageLeft + m_charaImageDeadPosX, m_charaImageTop + m_charaImageDeadPosY, m_charaImageRigth, m_charaImageBottom,
			20, m_playerRad, m_hPlayer, true, m_isCharaDirection);
	}

#if false	
	
	DrawBox(m_playerLeft, m_playerTop, m_playerRight, m_playerBottom, 0xffffff, false);

#endif
}
//�A�j���[�V�������Đ�
void PlayerNew::Animation()
{
	if (m_isStopMove)//�����Ă��Ȃ��ꍇ
	{
		m_frameCount1++;
		if (m_frameCount1 >= 3)//�摜�����炷
		{
			m_charaImageIdlePos += 80;
			m_frameCount1 = 0;
		}

		if (m_charaImageIdlePos >= 1440)//�摜���E�܂ŕ\�����ꂽ�獶�ɖ߂�
		{
			m_charaImageIdlePos = 0;
		}
	}
	else
	{
		m_frameCount1 = 0;
		m_charaImageIdlePos = 0;
	}

	if (m_isJumpMove)//�W�����v�A�j���[�V����
	{
		
		if (m_isJumpImagePos)//�摜�ʒu���W�����v�ɕύX
		{
			m_charaImageTop = 133 * 3;//�摜�ʒu�����炷
			m_isJumpImagePos = false;
		}

		m_frameCount3++;//�P�t���[���J�E���g
		if (m_frameCount3 >= 2)//�摜�����炷
		{
			m_charaImagePos += 112;//�摜���P�P�Q�s�N�Z��������
			m_frameCount3 = 0;//�J�E���g���Z�b�g
		}

		if (m_charaImagePos >= 1344)//�摜���E�܂ŕ\�����ꂽ�獶�ɖ߂�
		{
			m_charaImagePos = 0;//�摜�ʒu���E�Ƀ��Z�b�g
		}
	}
	else if (m_isRunMove)//���E�ɓ����Ă���ꍇ
	{
		//����摜�ʒu�ɕύX
		if (m_isRunImagePos)
		{
			m_charaImageTop = 133;
			m_isRunImagePos = false;
		}

		m_frameCount2++;
		if (m_frameCount2 >= 2)//�摜�����炷
		{
			m_charaImagePos += 112;
			m_frameCount2 = 0;
		}

		if (m_charaImagePos >= 1344)//�摜���E�܂ŕ\�����ꂽ�獶�ɖ߂�
		{
			m_charaImagePos = 0;
		}
	}
	else//�W�����v�A�j���[�V�������Đ����Ă��Ȃ��ꍇ
	{
		m_frameCount2 = 0;//�g���Ă��Ȃ��Ԃ̓J�E���g���Z�b�g
		m_frameCount3 = 0;//�g���Ă��Ȃ��Ԃ̓J�E���g���Z�b�g
		m_charaImagePos = 0;//�g���Ă��Ȃ��Ԃ͈ʒu�����Z�b�g
	}

}
//�v���C���[�̍s���͈�
void PlayerNew::PlayerPosSet()
{
	if (m_pos.x < 0.0f) m_pos.x = 1.0f;
	if (m_pos.x > Game::kScreenWidth ) m_pos.x = static_cast<float>(Game::kScreenWidth) - 1.0f;
	if (m_pos.y < 0.0f) m_pos.y = 1.0f;
	if (m_pos.y > Game::kScreenHeight) m_pos.y = static_cast<float>(Game::kScreenHeight) - 1.0f;
}
//����S��
void PlayerNew::Operation()
{
	OperationStandard();//��{����
	OperationJump();//�W�����v����
	OperationLadder();//��q�ł̑���
}
//��{����
void PlayerNew::OperationStandard()
{
	m_imagePos = m_pos; //�摜�p�̍��W
	m_isRunMove = false;//�����Ă��Ȃ��ꍇ�͔�\��
	m_isStopMove = true;//�����ĂȂ��ꍇ�͕\��
	//�ړ�
	if (CheckHitKey(KEY_INPUT_RIGHT)|| (m_padInput & PAD_INPUT_RIGHT))//�E
	{
		m_isRunMove = true;            //�����Ă���v���C���[��\��
		m_isRunImagePos = true;//�����Ă���ꍇ�̉摜�ʒu
		m_isCharaIdleDirection = false;//�v���C���[�̌�����ύX
		m_isCharaDirection = true;     //�v���C���[�̌�����ύX
		m_isStopMove = false;          //�����Ă������\��
		m_CountRunSound++;             //�T�E���h�Đ��܂ŃJ�E���g
		//�T�E���h
		if (m_CountRunSound >= 25)
		{
			if (CheckSoundMem(m_hRun) == 0)//���Ă��Ȃ�������
			{
					PlaySoundMem(m_hRun, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
					m_CountRunSound = 0;
			}
		}
		m_pos.x += kMoveSpeed;//���W���ړ�
	}
	if (CheckHitKey(KEY_INPUT_LEFT) || (m_padInput & PAD_INPUT_LEFT))//��
	{
		m_isRunMove = true;           //�����Ă���v���C���[��\��
		m_isRunImagePos = true;//�����Ă���ꍇ�̉摜�ʒu
		m_isCharaIdleDirection = true;//�v���C���[�̌�����ύX
		m_isCharaDirection = false;   //�v���C���[�̌�����ύX
		m_isStopMove = false;         //�����Ă������\��
		m_CountRunSound++;            //�T�E���h�Đ��܂ŃJ�E���g
		//�T�E���h
		if (m_CountRunSound >= 25)
		{
			if (CheckSoundMem(m_hRun) == 0)//���Ă��Ȃ�������
			{
					PlaySoundMem(m_hRun, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
					m_CountRunSound = 0;
			}
		}

		m_pos.x -= kMoveSpeed;//���W���ړ�

	}

	if (!m_isCharaIdleDirection)//�v���C���[�̉摜�̈ʒu�𒲐�����
	{
		m_imageBalancePos.x = + 35.0f;//�摜���E�ɂ��炷
	}
	else
	{
		m_imageBalancePos.x = +0.0f;
	}
}
//�W�����v����
void PlayerNew::OperationJump()////�n�ʂɂ���ꍇ&&��q�ɂ��Ȃ��ꍇ
{
	//�W�����v
	if (Pad::isTrigger(PAD_INPUT_1))//��
	{
		m_isJumpMove = true;//�W�����v�A�j���[�V�����Đ�
		m_isJumpImagePos = true;//�W�����v�摜�ʒu
		PlaySoundMem(m_hFxJump, DX_PLAYTYPE_BACK);
		m_vec.y = 0.0f;
		m_vec.y = kJump;//�W�����v�J�n
	}
}
//��q����
void PlayerNew::OperationLadder()
{
	if (CheckHitKey(KEY_INPUT_UP) || (m_padInput & PAD_INPUT_UP))
	{
		m_isLadderNow = true;//�v���C���[����q�ɐG��
		m_CountLadderSound++;
		if (m_CountLadderSound >= 13)
		{
			PlaySoundMem(m_hLadder, DX_PLAYTYPE_BACK);
			m_CountLadderSound = 0;
		}
		m_pos.y -= kMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) || (m_padInput & PAD_INPUT_DOWN))
	{
		m_isLadderNow = true;//�v���C���[����q�ɐG��
		m_CountLadderSound++;
		if (m_CountLadderSound >= 13)
		{
			PlaySoundMem(m_hLadder, DX_PLAYTYPE_BACK);
			m_CountLadderSound = 0;
		}
		m_pos.y += kMoveSpeed;
	}
	if (m_isLadderNow)//�v���C���[����q�ɐG���Ă���ꍇ
	{
		m_vec.x = 0.0f;//�x�N�g�������Z�b�g
		m_vec.y = 0.0f;
	}
}
void PlayerNew::Score()
{
	//printfDx("%d\n",m_score);
}

//�A�b�v�f�[�g����
void PlayerNew::UpdateMove()
{
	ChangeVolumeSoundMem(SoundVolume::kRun, m_hRun);//���ʒ���
	ChangeVolumeSoundMem(SoundVolume::kJump, m_hFxJump);//���ʒ���
	ChangeVolumeSoundMem(SoundVolume::kLadder, m_hLadder);//���ʒ���
	Score();//�X�R�A�\��

	if (m_playerColorSize > 45.0f)m_playerColorSize -= 10;//45

	Animation();//�A�j���[�V����
	Pad::update();//���͔���
	m_padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);//�W���C�p�b�h�̓��͏�Ԃ𓾂�
	OperationStandard();//����::�ړ�
	
	PlayerPosSet();//�ړ��\�͈�

	if (!m_isFall)//�n�ʂɓ������Ă��Ȃ�������
	{
		//�d��
		m_vec.y += kGravity;

	}

	if (m_isLadder)//��q�ɂ���ꍇ
	{
		OperationLadder();//����::��q�ړ�
	}
	else if (m_isFall)//�n�ʂɓ������Ă�����
	{
		m_vec.y = 0.0f;
		m_pos.y = m_getPos;//�v���C���[�̈ʒu���W
		m_isLadderNow = false;//�v���C���[�͒�q�ɐG���Ă��Ȃ����
		m_isJumpMove = false;//�W�����v�i�����j�A�j���[�V�������Đ����Ȃ�
		OperationJump();//����::�W�����v

	}

	//Animation();//�L�����N�^�[�̃A�j���[�V����
	
	if (m_isStageClear)//�X�e�[�W�N���A���ǂ���
	{
		m_isStageClearChangeScene = true;//�N���A
		DrawBox(Stage2::kGoalX, Stage2::kGoalY,Stage2::kGoalBottomX, Stage2::kGoalBottomY, GetColor(GetRand(255), GetRand(255), GetRand(255)), true);
	}

	if (m_isDamage||m_isDamageFallen||m_isDamageCharge|| m_trapHit == 1)//�U���������������ǂ���
	{
		//PlaySoundMem(m_hDead, DX_PLAYTYPE_NORMAL);//���񂾏ꍇ�̃T�E���h�Đ�

		if (m_isDamage)//�΂̋ʓG
		{
			m_func = &PlayerNew::UpdateDead;//���S�V�[���؂�ւ�
		}
		if (m_isDamageFallen)//�������m�G
		{
			m_func = &PlayerNew::UpdateDead;//���S�V�[���؂�ւ�
		}
		if (m_isDamageCharge && m_isRushBlink)//�����Ă���Ԃɓ�����Ǝ��ʓG
		{
			m_func = &PlayerNew::UpdateDead;//���S�V�[���؂�ւ�
		}
		if (m_trapHit == 1)
		{
			m_func = &PlayerNew::UpdateDead;//���S�V�[���؂�ւ�
		}
	}

	m_pos += m_vec;//�v���C���[�ʒu

	//�v���C���[�̍��W
	m_playerLeft   = static_cast<int>(m_pos.x);
	m_playerTop    = static_cast<int>(m_pos.y);
	m_playerRight  = m_playerLeft + 30;
	m_playerBottom = m_playerTop + 40;

	//�X�R�A������W
	//m_scoreLeft   = m_playerLeft;
	//m_scoreTop    = m_playerBottom;
	//m_scoreRight  = m_scoreLeft;
	//m_scoreBottom = m_scoreTop;
	

}

void PlayerNew::UpdateDead()
{
	//SetDrawScreen(DX_SCREEN_BACK);
	//DrawGraph(100, 100, m_tempScreenH, false);
	//GraphFilter(m_tempScreenH, DX_GRAPH_FILTER_GAUSS, 16, 1400);
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 32);

	m_isDead = true;//���S����œ�����������~

	m_frameCountDead++;

	if(!m_isDeadSound)
	{
		PlaySoundMem(m_hDead, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(SoundVolume::kDead, m_hDead);//���ʒ���
		m_isDeadSound = true;
	}
	if (m_frameCountDead >= 20)//�A�j���[�V������20�t���[����1�R�}�ōĐ�
	{
		m_charaImageDeadPosX += 112;//�摜112�h�b�g���E�ɓ�����
		m_frameCountDead = 0;//�J�E���g�����Z�b�g
	}

	if (m_charaImageDeadPosX >= 112 + 112)//�A�j���[�V�����̍Đ��ɐ�����������
	{
		m_charaImageDeadPosX = 112 + 112;//�\���摜���Œ�
		m_deadCount++;//�V�[����؂�ւ���܂ŃJ�E���g
	}

	if (m_deadCount == 60)//60�t���[���Q�[�����~
	{
		m_isStageDeadChangeScene = true;//�V�[����؂�ւ���
	
		m_deadCount = 0;//�J�E���g���Z�b�g
	}
}
