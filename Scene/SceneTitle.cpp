#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "game.h"

namespace
{

}

void SceneTitle::init()
{

}
void SceneTitle::end()
{

}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//メニュー画面に移動
	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}

	return this;
}

void SceneTitle::draw()
{
	DrawString(0,0, "タイトル", 0xffffff);
}