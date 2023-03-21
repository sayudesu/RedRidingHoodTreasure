#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver.h"
#include "DrawMapStage1.h"
#include "PlayerNew.h"
#include "Collision.h"
#include "SelectMenu.h"
#include "Fireworks.h"
#include "SlideSelect.h"
#include "Chest.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>
#include "Pad.h"

SceneMain2::SceneMain2() :
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hFadeImage(-1),
	m_hCopy(-1),
	m_hMusicBgm(-1),//BGM�p�n���h��
	m_stageCount(0),//�X�e�[�W���n�܂�܂ł̃J�E���g
	m_stageCountSeconds(0),
	m_fadeValue(0.0f),
	m_isStageCount(false),
	m_isFadeIn(false),//�t�F�C�h�C���������ǂ���
	m_isFadeOut(false),//�t�F�C�h�A�E�g�������ǂ���
	m_isSceneStage(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneRetry(false),
	m_isSceneTitle(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneDead(false),//���񂾂�V�[���؂�ւ�
	m_isGameClear(false),
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr),
	m_pMenu(nullptr),
	m_pSlidSelect(nullptr),
	m_pFireworks(nullptr),
	m_pChest(nullptr)
{
	m_pStage     = new DrawMapStage1;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision;
	m_pMenu      = new SelectMenu;
	m_pSlidSelect = new SlideSelect;
	m_pFireworks = new Fireworks;
	m_pChest = new Chest;
}

SceneMain2::~SceneMain2()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
	delete m_pSlidSelect;
	delete m_pFireworks;
	delete m_pChest;

}

void SceneMain2::Init()
{
	m_pCollision->Init();
	m_pStage->Init();
	m_pFireworks->Init();
	m_hMusicBgm = LoadSoundMem(Sound::kBgmStage);
	m_hCopy = LoadGraph(Image::kCountTime1);
	m_hFadeImage = LoadGraph(Image::kFade);//�t�F�C�h����

	//�v���C���[�摜
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

	m_stageCount = 60 * 3;//�X�e�[�W�J�n�J�E���g
	m_fadeValue = 255.0f;//��ʂ̐F

}

void SceneMain2::End()
{
	m_pPlayer->End();
	m_pStage->End();
	m_pFireworks->End();

	//�v���C���[�摜
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hCopy);

	StopSoundFile();//�Đ����̃T�E���h���~�߂�
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneMain2::Update()
{
	//�Q�[���N���A��̑I�����󂯎��
	GetSceneStage(m_pSlidSelect->SetSceneStage());
	GetSceneRetry(m_pSlidSelect->SetSceneRetry());
	GetSceneTitle(m_pSlidSelect->SetSceneTitle());
	GetSceneDead(m_pSlidSelect->SetSceneDead());

	GetMenuRetry(m_pMenu->SetSceneRetry());
	GetMenuTitle(m_pMenu->SetSceneTitle());

	if (!m_isFadeIn)FadeIn();//�t�F�C�h�C��
	if (m_stageCount == 60 * 3)
	{
		m_stageCountSeconds = 3;
	}
	if (m_stageCount == 60 * 2)
	{
		m_stageCountSeconds = 2;
	}
	if (m_stageCount == 60)
	{
		m_stageCountSeconds = 1;
	}

	if (m_isFadeIn)//��ʂ��ő�l���邭�Ȃ�����
	{
		if (m_stageCount == 0)
		{
			m_isStageCount = false;
			if (!m_isGameClear)//�N���A���Ă��Ȃ��ꍇ�͏�������
			{
				if (!m_pMenu->m_isMenu)//���j���[���J���Ă��Ȃ��ꍇ
				{
					m_pCollision->Update();
				}
			}
		}
		else
		{
			m_stageCount--;
			m_isStageCount = true;
		}

		m_pMenu->Update();


		if (m_pCollision->m_isStageClear)//�X�e�[�W���N���A�����ꍇ
		{
			m_isGameClear = true;
			//return(new SceneMain3);
		}

		if (m_pCollision->m_isDeadSceneChange)//�G��g���b�v�ɓ������Ď��񂾏ꍇ
		{
			//printfDx("�G��g���b�v�ɓ������Ď���");
			m_isSceneDead = true;//����
		}

		if (m_isGameClear)//�Q�[�����N���A������
		{
			//�����ɃJ�[�\�����菈��
			m_pSlidSelect->Collsion();
		}
	}
	
	//�T�E���h
	if (CheckSoundMem(m_hMusicBgm) == 0)//���Ă��Ȃ�������
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(SoundVolume::BGM, m_hMusicBgm);//���ʒ���
	}

	if (m_pMenu->SetSceneTitle() || m_isSceneTitle)//�I����������
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneTitle);//�^�C�g����ʂɈړ�
		}
	}
	else if (m_isSceneStage)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain3);//�V�����X�e�[�W�Ɉړ�
		}
	}
	else if (m_pMenu->SetSceneRetry() || m_isSceneRetry)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain2);//�����X�e�[�W���J��Ԃ�
		}
	}
	else if (m_isSceneDead)//���񂾏ꍇ�̃V�[���؂�ւ�
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneGameOver);
		}
	}

	if (CheckHitKey(KEY_INPUT_Z))//�ً}���^�C�g���ɖ߂�
	{
		return(new SceneTitle);
	}


	return this;
}

void SceneMain2::Draw()
{
	m_pStage->Draw();//�X�e�[�W��`��
	//�v���C���[�A�G�l�~�[��\��
	m_pCollision->Draw();
	if (m_pMenu->m_isMenu)
	{
		m_pMenu->Draw();

	}

	if (m_isGameClear)//�Q�[�����N���A�����ꍇ
	{
		GameClear();//�ǂ̉�ʂɈړ����邩�m�F
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	/*
	//���H�p�X�N���[���n���h�����Z�b�g����
	SetDrawScreen(m_hTempScreen);

	m_pStage->Draw();//�X�e�[�W��`��

	//�v���C���[�A�G�l�~�[��\��
	m_pCollision->Draw();

	m_timer = GetRand(1000);

	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(0, 0, m_hTempScreen, false);

	if (m_timer == 500)
	{
		GraphFilter(m_hTempScreen, DX_GRAPH_FILTER_GAUSS, 16, 1400);

		SetDrawBlendMode(DX_BLENDMODE_ADD, 192);

		DrawGraph(m_timer, 0, m_hTempScreen, false);
		GraphFilter(m_hTempScreen, DX_GRAPH_FILTER_GAUSS, 32, 1400);
		DrawGraph(m_timer, 0, m_hTempScreen, false);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	*/
	if (m_stageCount != 0)
	{
		DrawExtendGraph(0,0, Game::kScreenWidth, Game::kScreenHeight, m_hCopy, true);
	}
	if (m_isStageCount)
	{
		SetFontSize(128 + 32 + 32);//�����T�C�Y�ύX//�^�C�g��
		DrawFormatString(Game::kScreenWidth/2, Game::kScreenHeight/2, 0xffffff, "%d", m_stageCountSeconds);
		SetFontSize(32);//�����T�C�Y�ύX//�^�C�g��
	}
}

//�N���A�������̑I����ʕ\��
void SceneMain2::GameClear()
{
	m_pFireworks->Update();
	m_pSlidSelect->Slider();//�I����ʂ̏���

	m_pFireworks->Draw();
	SetFontSize(128 + 32 + 32);//�����T�C�Y�ύX//�^�C�g��
	DrawString(SceneSelect::kSelectLeft - 200 + 2, SceneSelect::kSelectTop - 300 + 2, "�Q�[���N���A", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft - 200, SceneSelect::kSelectTop - 300, "�Q�[���N���A", Color::kYellow);
	SetFontSize(32);//�����T�C�Y�ύX//�^�C�g��
	m_pSlidSelect->Draw();//�`�揈��

	m_pChest->Stage1Draw();
}

void SceneMain2::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//��ʂ��ő�ɖ��邭
	}
}

void SceneMain2::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//��ʂ��ő�ɈÂ�
	}
}