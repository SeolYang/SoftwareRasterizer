#pragma once

class Scene
{
public:
	Scene(){}
	virtual ~Scene(){}
	virtual bool InitApp(){ return true; }
	virtual bool Init() { return true; }
	virtual void Update(){}

private:


};