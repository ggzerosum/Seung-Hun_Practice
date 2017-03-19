#pragma once

#include "Include.h"

class CStage
{
public:
	virtual void Initialize() = 0;
	virtual void Progress() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	CStage();
	virtual ~CStage();
};

