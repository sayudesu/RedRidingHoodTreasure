#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class TitleCursor;
class TitleCollision;

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	void FadeIn();//�t�F�C�h�C��
	void FadeOut();//�t�F�C�h�A�E�g
private:
	//�摜�n���h��
	int m_hImagePlayer;
	int m_hImageMap;
	int m_charaImagePos;
	int m_hButtonUi;
	int m_hTitleMainImage;

	int m_hMusicBgm;
	int m_hSoundSelect;
	int m_hSoundSelect2;

	int m_colorA;
	int m_colorX;

	//�J�E���g
	int m_frameCount;
	int m_soundCount1;
	int m_soundCount2;
	int m_soundCount3;
	int m_sceneChangeCountDemo;
	int m_sceneChangeCountStage1;
	int m_sceneChangeCountEnd;

	int m_buttonALeft;
	int m_buttonATop;
	int m_buttonARigth;
	int m_buttonABottom;

	int m_buttonXLeft;
	int m_buttonXTop;
	int m_buttonXRigth;
	int m_buttonXBottom;

	float m_fadeValue;//��ʂ̖��邳����

	bool m_isFadeIn;//�t�F�C�h�C���������ǂ���
	bool m_isFadeOut;//�t�F�C�h�A�E�g�������ǂ���

	bool m_isSceneStage;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneEnd;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�

	bool m_isSceneFocus1;
	bool m_isSceneFocus2;
	bool m_isSceneFocus3;

	Vec2 m_imagePos;

	TitleCursor* m_pCursor;
	TitleCollision* m_pCollsion;
};
