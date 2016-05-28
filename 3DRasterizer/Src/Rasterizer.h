#pragma once

class Application;
class RenderTarget;
class DepthBuffer;
class Vertex;
class Edge;
MS_ALIGN(16) class Rasterizer
{
public:
	DEFINE_ALIGNED_NEW_DELETE;

	Rasterizer(Application* App);
	~Rasterizer();

	void SetTargets(RenderTarget* Target, DepthBuffer* TargetDepth);

	void DrawScanBuffer(int YCoord, int XMin, int XMax);

	void FillShape(int YMin, int YMax, DWORD Color);
	void FillTriangle(const Vertex& V1, const Vertex& V2, const Vertex& V3, DWORD Color);

	void ScanConvertLine(const Vertex& MinYVert, const Vertex& MaxYVert, int Handedness);
	void ScanConvertTriangle(const Vertex& MinYVert, const Vertex& MidYVert, const Vertex& MaxYVert, int Handedness);

	void ScanTriangle(const Vertex& MinYVert, const Vertex& MidYVert, const Vertex& MaxYVert, bool IsHandedness);
	void ScanEdges(Edge* E1, Edge* E2, bool IsHandedness);
	void DrawScanLine(const Edge& Left, const Edge& Right, int Y);

private:
	Application* CurrentApp;

	RenderTarget* CurrentRenderTarget;
	DepthBuffer* CurrentDepthBuffer;
	int* ScanBuffer;

	UINT Width;
	UINT Height;

};