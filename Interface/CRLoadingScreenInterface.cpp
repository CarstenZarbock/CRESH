#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRLoadingScene.h"
#include "CRLoadingScreenInterface.h"

void CRLoadingScreenInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string("LOADING..."), MAX_X / 2, MAX_Y / 2, EAlignment::LEFT);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Text_StartGame);
	}
}

void CRLoadingScreenInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Text_StartGame);
	}

	delete Text_StartGame;
}

void CRLoadingScreenInterface::Tick(const float deltaTime)
{

}