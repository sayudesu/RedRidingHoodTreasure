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
	void DrawPadCursor();
	void DrawSelection();
public:
	Vec2 GetCursor() { return m_padPos; }

private:
	Vec2 m_padPos;

};

