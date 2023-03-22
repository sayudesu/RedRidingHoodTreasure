#pragma once
class Chest
{
public:
	Chest();
	~Chest();

	void Stage1Draw();
	void Stage2Draw();
	void Stage3UDraw();
private:
	int m_hMapChip1;
	int m_hBox;

	int m_boxPuls;

};

