#include "DrawMapStage1.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>

DrawMapStage1::DrawMapStage1():
	m_hMap1(-1), m_hMap2(-1),//マップ用ハンドル
	m_hMap3(-1), m_hMap4(-1),
	m_hMap5(-1),
	m_hTiles(-1),
	m_hBlock(-1),
	m_hLadderChip(-1),
	m_hLadder(-1),//梯子
	m_hForest(),//マップ背景Forest
	m_hForestCut(),//背景切り取り
	m_hMapChip1(-1),//マップチップデータ
	m_hBox(-1)//箱画像

{

}

DrawMapStage1::~DrawMapStage1()
{
}

void DrawMapStage1::Init()
{

	for (int i = 0; i < 9; i++)
	{
		m_hForest[i] = 0;
		m_hForestCut[i] = 0;
	}

	//マップ画像読み込み
	m_hMap1 = LoadGraph(Image::kMapFirst);
	m_hMap2 = LoadGraph(Image::kMapSecond);
	m_hMap3 = LoadGraph(Image::kMapThird);
	m_hMap4 = LoadGraph(Image::kMapFourth);
	m_hMap5 = LoadGraph(Image::kMapFifth);
	m_hTiles = LoadGraph(Image::kMapTiles);//地面画像を読み込み

	m_hForest[0] = LoadGraph(Image::kMapForest0);//地面画像を読み込み
	m_hForest[1] = LoadGraph(Image::kMapForest2);//地面画像を読み込み
	m_hForest[2] = LoadGraph(Image::kMapForest3);//地面画像を読み込み
	m_hForest[3] = LoadGraph(Image::kMapForest4);//地面画像を読み込み
	m_hForest[4] = LoadGraph(Image::kMapForest5);//地面画像を読み込み
	m_hForest[5] = LoadGraph(Image::kMapForest6);//地面画像を読み込み
	m_hForest[6] = LoadGraph(Image::kMapForest7);//地面画像を読み込み
	m_hForest[7] = LoadGraph(Image::kMapForest8);//地面画像を読み込み
	m_hForest[8] = LoadGraph(Image::kMapForest9);//地面画像を読み込み



	m_hBlock = DerivationGraph(178 + 1, 236, 32 + 16 - 10 , 16, m_hTiles);//地面画像から一部を抽出

	int sizeX, sizeY;
	GetGraphSize(m_hForest[0],& sizeX, &sizeY);
	m_hForestCut[0] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[0]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[1], &sizeX, &sizeY);
	m_hForestCut[1] = DerivationGraph(0,250, sizeX, sizeY, m_hForest[1]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[2], &sizeX, &sizeY);
	m_hForestCut[2] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[2]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[3], &sizeX, &sizeY);
	m_hForestCut[3] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[3]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[4], &sizeX, &sizeY);
	m_hForestCut[4] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[4]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[5], &sizeX, &sizeY);
	m_hForestCut[5] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[5]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[6], &sizeX, &sizeY);
	m_hForestCut[6] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[6]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[7], &sizeX, &sizeY);
	m_hForestCut[7] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[7]);//地面画像から一部を抽出
	GetGraphSize(m_hForest[8], &sizeX, &sizeY);
	m_hForestCut[8] = DerivationGraph(0, 250, sizeX, sizeY, m_hForest[8]);//地面画像から一部を抽出

	//m_hTiles = LoadGraph(Image::kMapTiles);

	m_hMapChip1 = LoadGraph(Image::kMapTiles);
	m_hBox = DerivationGraph(288, 272, 32, 32, m_hMapChip1);//地面画像から一部を抽出

	m_hLadderChip = LoadGraph(Image::kLadder);//梯子読み込み
	m_hLadder = DerivationGraph(48, 160, 16, 32, m_hLadderChip);//画像の一部を読み込み
}

void DrawMapStage1::End()
{
	DeleteGraph(m_hMap1);
	DeleteGraph(m_hMap2);
	DeleteGraph(m_hMap3);
	DeleteGraph(m_hMap4);
	DeleteGraph(m_hMap5);
	DeleteGraph(m_hTiles);
	DeleteGraph(m_hBlock);

	for (int i = 0; i < 9; i++)
	{
		DeleteGraph(m_hForest[i]);
		DeleteGraph(m_hForestCut[i]);
	}

	DeleteGraph(m_hMapChip1);
	DeleteGraph(m_hBox);
}

void DrawMapStage1::Update()
{
}

void DrawMapStage1::Draw()
{
	DrawGraph(100, 100, m_hBox, true);

	DrawBackground();//マップの背景を表示
	DrawMap();//マップ表示

	//第一梯子
	DrawExtendGraph(Stage1::kLadder1X - 8, Stage1::kLadder1Y, Stage1::kLadderBottom1X + 8, Stage1::kLadderBottom1Y, m_hLadder, true);//判定確認用
	//DrawBox(Stage1::kLadder1X, Stage1::kLadder1Y, Stage1::kLadderBottom1X, Stage1::kLadderBottom1Y, 0xff0000, false);
	//第二梯子
	DrawExtendGraph(Stage1::kLadder2X - 8, Stage1::kLadder2Y, Stage1::kLadderBottom2X + 8, Stage1::kLadderBottom2Y, m_hLadder, true);//判定確認用
	//DrawBox(Stage1::kLadder2X, Stage1::kLadder2Y, Stage1::kLadderBottom2X, Stage1::kLadderBottom2Y, 0xff0000, false);

	//ゴール
	DrawExtendGraph(Stage1::kGoalX, Stage1::kGoalY, Stage1::kGoalBottomX, Stage1::kGoalBottomY, m_hBox, true);
	//DrawBox(Stage1::kGoalX, Stage1::kGoalY, Stage1::kGoalBottomX, Stage1::kGoalBottomY, 0xff00ff, false);

}

void DrawMapStage1::DrawBackground()
{
	for (int i = 0; i < 9; i++)//背景を描画
	{
		DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hForestCut[i], true);
	}
}

void DrawMapStage1::DrawMap()
{
	//1階地面
	DrawExtendGraph(Stage1::kBox1X, Stage1::kBox1Y - 2, Stage1::kBoxBottom1X, Stage1::kBoxBottom1Y, m_hBlock, true);
	//DrawBox(Stage1::kBox1X, Stage1::kBox1Y, Stage1::kBoxBottom1X, Stage1::kBoxBottom1Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox2X, Stage1::kBox2Y - 2, Stage1::kBoxBottom2X, Stage1::kBoxBottom2Y, m_hBlock, true);
	//DrawBox(Stage1::kBox2X, Stage1::kBox2Y, Stage1::kBoxBottom2X, Stage1::kBoxBottom2Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox3X, Stage1::kBox3Y - 2, Stage1::kBoxBottom3X, Stage1::kBoxBottom3Y, m_hBlock, true);
	//DrawBox(Stage1::kBox3X, Stage1::kBox3Y, Stage1::kBoxBottom3X, Stage1::kBoxBottom3Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox4X, Stage1::kBox4Y - 2, Stage1::kBoxBottom4X, Stage1::kBoxBottom4Y, m_hBlock, true);
	//DrawBox(Stage1::kBox4X, Stage1::kBox4Y, Stage1::kBoxBottom4X, Stage1::kBoxBottom4Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox5X, Stage1::kBox5Y - 2, Stage1::kBoxBottom5X, Stage1::kBoxBottom5Y, m_hBlock, true);
	//DrawBox(Stage1::kBox5X, Stage1::kBox5Y, Stage1::kBoxBottom5X, Stage1::kBoxBottom5Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox6X, Stage1::kBox6Y - 2, Stage1::kBoxBottom6X, Stage1::kBoxBottom6Y, m_hBlock, true);
	//DrawBox(Stage1::kBox6X, Stage1::kBox6Y, Stage1::kBoxBottom6X, Stage1::kBoxBottom6Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox7X, Stage1::kBox7Y - 2, Stage1::kBoxBottom7X, Stage1::kBoxBottom7Y, m_hBlock, true);
	//DrawBox(Stage1::kBox7X, Stage1::kBox7Y, Stage1::kBoxBottom7X, Stage1::kBoxBottom7Y, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox8X, Stage1::kBox8Y - 2, Stage1::kBoxBottom8X, Stage1::kBoxBottom8Y, m_hBlock, true);
	//DrawBox(Stage1::kBox8X, Stage1::kBox8Y, Stage1::kBoxBottom8X, Stage1::kBoxBottom8Y, 0xffffff, false);

	//2階地面
	DrawExtendGraph(Stage1::kBox1Xs, Stage1::kBox1Ys - 2, Stage1::kBoxBottom1Xs, Stage1::koxBottom1Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox1Xs, Stage1::kBox1Ys, Stage1::kBoxBottom1Xs, Stage1::koxBottom1Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox2Xs, Stage1::kBox2Ys - 2, Stage1::kBoxBottom2Xs, Stage1::kBoxBottom2Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox2Xs, Stage1::kBox2Ys, Stage1::kBoxBottom2Xs, Stage1::kBoxBottom2Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox3Xs, Stage1::kBox3Ys - 2, Stage1::kBoxBottom3Xs, Stage1::kBoxBottom3Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox3Xs, Stage1::kBox3Ys, Stage1::kBoxBottom3Xs, Stage1::kBoxBottom3Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox4Xs, Stage1::kBox4Ys - 2, Stage1::kBoxBottom4Xs, Stage1::kBoxBottom4Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox4Xs, Stage1::kBox4Ys, Stage1::kBoxBottom4Xs, Stage1::kBoxBottom4Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox5Xs, Stage1::kBox5Ys - 2, Stage1::kBoxBottom5Xs, Stage1::kBoxBottom5Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox5Xs, Stage1::kBox5Ys, Stage1::kBoxBottom5Xs, Stage1::kBoxBottom5Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox6Xs, Stage1::kBox6Ys - 2, Stage1::kBoxBottom6Xs, Stage1::kBoxBottom6Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox6Xs, Stage1::kBox6Ys, Stage1::kBoxBottom6Xs, Stage1::kBoxBottom6Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox7Xs, Stage1::kBox7Ys - 2, Stage1::kBoxBottom7Xs, Stage1::kBoxBottom7Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox7Xs, Stage1::kBox7Ys, Stage1::kBoxBottom7Xs, Stage1::kBoxBottom7Ys, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox8Xs, Stage1::kBox8Ys - 2, Stage1::kBoxBottom8Xs, Stage1::kBoxBottom8Ys, m_hBlock, true);
	//DrawBox(Stage1::kBox8Xs, Stage1::kBox8Ys, Stage1::kBoxBottom8Xs, Stage1::kBoxBottom8Ys, 0xffffff, false);

	//3階地面
	DrawExtendGraph(Stage1::kBox1Xt, Stage1::kBox1Yt - 2, Stage1::kBoxBottom1Xt, Stage1::kBoxBottom1Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox1Xt, Stage1::kBox1Yt, Stage1::kBoxBottom1Xt, Stage1::kBoxBottom1Yt, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox2Xt, Stage1::kBox2Yt - 2, Stage1::kBoxBottom2Xt, Stage1::kBoxBottom2Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox2Xt, Stage1::kBox2Yt, Stage1::kBoxBottom2Xt, Stage1::kBoxBottom2Yt, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox3Xt, Stage1::kBox3Yt - 2, Stage1::kBoxBottom3Xt, Stage1::kBoxBottom3Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox3Xt, Stage1::kBox3Yt, Stage1::kBoxBottom3Xt, Stage1::kBoxBottom3Yt, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox4Xt, Stage1::kBox4Yt - 2, Stage1::kBoxBottom4Xt, Stage1::kBoxBottom4Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox4Xt, Stage1::kBox4Yt, Stage1::kBoxBottom4Xt, Stage1::kBoxBottom4Yt, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox5Xt, Stage1::kBox5Yt - 2, Stage1::kBoxBottom5Xt, Stage1::kBoxBottom5Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox5Xt, Stage1::kBox5Yt, Stage1::kBoxBottom5Xt, Stage1::kBoxBottom5Yt, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox6Xt, Stage1::kBox6Yt - 2, Stage1::kBoxBottom6Xt, Stage1::kBoxBottom6Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox6Xt, Stage1::kBox6Yt, Stage1::kBoxBottom6Xt, Stage1::kBoxBottom6Yt, 0xffffff, false);
	DrawExtendGraph(Stage1::kBox7Xt, Stage1::kBox7Yt - 2, Stage1::kBoxBottom7Xt, Stage1::kBoxBottom7Yt, m_hBlock, true);
	//DrawBox(Stage1::kBox7Xt, Stage1::kBox7Yt, Stage1::kBoxBottom7Xt, Stage1::kBoxBottom7Yt, 0xffffff, false);
	//DrawBox(Stage1::kBox8Xt, Stage1::kBox8Yt, Stage1::kBoxBottom8Xt, Stage1::kBoxBottom8Yt, 0xffffff, true);

}
