#pragma once

#include "stdafx.h"
#include "..\Interface\CRInterface.h"

class CRIntroSceneInterface : public CRInterface
{
public:
	CRIntroSceneInterface::CRIntroSceneInterface() = default;

	CRIntroSceneInterface::CRIntroSceneInterface(class KEngine* engine)
	{
		Engine = engine;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;
	virtual void OnDestroy() override;

protected:
	class KRenderResourceText* Text_StartGame = nullptr;
};