#pragma once

#include "Engine.h"
#include "..\Interface\CRLoadingScreenInterface.h"
#include "Scene\Scene.h"
#include "..\Core\CRGameInstance.h"
#include "..\Scene\CRIntroScene.h"
#include "CRLoadingScenePlayerController.h"

void CRLoadingScenePlayerController::Initialize()
{
	Interface = new CRLoadingScreenInterface(Engine);
	Interface->Initialize();
	Scene->NewObject(this);
}


void CRLoadingScenePlayerController::Tick(const float deltaTime)
{
	if (Interface != nullptr)
	{
		Interface->Tick(deltaTime);
	}

	CurLoadingTime += 1.f * deltaTime;
	if (CurLoadingTime >= 5.f)
	{
		Engine->GetGameInstance().SwitchScene(*new CRIntroScene(Engine));
	}
}
