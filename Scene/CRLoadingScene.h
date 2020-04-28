#pragma once

#include "stdafx.h"
#include "Scene\Scene.h"

class CRLoadingScene : public KScene
{
public:
	CRLoadingScene::CRLoadingScene();
	CRLoadingScene::CRLoadingScene(class KEngine* engine);

	virtual void Load() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRLoadingScenePlayerController* PlayerController = nullptr;

	float CurLoadingTime = 0.f;
};