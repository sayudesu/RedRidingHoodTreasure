#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class TitleCursorGame;//�J�[�\���N���X
class GameSceneCollision;//�J�[�\������
class Fireworks;//�ԉ�

class SceneResult2 : public SceneBase
{
public:
	SceneResult2();

	virtual ~SceneResult2();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	int m_hSoundSelect;//�I�����̃T�E���h
	int m_hSoundSelect1;//�I�����̃T�E���h
	int m_hSoundSelect2;

	int m_hMusicBgm;//BGM�p�n���h��

	int m_soundCount;//�T�E���h�����܂ł̃J�E���g
	int m_soundCount1;//�T�E���h�����܂ł̃J�E���g
	int m_soundCount2;


	int m_color1;//�I����ʂ̐F
	int m_color2;
	int m_color3;

	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
	Fireworks* m_pFireworks;
};

