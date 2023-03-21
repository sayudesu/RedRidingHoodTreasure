#pragma once
#include "SceneBase.h"

class DrawMapStage2;
class PlayerNew;
class Collision2;
class SelectMenu;
class SlideSelect;
class Fireworks;
class Chest;


class SceneMain3 : public SceneBase
{
public:
	SceneMain3();
	virtual~SceneMain3();

	virtual void Init();
	virtual void End();
	virtual SceneBase* Update() override;
	virtual void Draw();
public:
	//�Q�[���N���A��̑I�����󂯎��
	void GetSceneStage(bool scene) { m_isSceneResult = scene; }
	void GetSceneRetry(bool scene) { m_isSceneRetry = scene; }
	void GetSceneTitle(bool scene) { m_isSceneTitle = scene; }
	void GetSceneDead(bool scene) { m_isSceneDead = scene; }

	void GetMenuRetry(bool scene) { m_isSceneRetry = scene; }
	void GetMenuTitle(bool scene) { m_isSceneTitle = scene; }

private:
	void GameClear();//�Q�[�����N���A�����ꍇ
private:
	void FadeIn();//�t�F�C�h�C��
	void FadeOut();//�t�F�C�h�A�E�g
private:
	//�v���C���[�摜
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;
	int m_hFadeImage;
	int m_hCopy;

	int m_hMusicBgm;

	int m_stageCount;//�X�e�[�W���n�܂�܂ł̃J�E���g
	int m_stageCountSeconds;

	float m_fadeValue;//��ʂ̖��邳����

	bool m_isStageCount;

	bool m_isFadeIn;//�t�F�C�h�C���������ǂ���
	bool m_isFadeOut;//�t�F�C�h�A�E�g�������ǂ���

	bool m_isSceneResult;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneRetry;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneTitle;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneDead;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isGameClear;

	DrawMapStage2* m_pStage;
	PlayerNew* m_pPlayer;
	Collision2* m_pCollision;
	SelectMenu* m_pMenu;
	SlideSelect* m_pSlidSelect;
	Fireworks* m_pFireworks;
	Chest* m_pChest;
};



