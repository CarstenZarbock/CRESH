#pragma once

#include "stdafx.h"
#include "Scene\Scene.h"

class CRMainMenuScene : public KScene
{
public:
	CRMainMenuScene::CRMainMenuScene();
	CRMainMenuScene::CRMainMenuScene(class KEngine* engine);

	virtual void Load() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRMainMenuPlayerController* PlayerController = nullptr;
};