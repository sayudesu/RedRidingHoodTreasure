#pragma once
#include "TitleCursor.h"

class SceneTitle;

class TitleCursorGame : TitleCursor
{
public:
	TitleCursorGame();
	~TitleCursorGame();
	void Init();
	void Update();
	void Draw();
private:
	void PosSet();
	void DrawPadCursor();
	void DrawSelection();
public:
	void GetMenu(bool menu) { m_isMenu = menu; }//���j���[�̏��
	Vec2 GetCursor() { return m_padPos; }

private:
	bool m_isMenu;//���j���[�����J���Ă��邩�ǂ���
	int m_mouseX, m_mouseY;
	Vec2 m_padPos;
};

