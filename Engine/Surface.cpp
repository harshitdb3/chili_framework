#include "Surface.h"
#include <cassert>
#include"ChiliWin.h"
#include <fstream>
#include<string>

Surface::Surface(int Width, int Height)
	:Width(Width), Height(Height), Ppixel( new Color[Width * Height])
{

}

Surface::Surface(const std::string& s)
{


	std::ifstream BMPFileStruct;
	assert(BMPFileStruct);
	BITMAPFILEHEADER BMPFile;
	BMPFileStruct.open(s, std::ios::binary);
	BMPFileStruct.read(reinterpret_cast<char*>(&BMPFile), sizeof(BMPFile));

	BITMAPINFOHEADER BmpInfo;
	BMPFileStruct.read(reinterpret_cast<char*>(&BmpInfo), sizeof(BmpInfo));
	{
		Width = BmpInfo.biWidth;
		int yStart;
		int yend;
		int dy;
		if (BmpInfo.biHeight < 0)
		{
			Height = -BmpInfo.biHeight;
			 yStart = 0;
			 yend = Height;
			 dy = 1;
		}
		else
		{
			Height = BmpInfo.biHeight;
			 yStart = Height - 1;
			 yend = -1;
			 dy = -1;
		}

		assert(BmpInfo.biBitCount == 24 || BmpInfo.biBitCount == 32);
		assert(BmpInfo.biCompression == BI_RGB);

		bool BitCount32 = false;
		if (BmpInfo.biBitCount == 32)
		{
			BitCount32 = true;
		}

		Ppixel = new Color[Width * Height];

		BMPFileStruct.seekg(BMPFile.bfOffBits);

		int Paddingoffset = (4 - (Width * 3) % 4) % 4;

		BMPFileStruct.seekg(BMPFile.bfOffBits);

		for (int y = yStart; y != yend; y += dy) {

			for (int x = 0; x < Width; x++) {

				PutPixel(x, y, Color(BMPFileStruct.get(), BMPFileStruct.get(), BMPFileStruct.get()));
				if (BitCount32) {
					BMPFileStruct.seekg(1, std::ios::cur);
				}
			}
			if (!BitCount32) {
				BMPFileStruct.seekg(Paddingoffset, std::ios::cur);
			}
		}

	}
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
