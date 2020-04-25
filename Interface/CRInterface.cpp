#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRMainScene.h"
#include "CRInterface.h"

#define BUTTON_START_LABEL "Start Game"
#define BUTTON_CONTINUE_LABEL "Continue"
#define BUTTON_OPTIONS_LABEL "Options"
#define BUTTON_EXIT_LABEL "Exit"

#define TEXT_GAMENAME_LABEL "CR=SH"
#define TEXT_COPYRIGHT_LABEL "Copyright 2020 SOMETHING Inc"

void CRInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string(BUTTON_START_LABEL), -60, 18, EAlignment::RIGHT);
	Text_ContinueGame = new KRenderResourceText(std::string(BUTTON_CONTINUE_LABEL), -65, 19, EAlignment::RIGHT);
	Text_Options = new KRenderResourceText(std::string(BUTTON_OPTIONS_LABEL), -70, 20, EAlignment::RIGHT);
	Text_Exit = new KRenderResourceText(std::string(BUTTON_EXIT_LABEL), -75, 21, EAlignment::RIGHT);

	Text_GameName = new KRenderResourceText(std::string(TEXT_GAMENAME_LABEL), 5, 6);
	Text_Copyright = new KRenderResourceText(std::string(TEXT_COPYRIGHT_LABEL), 79, 28, EAlignment::RIGHT);

	Background = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Background\\1.txt"), 0, 0);
	Girl1 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Characters\\3.txt"), 54, 8);
	Girl2 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Characters\\3.txt"), 65, 8);
	Logo = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Logo\\5.txt"), -80, 1);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Background);
		Engine->GetRenderer().RegisterComponent(Girl1);
		Engine->GetRenderer().RegisterComponent(Girl2);
		Engine->GetRenderer().RegisterComponent(Logo);

		Engine->GetRenderer().RegisterComponent(Text_StartGame);
		Engine->GetRenderer().RegisterComponent(Text_ContinueGame);
		Engine->GetRenderer().RegisterComponent(Text_Options);
		Engine->GetRenderer().RegisterComponent(Text_Exit);

		Engine->GetRenderer().RegisterComponent(Text_GameName);
		Engine->GetRenderer().RegisterComponent(Text_Copyright);

	}
	
	SwitchMenu(CurrentMenuIndex);
}

void CRInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Background);
		Engine->GetRenderer().UnRegisterComponent(Girl1);
		Engine->GetRenderer().UnRegisterComponent(Girl2);
		Engine->GetRenderer().UnRegisterComponent(Logo);

		Engine->GetRenderer().UnRegisterComponent(Text_StartGame);
		Engine->GetRenderer().UnRegisterComponent(Text_ContinueGame);
		Engine->GetRenderer().UnRegisterComponent(Text_Options);
		Engine->GetRenderer().UnRegisterComponent(Text_Exit);

		Engine->GetRenderer().UnRegisterComponent(Text_GameName);
		Engine->GetRenderer().UnRegisterComponent(Text_Copyright);
	}

	delete Text_StartGame;
	delete Text_ContinueGame;
	delete Text_Options;
	delete Text_Exit;

	delete Text_GameName;
	delete Text_Copyright;

	delete Background;
	delete Girl1;
	delete Girl2;
	delete Logo;
}

void CRInterface::Tick(const float deltaTime)
{
	ButtonTimeOut -= 1.f * deltaTime;
	ButtonTimeOut = std::max<float>(ButtonTimeOut, 0.f);

	BlinkTime -= 1.f * deltaTime;
	BlinkTime = std::max<float>(BlinkTime, 0.f);

	if (BlinkTime <= 0.f)
	{
		bIsBlinkVisible = !bIsBlinkVisible;
		BlinkTime += 1.f;
		UpdateBlink();
	}

	if (ButtonTimeOut <= 0.f)
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			SwitchMenu(CurrentMenuIndex + 1);
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			SwitchMenu(CurrentMenuIndex - 1);
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			Engine->GetGameInstance().SwitchScene(*new CRMainScene(Engine));
			return;
		}
	}

	static const float moveSpeed = 20.f;
	static const int targetX = 30;
	Text_StartGame->SetLocation(std::min<float>(targetX, Text_StartGame->GetX() + (moveSpeed * deltaTime)), Text_StartGame->GetY());
	Text_ContinueGame->SetLocation(std::min<float>(targetX, Text_ContinueGame->GetX() + (moveSpeed * deltaTime)), Text_ContinueGame->GetY());
	Text_Options->SetLocation(std::min<float>(targetX, Text_Options->GetX() + (moveSpeed * deltaTime)), Text_Options->GetY());
	Text_Exit->SetLocation(std::min<float>(targetX, Text_Exit->GetX() + (moveSpeed * deltaTime)), Text_Exit->GetY());
	Logo->SetLocation(std::min<float>(3, Logo->GetX() + (moveSpeed * deltaTime)), Logo->GetY());
}

void CRInterface::UpdateBlink()
{
	std::string blinkChar = bIsBlinkVisible ? "_" : " ";

	switch (CurrentMenuIndex)
	{
	case 0:
		Text_StartGame->ChangeText("[" + blinkChar + std::string(BUTTON_START_LABEL) + " ]");
		break;
	case 1:
		Text_ContinueGame->ChangeText("[" + blinkChar + std::string(BUTTON_CONTINUE_LABEL) + " ]");
		break;
	case 2:
		Text_Options->ChangeText("[" + blinkChar + std::string(BUTTON_OPTIONS_LABEL) + " ]");
		break;
	case 3:
		Text_Exit->ChangeText("[" + blinkChar + std::string(BUTTON_EXIT_LABEL) + " ]");
		break;
	default:
		break;
	}
}

void CRInterface::SwitchMenu(int index)
{
	if (index < 0)
	{
		index = 0;
	}
	else if (index > 3)
	{
		index = 3;
	}

	if (index == CurrentMenuIndex)
	{
		return;
	}

	switch (CurrentMenuIndex)
	{
	case 0:
		Text_StartGame->ChangeText(std::string(BUTTON_START_LABEL));
		break;
	case 1:
		Text_ContinueGame->ChangeText(std::string(BUTTON_CONTINUE_LABEL));
		break;
	case 2:
		Text_Options->ChangeText(std::string(BUTTON_OPTIONS_LABEL));
		break;
	case 3:
		Text_Exit->ChangeText(std::string(BUTTON_EXIT_LABEL));
		break;
	default:
		break;
	}

	CurrentMenuIndex = index;
	UpdateBlink();

	ButtonTimeOut += 0.5f;
}