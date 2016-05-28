#pragma once
#include "Application.h"

class ScanBufferApp : public Application
{
public:
	ScanBufferApp(HINSTANCE InInst, UINT InCmdShow);
	~ScanBufferApp();

protected:
	virtual void OnLoopStart() override;
	virtual void UpdateAndRender() override;

};