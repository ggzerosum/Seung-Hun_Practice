#pragma once

#include "Stage.h"

class CObj;
class CStage_MakeAccount : public CStage
{
private :
	CObj* m_pNewAccount;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CStage_MakeAccount();
	virtual ~CStage_MakeAccount();
};

