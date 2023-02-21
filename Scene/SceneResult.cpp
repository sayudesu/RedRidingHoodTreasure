#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	constexpr int kW = 192;
	constexpr int kH = 192;
}

SceneResult::SceneResult():
	handle(-1),
	left(0),
	top(0),
	rigth(kW),
	bottom(kH),
	frameCount(0),
	changeY(false),
	m_pos(0.0f, 0.0f)//中心.x.y
{
	m_pos.x = 200.0f;
	m_pos.y = 200.0f;
}

void SceneResult::Init()
{
	handle = LoadGraph("Data/pipo-mapeffect017_192.png");
}

void SceneResult::End()
{

}

SceneBase* SceneResult::Update()
{
	printfDx("%d\n", left);
	
	frameCount++;

	//10フレームごとに画像を右に192ドット移動していく
	if (frameCount == 3)
	{
		frameCount = 0;//フレームカウントリセット
		left += kW;//192プラス
	}
	if (left == 960)//画像の右まで移動すると左にリセット
	{
		left = 0;
		changeY = true;//画像を下に192移動
	}
	if (changeY)//画像を下に192ドット移動
	{
		top += kH;
		changeY = false;
	}
	if (top ==768)
	{
		top = 0;
	}
	
	return(new SceneTitle);
	return this;
}

void SceneResult::Draw()
{

	DrawRectRotaGraph(m_pos.x, m_pos.y,
		left, top, rigth, bottom, 1, 0, handle, true, false);
}