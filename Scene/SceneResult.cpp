#include <DxLib.h>
#include "Image.h"
#include "game.h"
#include "Pad.h"
#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMain.h"
#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneMain4.h"
#include "TitleCursorGame.h"
#include "GameSceneCollision.h"
#include "Fireworks.h"

namespace
{

}

SceneResult::SceneResult():
	m_hSoundSelect(-1),//�I�����̃T�E���h
	m_hSoundSelect1(-1),//�I�����̃T�E���h
	m_hSoundSelect2(-1),//�I�����̃T�E���h
	m_hMusicBgm(-1),//BGM�p�n���h��
	m_soundCount(0),//�T�E���h�����܂ł̃J�E���g
	m_soundCount1(0),//�T�E���h�����܂ł̃J�E���g
	m_soundCount2(0),
	m_color1(0),//�I����ʂ̐F
	m_color2(0),
	m_color3(0),
	m_pCursor(nullptr),
	m_pCursorCollision(nullptr),
	m_pFireworks(nullptr)
{
	m_pCursor = new TitleCursorGame;
	m_pCursorCollision = new GameSceneCollision;
	m_pFireworks = new Fireworks;
}

SceneResult::~SceneResult()
{
	delete m_pCursor;
	delete m_pCursorCollision;
	delete m_pFireworks;

	//�T�E���h�폜
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
}

void SceneResult::Init()
{
	//�T�E���h��ǂݍ���
	m_hSoundSelect = LoadSoundMem(Sound::kSelect);
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);

	m_hMusicBgm = LoadSoundMem(Sound::kBgmClear);
}

void SceneResult::End()
{
	StopSoundFile();//�Đ����̃T�E���h���~�߂�
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneResult::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	Pad::update();
	m_pCursor->Update();
	m_pCursorCollision->Update();
	m_pFireworks->Update();//�ԉ΍X�V����

	//�J�[�\�����������Ă��Ȃ��ꍇ�̕����w�i�̐F
	m_color1 = Color::kWhite;
	m_color2 = Color::kWhite;
	m_color3 = Color::kWhite;
	if (m_pCursorCollision->CollsionDemo())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount1++;
		m_color1 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (m_soundCount1 == 1)
		{
			PlaySoundMem(m_hSoundSelect2, PAD_INPUT_10);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_1)//X�{�^��
		{
			return(new SceneMain4);//�����X�e�[�W���J��Ԃ�
		}
	}

	if (m_pCursorCollision->CollsionStage1())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount++;
		m_color2 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (m_soundCount == 1)
		{
			PlaySoundMem(m_hSoundSelect2, PAD_INPUT_10);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_1)//X�{�^��
		{
			return(new SceneMain3);//�����X�e�[�W���J��Ԃ�
		}
	}
	else
	{
		m_soundCount = 0;
	}
	if (m_pCursorCollision->CollsionEnd())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount2++;
		m_color3 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (m_soundCount2 == 1)
		{
			PlaySoundMem(m_hSoundSelect2, PAD_INPUT_10);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_1)//X�{�^��
		{
			return(new SceneTitle);//�^�C�g����ʂɈړ�
		}
	}
	else
	{
		m_soundCount2 = 0;
	}

	ChangeVolumeSoundMem(SoundVolume::Button, m_hSoundSelect);//���ʒ���
	ChangeVolumeSoundMem(SoundVolume::Select, m_hSoundSelect2);//���ʒ���
	//�T�E���h
	if (CheckSoundMem(m_hMusicBgm) == 0)//���Ă��Ȃ�������
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(SoundVolume::BGM, m_hMusicBgm);//���ʒ���
	}

	if (Pad::isTrigger(PAD_INPUT_1))//X�{�^��
	{
		PlaySoundMem(m_hSoundSelect, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
	}

	return this;
}

void SceneResult::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0xf0e68c, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	m_pFireworks->Draw();//�ԉ΍X�V����

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0x00ffff, true);//��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0xffffff, false);//�g�g��

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//�F�𔖂�����
	DrawBox(SceneSelect::kSelectLeft, SceneSelect::kSelectTop, SceneSelect::kSelectRight, SceneSelect::kSelectBottom, m_color1, true);
	DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�F��߂�

	DrawString(SceneSelect::kSelectLeft + 75, SceneSelect::kSelectTop - 70, "�Q�[���N���A", Color::kYellow);
	DrawString(SceneSelect::kSelectLeft + 70, SceneSelect::kSelectTop + 5, "���̃X�e�[�W", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft2 + 85, SceneSelect::kSelectTop2 + 5, "������x", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft3 + 60, SceneSelect::kSelectTop3 + 5, "�^�C�g���ɖ߂�", Color::kBlue);

	m_pCursor->Draw();
}
