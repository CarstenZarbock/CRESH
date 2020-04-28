#pragma once

#include "Engine.h"
#include "..\Interface\CRWorldSceneInterface.h"
#include "Scene\Scene.h"
#include "CRPlayerController.h"

void CRPlayerController::Initialize()
{
	Interface = new CRWorldSceneInterface(Engine);
	Interface->Initialize();
	Scene->NewObject(this);
}

void CRPlayerController::Tick(const float deltaTime)
{
	if (Interface != nullptr)
	{
		Interface->Tick(deltaTime);
	}
}

void CRPlayerController::OnDestroy()
{
	if (Interface != nullptr)
	{
		Interface->OnDestroy();
		delete Interface;
	}
	Interface = nullptr;
}