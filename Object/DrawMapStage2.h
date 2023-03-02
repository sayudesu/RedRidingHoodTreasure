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
	//マップ画像
	int m_hMap1;
	int m_hMap2;
	int m_hMap3;
	int m_hMap4;
	int m_hMap5;
	//マップ地面、梯子
	int m_hTiles;
	int m_hBlock;//地面用

	//マップ背景Forest
	int m_hForest[9];
	int m_hForestCut[9];//背景切り取り


	//ゴール画像
	int m_hMapChip1;//画像データ
	int m_hBox;//箱を描画
};

