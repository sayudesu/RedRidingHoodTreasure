#pragma once

class TitleCursor;

class SelectMenu
{
public:
	SelectMenu();
	virtual~SelectMenu();

	void Init();
	void Update();
	void Draw();

	bool m_isMenu;//メニューを開いているかどうか
private:

	TitleCursor* m_pCursor;
};

