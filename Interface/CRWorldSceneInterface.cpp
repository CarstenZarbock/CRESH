#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRWorldScene.h"
#include "CRWorldSceneInterface.h"

void CRWorldSceneInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string("WORLDSCENE"), MAX_X / 2, MAX_Y / 2, EAlignment::LEFT);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Text_StartGame);
	}
}

void CRWorldSceneInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Text_StartGame);
	}

	delete Text_StartGame;
}

void CRWorldSceneInterface::Tick(const float deltaTime)
{

}