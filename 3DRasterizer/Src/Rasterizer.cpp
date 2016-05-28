#include "stdafx.h"
#include "Vector.h"
#include "Vertex.h"
#include "Edge.h"
#include "Matrix4x4.h"
#include "RenderTarget.h"
#include "DepthBuffer.h"
#include "Rasterizer.h"

Rasterizer::Rasterizer(Application* App) :
	CurrentApp(App),
	CurrentRenderTarget(nullptr),
	CurrentDepthBuffer(nullptr),
	ScanBuffer(nullptr)
{

}

Rasterizer::~Rasterizer()
{
	CurrentApp			 = nullptr;
	CurrentRenderTarget  = nullptr;
	CurrentDepthBuffer   = nullptr;
}

void Rasterizer::SetTargets(RenderTarget* Target, DepthBuffer* TargetDepth)
{
	CurrentRenderTarget = Target;
	CurrentDepthBuffer  = TargetDepth;

	if (CurrentRenderTarget != nullptr)
	{
		Width  = Target->GetWidth();
		Height = Target->GetHeight();
	}
	else if (CurrentDepthBuffer != nullptr)
	{
		Width  = TargetDepth->GetWidth();
		Height = TargetDepth->GetHeight();
	}

	if (ScanBuffer != nullptr)
	{
		TypeSafeDelete<int>(&ScanBuffer);
	}

	if (Height != 0)
	{
		ScanBuffer = new int[Height * 2];
		ZeroMemory(ScanBuffer, sizeof(int) * Height * 2);
	}
}

void Rasterizer::DrawScanBuffer(int YCoord, int XMin, int XMax)
{
	ScanBuffer[YCoord * 2    ] = XMin;
	ScanBuffer[YCoord * 2 + 1] = XMax;
}

void Rasterizer::FillShape(int YMin, int YMax, DWORD Color)
{
	if (ScanBuffer != nullptr)
	{
		for (int Y = YMin; Y < static_cast<int>(YMax); ++Y)
		{
			int XMin = ScanBuffer[Y * 2];
			int XMax = ScanBuffer[Y * 2 + 1];

			for (int X = XMin; X < static_cast<int>(XMax); ++X)
			{
				CurrentRenderTarget->SetPixel(X, Y, Color);
			}
		}
	}
}

void Rasterizer::FillTriangle(const Vertex& V1, const Vertex& V2, const Vertex& V3, DWORD Color)
{
	Matrix4x4 ScreenSpaceMat = Matrix4x4::CreateScreenSpace(Width / 2.0f, Height / 2.0f);
	Vertex MinYVert = V1.Transform(ScreenSpaceMat);
	Vertex MidYVert = V2.Transform(ScreenSpaceMat);
	Vertex MaxYVert = V3.Transform(ScreenSpaceMat);

	MinYVert.PerspectiveDevide();
	MidYVert.PerspectiveDevide();
	MaxYVert.PerspectiveDevide();

 	if (MaxYVert.Position.Y < MidYVert.Position.Y)
	{
		Vertex Temp = MaxYVert;
		MaxYVert	= MidYVert;
		MidYVert	= Temp;
	}

	if (MidYVert.Position.Y < MinYVert.Position.Y)
	{
		Vertex Temp = MidYVert;
		MidYVert	= MinYVert;
		MinYVert	= Temp;
	}

	if (MaxYVert.Position.Y < MidYVert.Position.Y)
	{
		Vertex Temp = MaxYVert;
		MaxYVert	= MidYVert;
		MidYVert	= Temp;
	}

	Vector4 MinToMax   = MaxYVert.Position - MinYVert.Position;
	Vector4 MinToMid   = MidYVert.Position - MinYVert.Position;
	float TriangleArea = (Vector2(MinToMax.X, MinToMax.Y)) ^ (Vector2(MinToMid.X, MinToMid.Y));
	ScanTriangle(MinYVert, MidYVert, MaxYVert, TriangleArea >=0);
}

void Rasterizer::ScanConvertLine(const Vertex& MinYVert, const Vertex& MaxYVert, int Handedness)
{
	int YStart = static_cast<int>(ceil(MinYVert.Position.Y));
	int YEnd   = static_cast<int>(ceil(MaxYVert.Position.Y));
	int XStart = static_cast<int>(ceil(MinYVert.Position.X));
	int XEnd   = static_cast<int>(ceil(MaxYVert.Position.X));

	float YDist = MaxYVert.Position.Y - MinYVert.Position.Y;
	float XDist = MaxYVert.Position.X - MinYVert.Position.X;

	if (YDist <= 0.0f)
	{
		return;
	}

	float XStep = static_cast<float>(XDist) / static_cast<float>(YDist);
	float YPrestep = YStart - MinYVert.Position.Y;
	float CurX = MinYVert.Position.X + (YPrestep * XStep);

	for (int Y = YStart; Y < YEnd; ++Y)
	{
		ScanBuffer[Y * 2 + Handedness] = static_cast<int>(ceil(CurX));
		CurX += XStep;
	}
}

void Rasterizer::ScanConvertTriangle(const Vertex& MinYVert, const Vertex& MidYVert, const Vertex& MaxYVert, int Handedness)
{
	ScanConvertLine(MinYVert, MaxYVert, 0 + Handedness);
	ScanConvertLine(MinYVert, MidYVert, 1 - Handedness);
	ScanConvertLine(MidYVert, MaxYVert, 1 - Handedness);
}

void Rasterizer::ScanTriangle(const Vertex& MinYVert, const Vertex& MidYVert, const Vertex& MaxYVert, bool IsHandedness)
{
	Edge TopToBottom	= Edge(MinYVert, MaxYVert);
	Edge TopToMiddle	= Edge(MinYVert, MidYVert);
	Edge MiddleToBottom = Edge(MidYVert, MaxYVert);

	ScanEdges(&TopToBottom, &TopToMiddle, IsHandedness);
	ScanEdges(&TopToBottom, &MiddleToBottom, IsHandedness);
}

void Rasterizer::ScanEdges(Edge* a, Edge* b, bool IsHandedness)
{
	Edge* Left = a;
	Edge* Right = b;
	if (IsHandedness)
	{
		Edge* Temp = Left;
		Left = Right;
		Right = Temp;
	}

	int YStart = b->GetYStart();
	int YEnd = b->GetYEnd();
	for (int Y = YStart; Y < YEnd; ++Y)
	{
		DrawScanLine(*Left, *Right, Y);
		Left->Step();
		Right->Step();
	}
}

void Rasterizer::DrawScanLine(const Edge& Left, const Edge& Right, int Y)
{
	int XMin = static_cast<int>(ceil(Left.GetX()));
	int XMax = static_cast<int>(ceil(Right.GetX()));

		for (int X = XMin; X < XMax; ++X)
		{
			CurrentRenderTarget->SetPixel(X, Y, COLOR_XRGB(255, 255, 255));
		}
}