#pragma once

#include "CRESH.h"
#include "Engine.h"
#include "Core\CRGameInstance.h"

int main()
{
	GameInstance = new CRGameInstance();
	Engine = new KEngine(GameInstance);
	
	Engine->PreInitialize();

	const int result = Engine->Main();

	delete Engine;
	delete GameInstance;
    return result;
}