#pragma once

#include "Engine.h"
#include "..\Scene\CRMainMenuScene.h"

#include "CRGameInstance.h"

CRGameInstance::CRGameInstance()
{
	Title = L"CR☰SH: Cerebellum";
}

void CRGameInstance::InitializeDefaultScene(KEngine* engine)
{
	Scene = new CRMainMenuScene(engine);
	Scene->Load();
}