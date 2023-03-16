#include <Dxlib.h>
#include "game.h"
#include "Image.h"
#include "Pad.h"
#include "SelectMenu.h"
#include "TitleCursor.h"
#include "GameSceneCollision.h"


SelectMenu::SelectMenu():
	m_hSoundSelect(-1),//�{�^���������ꍇ�̃T�E���h
	m_hSoundSelect2(-1),//�{�^���������ꍇ�̃T�E���h
	m_frameCount(0),//���j���[��ʂ��J�������Ƀf�B���C������
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
	m_soundCount2(0),//�T�E���h�Đ��܂ł̃J�E���g
	m_soundCount3(0),
	m_isMenu      (false),//���j���[���J���Ă��邩�ǂ���
	m_isMoveStop  (false),//�X���C�h�������邩�ǂ���
	m_isSceneStage(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneRetry(false),
	m_isSceneTitle(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneDead (false),//���񂾂�V�[���؂�ւ�
	m_pCursor(nullptr),
	m_pCursorCollision(nullptr)
{
	m_pCursor = new TitleCursor;
	m_pCursorCollision = new GameSceneCollision;

	m_hSoundSelect = LoadSoundMem(Sound::kSelect);//�{�^���������ꍇ�̃T�E���h��ǂݍ���
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);//�{�^���������ꍇ�̃T�E���h��ǂݍ���
}

SelectMenu::~SelectMenu()
{
	delete m_pCursor;
	delete m_pCursorCollision;

	//�T�E���h�폜
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
}

void SelectMenu::Init()
{

}

void SelectMenu::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	m_pCursor->GetMenu(m_isMenu);
	m_pCursor->Update();//�J�[�\���\��
	if (m_isMenu)//���j���[�\�����Ă���ꍇ
	{
		//�ォ�牺�Ƀ��j���[���X���C�h
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
					if (m_Sring_Y <= SceneSelect::kSelectTop) m_Sring_Y += SceneSelect::kSlideSpeed;
					if (m_Sring2_Y <= SceneSelect::kSelectTop2) m_Sring2_Y += SceneSelect::kSlideSpeed;
					if (m_Sring3_Y <= SceneSelect::kSelectTop3) m_Sring3_Y += SceneSelect::kSlideSpeed;
				}
			}
		}

		m_pCursorCollision->Update();

		//�J�[�\�����������Ă��Ȃ��ꍇ�̕����w�i�̐F
		m_color1 = Color::kWhite;
		m_color2 = Color::kWhite;
		m_color3 = Color::kWhite;

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

		m_frameCount++;
		if (m_frameCount >= 30)
		{
			if (padState & PAD_INPUT_10)//���j���[�����
			{
				m_isMoveStop = true;//����X���C�h�J�n
			}
		}
	}
	else
	{
		m_frameCount++;
		if (m_frameCount >= 30)
		{
			if (padState & PAD_INPUT_10)//���j���[���J��
			{
				m_isMenu = true;
				m_frameCount = 0;
				//���������j���[�\���ʒu
				m_backGround_Y = 0;//�w�i��DrawBox�ʒu�c���W
				m_SringBox_Y = 0;//�����g�͈͏c���W
				m_SringBox2_Y = 0;//�����g�͈͏c���W
				m_SringBox3_Y = 0;//�����g�͈͏c���W
				m_Sring_Y = 0;//�����c���W
				m_Sring2_Y = 0;//�����c���W
				m_Sring3_Y = 0;//�����c���W
			}
		}
	}

	if (m_isMoveStop)//���j���[�����O�ɉ��ɃX���C�h������
	{
		if (m_backGround_Y <= Game::kScreenHeight) m_backGround_Y += SceneSelect::kSlideSpeed;
		else
		{
			//������
			m_isMenu = false;//���j���[��ʂ��\��
			m_isMoveStop = false;//�X���C�h����
			m_frameCount = 0;

		}
		if (m_SringBox_Y <= Game::kScreenHeight) m_SringBox_Y += SceneSelect::kSlideSpeed;
		if (m_SringBox2_Y <= Game::kScreenHeight) m_SringBox2_Y += SceneSelect::kSlideSpeed;
		if (m_SringBox3_Y <= Game::kScreenHeight) m_SringBox3_Y += SceneSelect::kSlideSpeed;
		if (m_Sring_Y <= Game::kScreenHeight) m_Sring_Y += SceneSelect::kSlideSpeed;
		if (m_Sring2_Y <= Game::kScreenHeight) m_Sring2_Y += SceneSelect::kSlideSpeed;
		if (m_Sring3_Y <= Game::kScreenHeight) m_Sring3_Y += SceneSelect::kSlideSpeed;
	}
}

void SelectMenu::Draw()
{
	//�w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0x00ffff, true);//��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0xffffff, false);//�g�g��
	//�����w�i
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//�F�𔖂�����
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�F��߂�
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, Color::kThinBlue, false);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, Color::kThinBlue, false);
	
	DrawString(SceneSelect::kSelectLeft2 + 80, m_Sring2_Y - 35, "���X�^�[�g", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft3 + 65, m_Sring3_Y - 35, "�^�C�g���ɖ߂�", 0x0000ff);

	//m_pCursor->Draw();//�J�[�\���\��
	m_pCursorCollision->Draw();
}