#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMain2.h"
#include "SceneResult.h"
#include "PlayerMapMove.h"
#include "SceneGameOver.h"
//#include "Player.h"
#include "Enemy.h"
#include "game.h"
#include <DxLib.h>
#include "Image.h"

SceneMain::SceneMain() :
	m_test(0),
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemy(-1),
	m_hMapFirst(-1),
	m_hMapSecond(-1),
	m_hMapThird(-1),
	m_hMapFourth(-1),
	m_hMapFifth(-1),
	m_hMapChip(-1),
	m_hMapChipSecond(-1),
	m_hMusicBgm1(-1),//BGM�p�n���h��
	m_fadeValue(0.0f),//���邳�����p
	m_isFadeIn(false),//�t�F�C�h�C���������ǂ���
	m_isFadeOut(false),//�t�F�C�h�A�E�g�������ǂ���
	m_isSceneStage(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_isSceneEnd(false),//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	m_pPlayer(nullptr),
	m_pEnemy(nullptr)
{

	m_fadeValue = 255.0f;

	m_pPlayer = new PlayerMapMove;
	m_pEnemy = new Enemy;
}

SceneMain::~SceneMain()
{
	delete m_pPlayer;
	delete m_pEnemy;
	DeleteSoundMem(m_hMusicBgm1);
}

void SceneMain::Init()
{
	m_pPlayer->Init();
	
	//�v���C���[�摜
	m_hPlayer = LoadGraph(Image::kPlayerImage);
	m_hPlayerIdle = LoadGraph(Image::kPlayerImageIdle);
	m_hPlayerLighting = LoadGraph(Image::kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(Image::kPlayerHealthBer);

	//�G�l�~�[�摜
	m_hEnemy = LoadGraph(Image::kEnemyEye);

	//�}�b�v�摜
	m_hMapFirst  = LoadGraph(Image::kMapFirst);
	m_hMapSecond = LoadGraph(Image::kMapSecond);
	m_hMapThird  = LoadGraph(Image::kMapThird);
	m_hMapFourth = LoadGraph(Image::kMapFourth);
	m_hMapFifth = LoadGraph(Image::kMapFifth);
	m_hMapChip = LoadGraph(Image::kMapChip);
	m_hMapChipSecond = LoadGraph(Image::kMapChipSecond);

	//�v���C���[�摜
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);
	m_pPlayer->SetHandleLighting(m_hPlayerLighting);
	m_pPlayer->SetHandleHealthBer(m_hPlayerHealthBer);

	//�G�l�~�[�摜
	m_pEnemy->SetHandle(m_hEnemy);

	//�}�b�v�摜
	m_pPlayer->SetHandleMapFirst (m_hMapFirst);
	m_pPlayer->SetHandleMapSecond(m_hMapSecond);
	m_pPlayer->SetHandleMapThird (m_hMapThird);
	m_pPlayer->SetHandleMapFourth(m_hMapFourth);
	m_pPlayer->SetHandleMapFifth(m_hMapFifth);
	m_pPlayer->SetHnadleMapChip(m_hMapChip);
	m_pPlayer->SetHnadleMapChipSecond(m_hMapChipSecond);

	m_hMusicBgm1 = LoadSoundMem(Sound::kBgm1);
	PlaySoundMem(m_hMusicBgm1, DX_SOUNDTYPE_STREAMSTYLE);
	// ���ʂ̐ݒ�
	//ChangeVolumeSoundMem(255 / 3, m_hMusicBgm1);

}
void SceneMain::End()
{
	m_pPlayer->End();
	m_pEnemy->End();

	DeleteGraph(m_test);

	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hPlayerLighting);
	DeleteGraph(m_hPlayerHealthBer);

	DeleteGraph(m_hEnemy);

	DeleteGraph(m_hMapFirst);
	DeleteGraph(m_hMapSecond);
	DeleteGraph(m_hMapThird);
	DeleteGraph(m_hMapFourth);
	DeleteGraph(m_hMapFifth);

	DeleteGraph(m_hMapChip);
	DeleteGraph(m_hMapChipSecond);
}

SceneBase* SceneMain::Update()
{
	FadeIn();//�t�F�C�h�C��

	m_pPlayer->Update();

	//�G�������Ă��邩�ǂ���
	if(m_pPlayer->GetLifeEnemy() && m_pPlayer->GetEnemyMove())
	{
		m_pEnemy->Update();
	}
	//�X�e�[�W���N���A�����ꍇ
	if (m_pPlayer->GetStageClear())
	{
		return(new SceneMain2);
	}
	//���񂾏ꍇ
	if (m_pPlayer->IsDead())
	{
		return(new SceneGameOver);
	}
	//�^�C�g�����߂�ꍇ
	else if (m_pPlayer->IsTitle())
	{
		return(new SceneTitle);
	}

	return this;
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();

	//�G�������Ă��邩�ǂ���
	if (m_pPlayer->GetLifeEnemy())
	{
		m_pEnemy->Draw();
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, 640, 480, 0xffffff, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//�t�F�C�h����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneMain::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//��ʂ��ő�ɖ��邭
	}
}

void SceneMain::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//��ʂ��ő�ɈÂ�
	}
}


//�G�ƃv���C���[�̏Փ˔���
bool SceneMain::Check(int firstLeft, int firstTop, int firstRight, int firstBottom,
	int SecondLeft, int SecondTop, int SecondRight, int SecondBottom)
{
	if ((firstRight > SecondLeft) &&
		(firstLeft < SecondRight))
	{
		if ((firstBottom > SecondTop) &&
			(firstTop < SecondBottom))
		{
			printfDx("����L��");
			return true;
		}
	}
	return false;
}







