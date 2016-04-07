#include "stdafx.h"

HINSTANCE GhInstance;
HWND GhWnd;

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
	WNDCLASSEX Wc;
	ZeroMemory(&Wc, sizeof(WNDCLASSEX));
	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_VREDRAW | CS_HREDRAW;
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.lpszClassName = L"WinClass";
	Wc.hInstance = hInstance;
	Wc.lpfnWndProc = WndProc;
	RegisterClassEx(&Wc);

	RECT WindowRect{ 0, 0, WIN_WIDTH, WIN_HEIGHT };
	AdjustWindowRect(&WindowRect, WS_OVERLAPPEDWINDOW, FALSE);

	GhWnd = CreateWindowEx(
		NULL,
		L"WinClass",
		L"Software Rasterizer",
		WS_EX_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WindowRect.right - WindowRect.left,
		WindowRect.bottom - WindowRect.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(GhWnd, nCmdShow);
	UpdateWindow(GhWnd);

	MSG Msg;
	while (true)
	{
		if (PeekMessage(&Msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (Msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		else
		{
		}
	}

	return static_cast<int>(Msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}

	return DefWindowProc(hWnd, Message, wParam, lParam);
}