#include "Surface.h"
#include <cassert>

Surface::Surface(int Width, int Height)
	:Width(Width), Height(Height), Ppixel( new Color[Width * Height])
{

}

Surface::Surface(const Surface& rhs)
	:Surface(rhs.Width,rhs.Height)
{
	const int nPixel = Width * Height;
	for (int x = 0; x < nPixel; x++) 
	{
		Ppixel[x] = rhs.Ppixel[x];
	}
}

Surface::~Surface()
{
	delete[] Ppixel;
	Ppixel = nullptr;
}

Surface& Surface::operator=(const Surface & rhs)
{
	
	Width = rhs.Width;
	Height = rhs.Height;
	delete[] Ppixel;
	Ppixel = new Color[Width *Height];
	const int nPixel = Width * Height;
	for (int x = 0; x < nPixel; x++) {
		Ppixel[x] = rhs.Ppixel[x];
	}
	return *this;
	// TODO: insert return statement here
}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >=0);
	assert(y >= 0);
	assert(x < Width);
	assert(y < Height);
	Ppixel[y * Width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{

	assert(x >= 0);
	assert(y >= 0);
	assert(x < Width);
	assert(y < Height);

	return Ppixel[y * Width + x];
}



int Surface::GetWidth() const
{
	return Width;
}

int Surface::GetHeight() const
{
	return Height;
}
