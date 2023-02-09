#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"
#include "Image.h"

namespace
{
	constexpr int kAnimationFrame = 3;
	constexpr int kCharaImageRightPos = 112; //右移動
}

SceneTitle::SceneTitle():
	m_hImagePlayer(-1),
	m_charaImagePos(0),
	m_frameCount(0),
	m_sceneChangeCount(0),
	m_imagePos(0.0f,0.0f)
{
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_hImagePlayer);
}

void SceneTitle::Init()
{
	m_hImagePlayer = LoadGraph(Image::kPlayerImage);
	m_imagePos.x = Game::kScreenWidth / 2;
	m_imagePos.y = Game::kScreenHeight / 2 - 250;

	//m_charaImagePos = (1344 );
}
void SceneTitle::End()
{

}

SceneBase* SceneTitle::Update()
{
	//右に移動アニメーション

	m_frameCount++;
	if (m_frameCount >= kAnimationFrame)
	{
		m_charaImagePos += kCharaImageRightPos;
		m_frameCount = 0;
	}
	if (m_charaImagePos == 1344)
	{
		m_charaImagePos = 0;
	}


	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//メニュー画面に移動
	if (padState & PAD_INPUT_1)
	{
		m_sceneChangeCount++;
		m_imagePos.x += 15.0f;
		if(m_imagePos.x >= static_cast<float>(Game::kScreenWidth + 150))
		{
			m_sceneChangeCount = 0;
			return(new SceneMain);
		}
	}
	else
	{
		m_imagePos.x = Game::kScreenWidth / 2;
	}

	return this;
}

void SceneTitle::Draw()
{
	DrawRectRotaGraph(m_imagePos.x, m_imagePos.y,
		m_charaImagePos, 133, 112, 133, 18, 0, m_hImagePlayer, true, true);
	//DrawGraph(100, 100, m_hImagePlayer, true);
	DrawString(0,0, "タイトル", 0xffffff);
	DrawString(0, 100, "Zで長押しで開始", 0xffffff);
}