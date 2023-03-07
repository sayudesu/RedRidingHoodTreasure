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
	int m_frameCount;//メニュー画面を開いた時にディレイを入れる
	TitleCursor* m_pCursor;
};

