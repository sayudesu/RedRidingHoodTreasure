#include "SceneResult.h"
#include "DxLib.h"
#include "game.h"

namespace
{

}

void SceneResult::Init()
{

}

void SceneResult::End()
{

}

SceneBase* SceneResult::Update()
{
	printfDx("ゲームクリア\n");
	return this;
}

void SceneResult::Draw()
{

}