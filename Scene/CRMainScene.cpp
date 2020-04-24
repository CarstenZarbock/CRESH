#pragma once
#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
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
}

void CRMainScene::Tick(float deltaTime)
{

}