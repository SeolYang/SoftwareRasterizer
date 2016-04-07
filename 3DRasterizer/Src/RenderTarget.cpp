#include "stdafx.h"
#include "RenderTarget.h"

RenderTarget::RenderTarget(UINT InWidth, UINT InHeight) :
	Width(InWidth),
	Height(InHeight),
	Size(InWidth * InHeight)
{
	InitBitmap();
}

RenderTarget::RenderTarget(const RenderTarget& InTarget) :
	RenderTarget(InTarget.Width, InTarget.Height)
{
	memcpy(BitmapBits, InTarget.BitmapBits, sizeof(DWORD) * Size);
}

RenderTarget::RenderTarget(RenderTarget&& InTarget) :
	Width(InTarget.Width),
	Height(InTarget.Height),
	Size(InTarget.Size)
{
	BitmapBits = InTarget.BitmapBits;
	Bitmap = InTarget.Bitmap;

	InTarget.BitmapBits = nullptr;
	InTarget.Bitmap = nullptr;
}

RenderTarget::~RenderTarget()
{
	if (BitmapBits != nullptr)
	{
		BitmapBits = nullptr;

		//@TODO: Leave log message when delete object was fail.
		if (DeleteObject(Bitmap))
		{
			Bitmap = nullptr;
		}
	}
}

UINT RenderTarget::GetWidth() const
{
	return Width;
}

UINT RenderTarget::GetHeight() const
{
	return Height;
}

DWORD RenderTarget::GetPixel(UINT PixelIndex) const
{
	return BitmapBits[PixelIndex];
}

void RenderTarget::SetPixel(UINT PixelIndex, DWORD Color)
{
	BitmapBits[PixelIndex] = Color;
}

HBITMAP RenderTarget::GetBitmap() const
{
	return Bitmap;
}

void RenderTarget::Clear(DWORD Color)
{
	for (int Index = (Size - 1); Index; --Index)
	{
		BitmapBits[Index] = Color;
	}
}

void RenderTarget::InitBitmap()
{
	/*
	BITMAPINFOHEADER Reference: http://blog.naver.com/bfhj0708/220640285854
	CreateDIBSection Reference: http://blog.hs.pe.kr/40034125078
	*/
	BITMAPINFO Info;
	ZeroMemory(&Info, sizeof(BITMAPINFO));
	Info.bmiHeader.biSize = sizeof(BITMAPINFO);
	Info.bmiHeader.biWidth = Width;
	Info.bmiHeader.biHeight = Height;
	Info.bmiHeader.biBitCount = 32;
	Info.bmiHeader.biCompression = BI_RGB;
	Info.bmiHeader.biPlanes = 1;

	Bitmap = CreateDIBSection(
		nullptr,
		&Info,
		DIB_RGB_COLORS,
		reinterpret_cast<void**>(&BitmapBits), 
		nullptr,
		0);
}