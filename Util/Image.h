#pragma once

namespace Image
{
	//プレイヤー
	const char* const kPlayerImage    = "Data/Player/red hood itch free Copy-Sheet.png";
	const char* const kPlayerImageIdle = "Data/Player/idle sheet-Sheet.png";
	//エネミー
	const char* const kEnemyFireBall = "Data/Enemy/16_sunburn_spritesheet.png";
	const char* const kEnemySnail = "Data/Enemy/snail all.png";
	const char* const kEnemyBarre = "Data/Enemy/Run-Sheet-Black.png";
	const char* const kEnemyFallen = "Data/Map/Hive.png";

	//光
	const char* const kPlayerLighting = "Data/UI/lighting2.png";
	//花火
	const char* const RocketBlue     = "Data/FireWorks/Rocket_Blue.png";
	const char* const RocketOrange   = "Data/FireWorks/RocketOrange.png";
	const char* const LongOrange     = "Data/FireWorks/Long_Orange.png";
	const char* const LongGreen      = "Data/FireWorks/Long_Green.png";
	const char* const LongBlue       = "Data/FireWorks/Long_Blue.png";
	const char* const DefaultOrange  = "Data/FireWorks/Default_Orange.png";
	const char* const DefaultGreen   = "Data/FireWorks/Default_Green.png";
	const char* const DefaultBlue    = "Data/FireWorks/Default_Blue.png";
	const char* const CrystalsOrange = "Data/FireWorks/Crystals_Orange.png";
	const char* const CrystalsGreen  = "Data/FireWorks/Crystals_Green.png";
	const char* const CrystalsBlue   = "Data/FireWorks/Crystals_Blue.png";

	//フェード用
	const char* const kFade = "Data/UI/Fade2.png";

	//体力
	const char* const kPlayerHealthBer = "Data/UI/HP2.png";

	//マップ
	const char* const kMapFirst  = "Data/Map/plx-1.png";
	const char* const kMapSecond = "Data/Map/plx-2.png";
	const char* const kMapThird  = "Data/Map/plx-3.png";
	const char* const kMapFourth = "Data/Map/plx-4.png";
	const char* const kMapFifth  = "Data/Map/plx-5.png";
	const char* const kMapTiles = "Data/Map/Tiles.png";
	const char* const kMapTiles2 = "Data/Map/Buildings.png";

	const char* const kMapTitleMain = "Data/Map/Title.png";

	const char* const kCountTime1 = "Data/Map/Map1.png";
	const char* const kCountTime2 = "Data/Map/Map2.png";
	const char* const kCountTime3 = "Data/Map/Map3.png";

	const char* const kLadder = "Data/Map/inca_back2.png";//梯子
	const char* const kMapForest = "Data/Map/Background.png";

	const char* const kMapForest0 = "Data/Map/Layer_0011_0.png";
	const char* const kMapForest1 = "Data/Map/Layer_0010_1.png";
	const char* const kMapForest2 = "Data/Map/Layer_0009_2.png";
	const char* const kMapForest3 = "Data/Map/Layer_0008_3.png";
	const char* const kMapForest4 = "Data/Map/Layer_0006_4.png";
	const char* const kMapForest5 = "Data/Map/Layer_0005_5.png";
	const char* const kMapForest6 = "Data/Map/Layer_0003_6.png";
	const char* const kMapForest7 = "Data/Map/Layer_0002_7.png";
	const char* const kMapForest8 = "Data/Map/Layer_0001_8.png";
	const char* const kMapForest9 = "Data/Map/Layer_0000_9.png";

	//マップチップ
	const char* const kMapChip       = "Data/Map/jungle tileset.png";
	const char* const kMapChipSecond = "Data/Map/SET1_decorative_obj.png";

	//エネミー
	const char* const kEnemyEye = "Data/Enemy/EyeBall Monster-Sheet.png";

}

namespace UI
{
	const char* const kButton = "Data/UI/gdb-xbox-2.png";//コントローラー画像
}

namespace Sound
{
	const char* const kBgm1 = "Data/Sound/BGM/DavidKBD - Pink Bloom Pack - 09 - Lightyear City.ogg";
	const char* const kBgm2 = "Data/Sound/BGM/DavidKBD - Pink Bloom Pack - 08 - Lost Spaceship's Signal.ogg";
	const char* const kBgmTitle = "Data/Sound/BGM/Title.wav";//ステージ用BGM
	const char* const kBgmStage = "Data/Sound/BGM/stage.wav";//ステージ用BGM
	const char* const kBgmStage2 = "Data/Sound/BGM/stage2.wav";//ステージ用BGM
	const char* const kBgmDead = "Data/Sound/BGM/Dead.mp3";//死んだ場合BGM
	const char* const kBgmClear = "Data/Sound/BGM/Clear.wav";//死んだ場合BGM

	const char* const kJump    = "Data/Sound/SE/Eat.mp3";				 //ジャンプサウンド
	const char* const kSelect  = "Data/Sound/SE/Item Drop.mp3";			 //ボタン押すサウンド
	const char* const kSelect2 = "Data/Sound/SE/Blocked.mp3";            //選択中のサウンド
	const char* const kRun     = "Data/Sound/SE/Run/Concrete 2.wav";     //走っているサウンド
	const char* const kLadder  = "Data/Sound/SE/Move/animal curious.wav";//走っているサウンド
	const char* const kDead    = "Data/Sound/SE/DeadNow.wav";//死んだ場合サウンド

	//Enemy
	const char* const kSnail   = "Data/Sound/SE/Enemy/Snail.wav";
	const char* const kBarreRun = "Data/Sound/SE/Enemy/BarreRun.wav";
	const char* const kBarreRun2 = "Data/Sound/SE/Enemy/BarreRun2.wav";
	const char* const kFire = "Data/Sound/SE/Enemy/Fire.mp3";
	const char* const kDonw = "Data/Sound/SE/Enemy/Down.mp3";
	//花火
	const char* const kFireWprkRocket = "Data/Sound/SE/Firework/rocket.mp3";
	const char* const kFireWprkBreak = "Data/Sound/SE/Firework/break.mp3";
}