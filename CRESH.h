#include "TextEngine\Engine.h"

CEngine* engine = nullptr;

namespace GEngine
{
	static CEngine* GetEngine() { return engine; }
}

class CShitRPG_GameInstance : public CGameInstance
{

public:
	CShitRPG_GameInstance::CShitRPG_GameInstance() = default;
	virtual const std::wstring& GetTitle() const { return Title; }

	virtual void PreTick() override;
	virtual void Tick(float deltaTime) override;
	virtual void PostTick() override;

	const std::wstring Title = L"Cyberpank 1989 Copyright 1972 World Software Inc";

protected:
};