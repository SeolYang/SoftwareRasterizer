#include "stdafx.h"
#include "Vector.h"
#include "RenderTarget.h"
#include "StarfieldApp.h"

StarfieldApp::StarfieldApp(HINSTANCE InInst, UINT InCmdShow, UINT InStarsNum, float InSpread, float InSpeed) :
	Spread(InSpread),
	Speed(InSpeed),
	StarsNum(InStarsNum),
	StarsPos(new Vector3[InStarsNum]),
	Application(InInst, InCmdShow)
{
	for (int Index = (InStarsNum - 1); Index; --Index)
	{
		InitStar(Index);
	}
}

StarfieldApp::~StarfieldApp()
{
	delete[] StarsPos;
}

void StarfieldApp::InitStar(int Index)
{
	if (Index >= 0 && Index < StarsNum)
	{
		StarsPos[Index].X = 2 * (static_cast<float>(SRMath::Random01()) - 0.5f) * Spread;
		StarsPos[Index].Y = 2 * (static_cast<float>(SRMath::Random01()) - 0.5f) * Spread;
		StarsPos[Index].Z = (static_cast<float>(SRMath::Random01() + 0.00001f)) * Spread;
	}
}

void StarfieldApp::UpdateAndRender()
{
	RenderTarget* BackBuffer = GetBackBuffer();
	BackBuffer->Clear(0);

	float DeltaTime = GetDeltaTime();

	for (int Index = (StarsNum - 1); Index; --Index)
	{
		StarsPos[Index].Z -= (DeltaTime * Speed);

		if (StarsPos[Index].Z <= 0.0f)
		{
			InitStar(Index);
		}

		// To Screen Space
		Vector2 WinSize = GetWinSize() * 0.5f;
		int X = static_cast<int>(StarsPos[Index].X / (DEGREE_TAN(70.0f) * StarsPos[Index].Z) * WinSize.X + WinSize.X);
		int Y = static_cast<int>(StarsPos[Index].Y / (DEGREE_TAN(70.0f) * StarsPos[Index].Z) * WinSize.Y + WinSize.Y);

		UINT Width = BackBuffer->GetWidth();
		UINT Height = BackBuffer->GetHeight();
		if (X >= Width ||
			Y >= Height ||
			X < 0 || Y < 0)
		{
			InitStar(Index);
		}
		else
		{
			BackBuffer->SetPixel(X, Y, COLOR_XRGB(255, 255, 255));
		}
	}

	Present();
}