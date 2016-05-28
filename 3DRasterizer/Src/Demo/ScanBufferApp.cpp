#include "stdafx.h"
#include "Rasterizer.h"
#include "Vertex.h"
#include "RenderTarget.h"
#include "Matrix4x4.h"
#include "ScanBufferApp.h"

ScanBufferApp::ScanBufferApp(HINSTANCE InInst, UINT InCmdShow) :
	Application(InInst, InCmdShow)
{

}

ScanBufferApp::~ScanBufferApp()
{

}

void ScanBufferApp::OnLoopStart()
{
	Rasterizer* RasterizerInst = GetRasterizer();
	RasterizerInst->SetTargets(GetBackBuffer(), GetDepthBuffer());
	//RasterizerInst->DrawScanBuffer(400, 50, 350);
	//RasterizerInst->DrawScanBuffer(402, 20, 360);
	//RasterizerInst->DrawScanBuffer(404, 40, 370);
	//RasterizerInst->DrawScanBuffer(406, 30, 380);
	//RasterizerInst->DrawScanBuffer(408, 70, 390);
	//RasterizerInst->DrawScanBuffer(410, 10, 400);
	//RasterizerInst->DrawScanBuffer(412, 90, 410);

	//for (int Index = 100; Index < 200; ++Index)
	//{
	//	RasterizerInst->DrawScanBuffer(Index, 300 - Index, 300 + Index);
	//}

}

void ScanBufferApp::UpdateAndRender()
{
	RenderTarget* BackBuffer = GetBackBuffer();
	BackBuffer->Clear(0);

	Vector2 WinSize = GetWinSize();
	//GetRasterizer()->FillShape(0, 300, COLOR_XRGB(255, 255, 255));

	static Matrix4x4 ScaleMat = Matrix4x4::CreateScale(4.0f, 1.0f, 1.0f);
	static Vertex MinYVert = Vertex(Vector4(100.0f, 0.0f, 0.0f, 1.0f), Vector3(), Vector2());
	static Vertex MidYVert = Vertex(Vector4(120.0f, 200.0f, 0.0f, 1.0f), Vector3(), Vector2());
	static Vertex MaxYVert = Vertex(Vector4(80.0f, 300.0f, 0.0f, 1.0f), Vector3(), Vector2());

	GetRasterizer()->FillTriangle(MinYVert.Transform(ScaleMat), MidYVert.Transform(ScaleMat), MaxYVert.Transform(ScaleMat), COLOR_XRGB(0, 255, 0));

	Present();
}