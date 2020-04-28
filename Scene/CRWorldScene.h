#pragma once

#include "stdafx.h"
#include "Scene\Scene.h"

class CRWorldScene : public KScene
{
public:
	CRWorldScene::CRWorldScene();
	CRWorldScene::CRWorldScene(class KEngine* engine);

	virtual void Load() override;
	virtual void Tick(const float deltaTime) override;

protected:
	class CRPlayerController* PlayerController = nullptr;
};