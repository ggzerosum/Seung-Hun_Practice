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
	//��ü�� ������ �Ҹ��� �Ժη� �� �� ������ ���� ������ �صξ���. (������ ������ ���� �� �ڴ�� �����Ǵ� ���� ����)
	CPlayerInfo_List();
	~CPlayerInfo_List();
};

