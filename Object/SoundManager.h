/*
#pragma once
#include <unordered_map>
#include <string>

/// <summary>
/// SEの管理を行うシングルトンクラス
/// </summary>
class SoundManager
{
public:
	/// <summary>
	/// SoundManager使用者はGetInstance()を通したから参照からしか利用できない
	/// </summary>
	/// <returns></returns>
	static SoundManager& GetInstance()
	{
		static SoundManager instance;//ここが唯一の実態
		return instance;//それの参照を返す
	}
	/// <summary>
	/// 指定のサウンドを鳴らす
	/// </summary>
	/// <param name="name">サウンド名</param>
	void Play(const wchar_t* name);

private:
	std::unordered_map<std::wstring, int>nameAndHandleTable_;
	int LoadSoundFile(const wchar_t* fileName);
	SoundManager();
	~SoundManager();
	//コピーも代入も禁止する
	SoundManager(const SoundManager&) = delete;
	void operator = (const SoundManager&) = delete;
};
*/

