#include "SceneTitle.h"
#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneMain4.h"
#include "SceneResult2.h"
#include "SceneGameOver.h"
#include "SceneGameOver2.h"
#include "SceneGameOver3.h"
#include "TitleCursor.h"
#include "TitleCollision.h"
#include <DxLib.h>
#include "game.h"
#include "Image.h"
#include <Pad.h>
#include <cassert>

namespace
{
	constexpr int kAnimationFrame = 3;
	constexpr int kCharaImageRightPos = 112; //�E�ړ�

	constexpr int kColorWhite = 0x000000;//���F
	constexpr int kColorRed = 0xff0000;//�ԐF
}

SceneTitle::SceneTitle() :
	m_hImagePlayer(-1),
	m_hImageMap(-1),
	m_charaImagePos(0),
	m_hMusicBgm(-1),//�T�E���hBGM
	m_hButtonUi(-1),
	m_hTitleMainImage(-1),
	m_hSoundSelect(-1),
	m_hSoundSelect2(-1),
	m_colorA(0),
	m_colorX(0),
	m_frameCount(0),
	m_soundCount1(0),
	m_soundCount2(0),
	m_soundCount3(0),
	m_sceneChangeCountDemo(0),
	m_sceneChangeCountStage1(0),
	m_sceneChangeCountEnd(0),
	m_buttonALeft(0),
	m_buttonATop(0),
	m_buttonARigth(0),
	m_buttonABottom(0),
	m_buttonXLeft(0),
	m_buttonXTop(0),
	m_buttonXRigth(0),
	m_buttonXBottom(0),
	m_fadeValue(0.0f),
	m_imagePos(0.0f, 0.0f),
	m_isFadeIn(false),//�t�F�C�h�C���������ǂ���
	m_isFadeOut(false),//�t�F�C�h�A�E�g�������ǂ���
	m_isSceneStage(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneEnd(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneFocus1(false),
	m_isSceneFocus2(false),
	m_isSceneFocus3(false),
	m_pCursor(nullptr),
	m_pCollsion(nullptr),
	m_hSoundSnail (-1)
{
	m_pCursor = new TitleCursor;
	m_pCollsion = new TitleCollision;

	m_hSoundSnail = LoadSoundMem(Sound::kSnail);//�����ނ�T�E���h
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_hImagePlayer);
	DeleteGraph(m_hImageMap);
	DeleteGraph(m_hButtonUi);
	DeleteGraph(m_hTitleMainImage);

	StopSoundFile();//�Đ����̃T�E���h���~�߂�
	DeleteSoundMem(m_hMusicBgm);
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
	DeleteSoundMem(m_hSoundSnail);


}

void SceneTitle::Init()
{

	m_hImagePlayer = LoadGraph(Image::kPlayerImage);
	m_hImageMap    = LoadGraph(Image::kMapFirst);
	m_hButtonUi = LoadGraph(UI::kButton);
	m_hTitleMainImage = LoadGraph(Image::kMapTitleMain);
	m_hMusicBgm = LoadSoundMem(Sound::kBgmTitle);
	m_hSoundSelect = LoadSoundMem(Sound::kSelect);
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);


	assert(m_hImagePlayer > -1);
	//assert(m_hImageMap > -1);
	assert(m_hButtonUi > -1);
	assert(m_hMusicBgm > -1);
	assert(m_hSoundSelect > -1);
	assert(m_hSoundSelect2 > -1);


	m_imagePos.x   = Game::kScreenWidth / 2.0f;
	m_imagePos.y   = Game::kScreenHeight / 2.0f - 250.0f;

	//A�{�^�������Ă��Ȃ���ԁi�摜�j
	m_buttonALeft = 16 + 16 + 16;
	m_buttonATop = 16 + 16;
	m_buttonARigth = 16;
	m_buttonABottom = 16 ;

	//X�{�^�������Ă��Ȃ���ԁi�摜�j
	m_buttonXLeft = 16 + 16 + 16;
	m_buttonXTop = 16 + 16 + 16;
	m_buttonXRigth = 16;
	m_buttonXBottom = 16;

	m_colorA = kColorWhite;
	m_colorX = kColorWhite;

	m_fadeValue = 255.0f;
}
void SceneTitle::End()
{
	delete m_pCollsion;
	delete m_pCursor;
}

SceneBase* SceneTitle::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (!m_isFadeIn)FadeIn();//�t�F�C�h�C��
	
	if (m_isFadeIn)//��ʂ��ő�l���邭�Ȃ�����
	{
		m_pCursor->Update();
		m_pCollsion->Update();
		Pad::update();
		if (padState & PAD_INPUT_1)//A�{�^���������ꍇ
		{
			if (Pad::isTrigger(PAD_INPUT_1))//A�{�^���������ꍇ
			{
				PlaySoundMem(m_hSoundSelect, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
				m_buttonXLeft = 16 + 16 + 16 + 16 + 16;//�摜�\���ʒu��ύX
				m_colorX = kColorRed;//�����̐F��ύX
			}
		}
		else
		{
			m_buttonXLeft = 16 + 16 + 16;//�摜�\���ʒu��ύX
			m_colorX = kColorWhite;//�����̐F��ύX
		}

		if (m_pCollsion->CollsionStage1())//�V�[���؂�ւ�::�Q�[���v���C
		{
			m_sceneChangeCountStage1 = 300;
			m_soundCount2++;
			if (m_soundCount2 == 1)
			{
				PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
			}
			m_isSceneFocus2 = true;//�t�H�[�J�X�����킹���ꍇ
			if (padState & PAD_INPUT_1)//A�{�^���������ꍇ
			{
				m_isSceneStage = true;//�V�[����؂�ւ�	
			}
		}
		else
		{	
			m_sceneChangeCountStage1 = 0;
			m_soundCount2 = 0;
			m_isSceneFocus2 = false;//�t�H�[�J�X���O�����ꍇ
		}

		if (m_pCollsion->CollsionEnd())//�V�[���؂�ւ�::�f�X�N�g�b�v�ɖ߂�
		{
			m_sceneChangeCountEnd = 300;
			m_soundCount3++;
			if (m_soundCount3 == 1)
			{
				PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
			}
			m_isSceneFocus3 = true;//�t�H�[�J�X�����킹���ꍇ
			if (padState & PAD_INPUT_1)
			{
				m_isSceneEnd = true;//�V�[����؂�ւ�
			}
		}
		else
		{
			m_sceneChangeCountEnd = 0;
			m_soundCount3 = 0;
			m_isSceneFocus3 = false;//�t�H�[�J�X���O�����ꍇ
		}

		//�E�Ɉړ��A�j���[�V����
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImagePos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 1344)
		{
			m_charaImagePos = 0;
		}
		
	}
	ChangeVolumeSoundMem(SoundVolume::Button, m_hSoundSelect);//���ʒ���
	ChangeVolumeSoundMem(SoundVolume::Select, m_hSoundSelect2);//���ʒ���
	//�T�E���h
	if (CheckSoundMem(m_hMusicBgm) == 0)//���Ă��Ȃ�������
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(SoundVolume::BGM, m_hMusicBgm);//���ʒ���
	}

	if (m_isSceneEnd)//�I����������
	{
		FadeOut();
		if (m_isFadeOut)
		{
			DxLib_End();//�Q�[���I��
		}
	}
	else if (m_isSceneStage)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain2);//1�X�e�[�W�؂�ւ�
		}
	}

	return this;
}

void SceneTitle::Draw()
{
	//�}�b�v��w�i�ɕ`��
	DrawExtendGraph(0, 0, Game::kScreenWidth,Game::kScreenHeight, m_hTitleMainImage, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 30);//����
	DrawBox(0 + 100,0 + 100, Game::kScreenWidth  - 100,Game::kScreenHeight  - 100, Color::kWhite, true);//�w�i
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawRectRotaGraph(static_cast<int>(m_imagePos.x), static_cast<int>(m_imagePos.y),
		m_charaImagePos, 133, 112, 133, 18, 0, m_hImagePlayer, true, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//�F�𔖂�����
	
	//�X�e�[�W1
	DrawBox(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, TitleMenu::kSelectionBottom2X, TitleMenu::kSelectionBottom2Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, TitleMenu::kSelectionBottom2X + m_sceneChangeCountStage1 - 300
		, TitleMenu::kSelectionBottom2Y, 0xff0000, true);
	//�f�X�N�g�b�v�ɖ߂�
	DrawBox(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, TitleMenu::kSelectionBottom3X, TitleMenu::kSelectionBottom3Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, TitleMenu::kSelectionBottom3X + m_sceneChangeCountEnd - 300
		, TitleMenu::kSelectionBottom3Y, 0xff0000, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�F��߂�

	//�g�g�݁i�F�j
	//DrawBox(TitleMenu::kSelection1X - 1, TitleMenu::kSelection1Y - 1, TitleMenu::kSelectionBottom1X + 1, TitleMenu::kSelectionBottom1Y + 1, 0x0000ff, false);
	DrawBox(TitleMenu::kSelection2X -1, TitleMenu::kSelection2Y - 1, TitleMenu::kSelectionBottom2X + 1, TitleMenu::kSelectionBottom2Y + 1, 0x0000ff, false);
	DrawBox(TitleMenu::kSelection3X - 1, TitleMenu::kSelection3Y - 1, TitleMenu::kSelectionBottom3X + 1, TitleMenu::kSelectionBottom3Y + 1, 0x0000ff, false);

	if (m_isSceneFocus2)
	{

		DrawBox(TitleMenu::kSelection2X - 1, TitleMenu::kSelection2Y - 1, TitleMenu::kSelectionBottom2X + 1, TitleMenu::kSelectionBottom2Y + 1, 0xff00ff, false);
	}
	if (m_isSceneFocus3)
	{
		DrawBox(TitleMenu::kSelection3X - 1, TitleMenu::kSelection3Y - 1, TitleMenu::kSelectionBottom3X + 1, TitleMenu::kSelectionBottom3Y + 1, 0xff00ff, false);
	}

	//����
	DrawString(TitleMenu::kSelection2X + 85, TitleMenu::kSelection2Y + 5, "�Q�[���X�^�[�g", 0x0000ff);
	DrawString(TitleMenu::kSelection3X + 65, TitleMenu::kSelection3Y + 15, "�f�X�N�g�b�v�ɖ߂�", 0x0000ff);
	SetFontSize(128 + 32 + 32);//�����T�C�Y�ύX//�^�C�g��
	//ChangeFont(Game::kFontNameJp);//�t�H���g�ύX
	DrawString(Game::kScreenWidth /2 - 400 + 5, Game::kScreenHeight / 2 - 200 + 5 , "�Ԃ�����̍���", 0x00000);//�^�C�g��
	DrawString(Game::kScreenWidth /2 - 400, Game::kScreenHeight/2 - 200, "�Ԃ�����̍���", 0xffff00);//�^�C�g��
	SetFontSize(32);//�����T�C�X�ύX

	//A
	DrawRectRotaGraph(230, 300,
		m_buttonXLeft, m_buttonXTop, m_buttonXRigth, m_buttonXBottom, 5, 0, m_hButtonUi, true, false);
	DrawString(230 + 50, 290, "�W�����v & ����", m_colorX);

	//�J�[�\���̈ʒu��`��
	m_pCursor->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneTitle::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//��ʂ��ő�ɖ��邭
	}
}

void SceneTitle::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//��ʂ��ő�ɈÂ�
	}
}





