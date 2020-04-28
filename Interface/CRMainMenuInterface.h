#pragma once

#include "stdafx.h"
#include "..\Interface\CRInterface.h"

class CRMainMenuInterface : public CRInterface
{
public:
	CRMainMenuInterface::CRMainMenuInterface() = default;

	CRMainMenuInterface::CRMainMenuInterface(class KEngine* engine)
	{
		Engine = engine;
	}

	virtual void Initialize() override;
	virtual void Tick(const float deltaTime) override;
	virtual void OnDestroy() override;

protected:
	void SwitchMenu(int index);
	void UpdateBlink();

	int CurrentMenuIndex = -1;
	float ButtonTimeOut = 0;
	float BlinkTime = 0;
	bool bIsBlinkVisible = false;

	class KRenderResourceText* Text_StartGame = nullptr;
	class KRenderResourceText* Text_ContinueGame = nullptr;
	class KRenderResourceText* Text_Options = nullptr;
	class KRenderResourceText* Text_Exit = nullptr;

	class KRenderResourceText* Text_GameName = nullptr;
	class KRenderResourceText* Text_Copyright = nullptr;

	class KRenderResourceText* MSG1Text_Name = nullptr;
	class KRenderResourceText* MSG1Text_Time = nullptr;
	class KRenderResourceText* MSG1Text_MSG = nullptr;

	class KRenderResourceText* MSG2Text_Name = nullptr;
	class KRenderResourceText* MSG2Text_Time = nullptr;
	class KRenderResourceText* MSG2Text_MSG = nullptr;

	class KRenderResourceText* MSG3Text_Name = nullptr;
	class KRenderResourceText* MSG3Text_Time = nullptr;
	class KRenderResourceText* MSG3Text_MSG = nullptr;

	class KRenderResourceText* Random_Text_1 = nullptr;
	class KRenderResourceText* Random_Text_2 = nullptr;
	class KRenderResourceText* Random_Text_3 = nullptr;
	class KRenderResourceText* Random_Text_4 = nullptr;
	class KRenderResourceText* Random_Text_5 = nullptr;
	class KRenderResourceText* Random_Text_6 = nullptr;
	class KRenderResourceText* Random_Text_7 = nullptr;

	class KRenderResourceImage* Background = nullptr;
	class KRenderResourceImage* Logo = nullptr;
};