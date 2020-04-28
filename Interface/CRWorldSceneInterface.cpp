#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRWorldScene.h"
#include "CRWorldSceneInterface.h"

void CRWorldSceneInterface::Initialize()
{
	Text_StartGame3 = new KRenderResourceText(std::string("INTRO DONE"), MAX_X / 2, (MAX_Y / 2) - 1, EAlignment::CENTER);
	Text_StartGame = new KRenderResourceText(std::string("[_WORLDSCENE ]"), MAX_X / 2, MAX_Y / 2, EAlignment::CENTER);
	Text_StartGame2 = new KRenderResourceText(std::string("NOTHING TO SEE HERE"), MAX_X / 2, (MAX_Y / 2) + 1, EAlignment::CENTER);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Text_StartGame);
		Engine->GetRenderer().RegisterComponent(Text_StartGame2);
		Engine->GetRenderer().RegisterComponent(Text_StartGame3);
	}
}

void CRWorldSceneInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Text_StartGame);
		Engine->GetRenderer().UnRegisterComponent(Text_StartGame2);
		Engine->GetRenderer().UnRegisterComponent(Text_StartGame3);
	}

	delete Text_StartGame;
	delete Text_StartGame2;
	delete Text_StartGame3;
}

void CRWorldSceneInterface::Tick(const float deltaTime)
{

}