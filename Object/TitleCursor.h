#pragma once
#include "Vec2.h"

class SceneTitle;

class TitleCursor
{
public:
	TitleCursor();
	~TitleCursor();
	void Init();
	void Update();
	void Draw();
private:
	void PosSet();
	void DrawPadCursor();
	void DrawSelection();
public:
	void GetMenu(bool menu) { m_isMenu = menu; }//メニューの状態
	Vec2 GetCursor() { return m_padPos; }

private:
	bool m_isMenu;//メニューが今開いているかどうか
	Vec2 m_padPos;
};

