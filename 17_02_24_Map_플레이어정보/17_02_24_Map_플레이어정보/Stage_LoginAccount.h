#pragma once

#include "Stage.h"

class CStage_LoginAccount : public CStage
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CStage_LoginAccount();
	virtual ~CStage_LoginAccount();
};

