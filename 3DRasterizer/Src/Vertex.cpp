#include "stdafx.h"
#include "Vector.h"
#include "Matrix4x4.h"
#include "Vertex.h"

Vertex::Vertex(float X, float Y, float Z)
{
	Position = Vector4(X, Y, Z);
}

Vertex::Vertex(const Vector4& InPosition, const Vector3& InNormal, const Vector2& InTexCoord) :
	Position(InPosition),
	Normal(InNormal),
	TexCoord(InTexCoord)
{

}

Vertex::Vertex(const Vertex& InVert) :
	Position(InVert.Position),
	Normal(InVert.Normal),
	TexCoord(InVert.TexCoord)
{

}

void Vertex::PerspectiveDevide()
{
	Position.X /= Position.W;
	Position.Y /= Position.W;
	Position.Z /= Position.W;
}

Vertex Vertex::Transform(const Matrix4x4& InM) const
{
	return Vertex((InM * Position), Normal, TexCoord);
}