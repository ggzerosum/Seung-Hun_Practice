#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
}


CObj::~CObj()
{
}

void CObj::SetInfo(int ix, int iy, int sizex, int sizey)
{
	m_Info.iX = ix;
	m_Info.iY = iy;

	m_Info.iSizeX = sizex;
	m_Info.iSizeY = sizey;
}