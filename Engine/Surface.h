#pragma once
#include "Colors.h"

class Surface {
public:
	Surface(int Width, int Height);
	Surface(const Surface& rhs);
	~Surface();
	Surface& operator=(const Surface& rhs);
	void PutPixel(int x, int y,Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const ;

private: 
	Color* Ppixel = nullptr;
	int Width;
	int Height;
	
};