#include <Dxlib.h>
#include "game.h"
#include "Image.h"
#include "Pad.h"
#include "SceneGameOver.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMain2.h"
#include "TitleCursorGame.h"
#include "GameSceneCollision.h"

SceneGameOver::SceneGameOver():
	m_hSoundSelect(-1),//�I�����̃T�E���h
	m_hSoundSelect2(-1),//�I�����̃T�E���h
	m_hMusicBgm(-1),//BGM�p�n���h��
	m_soundCount(0),//�T�E���h�����܂ł̃J�E���g
	m_soundCount2(0),
	m_color1(0),//�I����ʂ̐F
	m_color2(0),
	m_color3(0),
	m_pCursor(nullptr),//�J�[�\���\���p
	m_pCursorCollision(nullptr)//�J�[�\�������蔻��
{
	m_pCursor = new TitleCursorGame;
	m_pCursorCollision = new GameSceneCollision;
}

SceneGameOver::~SceneGameOver()
{
	delete m_pCursor;
	delete m_pCursorCollision;

	//�T�E���h�폜
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
}

void SceneGameOver::Init()
{
	//�T�E���h��ǂݍ���
	m_hSoundSelect = LoadSoundMem(Sound::kSelect);
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);

	m_hMusicBgm = LoadSoundMem(Sound::kBgmDead);
}

void SceneGameOver::End()
{
	StopSoundFile();//�Đ����̃T�E���h���~�߂�
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneGameOver::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	Pad::update();
	m_pCursor->Update();//�J�[�\���̍X�V����
	m_pCursorCollision->Update();//�J�[�\���ƑI��͈͂̓����蔻��

	//�J�[�\�����������Ă��Ȃ��ꍇ�̕����w�i�̐F
	m_color2 = Color::kWhite;
	m_color3 = Color::kWhite;

	if (m_pCursorCollision->CollsionStage1())//�J�[�\���ƑI��͈͂ɓ������Ă�����
	{
		m_soundCount++;
		m_color2 = Color::kRed;//�J�[�\�����������Ă���ꍇ�̕����w�i�̐F
		if (m_soundCount == 1)
		{
			PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_2)//X�{�^��
		{
			return(new SceneMain2);//�����X�e�[�W���J��Ԃ�
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
			PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
		}
		if (padState & PAD_INPUT_2)//X�{�^��
		{
			return(new SceneTitle);//�^�C�g����ʂɈړ�
		}
	}
	else
	{
		m_soundCount2 = 0;
	}

	//�T�E���h
	if (CheckSoundMem(m_hMusicBgm) == 0)//���Ă��Ȃ�������
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(100, m_hMusicBgm);//���ʒ���
	}

	if (Pad::isTrigger(PAD_INPUT_2))//X�{�^��
	{
		PlaySoundMem(m_hSoundSelect, DX_PLAYTYPE_BACK);//�����Ă��鉹���Đ�
	}

	return this;
}

void SceneGameOver::Draw()
{

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0x00ffff, true);//��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0xffffff, false);//�g�g��

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//�F�𔖂�����
	//DrawBox(SceneSelect::kSelectLeft, SceneSelect::kSelectTop, SceneSelect::kSelectRight, SceneSelect::kSelectBottom, m_color1, true);
	DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�F��߂�

	DrawString(SceneSelect::kSelectLeft - 70, SceneSelect::kSelectTop + 5, "�Ԃ�����͍������ɓ���鎖�͂ł��Ȃ�����...", Color::kRed);
	DrawString(SceneSelect::kSelectLeft2 + 85, SceneSelect::kSelectTop2 + 5, "������x", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft3 + 65, SceneSelect::kSelectTop3 + 5, "�^�C�g���ɖ߂�", Color::kBlue);
	printfDx("%d\n", stageNum);
	stageNum++;
	m_pCursor->Draw();
}
