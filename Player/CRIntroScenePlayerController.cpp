#pragma once

#include "Engine.h"
#include "..\Interface\CRIntroSceneInterface.h"
#include "Scene\Scene.h"
#include "CRIntroScenePlayerController.h"

void CRIntroScenePlayerController::Initialize()
{
	Interface = new CRIntroSceneInterface(Engine);
	Interface->Initialize();
	Scene->NewObject(this);
}


void CRIntroScenePlayerController::Tick(const float deltaTime)
{
	if (Interface != nullptr)
	{
		Interface->Tick(deltaTime);
	}
}
