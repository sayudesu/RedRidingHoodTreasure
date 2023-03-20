#pragma once

class TitleCursorGame;
class GameSceneCollision;

class SelectMenu
{
public:
	SelectMenu();
	virtual~SelectMenu();

	void Init();
	void Update();
	void Draw();

	bool m_isMenu;//���j���[���J���Ă��邩�ǂ���
public:
	//�I��������Ԃ�n��
	bool SetSceneRetry() { return m_isSceneRetry; }
	bool SetSceneTitle() { return m_isSceneTitle; }
private:

	//�T�E���h�n���h��
	int m_hSoundSelect;//�{�^�����������ꍇ�̃T�E���h
	int m_hSoundSelect2;

	int m_frameCount;//���j���[��ʂ��J�������Ƀf�B���C������

	int m_backGround_Y;//�w�i��DrawBox�ʒu�c���W
	int m_SringBox_Y;//�����g�͈͏c���W
	int m_SringBox2_Y;//�����g�͈͏c���W
	int m_SringBox3_Y;//�����g�͈͏c���W

	int m_Sring_Y;//�����c���W
	int m_Sring2_Y;//�����c���W
	int m_Sring3_Y;//�����c���W

	int m_color1;//�I����ʂ̐F
	int m_color2;
	int m_color3;

	int m_soundCount2;//�T�E���h�Đ��܂ł̃J�E���g
	int m_soundCount3;

	bool m_isMoveStop = true;

	bool m_isSceneStage;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneRetry;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneTitle;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�
	bool m_isSceneDead;//��ʂ��Â��Ȃ�����ɃV�[���̐؂�ւ�

	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
};

