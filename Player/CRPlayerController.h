#pragma once

#include "stdafx.h"
#include "Player\PlayerController.h"

class CRPlayerController : public KPlayerController
{
public:
	CRPlayerController::CRPlayerController() = default;

	CRPlayerController::CRPlayerController(class KEngine* engine, class KScene* scene)
	{
		Engine = engine;
		Scene = scene;
	}

	virtual void Initialize() override;
	virtual void OnDestroy() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRInterface* Interface = nullptr;
};