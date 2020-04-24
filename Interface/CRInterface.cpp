#pragma once

#include "Engine.h"
#include "Rendering\Renderer.h"
#include "Rendering\RenderResources\RenderResource.h"
#include "CRInterface.h"

void CRInterface::Initialize()
{
	TestText = new KRenderResourceText(std::string("Test Interface Text"), 0, 0);
	if (Engine != nullptr)
	{
		Engine->GetRenderer().RegisterComponent(TestText);
	}
}

void CRInterface::Tick(const float deltaTime)
{
	TestText->SetLocation(TestText->GetX() + (1.f * deltaTime), TestText->GetY() + (1.f * deltaTime));
}