#pragma once

#include "Obj.h"

class CPlayer : public CObj
{
private :
	Status_Player m_Status;

public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CPlayer();
	virtual ~CPlayer();
};

