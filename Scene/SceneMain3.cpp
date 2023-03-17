#include "SceneMain3.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver2.h"
#include "DrawMapStage2.h"
#include "PlayerNew.h"
#include "Collision2.h"
#include "SelectMenu.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>

SceneMain3::SceneMain3():
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemyFireBall(-1),
	m_hMusicBgm(-1),
	m_fadeValue(0.0f),
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
	m_pMenu(nullptr)
{
	m_pStage     = new DrawMapStage2;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision2;
	m_pMenu      = new SelectMenu;
}

SceneMain3::~SceneMain3()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
}

void SceneMain3::Init()
{
	
	m_pCollision->Init();
	m_pStage->Init();

	m_hMusicBgm = LoadSoundMem(Sound::kBgmStage2);//�T�E���h�ǂݍ���

	m_hPlayerLighting = LoadGraph(Image::kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(Image::kPlayerHealthBer);
	//�G�l�~�[�摜
	m_hEnemyFireBall = LoadGraph(Image::kEnemyFireBall);

	//�v���C���[�摜
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

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
	//�G�l�~�[�摜
	DeleteGraph(m_hEnemyFireBall);

	StopSoundFile();//�Đ����̃T�E���h���~�߂�
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneMain3::Update()
{

	if (!m_isFadeIn)FadeIn();//�t�F�C�h�C��

	if (m_isFadeIn)//��ʂ��ő�l���邭�Ȃ�����
	{
		if (!m_pMenu->m_isMenu)//���j���[���J���Ė���������
		{
			m_pCollision->Update();
		}

		m_pMenu->Update();//���j���[�̏�Ԃ��X�V���Ȃ���m�F

		if (m_pCollision->m_isStageClear)//�X�e�[�W���N���A�����ꍇ
		{
			m_isSceneResult = true;
			//return(new SceneResult);
		}

		if (m_pCollision->m_isDeadSceneChange)//�G��g���b�v�ɓ������Ď��񂾏ꍇ
		{
			m_isSceneDead = true;
			//printfDx("�G��g���b�v�ɓ������Ď���");
			//return(new SceneGameOver2);
		}
	}

	//�T�E���h
	if (CheckSoundMem(m_hMusicBgm) == 0)//���Ă��Ȃ�������
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//�T�E���h���Đ�
		ChangeVolumeSoundMem(SoundVolume::BGM, m_hMusicBgm);//���ʒ���
	}

	if (m_isSceneResult)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneResult);//�V�����X�e�[�W�Ɉړ�
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
	else if (m_pMenu->SetSceneRetry())//�J��Ԃ��ꍇ�̃V�[���؂�ւ�
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain3);
		}
	}
	else if (m_pMenu->SetSceneTitle())//�^�C�g���ɖ߂�ꍇ�̃V�[���؂�ւ�
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneTitle);
		}
	}

	if (CheckHitKey(KEY_INPUT_Z))
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

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

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