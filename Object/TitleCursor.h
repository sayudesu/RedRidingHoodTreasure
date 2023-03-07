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
	Vec2 GetCursor() { return m_padPos; }

private:

	int m_mouseX;
	int m_mouseY;

	Vec2 m_padPos;

};

