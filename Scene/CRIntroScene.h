#pragma once

#include "stdafx.h"
#include "Scene\Scene.h"

class CRIntroScene : public KScene
{
public:
	CRIntroScene::CRIntroScene();
	CRIntroScene::CRIntroScene(class KEngine* engine);

	virtual void Load() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRIntroScenePlayerController* PlayerController = nullptr;

	float CurLoadingTime = 0.f;
};