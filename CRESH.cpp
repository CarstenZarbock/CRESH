#pragma once

#include "CRESH.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"

int main()
{
	CCresh_GameInstance* gameInstance = new CCresh_GameInstance();
	engine = new CEngine(gameInstance);
	const int result = engine->Main();
	delete engine;
	delete gameInstance;
    return result;
}

CRenderResourceImage* testImage = nullptr;
CRenderResourceImage* testImage1 = nullptr;
CRenderResourceImage* testImage2 = nullptr;
CRenderResourceImage* testImage3 = nullptr;
CRenderResourceText* testText = nullptr;
CRenderResourceText* testText2 = nullptr;
CRenderResourceText* testText3 = nullptr;
CRenderResourceText* testText4 = nullptr;
CRenderResourceText* testText5 = nullptr;

static bool ahShit = false;
void CCresh_GameInstance::PreTick()
{
	if (ahShit == false)
	{
		testImage1 = new CRenderResourceImage(CRenderResourceImage::LoadImage("Content\\Characters\\1.txt"), 0, 0);
		GEngine::GetEngine()->Renderer->RegisterComponent(testImage1);
		testImage = new CRenderResourceImage(CRenderResourceImage::LoadImage("Content\\Characters\\5.txt"), -70, 1);
		GEngine::GetEngine()->Renderer->RegisterComponent(testImage);
		testImage2 = new CRenderResourceImage(CRenderResourceImage::LoadImage("Content\\Characters\\3.txt"), 65, 8);
		GEngine::GetEngine()->Renderer->RegisterComponent(testImage2);
		testImage3 = new CRenderResourceImage(CRenderResourceImage::LoadImage("Content\\Characters\\3.txt"), 53, 8);
		GEngine::GetEngine()->Renderer->RegisterComponent(testImage3);

		testText = new CRenderResourceText(std::string("Cyberpank 1989"), -70, 12);
		GEngine::GetEngine()->Renderer->RegisterComponent(testText);
		testText2 = new CRenderResourceText(std::string("> [ Play ]"), -75, 18);
		GEngine::GetEngine()->Renderer->RegisterComponent(testText2);
		testText3 = new CRenderResourceText(std::string("_ Options"), -80, 20);
		GEngine::GetEngine()->Renderer->RegisterComponent(testText3);
		testText4 = new CRenderResourceText(std::string("_ Credits"), -85, 21);
		GEngine::GetEngine()->Renderer->RegisterComponent(testText4);
		testText5 = new CRenderResourceText(std::string("_ Exit"), -90, 23);
		GEngine::GetEngine()->Renderer->RegisterComponent(testText5);

		CRenderResourceText* testText5 = new CRenderResourceText(std::string("Copyright 1972 - World Software Inc"), 22, 28);
		GEngine::GetEngine()->Renderer->RegisterComponent(testText5);
		ahShit = true;
	}
}

static int bla = 0;
void CCresh_GameInstance::Tick(float deltaTime)
{
	testImage->SetLocation(std::min<float>(testImage->GetX() + (13.f * deltaTime), 3.f), testImage->GetY());
	testText->SetLocation(std::min<float>(testText->GetX() + (14.f * deltaTime), 8.f), testText->GetY());
	testText2->SetLocation(std::min<float>(testText2->GetX() + (14.f * deltaTime), 10.f), testText2->GetY());
	testText3->SetLocation(std::min<float>(testText3->GetX() + (14.f * deltaTime), 10.f), testText3->GetY());
	testText4->SetLocation(std::min<float>(testText4->GetX() + (14.f * deltaTime), 10.f), testText4->GetY());
	testText5->SetLocation(std::min<float>(testText5->GetX() + (14.f * deltaTime), 10.f), testText5->GetY());

	//bla += 1;
	//if (bla == 1000)
	//{
	//	GEngine::GetEngine()->Renderer->UnRegisterComponent(testImage1);
	//	delete testImage1;
	//	testImage1 = nullptr;

	//	GEngine::GetEngine()->Renderer->UnRegisterComponent(testText);
	//	delete testText;
	//	testText = nullptr;
	//}
}

void CCresh_GameInstance::PostTick()
{

}