#pragma once
#include "ShotBase.h"

class ShotPlayer : public ShotBase
{
public:
	ShotPlayer();
	virtual ~ShotPlayer() {};

	virtual void Start(Vec2 pos);

	virtual void Update();

};

