#pragma once

#include "Engine.h"
#include "..\Interface\CRMainMenuInterface.h"
#include "Scene\Scene.h"
#include "CRMainMenuPlayerController.h"

void CRMainMenuPlayerController::Initialize()
{
	Interface = new CRMainMenuInterface(Engine);
	Interface->Initialize();
	Scene->NewObject(this);
}

void CRMainMenuPlayerController::Tick(const float deltaTime)
{
	if (Interface != nullptr)
	{
		Interface->Tick(deltaTime);
	}
}

void CRMainMenuPlayerController::OnDestroy()
{
	if (Interface != nullptr)
	{
		Interface->OnDestroy();
		delete Interface;
	}
	Interface = nullptr;
}
