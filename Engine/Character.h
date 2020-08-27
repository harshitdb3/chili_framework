#pragma once

#include "animation.h"
#include "Vec2.h"
class Character
{
private:
	enum Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingTop,
		WalkingBottom,
		StandingLeft,
		StandingRight,
		StandingTop,
		StandingBottom,
		Count

	};

public:
	Character(const Vec2 pos);
	void SetDirection(const Vec2& dir);
	void Draw(Graphics &gfx) const;
	void Update(float dt);
private:
	Vec2 pos;
	Vec2 velocity = { 0.0f,0.0f };
	Surface Sprite;
	std::vector<animation> AnimationFrames;
	Sequence iCurrentFrame = Sequence::StandingBottom;
	float speed = 90.0f;
};

