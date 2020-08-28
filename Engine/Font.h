#pragma once
#include"Surface.h"
#include"Rect.h"
#include<string>
#include"Graphics.h"
#include"Vec2.h"
class Font
{
private:
	Surface Sprite;
	const int HorFontsNumbers = 32;
	const int VertFontNumbers  = 3;
	

	const int FontWidth;
	const int FontHeight;
	Color chroma;
	Color Substitute;
	

public:
	Font(std::string& Letter,Color chroma = Colors::White);
	RectI GetFontPixel(char c) const;
	void DrawFont(const std::string& text, const Vei2& pos, Graphics& gfx);

};

