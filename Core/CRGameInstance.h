#pragma once

#include "Core\GameInstance.h"

class CRGameInstance : public KGameInstance
{

public:
	CRGameInstance::CRGameInstance();

	virtual void PreTick() override;
	virtual void Tick(float deltaTime) override;
	virtual void PostTick() override;

protected:
};