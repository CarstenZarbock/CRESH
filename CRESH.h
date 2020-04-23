#pragma once

class KEngine* Engine = nullptr;
class CRGameInstance* GameInstance = nullptr;

namespace GEngine
{
	static KEngine* GetEngine() { return Engine; }
}