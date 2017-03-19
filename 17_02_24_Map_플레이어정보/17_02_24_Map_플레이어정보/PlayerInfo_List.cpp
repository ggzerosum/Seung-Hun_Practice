#include "PlayerInfo_List.h"

#include "Obj.h"
#include "Account.h"

CPlayerInfo_List* CPlayerInfo_List::m_pInst = nullptr;

CPlayerInfo_List::CPlayerInfo_List()
{
}


CPlayerInfo_List::~CPlayerInfo_List()
{
}

bool CPlayerInfo_List::AddList(CObj* _account)
{
	string Key = ((CAccount*)_account)->GetName_String();
	map<string, list<CObj*>>::iterator KeyPosition = m_MapList.find(Key);

	if (KeyPosition == m_MapList.end() ) //맵안에 키값이 없을 때
	{
		list<CObj*> temp_ObjList;
		temp_ObjList.push_back(_account);

		m_MapList.insert(make_pair(Key, temp_ObjList)); // 이게 대체 무슨 오류지? 알아보자. -> 해결됨. 리스트를 세컨드에 넣었어야한다.

		return true;
	}
	else
	{
		(KeyPosition->second).push_back(_account); //맵안에 키값이 있을 때

		return false;
	}
}