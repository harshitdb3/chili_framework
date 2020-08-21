//#include "animation.h"
//#include<vector>
//
//
//animation::animation(int x, int y,int width,int height, const Surface& Sprite, float HoldTime, int NFrames, Color Chroma)
//	:
//	Sprite(Sprite),
//	Chroma(Chroma),
//	HoldTime(HoldTime)
//{
//
//	for (int i = 0; i < NFrames; i++)
//	{
//		Frames.emplace_back(x + i * width, x + (i + 1 ) * width, y , y * height);
//
//    }
//}
//
//void animation::Draw(const Vei2 & position,  Graphics & gfx, const RectI & Clip) const
//{
//
//	gfx.DrawSprite(position.x, position.y, Frames[Currentframe],Clip,Sprite,Chroma );
//}
//
//void animation::Draw(const Vei2 & position, Graphics & gfx) const
//{
//	gfx.DrawSpriteWithoutChroma(position.x, position.y, Frames[Currentframe]);
//
//}
//
//void animation::Update(float DeltaTime)
//{
//	while ((CurrentFrameTime += DeltaTime) > HoldTime)
//	{
//		Advance();
//		CurrentFrameTime -= DeltaTime;
//
//	}
//}
//
//void animation::Advance()
//{
//	if (++Currentframe == Frames.size())
//	{
//
//		Currentframe = 0;
//	}
//}

#include "animation.h"

animation::animation(int x, int y, int width, int height, int count,
	const Surface& sprite, float holdTime, Color chroma)
	:
	sprite(sprite),
	holdTime(holdTime),
	chroma(chroma)
{
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back(x + i * width, x + (i + 1) * width, y, y + height);
	}
}

//void animation::Draw(const Vei2 & pos, Graphics & gfx) const
//{
//	gfx.DrawSprite(pos.x, pos.y, sprite);
//}

//void animation::Draw(const Vei2& pos, Graphics& gfx) const
//{
//	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame],);
//}

void animation::Draw(const Vei2& pos, Graphics& gfx, const RectI& clip) const
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], clip, sprite, chroma);
}

void animation::Update(float dt)
{
	curFrameTime += dt;
	while (curFrameTime >= holdTime)
	{
		Advance();
		curFrameTime -= holdTime;
	}
}

void animation::Advance()
{
	if (++iCurFrame >= frames.size())
	{
		iCurFrame = 0;
	}
}
