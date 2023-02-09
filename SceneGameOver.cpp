#include "SceneGameOver.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include <Dxlib.h>

SceneGameOver::SceneGameOver()
{
}

SceneGameOver::~SceneGameOver()
{
}

void SceneGameOver::Init()
{
}

void SceneGameOver::End()
{
}

SceneBase* SceneGameOver::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//メニュー画面に移動
	if (padState & PAD_INPUT_1)
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneGameOver::Draw()
{
	DrawString(10, 0, "ゲームオーバー", 0xffffff);
	DrawString(10, 100, "Zでタイトル画面に移動", 0xffffff);
}
