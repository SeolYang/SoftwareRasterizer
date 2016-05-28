#include "stdafx.h"
#include "Vector.h"
#include "DepthBuffer.h"

DepthBuffer::DepthBuffer(UINT InHeight, UINT InWidth) :
	Width(InWidth),
	Height(InHeight),
	Size(InWidth * InHeight),
	Data(new float[Size])
{

}

DepthBuffer::DepthBuffer(const DepthBuffer& InBuffer) :
	DepthBuffer(InBuffer.Width, InBuffer.Height)
{
	memcpy(this->Data, InBuffer.Data, Size);
}

DepthBuffer::DepthBuffer(DepthBuffer&& InBuffer) :
	Width(InBuffer.Width),
	Height(InBuffer.Height),
	Size(InBuffer.Size),
	Data(InBuffer.Data)
{
	InBuffer.Data = nullptr;
}

DepthBuffer::~DepthBuffer()
{
	SAFE_DELETE(Data);
}

float DepthBuffer::GetValue(UINT PixelIndex) const
{
	return Data[PixelIndex];
}

float DepthBuffer::GetValue(UINT InX, UINT InY) const
{
	return Data[(InY * Width) + InX];
}

float DepthBuffer::GetValue(const Vector2& InPosition) const
{
	return Data[
		(static_cast<UINT>(InPosition.Y) * Width)
			+ static_cast<UINT>(InPosition.X)];
}

void DepthBuffer::SetValue(UINT PixelIndex, float Value)
{
	Data[PixelIndex] = Value;
}

void DepthBuffer::SetValue(UINT InX, UINT InY, float Value)
{
	Data[(InY * Width) + InX] = Value;
}

void DepthBuffer::SetValue(const Vector2& InPosition, float Value)
{
	Data[(static_cast<UINT>(InPosition.Y) * Width)
		+ static_cast<UINT>(InPosition.X)] = Value;
}

void DepthBuffer::Clear(float Value)
{
	for (int Index = (Size - 1); Index; --Index)
	{
		Data[Index] = Value;
	}
}