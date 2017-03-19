#pragma once

#include "Stage.h"

class CStage_Menu : public CStage
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CStage_Menu();
	virtual ~CStage_Menu();
};

