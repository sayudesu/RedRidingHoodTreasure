#pragma once
class TitleCursor;
class TitleCollision
{
public:

	TitleCollision();
	~TitleCollision();

	void Init();
	void Update();
	void Draw();

public:

	bool CollsionDemo();
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	bool CollsionStage1();
	float DistanceSqrfStage1(const float t_x1, const float t_y1, const float t_x2, const float t_y2);
	bool CollsionEnd();
	float DistanceSqrfEnd(const float t_x1, const float t_y1, const float t_x2, const float t_y2);

private:

	TitleCursor* m_pCursor;

};

