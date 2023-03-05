#include "SelectMenu.h"
#include "TitleCursor.h"
#include "game.h"
#include <Dxlib.h>


SelectMenu::SelectMenu():
	m_isMenu(false),//メニューを開いているかどうか
	m_pCursor(nullptr)
{
	m_pCursor = new TitleCursor;
}

SelectMenu::~SelectMenu()
{
	delete m_pCursor;
}

void SelectMenu::Init()
{

}

void SelectMenu::Update()
{

	if (m_isMenu)//メニュー表示している場合
	{
		m_pCursor->Update();//カーソル表示

		if (CheckHitKey(KEY_INPUT_O))//メニューを閉じる
		{
			m_isMenu = false;//メニュー画面を非表示
		}
	}
	if (CheckHitKey(KEY_INPUT_P))//メニューを開く
	{
		m_isMenu = true;
	}

}

void SelectMenu::Draw()
{
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0x00ffff, true);//中
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0xffffff,false);//枠組み
	m_pCursor->Draw();//カーソル表示
}
