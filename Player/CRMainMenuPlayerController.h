#pragma once

#include "stdafx.h"
#include "Player\PlayerController.h"

class CRMainMenuPlayerController : public KPlayerController
{
public:
	CRMainMenuPlayerController::CRMainMenuPlayerController() = default;

	CRMainMenuPlayerController::CRMainMenuPlayerController(class KEngine* engine, class KScene* scene)
	{
		Engine = engine;
		Scene = scene;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;
	virtual void OnDestroy() override;

protected:
	class CRMainMenuInterface* Interface = nullptr;
};