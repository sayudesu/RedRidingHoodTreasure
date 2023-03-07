#include <Dxlib.h>
#include "game.h"
#include "Pad.h"
#include "SelectMenu.h"
#include "TitleCursor.h"


SelectMenu::SelectMenu():
	m_frameCount(0),//メニュー画面を開いた時にディレイを入れる
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
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	m_pCursor->GetMenu(m_isMenu);
	m_pCursor->Update();//カーソル表示
	if (m_isMenu)//メニュー表示している場合
	{
		m_frameCount++;
		if (m_frameCount >= 30)
		{
			if (padState & PAD_INPUT_X)//メニューを閉じる
			{
				m_isMenu = false;//メニュー画面を非表示
				m_frameCount = 0;
			}
		}
	}
	else
	{
		m_frameCount++;
		if (m_frameCount >= 30)
		{
			if (padState & PAD_INPUT_X)//メニューを開く
			{
				m_isMenu = true;
				m_frameCount = 0;
			}
		}
	}
}

void SelectMenu::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0x00ffff, true);//中
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0xffffff, false);//枠組み

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//色を薄くする
//DrawBox(SceneSelect::kSelectLeft, SceneSelect::kSelectTop, SceneSelect::kSelectRight, SceneSelect::kSelectBottom, m_color1, true);
	DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, 0xffffff, true);
	DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, 0xffffff, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//色を戻す

	m_pCursor->Draw();//カーソル表示
}