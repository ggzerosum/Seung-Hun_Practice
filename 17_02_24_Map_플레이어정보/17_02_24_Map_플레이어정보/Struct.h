#pragma once

typedef struct __Status_Player
{
	int iHp;
	int iMp;
	
	int iStamina;

	int iAtt;
	int iDef;

	__Status_Player() 
	{
		//�ʱⰪ ���� (������) Start
		iHp = 100;
		iMp = 200;

		iStamina = 1000;

		iAtt = 10;
		iDef = 10;
		//�ʱⰪ ���� (������) End

		cout << "�÷��̾� �������ͽ� �ʱⰪ ���� �Ϸ�" << endl;
	};

	__Status_Player
	(
		int _iHp				, 
		int _iMp				, 
		int _iStamina			, 
		int _iAtt				, 
		int _iDef				
	) 
		: 
		iHp(_iHp)				, 
		iMp(_iMp)				, 
		iStamina(_iStamina)		, 
		iAtt(_iAtt)				, 
		iDef(_iDef)				
	{
		cout << "�÷��̾� �������ͽ� ���ڰ����� ���� �Ϸ�" << endl;
	};
}Status_Player;

typedef struct __Status_Item
{
	string* sItemCode; //String���� �ڵ带 �ۼ�(������ ����)

	string* sItemName;

	int iAtt;
	int iDef;
	int iIndurance;

	int iValue;

	__Status_Item() 
	{
		sItemCode = nullptr;
		sItemName = nullptr;

		iAtt = 0;
		iDef = 0;

		iIndurance = 100;

		iValue = 0;

		cout << "������ �ʱⰪ���� ���� �Ϸ�" << endl;
	};
	__Status_Item
	(
		string* _sItemCode,
		string* _sItemName,
		int _iAtt,
		int _iDef,
		int _iIndurance,
		int _iValue
	) 
		: 
		sItemCode(_sItemCode)	,
		sItemName(_sItemName)	,
		iAtt(_iAtt)				,
		iDef(_iDef)				,
		iIndurance(_iIndurance)	,
		iValue(_iValue)			
	{
		cout << "������ ���ڰ����� ���� �Ϸ�" << endl;
	};
}Status_Item;