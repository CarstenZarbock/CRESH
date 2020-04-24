#pragma once

#include "Core\GameInstance.h"

class CRGameInstance : public KGameInstance
{

public:
	CRGameInstance::CRGameInstance();
	virtual void InitializeDefaultScene(class KEngine* engine) override;

protected:
};