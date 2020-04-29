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
	void SwitchForeGroundState(int newState);

	class KRenderResourceText* Foreground_Text = nullptr;
	class KRenderResourceText* Foreground_Text2 = nullptr;

	class KRenderResourceImage* Foreground_1 = nullptr;
	class KRenderResourceImage* Foreground_2 = nullptr;

	class KRenderResourceImage* Cloud_1 = nullptr;
	class KRenderResourceImage* Cloud_2 = nullptr;
	class KRenderResourceImage* Cloud_f3 = nullptr;

	class KRenderResourceImage* Cloud_3 = nullptr;
	class KRenderResourceImage* Cloud_4 = nullptr;
	class KRenderResourceImage* Cloud_5 = nullptr;
	class KRenderResourceImage* Cloud_6 = nullptr;

	class KRenderResourceImage* MCycle_1 = nullptr;
	class KRenderResourceImage* MCycle_2 = nullptr;

	float Foreground_Text_timer = 5.f;
	int Foreground_Text_Step = 0;
};