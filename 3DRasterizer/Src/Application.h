#pragma once
#include "stdafx.h"
#include "Vector.h"

#undef DEFAULT_WIN_WIDTH
#define DEFAULT_WIN_WIDTH 800.0f
#undef DEFAULT_WIN_HEIGHT
#define DEFAULT_WIN_HEIGHT 600.0f

class Rasterizer;
class RenderTarget;
class DepthBuffer;
MS_ALIGN(16) class Application
{
public:
	DEFINE_ALIGNED_NEW_DELETE

	Application(HINSTANCE InInst, int InCmdShow);
	Application(const Application&) = delete;
	virtual ~Application();

	static Application* GetInstance();
	virtual bool Run() final;
	virtual void Resize() final;

	inline float GetDeltaTime() const { return DeltaTime; }
	inline float GetElasedTime() const { return ElasedTime; }
	inline int GetFPS() const { return FPS; }

	inline void SetFPSDebug(bool IsDebug) { bIsFPSDebug = IsDebug; }
	inline bool IsFpsDebug() const { return bIsFPSDebug; }

	inline Rasterizer* GetRasterizer() const { return RasterizerInstance; }
	inline RenderTarget* GetBackBuffer() const { return BackBufferTarget; }
	inline DepthBuffer* GetDepthBuffer() const { return BackBufferDepth; }
	inline const Vector2 GetWinSize() const { return WinSize; }

	void Present();

protected:
	virtual void UpdateAndRender();

	/* Called Before Application Initialize Start */
	virtual void OnInitStart();

	/* Called When Application Start Main Loop */
	virtual void OnLoopStart();

private:
	bool Init();
	bool WinInit();
	bool D3DInit();

	void MainLoop();

private:
	static Application* Instance;

	Vector2 WinSize;

	int CmdShow;
	HINSTANCE hInstance;
	HWND hWnd;

	LPDIRECT3D9 D3D;
	LPDIRECT3DDEVICE9 D3DDevice;
	LPDIRECT3DSURFACE9 BackBuffer;

	Rasterizer* RasterizerInstance;
	RenderTarget* BackBufferTarget;
	DepthBuffer* BackBufferDepth;

	float ElasedTime;
	float DeltaTime;

	bool bIsFPSDebug;
	long FrameCount;
	int FPS;
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);