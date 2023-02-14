#include "DrawMapStage2.h"
#include "game.h"
#include <Dxlib.h>

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
	//1ŠK’n–Ê
	DrawBox(Stage2::Box1X, Stage2::Box1Y, Stage2::BoxBottom1X, Stage2::BoxBottom1Y, 0xffffff, true);
	DrawBox(Stage2::Box2X, Stage2::Box2Y, Stage2::BoxBottom2X, Stage2::BoxBottom2Y, 0xffffff, true);
	DrawBox(Stage2::Box3X, Stage2::Box3Y, Stage2::BoxBottom3X, Stage2::BoxBottom3Y, 0xffffff, true);
	DrawBox(Stage2::Box4X, Stage2::Box4Y, Stage2::BoxBottom4X, Stage2::BoxBottom4Y, 0xffffff, true);
	DrawBox(Stage2::Box5X, Stage2::Box5Y, Stage2::BoxBottom5X, Stage2::BoxBottom5Y, 0xffffff, true);
	DrawBox(Stage2::Box6X, Stage2::Box6Y, Stage2::BoxBottom6X, Stage2::BoxBottom6Y, 0xffffff, true);
	DrawBox(Stage2::Box7X, Stage2::Box7Y, Stage2::BoxBottom7X, Stage2::BoxBottom7Y, 0xffffff, true);
	DrawBox(Stage2::Box8X, Stage2::Box8Y, Stage2::BoxBottom8X, Stage2::BoxBottom8Y, 0xffffff, true);

	//2ŠK’n–Ê
	DrawBox(Stage2::Box1Xs, Stage2::Box1Ys, Stage2::BoxBottom1Xs, Stage2::BoxBottom1Ys, 0xffffff, true);
	DrawBox(Stage2::Box2Xs, Stage2::Box2Ys, Stage2::BoxBottom2Xs, Stage2::BoxBottom2Ys, 0xffffff, true);
	DrawBox(Stage2::Box3Xs, Stage2::Box3Ys, Stage2::BoxBottom3Xs, Stage2::BoxBottom3Ys, 0xffffff, true);
	DrawBox(Stage2::Box4Xs, Stage2::Box4Ys, Stage2::BoxBottom4Xs, Stage2::BoxBottom4Ys, 0xffffff, true);
	DrawBox(Stage2::Box5Xs, Stage2::Box5Ys, Stage2::BoxBottom5Xs, Stage2::BoxBottom5Ys, 0xffffff, true);
	DrawBox(Stage2::Box6Xs, Stage2::Box6Ys, Stage2::BoxBottom6Xs, Stage2::BoxBottom6Ys, 0xffffff, true);
	DrawBox(Stage2::Box7Xs, Stage2::Box7Ys, Stage2::BoxBottom7Xs, Stage2::BoxBottom7Ys, 0xffffff, true);
	DrawBox(Stage2::Box8Xs, Stage2::Box8Ys, Stage2::BoxBottom8Xs, Stage2::BoxBottom8Ys, 0xffffff, true);


	//’òŽq
	DrawBox(Stage2::Ladder1X, Stage2::Ladder1Y, Stage2::LadderBottom1X, Stage2::LadderBottom1Y, 0xffffff, true);
}
