#pragma once

#include "Include.h"

class CObj;
class CObjMgr
{
public :
	DECLARE_SINGLETON(CObjMgr)

private :
	std::map<OBJ_ID, std::list<CObj*>> m_MapObjList;
public :
	void AddObject(OBJ_ID _id, CObj* _pointer);
	void DeleteObject(OBJ_ID _id, CObj* _pointer);
	void DestroyMap();
public :
	void Init();
	void Progress();
	void Render();
	void Release();

private :
	CObjMgr();
public:
	~CObjMgr();
};

