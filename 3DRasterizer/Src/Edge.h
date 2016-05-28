#pragma once

class Vertex;
class Edge
{
public:
	Edge(const Vertex& VStart, const Vertex& VEnd);
	Edge(const Edge& InEdge);

	void Step();

	inline float GetX() const { return X; }
	inline float GetXStep() const { return XStep; }
	inline int GetYStart() const { return YStart; }
	inline int GetYEnd() const { return YEnd; }

private:
	float X;
	float XStep;
	int YStart;
	int YEnd;

};