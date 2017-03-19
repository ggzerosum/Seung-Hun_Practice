#pragma once

#include "Things.h"

class CBullet : public CThings
{
private :
	HDC m_hDC;
	float m_fBulletSpeed;

public :
	virtual void init();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CBullet();
	virtual ~CBullet();
};

