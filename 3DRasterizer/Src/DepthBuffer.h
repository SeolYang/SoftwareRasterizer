#pragma once

MS_ALIGN(16) class DepthBuffer
{
public:
	DEFINE_ALIGNED_NEW_DELETE
	DepthBuffer(UINT InHeight, UINT InWidth);
	DepthBuffer(const DepthBuffer& InBuffer);
	DepthBuffer(DepthBuffer&& InBuffer);
	~DepthBuffer();

	inline UINT GetWidth() const { return Width; }
	inline UINT GetHeight() const { return Height; }

	float GetValue(UINT PixelIndex) const;
	float GetValue(UINT InX, UINT InY) const;
	float GetValue(const Vector2& InPosition) const;

	void SetValue(UINT PixelIndex, float Value);
	void SetValue(UINT InX, UINT InY, float Value);
	void SetValue(const Vector2& InPosition, float Value);

	void Clear(float Value);

private:
	UINT Width;
	UINT Height;
	UINT Size;
	float* Data;

};	