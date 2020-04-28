#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRLoadingScene.h"
#include "CRLoadingScreenInterface.h"

void CRLoadingScreenInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string("[_LOADING... ]"), MAX_X / 2, MAX_Y / 2, EAlignment::CENTER);

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
	CurLoadingTime += 1.f * deltaTime;
	if (CurLoadingTime >= 4.f)
	{
		Text_StartGame->SetLocation(Text_StartGame->GetX() - (50.f * deltaTime), Text_StartGame->GetY());
	}

	BlinkTime -= 1.f * deltaTime;
	BlinkTime = std::max<float>(BlinkTime, 0.f);

	if (BlinkTime <= 0.f)
	{
		bIsBlinkVisible = !bIsBlinkVisible;
		BlinkTime += 0.75f;
		UpdateBlink();
	}
}

void CRLoadingScreenInterface::UpdateBlink()
{
	std::string blinkChar = bIsBlinkVisible ? "_" : " ";
	Text_StartGame->ChangeText("[" + blinkChar + std::string("LOADING... ]"));
}