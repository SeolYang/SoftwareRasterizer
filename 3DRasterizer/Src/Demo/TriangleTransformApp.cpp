#include "TriangleTransformApp.h"
#include "RenderTarget.h"
#include "Rasterizer.h"

TriangleTransformApp::TriangleTransformApp(HINSTANCE InInst, UINT InCmdShow) :
	Angle(0.0f),
	V1(-1.0f, -1.0f, 0.0f),
	V2(0.0f, 1.0f, 0.0f),
	V3(1.0f, -1.0f, 0.0f),
	Application(InInst, InCmdShow)
{

}

TriangleTransformApp::~TriangleTransformApp()
{

}

void TriangleTransformApp::OnLoopStart()
{
	this->SetFPSDebug(true);
	RenderTarget* BackBuffer = GetBackBuffer();
	ProjMat = Matrix4x4::CreatePerspectiveProj(
		140.0f,
		BackBuffer->GetWidth() / static_cast<float>(BackBuffer->GetHeight()), 
		0.1f, 
		1000.0f);

	GetRasterizer()->SetTargets(BackBuffer, GetDepthBuffer());
}

void TriangleTransformApp::UpdateAndRender()
{
	Angle -= 30.0f * GetDeltaTime();
	if (Angle >= 360.0f)
	{
		Angle = 0.0f;
	}

	RenderTarget* BackBuffer = GetBackBuffer();
	BackBuffer->Clear(COLOR_XRGB(0, 0, 0));
	Matrix4x4 RotMat = Matrix4x4::CreateRotation(0.0f, Angle, 0.0f);
	Matrix4x4 TransMat = Matrix4x4::CreateTransition(0.0f, 0.0f, 3.0f);
	Matrix4x4 ResultMat = ProjMat * TransMat * RotMat;

	GetRasterizer()->FillTriangle(V1.Transform(ResultMat), V2.Transform(ResultMat), V3.Transform(ResultMat), COLOR_XRGB(0, 255, 0));
	Present();
}