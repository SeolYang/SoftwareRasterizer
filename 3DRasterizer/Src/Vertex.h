#pragma once

MS_ALIGN(16) class Vertex
{
public:
	Vector3 Position;
	Vector3 Normal;
	Vector2 TexCoord;

public:
	Vertex();
	Vertex(const Vector3& InPosition, const Vector3& InNormal, const Vector2& InTexCoord);
	Vertex(const Vertex& InVert);

};