#pragma once
#include "Application.h"

class StarfieldApp : public Application
{
public:
	StarfieldApp(HINSTANCE InInst, UINT InCmdShow, UINT InStarsNum, float InSpread, float InSpeed);
	~StarfieldApp();

	void InitStar(int Index);

protected:
	virtual void UpdateAndRender() override;

private:
	float Spread;
	float Speed;

	UINT StarsNum;

	Vector3* StarsPos;

};
