#pragma once

/* RenderTarget Reference:
	https://en.wikipedia.org/wiki/Render_Target,
	http://blog.naver.com/fish19/120045605984
*/
class RenderTarget
{
public:
	RenderTarget(UINT InHeight, UINT InWidth);
	RenderTarget(const RenderTarget& InTarget);
	RenderTarget(RenderTarget&& InTarget);
	~RenderTarget();

	UINT GetWidth() const;
	UINT GetHeight() const;

	DWORD GetPixel(UINT PixelIndex) const;
	void SetPixel(UINT PixelIndex, DWORD Color);

	HBITMAP GetBitmap() const;

	void Clear(DWORD Color);

private:
	void InitBitmap();

private:
	UINT Width;
	UINT Height;
	UINT Size;
	DWORD* BitmapBits;
	HBITMAP Bitmap;

};