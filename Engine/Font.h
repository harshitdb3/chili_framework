#pragma once
#include"Surface.h"
#include"RectI.h"
#include<string>
#include"Graphics.h"
#include"Vec2.h"
class Font
{
private:
	Surface Sprite;
	const int HorFontsNumbers = 32;
	const int VertFontNumbers  = 3;
	

	int FontWidth;
	 int FontHeight;
	Color chroma;
	Color Substitute;
	

public:
	Font(std::string& Letter,Color chroma = Colors::White);
	RectI GetFontPixel(char c);
	void DrawFont(const std::string& text, const Vei2& pos, Graphics& gfx);

};

