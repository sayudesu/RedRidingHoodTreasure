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
	//1階地面
	DrawBox(Stage2::kBox1X, Stage2::kBox1Y, Stage2::kBoxBottom1X, Stage2::kBoxBottom1Y, 0xffffff, true);
	DrawBox(Stage2::kBox2X, Stage2::kBox2Y, Stage2::kBoxBottom2X, Stage2::kBoxBottom2Y, 0xffffff, true);
	DrawBox(Stage2::kBox3X, Stage2::kBox3Y, Stage2::kBoxBottom3X, Stage2::kBoxBottom3Y, 0xffffff, true);
	DrawBox(Stage2::kBox4X, Stage2::kBox4Y, Stage2::kBoxBottom4X, Stage2::kBoxBottom4Y, 0xffffff, true);
	DrawBox(Stage2::kBox5X, Stage2::kBox5Y, Stage2::kBoxBottom5X, Stage2::kBoxBottom5Y, 0xffffff, true);
	DrawBox(Stage2::kBox6X, Stage2::kBox6Y, Stage2::kBoxBottom6X, Stage2::kBoxBottom6Y, 0xffffff, true);
	DrawBox(Stage2::kBox7X, Stage2::kBox7Y, Stage2::kBoxBottom7X, Stage2::kBoxBottom7Y, 0xffffff, true);
	DrawBox(Stage2::kBox8X, Stage2::kBox8Y, Stage2::kBoxBottom8X, Stage2::kBoxBottom8Y, 0xffffff, true);

	//2階地面
	DrawBox(Stage2::kBox1Xs, Stage2::kBox1Ys, Stage2::kBoxBottom1Xs, Stage2::koxBottom1Ys, 0xffffff, true);
	DrawBox(Stage2::kBox2Xs, Stage2::kBox2Ys, Stage2::kBoxBottom2Xs, Stage2::kBoxBottom2Ys, 0xffffff, true);
	DrawBox(Stage2::kBox3Xs, Stage2::kBox3Ys, Stage2::kBoxBottom3Xs, Stage2::kBoxBottom3Ys, 0xffffff, true);
	DrawBox(Stage2::kBox4Xs, Stage2::kBox4Ys, Stage2::kBoxBottom4Xs, Stage2::kBoxBottom4Ys, 0xffffff, true);
	DrawBox(Stage2::kBox5Xs, Stage2::kBox5Ys, Stage2::kBoxBottom5Xs, Stage2::kBoxBottom5Ys, 0xffffff, true);
	DrawBox(Stage2::kBox6Xs, Stage2::kBox6Ys, Stage2::kBoxBottom6Xs, Stage2::kBoxBottom6Ys, 0xffffff, true);
	DrawBox(Stage2::kBox7Xs, Stage2::kBox7Ys, Stage2::kBoxBottom7Xs, Stage2::kBoxBottom7Ys, 0xffffff, true);
	DrawBox(Stage2::kBox8Xs, Stage2::kBox8Ys, Stage2::kBoxBottom8Xs, Stage2::kBoxBottom8Ys, 0xffffff, true);

	//3階地面
	DrawBox(Stage2::kBox1Xt, Stage2::kBox1Yt, Stage2::kBoxBottom1Xt, Stage2::kBoxBottom1Yt, 0xffffff, true);
	DrawBox(Stage2::kBox2Xt, Stage2::kBox2Yt, Stage2::kBoxBottom2Xt, Stage2::kBoxBottom2Yt, 0xffffff, true);
	DrawBox(Stage2::kBox3Xt, Stage2::kBox3Yt, Stage2::kBoxBottom3Xt, Stage2::kBoxBottom3Yt, 0xffffff, true);
	DrawBox(Stage2::kBox4Xt, Stage2::kBox4Yt, Stage2::kBoxBottom4Xt, Stage2::kBoxBottom4Yt, 0xffffff, true);
	DrawBox(Stage2::kBox5Xt, Stage2::kBox5Yt, Stage2::kBoxBottom5Xt, Stage2::kBoxBottom5Yt, 0xffffff, true);
	DrawBox(Stage2::kBox6Xt, Stage2::kBox6Yt, Stage2::kBoxBottom6Xt, Stage2::kBoxBottom6Yt, 0xffffff, true);
	DrawBox(Stage2::kBox7Xt, Stage2::kBox7Yt, Stage2::kBoxBottom7Xt, Stage2::kBoxBottom7Yt, 0xffffff, true);
	DrawBox(Stage2::kBox8Xt, Stage2::kBox8Yt, Stage2::kBoxBottom8Xt, Stage2::kBoxBottom8Yt, 0xffffff, true);

	//4階地面
	DrawBox(Stage2::kBox1Xf, Stage2::kBox1Yf, Stage2::kBoxBottom1Xf, Stage2::kBoxBottom1Yf, 0xffffff, true);
	DrawBox(Stage2::kBox2Xf, Stage2::kBox2Yf, Stage2::kBoxBottom2Xf, Stage2::kBoxBottom2Yf, 0xffffff, true);
	DrawBox(Stage2::kBox3Xf, Stage2::kBox3Yf, Stage2::kBoxBottom3Xf, Stage2::kBoxBottom3Yf, 0xffffff, true);
	DrawBox(Stage2::kBox4Xf, Stage2::kBox4Yf, Stage2::kBoxBottom4Xf, Stage2::kBoxBottom4Yf, 0xffffff, true);
	DrawBox(Stage2::kBox5Xf, Stage2::kBox5Yf, Stage2::kBoxBottom5Xf, Stage2::kBoxBottom5Yf, 0xffffff, true);
	DrawBox(Stage2::kBox6Xf, Stage2::kBox6Yf, Stage2::kBoxBottom6Xf, Stage2::kBoxBottom6Yf, 0xffffff, true);
	DrawBox(Stage2::kBox7Xf, Stage2::kBox7Yf, Stage2::kBoxBottom7Xf, Stage2::kBoxBottom7Yf, 0xffffff, true);
	DrawBox(Stage2::kBox8Xf, Stage2::kBox8Yf, Stage2::kBoxBottom8Xf, Stage2::kBoxBottom8Yf, 0xffffff, true);

	//5階地面
	DrawBox(Stage2::kBox1XFi, Stage2::kBox1YFi, Stage2::kBoxBottom1XFi, Stage2::kBoxBottom1YFi, 0xffffff, true);
	DrawBox(Stage2::kBox2XFi, Stage2::kBox2YFi, Stage2::kBoxBottom2XFi, Stage2::kBoxBottom2YFi, 0xffffff, true);
	DrawBox(Stage2::kBox3XFi, Stage2::kBox3YFi, Stage2::kBoxBottom3XFi, Stage2::kBoxBottom3YFi, 0xffffff, true);
	DrawBox(Stage2::kBox4XFi, Stage2::kBox4YFi, Stage2::kBoxBottom4XFi, Stage2::kBoxBottom4YFi, 0xffffff, true);
	DrawBox(Stage2::kBox5XFi, Stage2::kBox5YFi, Stage2::kBoxBottom5XFi, Stage2::kBoxBottom5YFi, 0xffffff, true);
	DrawBox(Stage2::kBox6XFi, Stage2::kBox6YFi, Stage2::kBoxBottom6XFi, Stage2::kBoxBottom6YFi, 0xffffff, true);
	DrawBox(Stage2::kBox7XFi, Stage2::kBox7YFi, Stage2::kBoxBottom7XFi, Stage2::kBoxBottom7YFi, 0xffffff, true);
	DrawBox(Stage2::kBox8XFi, Stage2::kBox8YFi, Stage2::kBoxBottom8XFi, Stage2::kBoxBottom8YFi, 0xffffff, true);

	//第一梯子
	DrawBox(Stage2::kLadder1X, Stage2::kLadder1Y, Stage2::kLadderBottom1X, Stage2::kLadderBottom1Y, 0xff0000, true);
	//第二梯子
	DrawBox(Stage2::kLadder2X, Stage2::kLadder2Y, Stage2::kLadderBottom2X, Stage2::kLadderBottom2Y, 0xff0000, true);
	//第三梯子
	DrawBox(Stage2::kLadder3X, Stage2::kLadder3Y, Stage2::kLadderBottom3X, Stage2::kLadderBottom3Y, 0xff0000, true);
	//第四梯子
	DrawBox(Stage2::kLadder4X, Stage2::kLadder4Y, Stage2::kLadderBottom4X, Stage2::kLadderBottom4Y, 0xff0000, true);

	//ゴール
	DrawBox(Stage2::kGoalX, Stage2::kGoalY, Stage2::kGoalBottomX, Stage2::kGoalBottomY, 0xff00ff, false);

}
