#include "stdafx.h"
#include "Vector.h"
#include "Vertex.h"

Vertex::Vertex()
{

}

Vertex::Vertex(const Vector3& InPosition, const Vector3& InNormal, const Vector2& InTexCoord) :
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