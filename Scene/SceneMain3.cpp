#include "SceneMain3.h"
#include "SceneMain4.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver2.h"
#include "DrawMapStage2.h"
#include "PlayerNew.h"
#include "Collision2.h"
#include "SelectMenu.h"
#include "game.h"
#include "Image.h"
#include "SlideSelect.h"
#include "Fireworks.h"
#include <Dxlib.h>

SceneMain3::SceneMain3():
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hFadeImage(-1),
	m_hCopy(-1),
	m_hMusicBgm(-1),
	m_stageCount(0),//�X�e�[�W���n�܂�܂ł̃J�E���g
	m_stageCountSeconds(0),
	m_fadeValue(0.0f),
	m_isStageCount(false),
	m_isFadeIn(false),//�t�F�C�h�C���������ǂ���
	m_isFadeOut(false),//�t�F�C�h�A�E�g�������ǂ���
	m_isSceneResult(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneRetry(false),
	m_isSceneTitle(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isGameClear(false),//�Q�[�����N���A�����ꍇ
	m_isSceneDead(false),//���񂾂�V�[���؂�ւ�
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr),
	m_pMenu(nullptr),
	m_pSlidSelect(nullptr),
	m_pFireworks(nullptr)
{
	m_pStage     = new DrawMapStage2;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision2;
	m_pMenu      = new SelectMenu;
	m_pSlidSelect = new SlideSelect;
	m_pFireworks = new Fireworks;
}

SceneMain3::~SceneMain3()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
	delete m_pSlidSelect;
	delete m_pFireworks;
}

void SceneMain3::Init()
{
	
	m_pCollision->Init();
	m_pStage->Init();

	m_hMusicBgm = LoadSoundMem(Sound::kBgmStage2);//�T�E���h�ǂݍ���

	m_hFadeImage = LoadGraph(Image::kFade);//�t�F�C�h����
	m_hCopy = LoadGraph(Image::kCountTime2);
	//�v���C���[�摜
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

	m_stageCount = 60 * 3;//�X�e�[�W�J�n�J�E���g
	m_fadeValue = 255.0f;
}

void SceneMain3::End()
{
	m_pPlayer->End();
	m_pStage->End();

	//m_pEnemy->End();
	//�v���C���[�摜
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hCopy);
	StopSoundFile();//�Đ����̃T�E���h���~�߂�
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneMain3::Update()
{
	//�Q�[���N���A��̑I�����󂯎��
	GetSceneStage(m_pSlidSelect->SetSceneStage());
	GetSceneRetry(m_pSlidSelect->SetSceneRetry());
	GetSceneTitle(m_pSlidSelect->SetSceneTitle());
	GetSceneDead(m_pSlidSelect->SetSceneDead());

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
		if (!m_isGameClear)//�N���A���Ă��Ȃ��ꍇ�͏�������
		{
			if (m_stageCount == 0)
			{
				m_isStageCount = false;
				if (!m_pMenu->m_isMenu)
				{
					m_pCollision->Update();
				}
			}
			else
			{
				m_stageCount--;
				m_isStageCount = true;
			}
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
	else if (m_isSceneResult)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain4);//�V�����X�e�[�W�Ɉړ�
		}
	}
	else if (m_pMenu->SetSceneRetry() || m_isSceneRetry)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain3);//�����X�e�[�W���J��Ԃ�
		}
	}
	else if (m_isSceneDead)//���񂾏ꍇ�̃V�[���؂�ւ�
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneGameOver2);
		}
	}

	if (CheckHitKey(KEY_INPUT_Z))//�ً}���^�C�g���ɖ߂�
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneMain3::Draw()
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

	if (m_stageCount != 0)
	{
		DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hCopy, true);
	}
	if (m_isStageCount)
	{
		SetFontSize(128 + 32 + 32);//�����T�C�Y�ύX//�^�C�g��
		DrawFormatString(Game::kScreenWidth / 2, Game::kScreenHeight / 2, 0xffffff, "%d", m_stageCountSeconds);
		SetFontSize(32);//�����T�C�Y�ύX//�^�C�g��
	}

}

void SceneMain3::GameClear()
{
	m_pFireworks->Update();
	m_pSlidSelect->Slider();//�I����ʂ̏���

	m_pFireworks->Draw();
	SetFontSize(128 + 32 + 32);//�����T�C�Y�ύX//�^�C�g��
	DrawString(SceneSelect::kSelectLeft - 200 + 2, SceneSelect::kSelectTop - 300 + 2, "�Q�[���N���A", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft - 200, SceneSelect::kSelectTop - 300, "�Q�[���N���A", Color::kYellow);
	SetFontSize(32);//�����T�C�Y�ύX//�^�C�g��
	m_pSlidSelect->Draw();//�`�揈��
}

void SceneMain3::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//��ʂ��ő�ɖ��邭
	}
}

void SceneMain3::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//��ʂ��ő�ɈÂ�
	}
}