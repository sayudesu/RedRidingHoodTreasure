#pragma once

namespace Image
{
	//プレイヤー
	const char* const kPlayerImage    = "Data/Player/red hood itch free Copy-Sheet.png";
	const char* const kPlayerImageIdle = "Data/Player/idle sheet-Sheet.png";
	//エネミー
	const char* const kEnemyFireBall = "Data/Enemy/16_sunburn_spritesheet.png";

	//光
	const char* const kPlayerLighting = "Data/UI/lighting2.png";

	//体力
	const char* const kPlayerHealthBer = "Data/UI/HP2.png";

	//マップ
	const char* const kMapFirst  = "Data/Map/plx-1.png";
	const char* const kMapSecond = "Data/Map/plx-2.png";
	const char* const kMapThird  = "Data/Map/plx-3.png";
	const char* const kMapFourth = "Data/Map/plx-4.png";
	const char* const kMapFifth  = "Data/Map/plx-5.png";

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

namespace FX
{
	const char* const kBgm1 = "Data/Sound/BGM/DavidKBD - Pink Bloom Pack - 09 - Lightyear City.ogg";
	const char* const kBgm2 = "Data/Sound/BGM/DavidKBD - Pink Bloom Pack - 08 - Lost Spaceship's Signal.ogg";

	const char* const kJump = "Data/Sound/FX/Eat.mp3";//ジャンプサウンド
	const char* const kSelect = "Data/Sound/FX/Item Drop.mp3";//ボタン押すサウンド
	const char* const kSelect2 = "Data/Sound/FX/Blocked.mp3";//選択中のサウンド
	const char* const kAttack = "Data/Sound/FX/Power Hit.mp3";//プレイヤーが攻撃した場合のサウンド
	const char* const kDead = "Data/Sound/FX/Move/need edit.wav";//死んだ場合のサウンド
	const char* const kRun = "Data/Sound/FX/Run/Concrete 2.wav";//走っているサウンド
	const char* const kLadder = "Data/Sound/FX/Move/animal curious.wav";//走っているサウンド
}