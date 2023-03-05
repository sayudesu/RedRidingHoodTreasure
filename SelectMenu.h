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

	bool m_isMenu;//ƒƒjƒ…[‚ğŠJ‚¢‚Ä‚¢‚é‚©‚Ç‚¤‚©
private:

	TitleCursor* m_pCursor;
};

