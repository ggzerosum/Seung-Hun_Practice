#pragma once

#include "Include.h"

class CObj
{
protected :
	INFO m_Info;

public :
	virtual void init() = 0;
	virtual void Progress() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
public :
	void SetInfo(int ix, int iy, int sizex, int sizey);
	INFO GetInfo()
	{
		return m_Info;
	}

public:
	CObj();
	virtual ~CObj();
};

