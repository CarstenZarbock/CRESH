#pragma once

#include "stdafx.h"
#include "..\Interface\CRInterface.h"

class CRWorldSceneInterface : public CRInterface
{
public:
	CRWorldSceneInterface::CRWorldSceneInterface() = default;

	CRWorldSceneInterface::CRWorldSceneInterface(class KEngine* engine)
	{
		Engine = engine;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;
	virtual void OnDestroy() override;

protected:
	class KRenderResourceText* Text_StartGame = nullptr;
	class KRenderResourceText* Text_StartGame2 = nullptr;
	class KRenderResourceText* Text_StartGame3 = nullptr;
};