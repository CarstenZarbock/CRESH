#pragma once
#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Objects\GameObject.h"
#include "..\Player\CRLoadingScenePlayerController.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRIntroScene.h"
#include "CRLoadingScene.h"

CRLoadingScene::CRLoadingScene()
{
	CRLoadingScene(nullptr);
}

CRLoadingScene::CRLoadingScene(KEngine* engine)
{
	Engine = engine;
}

void CRLoadingScene::Load()
{
	KScene::Load();

	PlayerController = new CRLoadingScenePlayerController(Engine, this);
	PlayerController->Initialize();
}

void CRLoadingScene::Tick(float deltaTime)
{
	KScene::Tick(deltaTime);

	CurLoadingTime += 1.f * deltaTime;
	if (CurLoadingTime >= 5.f)
	{
		Engine->GetGameInstance().SwitchScene(*new CRIntroScene(Engine));
	}
}