#include <Dxlib.h>
#include "game.h"
#include "image.h"
#include "SlideSelect.h"
#include "TitleCursorGame.h"
#include "GameSceneCollision.h"
#include "Pad.h"

SlideSelect::SlideSelect():
	m_hSoundSelect(-1),//�{�^���������ꍇ�̃T�E���h
	m_hSoundSelect2(-1),//�{�^���������ꍇ�̃T�E���h
	m_backGround_Y(0),//�w�i��DrawBox�ʒu
	m_SringBox_Y(0),//�����g�͈�
	m_SringBox2_Y(0),//�����g�͈�
	m_SringBox3_Y(0),//�����g�͈�
	m_Sring_Y(0),//�����c���W
	m_Sring2_Y(0),//�����c���W
	m_Sring3_Y(0),//�����c���W
	m_color1(0),//�I����ʂ̐F
	m_color2(0),
	m_color3(0),
	m_soundCount(0),//�T�E���h�Đ��܂ł̃J�E���g
	m_soundCount2(0),//�T�E���h�Đ��܂ł̃J�E���g
	m_soundCount3(0),
	m_isMoveStop(false),//�X���C�h�������邩�ǂ���
	m_isSceneStage(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneRetry(false),
	m_isSceneTitle(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneDead(false),//���񂾂�V�[���؂�ւ�
	m_pCursor(nullptr),
	m_pCursorCollision(nullptr)
{

	m_isMoveStop = true;

	m_hSoundSelect = LoadSoundMem(Sound::kSelect);//�{�^���������ꍇ�̃T�E���h��ǂݍ���
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);//�{�^���������ꍇ�̃T�E���h��ǂݍ���

	m_pCursor = new TitleCursorGame;
	m_pCursorCollision = new GameSceneCollision;
}

SlideSelect::~SlideSelect()
{
	delete m_pCursorCollision;

	//�T�E���h�폜
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
}

void SlideSelect::Update()
{

}

void SlideSelect::Draw()
{
	//DrawBox(SceneSelect::kSelectLeft, SceneSelect::kSelectTop, SceneSelect::kSelectRight, SceneSelect::kSelectBottom, m_color1, true);
	//DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, m_color1, true);
	//DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, m_color1, true);

	//�w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0x00ffff, true);//��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0xffffff, false);//�g�g��
	//�����w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//�F�𔖂�����
	DrawBox(SceneSelect::kSelectLeft,  m_SringBox_Y,  SceneSelect::kSelectRight,  m_SringBox_Y  + 30, m_color1, true);
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�F��߂�
	DrawBox(SceneSelect::kSelectLeft, m_SringBox_Y, SceneSelect::kSelectRight, m_SringBox_Y + 30,	  Color::kThinBlue, false);
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, Color::kThinBlue, false);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, Color::kThinBlue, false);
	//����
	DrawString(SceneSelect::kSelectLeft + 70,  m_Sring_Y + 5, "���̃X�e�[�W", 0x0000ff);//+5
	DrawString(SceneSelect::kSelectLeft2 + 85,m_Sring2_Y - 35, "������x", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft3 + 60, m_Sring3_Y - 35, "�^�C�g���ɖ߂�", 0x0000ff);



	//�����ɃX���C�h�|�C���^
	m_pCursor->Draw();
}

void SlideSelect::Slider()
{
	if (m_backGround_Y <= 300) m_backGround_Y += SceneSelect::kSlideSpeed;
	else
	{
		if (m_SringBox_Y <= SceneSelect::kSelectTop - 10) m_SringBox_Y += SceneSelect::kSlideSpeed;
		else
		{
			if (m_SringBox2_Y <= SceneSelect::kSelectTop2 - 10) m_SringBox2_Y += SceneSelect::kSlideSpeed;
			else
			{
				if (m_SringBox3_Y <= SceneSelect::kSelectTop3 - 10) m_SringBox3_Y += SceneSelect::kSlideSpeed;
				if (m_Sring_Y     <= SceneSelect::kSelectTop      ) m_Sring_Y     += SceneSelect::kSlideSpeed;
				if (m_Sring2_Y    <= SceneSelect::kSelectTop2     ) m_Sring2_Y    += SceneSelect::kSlideSpeed;
				if (m_Sring3_Y    <= SceneSelect::kSelectTop3     ) m_Sring3_Y    += SceneSelect::kSlideSpeed;
			}
		}
	}
}

void SlideSelect::Collsion()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	m_pCursor->Update();//�J�[�\���̍X�V����
	m_pCursorCollision->Update();//�J�[�\���ƑI��͈͂̓����蔻��

	//�J�[�\�����������Ă��Ȃ��ꍇ�̕����w�i�̐F
	m_color1 = Color::kWhite;
	m_color2 = Color::kWhite;
	m_color3 = Color::kWhite;


	if (m_pCursorCollision->CollsionDemo())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount++;//�T�E���h�Đ��܂ł̃J�E���g
		if (m_soundCount == 1)
		{
			PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
		}
		m_color1 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (padState & PAD_INPUT_2)//X�{�^��
		{
			m_isSceneStage = true;
		}
	}
	else//�J�[�\�����I��͈͊O��������
	{
		m_soundCount = 0;//�T�E���h�J�E���g�����Z�b�g
	}
	if (m_pCursorCollision->CollsionStage1())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount2++;//�T�E���h�Đ��܂ł̃J�E���g
		m_color2 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (m_soundCount2 == 1)
		{
			PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_2)//X�{�^��
		{
			m_isSceneRetry = true;
		}
	}
	else//�J�[�\�����I��͈͊O��������
	{
		m_soundCount2 = 0;//�T�E���h�J�E���g�����Z�b�g
	}
	if (m_pCursorCollision->CollsionEnd())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount3++;//�T�E���h�Đ��܂ł̃J�E���g
		m_color3 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (m_soundCount3 == 1)
		{
			PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_2)//X�{�^��
		{
			m_isSceneTitle = true;
		}
	}
	else//�J�[�\�����I��͈͊O��������
	{
		m_soundCount3 = 0;//�T�E���h�J�E���g�����Z�b�g
	}
	Pad::update();
	if (Pad::isTrigger(PAD_INPUT_2))//X�{�^��
	{
		PlaySoundMem(m_hSoundSelect, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
	}

}
