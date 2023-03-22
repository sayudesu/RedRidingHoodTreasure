#include "DxLib.h"
#include "game.h"
#include "Scene/SceneManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetWindowSizeChangeEnableFlag(true);
	SetAlwaysRunFlag(true);
	// windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	//マウスカーソル表示
	SetMouseDispFlag(Game::kMouseMode);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);
	//CreateFontToHandle(Game::kFontName,64,-1,-1);

	SetChangeScreenModeGraphicsSystemResetFlag(false);//フルスクリーン切り替え用

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	PCSTR font_path = "Data/Font/Silver.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) 
	{
	}
	else
	{
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	//フォント変更
	ChangeFont("Silver");

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);
	//フルスクリーンかどうか
	bool isScreenSize = false;
	bool isTrigger = false;//ボタン確認
	// 最初のシーンの初期化
	SceneManager scene;
	scene.Init();

	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();

		// 画面のクリア
		ClearDrawScreen();

		
		//フルスクリーン設定
		if (CheckHitKey(KEY_INPUT_LALT))
		{
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				if (!isTrigger)
				{
					isScreenSize = !isScreenSize;
					ChangeWindowMode(isScreenSize);
					SetDrawScreen(DX_SCREEN_BACK);//描画先を再定義
				}
				
				isScreenSize = true;
			}
			else
			{
				isScreenSize = false;
			}
		}
		

		//更新処理
		scene.Update();

		//表示処理
		scene.Draw();

#if false		
		auto fps = GetFPS();// Frame Per Second
		auto drawcall = GetDrawCallCount();// 描画命令数
		DrawFormatString(200, 200, 0xffffff, "FPS=%2.2f", fps);
		DrawFormatString(200, 230, 0xffffff, "DC=%d", drawcall);
#endif

		//裏画面を表画面を入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	//メモリの解放
	scene.End();
	//DeleteFontToHandle(font);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}