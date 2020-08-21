#include "Character.h"
#include "animation.h"

Character::Character(const Vec2 pos):
	Sprite("link90x90.bmp"),pos(pos)
{
	for(int i = 0 ; i<(int)Sequence::StandingLeft;i++)
	{
		AnimationFrames.push_back(animation(90, 90 * i, 90, 90, 4, Sprite, 0.16f));
	
	}
	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++)
	{
		AnimationFrames.push_back(animation(0, 90 *(i - Sequence::StandingLeft), 90, 90, 1, Sprite, 0.16f));

	}
}

void Character::SetDirection(Vec2 dir)
{
	if(dir.x < 0.0f )
	{
		iCurrentFrame = Sequence::WalkingLeft;
	}

	else if (dir.x > 0.0f)
	{
		iCurrentFrame = Sequence::WalkingRight;
	}

	else if (dir.y < 0.0f)
	{
		iCurrentFrame = Sequence::WalkingTop;
	}

	else if (dir.y > 0.0f)
	{
		iCurrentFrame = Sequence::WalkingBottom;
	}
	else 
	{
		if(velocity.x < 0.0f)
		{
			iCurrentFrame = Sequence::StandingLeft;
		}
		else if (velocity.x > 0.0f)
		{
			iCurrentFrame = Sequence::StandingRight;
		}
		else if (velocity.y < 0.0f)
		{
			iCurrentFrame = Sequence::StandingTop;
		}
		else if (velocity.x > 0.0f)
		{
			iCurrentFrame = Sequence::StandingBottom;
		}
	}
	velocity = dir * speed;
}

void Character::Draw(Graphics & gfx) const
{
	AnimationFrames[(int)iCurrentFrame].Draw((Vei2)pos, gfx, {0,800,0,600});
}

void Character::Update(float dt)
{
	pos += velocity * dt;
	AnimationFrames[(int)iCurrentFrame].Update(dt);
}
