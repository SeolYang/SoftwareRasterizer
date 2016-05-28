#include "stdafx.h"
#include "Application.h"
#include "Rasterizer.h"
#include "RenderTarget.h"
#include "DepthBuffer.h"
Application* Application::Instance = nullptr;

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

Application::Application(HINSTANCE InInst, int InCmdShow) :
	CmdShow(InCmdShow),
	WinSize(DEFAULT_WIN_WIDTH, DEFAULT_WIN_HEIGHT),
	hInstance(InInst),
	hWnd(nullptr),
	D3D(nullptr),
	D3DDevice(nullptr),
	BackBuffer(nullptr),
	BackBufferTarget(nullptr),
	ElasedTime(float()),
	DeltaTime(float()),
	bIsFPSDebug(false),
	FrameCount(long()),
	FPS(int())
{
	if (Instance != this)
	{
		delete Instance;
	}

	Instance = this;
}

Application::~Application()
{
	if (D3DDevice != nullptr)
	{
		D3DDevice->Release();
		D3DDevice = nullptr;
	}

	if (D3D != nullptr)
	{
		D3D->Release();
		D3D = nullptr;
	}

	TypeSafeDelete<RenderTarget>(&BackBufferTarget);
	TypeSafeDelete<DepthBuffer>(&BackBufferDepth);

	Instance = nullptr;
}

Application* Application::GetInstance()
{
	return Instance;
}

void Application::OnInitStart()
{

}

void Application::OnLoopStart()
{

}

bool Application::Run()
{
	// Initialize Application
	OnInitStart();
	if (!Init())
	{
		return false;
	}

	// Start Main Application MainLoop
	OnLoopStart();
	MainLoop();

	// Application End
	return true;
}

void Application::Resize()
{

}

bool Application::Init()
{
	if (!WinInit())
	{
		return false;
	}

	if (!D3DInit())
	{
		return false;
	}

	UINT WinSizeX			 = static_cast<UINT>(WinSize.X);
	UINT WinSizeY			 = static_cast<UINT>(WinSize.Y);
	this->BackBufferTarget	 = new RenderTarget(WinSizeX, WinSizeY);
	this->BackBufferDepth	 = new DepthBuffer(WinSizeX, WinSizeY);
	this->RasterizerInstance = new Rasterizer(this);

	return true;
}

bool Application::WinInit()
{
	WNDCLASSEX Wc;
	ZeroMemory(&Wc, sizeof(WNDCLASSEX));
	Wc.cbSize			= sizeof(WNDCLASSEX);
	Wc.style			= CS_VREDRAW | CS_HREDRAW;
	Wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	Wc.lpszClassName	= "WinClass";
	Wc.hInstance		= hInstance;
	Wc.lpfnWndProc		= WndProc;
	RegisterClassEx(&Wc);

	RECT WindowRect{ 0, 0, static_cast<LONG>(WinSize.X), static_cast<LONG>(WinSize.Y) };
	AdjustWindowRect(&WindowRect, WS_OVERLAPPEDWINDOW, FALSE);

	hWnd = CreateWindowEx(
		NULL,
		"WinClass",
		"Software Rasterizer",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WindowRect.right - WindowRect.left,
		WindowRect.bottom - WindowRect.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (ShowWindow(hWnd, CmdShow))
	{
		return false;
	}

	UpdateWindow(hWnd);

	return true;
}

bool Application::D3DInit()
{
	if (NULL == (D3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed				= TRUE;
	d3dpp.SwapEffect			= D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat		= D3DFMT_UNKNOWN;
	d3dpp.Flags					= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
	d3dpp.PresentationInterval  = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &D3DDevice)))
	{
		return false;
	}

	D3DDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &BackBuffer);
	if (BackBuffer == nullptr)
	{
		return false;
	}

	return true;
}

void Application::MainLoop()
{
	using namespace std;
	MSG Msg;

	DWORD PreviousTime	= 0;
	DWORD CurrentTime	= 0;

	while (true)
	{
		CurrentTime		= GetTickCount();
		DeltaTime		= (CurrentTime - PreviousTime) / 1000.0f;
		PreviousTime	= CurrentTime;

		++FrameCount;
		ElasedTime += DeltaTime;

		if (ElasedTime >= 1.0f)
		{
			FPS = static_cast<int>(static_cast<float>(FrameCount) / ElasedTime);
			if (bIsFPSDebug)
			{
				std::cout << FPS << std::endl;
			}

			ElasedTime = 0.0f;
			FrameCount = 0;
		}

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
			UpdateAndRender();
		}
		
	}
}

void Application::UpdateAndRender()
{

}

void Application::Present()
{
	D3DDevice->BeginScene();

	D3DLOCKED_RECT rcLocked;
	BackBuffer->LockRect(&rcLocked, nullptr, 0);
	DWORD* Base = (DWORD*)rcLocked.pBits;

	float Pitch = (rcLocked.Pitch * 0.25f);
	UINT Offset = 0;
	for (UINT Y = 0; Y < WinSize.Y; ++Y)
	{
		for (UINT X = 0; X < WinSize.X; ++X)
		{
			Offset = static_cast<UINT>(X + Pitch * Y);
			*(Base + Offset) = BackBufferTarget->BitmapBits[static_cast<int>((X + Y * WinSize.X))];
		}
	}

	BackBuffer->UnlockRect();

	D3DDevice->EndScene();
	D3DDevice->Present(nullptr, nullptr, nullptr, nullptr);
}