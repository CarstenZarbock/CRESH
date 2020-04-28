#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRIntroScene.h"
#include "CRIntroSceneInterface.h"

void CRIntroSceneInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string("INTROSCENE"), MAX_X / 2, MAX_Y / 2, EAlignment::LEFT);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Text_StartGame);
	}
}

void CRIntroSceneInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Text_StartGame);
	}

	delete Text_StartGame;
}

void CRIntroSceneInterface::Tick(const float deltaTime)
{

}