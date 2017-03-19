#pragma once

#include "Include.h"

class CObj
{
public :
	virtual void Initialize() = 0;
	virtual void Progress() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	CObj();
	virtual ~CObj();
};

