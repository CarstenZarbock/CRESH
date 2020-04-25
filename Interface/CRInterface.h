#pragma once

#include "stdafx.h"
#include "Interface\Interface.h"

class CRInterface : public KInterface
{
public:
	CRInterface::CRInterface() = default;

	CRInterface::CRInterface(class KEngine* engine)
	{
		Engine = engine;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;

protected:
	void SwitchMenu(int index);

	int CurrentMenuIndex = -1;
	float ButtonTimeOut = 0;
	class KRenderResourceText* Text_StartGame = nullptr;
	class KRenderResourceText* Text_ContinueGame = nullptr;
	class KRenderResourceText* Text_Options = nullptr;
	class KRenderResourceText* Text_Exit = nullptr;

	class KRenderResourceText* Text_GameName = nullptr;
	class KRenderResourceText* Text_Copyright = nullptr;

	class KRenderResourceImage* Background = nullptr;
	class KRenderResourceImage* Girl1 = nullptr;
	class KRenderResourceImage* Girl2 = nullptr;
	class KRenderResourceImage* Logo = nullptr;
};