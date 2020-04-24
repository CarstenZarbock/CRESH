#pragma once

#include "Engine.h"
#include "..\Scene\CRMainScene.h"

#include "CRGameInstance.h"

CRGameInstance::CRGameInstance()
{
	Title = L"CR☰SH";
}

void CRGameInstance::InitializeDefaultScene(KEngine* engine)
{
	Scene = new CRMainScene(engine);
	Scene->Load();
}