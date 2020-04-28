#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRMainMenuScene.h"
#include "..\Scene\CRLoadingScene.h"
#include "CRMainMenuInterface.h"

#define BUTTON_START_LABEL "Start Game"
#define BUTTON_CONTINUE_LABEL "Continue"
#define BUTTON_OPTIONS_LABEL "Options"
#define BUTTON_EXIT_LABEL "Exit"

#define TEXT_GAMENAME_LABEL "CR=SH: Cerebellum"
#define TEXT_COPYRIGHT_LABEL "Copyright 1972 NeutrKopy Inc"

#define TEXT_MSG1_NAME "@Devote1958"
#define TEXT_MSG1_TIME "10 Min."
#define TEXT_MSG1_MSG "Help. Please. #Cerebellum"

#define TEXT_MSG2_NAME "@_PierWeak54"
#define TEXT_MSG2_TIME "13 Min."
#define TEXT_MSG2_MSG "Nothingness. #Cerebellum"

#define TEXT_MSG3_NAME "@VOID18"
#define TEXT_MSG3_TIME "15 Min."
#define TEXT_MSG3_MSG "??? #Cerebellum Not Real!!"

void CRMainMenuInterface::Initialize()
{
	Text_StartGame = new KRenderResourceText(std::string(BUTTON_START_LABEL), -60, 18, EAlignment::RIGHT);
	Text_ContinueGame = new KRenderResourceText(std::string(BUTTON_CONTINUE_LABEL), -65, 19, EAlignment::RIGHT);
	Text_Options = new KRenderResourceText(std::string(BUTTON_OPTIONS_LABEL), -70, 20, EAlignment::RIGHT);
	Text_Exit = new KRenderResourceText(std::string(BUTTON_EXIT_LABEL), -75, 21, EAlignment::RIGHT);

	Text_GameName = new KRenderResourceText(std::string(TEXT_GAMENAME_LABEL), 5, 6);
	Text_Copyright = new KRenderResourceText(std::string(TEXT_COPYRIGHT_LABEL), 78, 28, EAlignment::RIGHT);

	MSG1Text_Name = new KRenderResourceText(std::string(TEXT_MSG1_NAME), 77, 17, EAlignment::RIGHT);
	MSG1Text_Time = new KRenderResourceText(std::string(TEXT_MSG1_TIME), 46, 17, EAlignment::LEFT);
	MSG1Text_MSG = new KRenderResourceText(std::string(TEXT_MSG1_MSG), 77, 18, EAlignment::RIGHT);

	MSG2Text_Name = new KRenderResourceText(std::string(TEXT_MSG2_NAME), 77, 20, EAlignment::RIGHT);
	MSG2Text_Time = new KRenderResourceText(std::string(TEXT_MSG2_TIME), 46, 20, EAlignment::LEFT);
	MSG2Text_MSG = new KRenderResourceText(std::string(TEXT_MSG2_MSG), 77, 21, EAlignment::RIGHT);

	MSG3Text_Name = new KRenderResourceText(std::string(TEXT_MSG3_NAME), 77, 23, EAlignment::RIGHT);
	MSG3Text_Time = new KRenderResourceText(std::string(TEXT_MSG3_TIME), 46, 23, EAlignment::LEFT);
	MSG3Text_MSG = new KRenderResourceText(std::string(TEXT_MSG3_MSG), 77, 24, EAlignment::RIGHT);

	Random_Text_1 = new KRenderResourceText(std::string("D)Z§%UHDD)Z§%UHDASFJKH#@SFJKH#@"), 46, 9, EAlignment::LEFT);
	Random_Text_2 = new KRenderResourceText(std::string("ASD=)ASD=)($%/DUASDSD($%/UASDSD"), 46, 10, EAlignment::LEFT);
	Random_Text_3 = new KRenderResourceText(std::string("FDS§$EFFDS§$EF4SD&$%FSDSD&$%FSD"), 46, 11, EAlignment::LEFT);
	Random_Text_4 = new KRenderResourceText(std::string("DSGZRZ$DS3GZRZ$&GGDS#DS&GGDS#DS"), 46, 12, EAlignment::LEFT);
	Random_Text_5 = new KRenderResourceText(std::string("D)Z§%UHDD)Z§%UHDASFJKH#@SFJKH#@"), 46, 13, EAlignment::LEFT);
	Random_Text_6 = new KRenderResourceText(std::string("ASD=)ASD=)($%/DUASDSD($%/UASDSD"), 46, 14, EAlignment::LEFT);
	Random_Text_7 = new KRenderResourceText(std::string("FDS§$EFFDS§$EF4SD&$%FSDSD&$%FSD"), 46, 15, EAlignment::LEFT);

	Background = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Background\\1.txt"), 0, 0);
	Logo = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Logo\\5.txt"), -80, 1);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Background);
		Engine->GetRenderer().RegisterComponent(Logo);

		Engine->GetRenderer().RegisterComponent(Text_StartGame);
		Engine->GetRenderer().RegisterComponent(Text_ContinueGame);
		Engine->GetRenderer().RegisterComponent(Text_Options);
		Engine->GetRenderer().RegisterComponent(Text_Exit);

		Engine->GetRenderer().RegisterComponent(Text_GameName);
		Engine->GetRenderer().RegisterComponent(Text_Copyright);

		Engine->GetRenderer().RegisterComponent(MSG1Text_Name);
		Engine->GetRenderer().RegisterComponent(MSG1Text_Time);
		Engine->GetRenderer().RegisterComponent(MSG1Text_MSG);

		Engine->GetRenderer().RegisterComponent(MSG2Text_Name);
		Engine->GetRenderer().RegisterComponent(MSG2Text_Time);
		Engine->GetRenderer().RegisterComponent(MSG2Text_MSG);

		Engine->GetRenderer().RegisterComponent(MSG3Text_Name);
		Engine->GetRenderer().RegisterComponent(MSG3Text_Time);
		Engine->GetRenderer().RegisterComponent(MSG3Text_MSG);

		Engine->GetRenderer().RegisterComponent(Random_Text_1);
		Engine->GetRenderer().RegisterComponent(Random_Text_2);
		Engine->GetRenderer().RegisterComponent(Random_Text_3);
		Engine->GetRenderer().RegisterComponent(Random_Text_4);
		Engine->GetRenderer().RegisterComponent(Random_Text_5);
		Engine->GetRenderer().RegisterComponent(Random_Text_6);
		Engine->GetRenderer().RegisterComponent(Random_Text_7);
	}
	
	SwitchMenu(CurrentMenuIndex);
}

void CRMainMenuInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Background);
		Engine->GetRenderer().UnRegisterComponent(Logo);

		Engine->GetRenderer().UnRegisterComponent(Text_StartGame);
		Engine->GetRenderer().UnRegisterComponent(Text_ContinueGame);
		Engine->GetRenderer().UnRegisterComponent(Text_Options);
		Engine->GetRenderer().UnRegisterComponent(Text_Exit);

		Engine->GetRenderer().UnRegisterComponent(Text_GameName);
		Engine->GetRenderer().UnRegisterComponent(Text_Copyright);

		Engine->GetRenderer().UnRegisterComponent(MSG1Text_Name);
		Engine->GetRenderer().UnRegisterComponent(MSG1Text_Time);
		Engine->GetRenderer().UnRegisterComponent(MSG1Text_MSG);

		Engine->GetRenderer().UnRegisterComponent(MSG2Text_Name);
		Engine->GetRenderer().UnRegisterComponent(MSG2Text_Time);
		Engine->GetRenderer().UnRegisterComponent(MSG2Text_MSG);

		Engine->GetRenderer().UnRegisterComponent(MSG3Text_Name);
		Engine->GetRenderer().UnRegisterComponent(MSG3Text_Time);
		Engine->GetRenderer().UnRegisterComponent(MSG3Text_MSG);

		Engine->GetRenderer().UnRegisterComponent(Random_Text_1);
		Engine->GetRenderer().UnRegisterComponent(Random_Text_2);
		Engine->GetRenderer().UnRegisterComponent(Random_Text_3);
		Engine->GetRenderer().UnRegisterComponent(Random_Text_4);
		Engine->GetRenderer().UnRegisterComponent(Random_Text_5);
		Engine->GetRenderer().UnRegisterComponent(Random_Text_6);
		Engine->GetRenderer().UnRegisterComponent(Random_Text_7);
	}
	delete Random_Text_1;
	delete Random_Text_2;
	delete Random_Text_3;
	delete Random_Text_4;
	delete Random_Text_5;
	delete Random_Text_6;
	delete Random_Text_7;

	delete MSG1Text_Name;
	delete MSG1Text_Time;
	delete MSG1Text_MSG;

	delete MSG2Text_Name;
	delete MSG2Text_Time;
	delete MSG2Text_MSG;

	delete MSG3Text_Name;
	delete MSG3Text_Time;
	delete MSG3Text_MSG;
	
	delete Text_StartGame;
	delete Text_ContinueGame;
	delete Text_Options;
	delete Text_Exit;

	delete Text_GameName;
	delete Text_Copyright;

	delete Background;
	delete Logo;
}

void CRMainMenuInterface::Tick(const float deltaTime)
{
	ButtonTimeOut -= 1.f * deltaTime;
	ButtonTimeOut = std::max<float>(ButtonTimeOut, 0.f);

	BlinkTime -= 1.f * deltaTime;
	BlinkTime = std::max<float>(BlinkTime, 0.f);

	if (BlinkTime <= 0.f)
	{
		bIsBlinkVisible = !bIsBlinkVisible;
		BlinkTime += 0.75f;
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
			Engine->GetGameInstance().SwitchScene(*new CRLoadingScene(Engine));
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

void CRMainMenuInterface::UpdateBlink()
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

void CRMainMenuInterface::SwitchMenu(int index)
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