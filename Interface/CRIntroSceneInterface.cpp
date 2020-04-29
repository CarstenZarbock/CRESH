#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "Core\GameInstance.h"
#include "..\Scene\CRIntroScene.h"
#include "CRIntroSceneInterface.h"

void CRIntroSceneInterface::Initialize()
{
	Foreground_1 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Background\\IntroScene\\1.txt"), MAX_X + 0, 0, true, char('X'));
	Foreground_2 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Background\\IntroScene\\1.txt"), MAX_X + MAX_X, 0, true, char('X'));
	Cloud_1 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_1.txt"), MAX_X + 0, 0, true, char('X'));
	Cloud_2 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_1.txt"), MAX_X + MAX_X, 0, true, char('X'));
	Cloud_f3 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_1.txt"), MAX_X + (MAX_X / 2), 0, true, char('X'));

	Cloud_3 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_2.txt"), MAX_X + 10, 2, true, char('X'));
	Cloud_4 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_2.txt"), MAX_X + 45, 7, true, char('X'));
	Cloud_5 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_2.txt"), MAX_X + 55, 5, true, char('X'));
	Cloud_6 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\Cloud_2.txt"), MAX_X + 75, 9, true, char('X'));

	MCycle_1 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\MCycle.txt"), MAX_X, 12 + 10, true, char('X'));
	MCycle_2 = new KRenderResourceImage(KRenderResourceImage::LoadImage("Content\\Objects\\MCycle.txt"), MAX_X + 6, 12 + 12, true, char('X'));

	Foreground_Text = new KRenderResourceText(std::string(""), MAX_X / 2, MAX_Y / 2, EAlignment::CENTER);
	Foreground_Text2 = new KRenderResourceText(std::string(""), MAX_X / 2, MAX_Y / 2 + 1, EAlignment::CENTER);

	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(Cloud_1);
		Engine->GetRenderer().RegisterComponent(Cloud_2);
		Engine->GetRenderer().RegisterComponent(Cloud_f3);
		Engine->GetRenderer().RegisterComponent(Foreground_1);
		Engine->GetRenderer().RegisterComponent(Foreground_2);
		Engine->GetRenderer().RegisterComponent(Cloud_3);
		Engine->GetRenderer().RegisterComponent(Cloud_4);
		Engine->GetRenderer().RegisterComponent(Cloud_5);
		Engine->GetRenderer().RegisterComponent(Cloud_6);
		Engine->GetRenderer().RegisterComponent(Foreground_Text);
		Engine->GetRenderer().RegisterComponent(Foreground_Text2);

		Engine->GetRenderer().RegisterComponent(MCycle_1);
		Engine->GetRenderer().RegisterComponent(MCycle_2);
	}
}

void CRIntroSceneInterface::OnDestroy()
{
	if (Engine != nullptr)
	{
		Engine->GetRenderer().UnRegisterComponent(Cloud_1);
		Engine->GetRenderer().UnRegisterComponent(Cloud_2);
		Engine->GetRenderer().UnRegisterComponent(Cloud_f3);
		Engine->GetRenderer().UnRegisterComponent(Foreground_1);
		Engine->GetRenderer().UnRegisterComponent(Foreground_2);
		Engine->GetRenderer().UnRegisterComponent(Cloud_3);
		Engine->GetRenderer().UnRegisterComponent(Cloud_4);
		Engine->GetRenderer().UnRegisterComponent(Cloud_5);
		Engine->GetRenderer().UnRegisterComponent(Cloud_6);
		Engine->GetRenderer().UnRegisterComponent(Foreground_Text);
		Engine->GetRenderer().UnRegisterComponent(Foreground_Text2);
		Engine->GetRenderer().UnRegisterComponent(MCycle_1);
		Engine->GetRenderer().UnRegisterComponent(MCycle_2);
	}

	delete Foreground_1;
	delete Foreground_2;
	delete Cloud_1;
	delete Cloud_2;
	delete Cloud_f3;
	delete Cloud_3;
	delete Cloud_4;
	delete Cloud_5;
	delete Cloud_6;
	delete Foreground_Text;
	delete Foreground_Text2;
	delete MCycle_1;
	delete MCycle_2;
}

void CRIntroSceneInterface::Tick(const float deltaTime)
{
	static float backCloudSpeed = 3.f;
	static float foregroundSpeed = 30.f;
	static float frontCloudSpeed = 40.f;
	Foreground_1->SetLocation(Foreground_1->GetX() - (foregroundSpeed * deltaTime), Foreground_1->GetY());
	Foreground_2->SetLocation(Foreground_2->GetX() - (foregroundSpeed * deltaTime), Foreground_2->GetY());
	if (Foreground_1->GetX() < (MAX_X * -1.f))
	{
		Foreground_1->SetLocation(MAX_X, Foreground_1->GetY());
	}
	if (Foreground_2->GetX() < (MAX_X * -1.f))
	{
		Foreground_2->SetLocation(MAX_X, Foreground_2->GetY());
	}
	MCycle_1->SetLocation(std::max<float>(MCycle_1->GetX() - (foregroundSpeed * deltaTime), 20.f), MCycle_1->GetY());
	MCycle_2->SetLocation(std::max<float>(MCycle_2->GetX() - (foregroundSpeed * deltaTime), 26.f), MCycle_2->GetY());


	Cloud_1->SetLocation(Cloud_1->GetX() - (backCloudSpeed * deltaTime), Cloud_1->GetY());
	Cloud_2->SetLocation(Cloud_2->GetX() - (backCloudSpeed * deltaTime), Cloud_2->GetY());
	Cloud_f3->SetLocation(Cloud_f3->GetX() - (backCloudSpeed * deltaTime), Cloud_f3->GetY());
	if (Cloud_1->GetX() < (52 * -1.f))
	{
		Cloud_1->SetLocation(MAX_X, Cloud_1->GetY());
	}
	if (Cloud_2->GetX() < (52 * -1.f))
	{
		Cloud_2->SetLocation(MAX_X, Cloud_2->GetY());
	}
	if (Cloud_f3->GetX() < (52 * -1.f))
	{
		Cloud_f3->SetLocation(MAX_X, Cloud_f3->GetY());
	}

	Cloud_3->SetLocation(Cloud_3->GetX() - (frontCloudSpeed * deltaTime), Cloud_3->GetY());
	Cloud_4->SetLocation(Cloud_4->GetX() - (frontCloudSpeed * deltaTime), Cloud_4->GetY());
	Cloud_5->SetLocation(Cloud_5->GetX() - (frontCloudSpeed * deltaTime), Cloud_5->GetY());
	Cloud_6->SetLocation(Cloud_6->GetX() - (frontCloudSpeed * deltaTime), Cloud_6->GetY());
	if (Cloud_3->GetX() < (25 * -1.f))
	{
		Cloud_3->SetLocation(MAX_X, Cloud_3->GetY());
	}
	if (Cloud_4->GetX() < (25 * -1.f))
	{
		Cloud_4->SetLocation(MAX_X, Cloud_4->GetY());
	}
	if (Cloud_5->GetX() < (25 * -1.f))
	{
		Cloud_5->SetLocation(MAX_X, Cloud_5->GetY());
	}
	if (Cloud_6->GetX() < (25 * -1.f))
	{
		Cloud_6->SetLocation(MAX_X, Cloud_6->GetY());
	}

	Foreground_Text_timer -= 1.f * deltaTime;
	if (Foreground_Text_timer < 0.f)
	{
		SwitchForeGroundState(Foreground_Text_Step + 1);
	}
}

void CRIntroSceneInterface::SwitchForeGroundState(int newState)
{
	Foreground_Text_Step = newState;
	switch (Foreground_Text_Step)
	{
	case 0:
		break;
	case 1:
		Foreground_Text->ChangeText(std::string("[_NeutrKopy presents... ]"));
		Foreground_Text_timer = 5.f;
		break;
	case 2:
		Foreground_Text->ChangeText(std::string(""));
		Foreground_Text_timer = 1.f;
		break;
	case 3:
		Foreground_Text->ChangeText(std::string("[_A visual entertainment application by }&/y)x%,$# ]"));
		Foreground_Text_timer = 5.f;
		break;
	case 4:
		Foreground_Text->ChangeText(std::string(""));
		Foreground_Text_timer = 1.f;
		break;
	case 5:
		Foreground_Text->ChangeText(std::string("[_#Cerebellum ]"));
		Foreground_Text_timer = 3.f;
		break;
	case 6:
		Foreground_Text->ChangeText(std::string("[_#Cerebellum ]"));
		Foreground_Text2->ChangeText(std::string("(Copyright 1972 NeutrKopy Inc)"));
		Foreground_Text_timer = 6.f;
		break;
	case 7:
		Foreground_Text->ChangeText(std::string(""));
		Foreground_Text2->ChangeText(std::string(""));
		Foreground_Text_timer = 666.f;
		break;
	}
}