#pragma once

#include "Man.h"

class CMonster : public CMan
{
private:
	HDC m_hWnd;

public :
	virtual void init();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CMonster();
	virtual ~CMonster();
};

