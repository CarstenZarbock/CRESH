#pragma once

#include "stdafx.h"
#include "Player\PlayerController.h"

class CRIntroScenePlayerController : public KPlayerController
{
public:
	CRIntroScenePlayerController::CRIntroScenePlayerController() = default;

	CRIntroScenePlayerController::CRIntroScenePlayerController(class KEngine* engine, class KScene* scene)
	{
		Engine = engine;
		Scene = scene;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRIntroSceneInterface* Interface = nullptr;
};