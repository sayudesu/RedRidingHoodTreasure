#pragma once
#include "Vec2.h"

class PlayerAnimation
{
public:

	PlayerAnimation();
	 virtual~PlayerAnimation();

	 void Update();
	 void Draw();

public:

	//画像
	void SetHandle(int handle) { m_hPlayer = handle; }//プレイヤー画像
	void SetHandleIdle(int handle) { m_hPlayerIdle = handle; }//プレイヤー画像(アイドル状態)

	void GetPosLeft(int pos) { m_pos.x = pos; }//プレイヤーの位置座標を取得
	void GetPosTop(int pos) { m_pos.y = pos; }//プレイヤーの位置座標を取得
	void GetPosY(int y) { m_posY = y; }//プレイヤーのY位置座標を取得

private:

	int m_hPlayer;//プレイヤー画像
	int m_hPlayerIdle;//プレイヤー画像（アイドル状態）
	
	int m_posY;

	Vec2 m_pos;

};

