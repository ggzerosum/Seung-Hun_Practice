#include "stdafx.h"
#include "ObjMgr.h"

#include "Obj.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::AddObject(OBJ_ID _id, CObj* _pointer)
{
	std::map<OBJ_ID, std::list<CObj*>>::iterator iter = m_MapObjList.find(_id);

	if (iter == m_MapObjList.end())
	{
		std::list<CObj*> pList;
		pList.push_back(_pointer);

		m_MapObjList.insert(make_pair(_id, pList));
	}
	else
	{
		(iter->second).push_back(_pointer);
	}
}

void CObjMgr::DeleteObject(OBJ_ID _id, CObj* _pointer)
{
	std::map<OBJ_ID, std::list<CObj*>>::iterator iter = m_MapObjList.find(_id);

	if (iter == m_MapObjList.end())
	{
		/*HDC hdc = GetDC(g_hWnd);
		TextOut(hdc, 100, 100, TEXT("키값없음"), 5);
		ReleaseDC(g_hWnd, hdc);*/
	}
	else
	{
		for (std::list<CObj*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++)
		{
			if ((*iter2) == _pointer)
			{
				delete (*iter2);
				(*iter2) = nullptr;

				(iter->second).erase(iter2);
				break;
			}
		}
	}
}


void CObjMgr::Init()
{
	//애드할 때 Init한다;
}

void CObjMgr::Progress()
{
	for (std::map<OBJ_ID, std::list<CObj*>>::iterator iter = m_MapObjList.begin(); iter != m_MapObjList.end(); iter++)
	{
		for (std::list<CObj*>::iterator iter2 = (iter->second).begin(); iter2 != (iter->second).end(); iter2++)
		{
			(*iter2)->Progress();
		}
	}
}

void CObjMgr::Render()
{
	for (std::map<OBJ_ID, std::list<CObj*>>::iterator iter = m_MapObjList.begin(); iter != m_MapObjList.end(); iter++)
	{
		for (std::list<CObj*>::iterator iter2 = (iter->second).begin(); iter2 != (iter->second).end(); iter2++)
		{
			(*iter2)->Render();
		}
	}
}

void CObjMgr::Release()
{
	DestroyMap();
}

void CObjMgr::DestroyMap()
{
	for (std::map<OBJ_ID, std::list<CObj*>>::iterator iter = m_MapObjList.begin(); iter != m_MapObjList.end(); iter++)
	{
		for (std::list<CObj*>::iterator iter2 = (iter->second).begin(); iter2 != (iter->second).end(); iter2++)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
		(iter->second).clear();
	}
	m_MapObjList.clear();
}