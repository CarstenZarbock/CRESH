#pragma once
#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Objects\GameObject.h"
#include "..\Player\CRMainMenuPlayerController.h"

#include "CRMainMenuScene.h"

CRMainMenuScene::CRMainMenuScene()
{
	CRMainMenuScene(nullptr);
}

CRMainMenuScene::CRMainMenuScene(KEngine* engine)
{
	Engine = engine;
}

void CRMainMenuScene::Load()
{
	KScene::Load();

	PlayerController = new CRMainMenuPlayerController(Engine, this);
	PlayerController->Initialize();
}

void CRMainMenuScene::Tick(float deltaTime)
{
	KScene::Tick(deltaTime);
}