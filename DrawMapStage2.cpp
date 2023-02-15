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
	DrawBox(Stage2::kBox1X, Stage2::kBox1Y, Stage2::kBoxBottom1X, Stage2::kBoxBottom1Y, 0xffffff, true);
	DrawBox(Stage2::kBox2X, Stage2::kBox2Y, Stage2::kBoxBottom2X, Stage2::kBoxBottom2Y, 0xffffff, true);
	DrawBox(Stage2::kBox3X, Stage2::kBox3Y, Stage2::kBoxBottom3X, Stage2::kBoxBottom3Y, 0xffffff, true);
	DrawBox(Stage2::kBox4X, Stage2::kBox4Y, Stage2::kBoxBottom4X, Stage2::kBoxBottom4Y, 0xffffff, true);
	DrawBox(Stage2::kBox5X, Stage2::kBox5Y, Stage2::kBoxBottom5X, Stage2::kBoxBottom5Y, 0xffffff, true);
	DrawBox(Stage2::kBox6X, Stage2::kBox6Y, Stage2::kBoxBottom6X, Stage2::kBoxBottom6Y, 0xffffff, true);
	DrawBox(Stage2::kBox7X, Stage2::kBox7Y, Stage2::kBoxBottom7X, Stage2::kBoxBottom7Y, 0xffffff, true);
	DrawBox(Stage2::kBox8X, Stage2::kBox8Y, Stage2::kBoxBottom8X, Stage2::kBoxBottom8Y, 0xffffff, true);

	//2ŠK’n–Ê
	DrawBox(Stage2::kBox1Xs, Stage2::kBox1Ys, Stage2::kBoxBottom1Xs, Stage2::koxBottom1Ys, 0xffffff, true);
	DrawBox(Stage2::kBox2Xs, Stage2::kBox2Ys, Stage2::kBoxBottom2Xs, Stage2::kBoxBottom2Ys, 0xffffff, true);
	DrawBox(Stage2::kBox3Xs, Stage2::kBox3Ys, Stage2::kBoxBottom3Xs, Stage2::kBoxBottom3Ys, 0xffffff, true);
	DrawBox(Stage2::kBox4Xs, Stage2::kBox4Ys, Stage2::kBoxBottom4Xs, Stage2::kBoxBottom4Ys, 0xffffff, true);
	DrawBox(Stage2::kBox5Xs, Stage2::kBox5Ys, Stage2::kBoxBottom5Xs, Stage2::kBoxBottom5Ys, 0xffffff, true);
	DrawBox(Stage2::kBox6Xs, Stage2::kBox6Ys, Stage2::kBoxBottom6Xs, Stage2::kBoxBottom6Ys, 0xffffff, true);
	DrawBox(Stage2::kBox7Xs, Stage2::kBox7Ys, Stage2::kBoxBottom7Xs, Stage2::kBoxBottom7Ys, 0xffffff, true);
	DrawBox(Stage2::kBox8Xs, Stage2::kBox8Ys, Stage2::kBoxBottom8Xs, Stage2::kBoxBottom8Ys, 0xffffff, true);

	//3ŠK’n–Ê
	DrawBox(Stage2::kBox1Xt, Stage2::kBox1Yt, Stage2::kBoxBottom1Xt, Stage2::kBoxBottom1Yt, 0xffffff, true);
	DrawBox(Stage2::kBox2Xt, Stage2::kBox2Yt, Stage2::kBoxBottom2Xt, Stage2::kBoxBottom2Yt, 0xffffff, true);
	DrawBox(Stage2::kBox3Xt, Stage2::kBox3Yt, Stage2::kBoxBottom3Xt, Stage2::kBoxBottom3Yt, 0xffffff, true);
	DrawBox(Stage2::kBox4Xt, Stage2::kBox4Yt, Stage2::kBoxBottom4Xt, Stage2::kBoxBottom4Yt, 0xffffff, true);
	DrawBox(Stage2::kBox5Xt, Stage2::kBox5Yt, Stage2::kBoxBottom5Xt, Stage2::kBoxBottom5Yt, 0xffffff, true);
	DrawBox(Stage2::kBox6Xt, Stage2::kBox6Yt, Stage2::kBoxBottom6Xt, Stage2::kBoxBottom6Yt, 0xffffff, true);
	DrawBox(Stage2::kBox7Xt, Stage2::kBox7Yt, Stage2::kBoxBottom7Xt, Stage2::kBoxBottom7Yt, 0xffffff, true);
	DrawBox(Stage2::kBox8Xt, Stage2::kBox8Yt, Stage2::kBoxBottom8Xt, Stage2::kBoxBottom8Yt, 0xffffff, true);


	//‘æˆê’òŽq
	DrawBox(Stage2::kLadder1X, Stage2::kLadder1Y, Stage2::kLadderBottom1X, Stage2::kLadderBottom1Y, 0xffffff, true);
	//‘æ“ñ’òŽq
	DrawBox(Stage2::kLadder2X, Stage2::kLadder2Y, Stage2::kLadderBottom2X, Stage2::kLadderBottom2Y, 0xffffff, true);
}
