#include "stdafx.h"
#include "StarfieldApp.h"
#include "ScanBufferApp.h"
#include "TriangleTransformApp.h"

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	// Memory Leak Checking
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	FILE *fp;
	AllocConsole();
	freopen_s(&fp, "CONIN$", "rb", stdin);
	freopen_s(&fp, "CONOUT$", "wb", stdout);

	//StarfieldApp* App = new StarfieldApp(hInstance, nCmdShow, 2048, 200.0f, 3.0f);
	//ScanBufferApp* App = new ScanBufferApp(hInstance, nCmdShow);
	TriangleTransformApp* App = new TriangleTransformApp(hInstance, nCmdShow);
	App->Run();
	// @Todo: Add Log

	TypeSafeDelete<ScanBufferApp>(&App);
	return 0;
}