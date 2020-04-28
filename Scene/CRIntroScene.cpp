#pragma once
#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Objects\GameObject.h"
#include "..\Player\CRIntroScenePlayerController.h"
#include "..\Scene\CRWorldScene.h"
#include "..\Core\CRGameInstance.h"
#include "CRIntroScene.h"

CRIntroScene::CRIntroScene()
{
	CRIntroScene(nullptr);
}

CRIntroScene::CRIntroScene(KEngine* engine)
{
	Engine = engine;
}

void CRIntroScene::Load()
{
	KScene::Load();

	PlayerController = new CRIntroScenePlayerController(Engine, this);
	PlayerController->Initialize();
}

void CRIntroScene::Tick(float deltaTime)
{
	KScene::Tick(deltaTime);

	CurLoadingTime += 1.f * deltaTime;
	if (CurLoadingTime >= 40.f)
	{
		Engine->GetGameInstance().SwitchScene(*new CRWorldScene(Engine));
	}
}