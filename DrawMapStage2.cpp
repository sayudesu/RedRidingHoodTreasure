#include "DrawMapStage2.h"
#include "game.h"
#include <Dxlib.h>

namespace 
{
	//î†ÇÃâ°ïù
	constexpr int BoxWidth = 150;
	//î†ÇÃçÇÇ≥
	constexpr int BoxHeight = 20;
	//íiç∑
	constexpr int BoxStep = 5;

	//àÍäK
	constexpr int Box1X = 0;
	constexpr int Box1Y = Game::kScreenHeight - 60;
	constexpr int BoxBottom1X = Box1X + Game::kScreenWidth / 2;
	constexpr int BoxBottom1Y = Box1Y + BoxHeight;

	//àÍäKàÍíiç∑
	constexpr int Box2X = BoxBottom1X;
	constexpr int Box2Y = Box1Y - BoxStep;
	constexpr int BoxBottom2X = Box2X + BoxWidth;
	constexpr int BoxBottom2Y = Box2Y + BoxHeight;

	//àÍäKìÒíiç∑
	constexpr int Box3X = BoxBottom2X;
	constexpr int Box3Y = Box2Y - BoxStep;
	constexpr int BoxBottom3X = Box3X + BoxWidth;
	constexpr int BoxBottom3Y = Box3Y + BoxHeight;

	//àÍäKéOíiç∑
	constexpr int Box4X = BoxBottom3X;
	constexpr int Box4Y = Box3Y - BoxStep;
	constexpr int BoxBottom4X = Box4X + BoxWidth;
	constexpr int BoxBottom4Y = Box4Y + BoxHeight;

	//àÍäKélíiç∑
	constexpr int Box5X = BoxBottom4X;
	constexpr int Box5Y = Box4Y - BoxStep;
	constexpr int BoxBottom5X = Box5X + BoxWidth;
	constexpr int BoxBottom5Y = Box5Y + BoxHeight;

	//àÍäKå‹íiç∑
	constexpr int Box6X = BoxBottom5X;
	constexpr int Box6Y = Box5Y - BoxStep;
	constexpr int BoxBottom6X = Box6X + BoxWidth;
	constexpr int BoxBottom6Y = Box6Y + BoxHeight;

	//àÍäKòZíiç∑
	constexpr int Box7X = BoxBottom6X;
	constexpr int Box7Y = Box6Y - BoxStep;
	constexpr int BoxBottom7X = Box7X + BoxWidth;
	constexpr int BoxBottom7Y = Box7Y + BoxHeight;

	//àÍäKéµíiç∑
	constexpr int Box8X = BoxBottom7X;
	constexpr int Box8Y = Box7Y - BoxStep;
	constexpr int BoxBottom8X = Box8X + BoxWidth;
	constexpr int BoxBottom8Y = Box8Y + BoxHeight;
}

DrawMapStage2::DrawMapStage2()
{
}

DrawMapStage2::~DrawMapStage2()
{
}

void DrawMapStage2::Init()
{
}

void DrawMapStage2::End()
{
}

void DrawMapStage2::Update()
{
}

void DrawMapStage2::Draw()
{
	DrawBox(Box1X, Box1Y, BoxBottom1X, BoxBottom1Y, 0xffffff, true);
	DrawBox(Box2X, Box2Y, BoxBottom2X, BoxBottom2Y, 0xffffff, true);
	DrawBox(Box3X, Box3Y, BoxBottom3X, BoxBottom3Y, 0xffffff, true);
	DrawBox(Box4X, Box4Y, BoxBottom4X, BoxBottom4Y, 0xffffff, true);
	DrawBox(Box5X, Box5Y, BoxBottom5X, BoxBottom5Y, 0xffffff, true);
	DrawBox(Box6X, Box6Y, BoxBottom6X, BoxBottom6Y, 0xffffff, true);
	DrawBox(Box7X, Box7Y, BoxBottom7X, BoxBottom7Y, 0xffffff, true);
	DrawBox(Box8X, Box8Y, BoxBottom8X, BoxBottom8Y, 0xffffff, true);
}
