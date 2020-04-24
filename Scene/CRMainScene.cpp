#pragma once
#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Objects\GameObject.h"
#include "..\Player\CRPlayerController.h"

#include "CRMainScene.h"

CRMainScene::CRMainScene()
{
	CRMainScene(nullptr);
}

CRMainScene::CRMainScene(KEngine* engine)
{
	Engine = engine;
}

void CRMainScene::Load()
{
	KScene::Load();

	PlayerController = new CRPlayerController(Engine, this);
	PlayerController->Initialize();
	NewObject(PlayerController);
}

void CRMainScene::Tick(float deltaTime)
{
	KScene::Tick(deltaTime);
}