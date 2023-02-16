#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"
#include "Image.h"

namespace
{
	constexpr int kAnimationFrame = 3;
	constexpr int kCharaImageRightPos = 112; //右移動

	constexpr int kStage1X = 100;
	constexpr int kStage1Y = 100;
	constexpr int kStageBottom1X = kStage1X + 200;
	constexpr int kStageBottom1Y = kStage1Y + 100;
}

SceneTitle::SceneTitle():
	m_hImagePlayer(-1),
	m_hImageMap(-1),
	m_charaImagePos(0),
	m_frameCount(0),
	m_sceneChangeCount(0),
	m_padPos(0.0f, 0.0f),
	m_imagePos(0.0f,0.0f)
{
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_hImagePlayer);
	DeleteGraph(m_hImageMap);
}

void SceneTitle::Init()
{
	m_hImagePlayer = LoadGraph(Image::kPlayerImage);
	m_hImageMap    = LoadGraph(Image::kMapFirst);

	m_padPos.x = Game::kScreenWidth / 2;
	m_padPos.y = Game::kScreenHeight / 2;

	m_imagePos.x   = Game::kScreenWidth / 2;
	m_imagePos.y   = Game::kScreenHeight / 2 - 250;

	//m_charaImagePos = (1344 );
}
void SceneTitle::End()
{

}

SceneBase* SceneTitle::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	if (padState & PAD_INPUT_RIGHT)//右
	{
		m_padPos.x += 10;
	}
	if (padState & PAD_INPUT_LEFT)//右
	{
		m_padPos.x -= 10;
	}
	if (padState & PAD_INPUT_UP)//右
	{
		m_padPos.y -= 10;
	}
	if (padState & PAD_INPUT_DOWN)//右
	{
		m_padPos.y += 10;
	}








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

	return this;
}

void SceneTitle::Draw()
{
	DrawExtendGraph(0 + 100, 0 + 100,Game::kScreenWidth  - 100, Game::kScreenHeight - 100,m_hImageMap,true);
	DrawRectRotaGraph(m_imagePos.x, m_imagePos.y,
		m_charaImagePos, 133, 112, 133, 18, 0, m_hImagePlayer, true, true);
	//DrawGraph(100, 100, m_hImagePlayer, true);
	int x = Game::kScreenWidth/2 - 300;
	int y = 700;
	int bx = x + 300 * 2;
	int by = y + 200;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);//透過
	DrawBox(x, y, bx, by, 0x0000ff, true);//背景
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawBox(x, y, bx, by, 0xffffff, false);//枠
	DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 2 + 250, "Z長押しでゲームスタート", 0xffffff);


	//パッドのカーソルを表示
	DrawPadCursor();
	//選択
	DrawSelection();
}

void SceneTitle::DrawPadCursor()
{
	DrawCircle(m_padPos.x, m_padPos.y, 20, 0x00ffff, false);
	// 描画ブレンドモードをアルファブレンド（５０％）にする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawCircle(m_padPos.x, m_padPos.y, 19, 0xffff00, true);
	// 描画ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneTitle::DrawSelection()
{
	DrawBox(kStage1X, kStage1Y, kStageBottom1X, kStageBottom1Y, 0xffffff, true);
}
