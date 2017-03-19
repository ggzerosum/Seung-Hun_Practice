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

	if (KeyPosition == m_MapList.end() ) //�ʾȿ� Ű���� ���� ��
	{
		list<CObj*> temp_ObjList;
		temp_ObjList.push_back(_account);

		m_MapList.insert(make_pair(Key, temp_ObjList)); // �̰� ��ü ���� ������? �˾ƺ���. -> �ذ��. ����Ʈ�� �����忡 �־�����Ѵ�.

		return true;
	}
	else
	{
		(KeyPosition->second).push_back(_account); //�ʾȿ� Ű���� ���� ��

		return false;
	}
}