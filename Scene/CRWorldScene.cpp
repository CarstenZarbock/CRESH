#pragma once
#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Objects\GameObject.h"
#include "..\Player\CRPlayerController.h"
#include "CRWorldScene.h"

CRWorldScene::CRWorldScene()
{
	CRWorldScene(nullptr);
}

CRWorldScene::CRWorldScene(KEngine* engine)
{
	Engine = engine;
}

void CRWorldScene::Load()
{
	KScene::Load();

	PlayerController = new CRPlayerController(Engine, this);
	PlayerController->Initialize();
}

void CRWorldScene::Tick(float deltaTime)
{
	KScene::Tick(deltaTime);
}