/*
#include "SoundManager.h"
#include <Dxlib.h>
#include <cassert>
void SoundManager::Play(const wchar_t* name)
{
	PlaySoundMem(nameAndHandleTable_[name], DX_PLAYTYPE_BACK);
}
int SoundManager::LoadSoundFile(const wchar_t* fileName)
{
	std::wstring path = L"Data/Sound/SE";
	path += fileName;
	int handle = LoadSoundMem(path.c_str());
	assert(handle >= 0);
	nameAndHandleTable_[fileName] = handle;
	return handle;
}
SoundManager::SoundManager()
{
	LoadSoundFile(L"decide");
	LoadSoundFile(L"shot");
	LoadSoundFile(L"chageshot");
	LoadSoundFile(L"burst");
	LoadSoundFile(L"dead");
}
SoundManager::~SoundManager()
{
	
}
*/