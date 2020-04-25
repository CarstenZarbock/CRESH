#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "CRInterface.h"

#define BUTTON_START_LABEL "Start Game"
#define BUTTON_CONTINUE_LABEL "Continue"
#define BUTTON_OPTIONS_LABEL "Options"
#define BUTTON_EXIT_LABEL "Exit"

#define TEXT_GAMENAME_LABEL "CR=SH"
#define TEXT_COPYRIGHT_LABEL "Copyright 2020 SOMETHING Inc"

void CRInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string(BUTTON_START_LABEL), -90, 18);
	Text_ContinueGame = new KRenderResourceText(std::string(BUTTON_CONTINUE_LABEL), -95, 19);
	Text_Options = new KRenderResourceText(std::string(BUTTON_OPTIONS_LABEL), -100, 20);
	Text_Exit = new KRenderResourceText(std::string(BUTTON_EXIT_LABEL), -105, 21);

	Text_GameName = new KRenderResourceText(std::string(TEXT_GAMENAME_LABEL), 5, 6);
	Text_Copyright = new KRenderResourceText(std::string(TEXT_COPYRIGHT_LABEL), 20, 28);

	Background = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Background\\1.txt"), 0, 0);
	Girl1 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Characters\\3.txt"), 54, 8);
	Girl2 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Characters\\3.txt"), 65, 8);
	Logo = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Logo\\5.txt"), -100, 1);

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

void CRInterface::Tick(const float deltaTime)
{
	ButtonTimeOut -= 1.f * deltaTime;
	ButtonTimeOut = std::max<float>(ButtonTimeOut, 0.f);

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
	}

	Text_StartGame->SetLocation(std::min<float>(10, Text_StartGame->GetX() + (10.f * deltaTime)), Text_StartGame->GetY());
	Text_ContinueGame->SetLocation(std::min<float>(10, Text_ContinueGame->GetX() + (10.f * deltaTime)), Text_ContinueGame->GetY());
	Text_Options->SetLocation(std::min<float>(10, Text_Options->GetX() + (10.f * deltaTime)), Text_Options->GetY());
	Text_Exit->SetLocation(std::min<float>(10, Text_Exit->GetX() + (10.f * deltaTime)), Text_Exit->GetY());
	Logo->SetLocation(std::min<float>(3, Logo->GetX() + (10.f * deltaTime)), Logo->GetY());
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
	switch (CurrentMenuIndex)
	{
	case 0:
		Text_StartGame->ChangeText("[ " + std::string(BUTTON_START_LABEL) + " ]");
		break;
	case 1:
		Text_ContinueGame->ChangeText("[ " + std::string(BUTTON_CONTINUE_LABEL) + " ]");
		break;
	case 2:
		Text_Options->ChangeText("[ " + std::string(BUTTON_OPTIONS_LABEL) + " ]");
		break;
	case 3:
		Text_Exit->ChangeText("[ " + std::string(BUTTON_EXIT_LABEL) + " ]");
		break;
	default:
		break;
	}

	ButtonTimeOut += 1.f;
}