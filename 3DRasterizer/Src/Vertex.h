#pragma once
#include "Vector.h"

/*
* This class representing Vertex.
*/
class Matrix4x4;
MS_ALIGN(16) class Vertex
{
public:
	Vector4 Position;
	Vector3 Normal;
	Vector2 TexCoord;

public:
	DEFINE_ALIGNED_NEW_DELETE
	Vertex(float X, float Y, float Z);
	Vertex(const Vector4& InPosition, const Vector3& InNormal, const Vector2& InTexCoord);
	Vertex(const Vertex& InVert);

	void PerspectiveDevide();

	Vertex Transform(const Matrix4x4& InM) const;

};