#include "stdafx.h"
#include "Edge.h"
#include "Vertex.h"

Edge::Edge(const Vertex& VStart, const Vertex& VEnd) :
	YStart(static_cast<int>(ceil(VStart.Position.Y))),
	YEnd(static_cast<int>(ceil(VEnd.Position.Y))),
	XStep(0.0f),
	X(0.0f)
{
	float YDist = VEnd.Position.Y - VStart.Position.Y;
	float XDist = VEnd.Position.X - VStart.Position.X;

	if (YDist > 0.0f)
	{
		float YPrestep = YStart - VStart.Position.Y;
		XStep = XDist / YDist;
		X = VStart.Position.X + (YPrestep * XStep);
	}
}

Edge::Edge(const Edge& InEdge) :
	X(InEdge.X),
	XStep(InEdge.XStep),
	YStart(InEdge.YStart),
	YEnd(InEdge.YEnd)
{

}

void Edge::Step()
{
	X += XStep;
}