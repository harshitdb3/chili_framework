#include "Font.h"
#include "Vec2.h"
#include"Surface.h"
#include<cassert>
#include"Colors.h"


Font::Font(std::string& Letter,Color chroma)
	:
	Sprite(Letter),
	chroma(chroma),
	FontWidth( Sprite.GetWidth() / HorFontsNumbers),
	FontHeight(Sprite.GetHeight() / VertFontNumbers)
{
	assert(FontWidth * HorFontsNumbers == Sprite.GetWidth());
	assert(FontHeight * VertFontNumbers == Sprite.GetHeight());

}

RectI Font::GetFontPixel(char c) const
{
	
	const int FinalCopy = c - ' ';
	
	const int yGlymp = FinalCopy/ HorFontsNumbers;
	const int xGlymp = FinalCopy % HorFontsNumbers;
	return RectI({xGlymp * FontWidth,yGlymp * FontHeight},FontWidth,FontHeight);
}

void Font::DrawFont(const std::string& text, const Vei2& pos, Graphics& gfx)
{
	Vei2 TempPos = pos;
	for(auto c : text)
	{
		if (c != '\n') {
		
			gfx.DrawSpriteSubstitute(TempPos.x, TempPos.y, GetFontPixel(c), { 0,800,0,600 }, Sprite, Substitute = Colors::Yellow, chroma);
			TempPos.x += FontWidth;
		}
		else {
			TempPos.y += FontHeight;
			TempPos.x = pos.x;
			continue;
		}
	}
}
