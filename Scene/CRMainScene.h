#pragma once

#include "stdafx.h"
#include "Scene\Scene.h"

class CRMainScene : public KScene
{
public:
	CRMainScene::CRMainScene();
	CRMainScene::CRMainScene(class KEngine* engine);

	virtual void Load() override;
	virtual void Tick(const float deltaTime) override;

protected:
};