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
	class KRenderResourceText* TestText = nullptr;
};