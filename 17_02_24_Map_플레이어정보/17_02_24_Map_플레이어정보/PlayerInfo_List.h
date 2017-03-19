#pragma once

#include "Include.h"

class CObj;
class CPlayerInfo_List
{
private :
	static CPlayerInfo_List* m_pInst;
public :
	static CPlayerInfo_List* GetInst()
	{
		if (m_pInst == nullptr)
		{
			m_pInst = new CPlayerInfo_List;
		}

		return m_pInst;
	}
	void DeleteObj()
	{
		if (m_pInst != nullptr)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}
	}

private :
	map<string, list<CObj*>> m_MapList;
public :
	bool AddList(CObj* _account);

private :
	//객체의 생성과 소멸을 함부로 할 수 없도록 전용 선언을 해두었다. (유저의 정보가 게임 중 멋대로 삭제되는 현상 방지)
	CPlayerInfo_List();
	~CPlayerInfo_List();
};

