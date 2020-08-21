//#pragma once
//
//
//#include"Graphics.h"
//#include"Surface.h"
//#include"Game.h"
//#include"RectI.h"
//#include<vector>
//class animation
//{
//public:
//	animation(int x, int y, int width , int height,const Surface& Sprite, float HoldTime, int NFrames, Color Chroma = Colors::Magenta);
//
//	void Draw(const Vei2& position, Graphics& gfx, const RectI& Clip) const;
//	//void Draw(const Vei2& position, Graphics& gfx) const;
//	void Update(float DeltaTime);
//
//private:
//	void Advance();
//private:
//
//	Color Chroma;
//	const Surface& Sprite;
//	std::vector<RectI> Frames;
//	int Currentframe = 0;
//	float HoldTime;
//	float CurrentFrameTime = 0.0f;
//	
//};
//
#pragma once

#include "Surface.h"
#include "Graphics.h"
#include <vector>

class animation
{
public:
	animation(int x, int y, int width, int height, int count, const Surface& sprite, float holdTime, Color chroma = Colors::Magenta);
	/*void Draw(const Vei2& pos, Graphics& gfx) const;*/
	void Draw(const Vei2& pos, Graphics& gfx, const RectI& clip) const;
	void Update(float dt);
private:
	void Advance();
private:
	Color chroma;
	const Surface& sprite;
	std::vector<RectI> frames;
	int iCurFrame = 0;
	float holdTime;
	float curFrameTime = 0.0f;
};