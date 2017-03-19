#pragma once

#include "Obj.h"

template<typename DataType>
class CObjFactory
{
public :
	static CObj* CreateObj()
	{
		CObj* pObj = new DataType;
		pObj->Initialize();

		return pObj;
	}
};