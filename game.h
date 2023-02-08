#pragma once

namespace Game
{
	// ウインドウモード設定
	constexpr bool kWindowMode = true;
	// マウスカーソル表示
	constexpr bool kMouseMode = true;
	// ウインドウ名
	const char* const kTitleText = "ゲーム（制作中）";
	//フォント名
	const char* const kFontName = "HG行書体";
	//const char* const kFontName = "Data/Font/GAGAGAGA FREE";
	constexpr int kFontSize = 64;
	// ウインドウサイズ
	/*constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;*/
	constexpr int kScreenWidth = 1920;
	constexpr int kScreenHeight = 1080;
	// カラーモード
	constexpr int kColorDepth = 32;		// 32 or 16
};