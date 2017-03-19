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
		//초기값 설정 (생성자) Start
		iHp = 100;
		iMp = 200;

		iStamina = 1000;

		iAtt = 10;
		iDef = 10;
		//초기값 설정 (생성자) End

		cout << "플레이어 스테이터스 초기값 설정 완료" << endl;
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
		cout << "플레이어 스테이터스 인자값으로 설정 완료" << endl;
	};
}Status_Player;

typedef struct __Status_Item
{
	string* sItemCode; //String으로 코드를 작성(영문자 포함)

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

		cout << "아이템 초기값으로 설정 완료" << endl;
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
		cout << "아이템 인자값으로 설정 완료" << endl;
	};
}Status_Item;