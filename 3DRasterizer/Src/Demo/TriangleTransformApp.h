#pragma once
#include "Application.h"
#include "Matrix4x4.h"
#include "Vertex.h"

class TriangleTransformApp : public Application
{
public:
	TriangleTransformApp(HINSTANCE InInst, UINT InCmdShow);
	~TriangleTransformApp();

protected:
	virtual void OnLoopStart() override;
	virtual void UpdateAndRender() override;

private:
	float Angle;
	Vertex V1;
	Vertex V2;
	Vertex V3;

	Matrix4x4 ProjMat;

};