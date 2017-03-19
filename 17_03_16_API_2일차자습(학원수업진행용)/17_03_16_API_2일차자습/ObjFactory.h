#pragma once

#include "Obj.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

class CObj;

template<typename T>
class CObjFactory
{
public :
	static CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->init();

		return pObj;
	}

	static CObj* CreateObj(int ix, int iy, int sizex, int sizey)
	{
		CObj* pObj = new T;
		pObj->init();
		pObj->SetInfo(ix, iy, sizex, sizey);

		return pObj;
	}

private:
	CObjFactory() {};
	~CObjFactory() {};
};

