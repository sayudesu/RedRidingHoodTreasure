#pragma once

class DrawMapStage2
{
public:

	DrawMapStage2();
	virtual~DrawMapStage2();

	virtual void Init();
	virtual void End();
	virtual void Update();
	virtual void Draw();
private:
	void DrawBackground();
	void DrawMap();
private:
	//ƒ}ƒbƒv‰æ‘œ
	int m_hMap1;
	int m_hMap2;
	int m_hMap3;
	int m_hMap4;
	int m_hMap5;
};

