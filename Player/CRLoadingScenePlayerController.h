#pragma once

#include "stdafx.h"
#include "Player\PlayerController.h"

class CRLoadingScenePlayerController : public KPlayerController
{
public:
	CRLoadingScenePlayerController::CRLoadingScenePlayerController() = default;

	CRLoadingScenePlayerController::CRLoadingScenePlayerController(class KEngine* engine, class KScene* scene)
	{
		Engine = engine;
		Scene = scene;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRLoadingScreenInterface* Interface = nullptr;
	float CurLoadingTime = 0.f;
};