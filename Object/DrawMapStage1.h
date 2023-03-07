#pragma once

class DrawMapStage1
{
public:

	DrawMapStage1();
	virtual~DrawMapStage1();

	virtual void Init();
	virtual void End();
	virtual void Update();
	virtual void Draw();
private:
	void DrawBackground();
	void DrawMap();
private:
	//�}�b�v�摜
	int m_hMap1;
	int m_hMap2;
	int m_hMap3;
	int m_hMap4;
	int m_hMap5;
	//�}�b�v�n�ʁA��q
	int m_hTiles;
	int m_hBlock;//�n�ʗp

	//��q
	int m_hLadderChip;
	int m_hLadder;

	//�}�b�v�w�iForest
	int m_hForest[9];
	int m_hForestCut[9];//�w�i�؂���


	//�S�[���摜
	int m_hMapChip1;//�摜�f�[�^
	int m_hBox;//����`��
};
