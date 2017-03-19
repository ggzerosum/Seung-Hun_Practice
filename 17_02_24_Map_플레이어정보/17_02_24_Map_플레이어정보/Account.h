#pragma once

#include "Obj.h"

class CAccount : public CObj
{
private :
	CObj* m_pRefAccount;

private :
	string m_sPlayer_ID;
	int m_iPlayer_PassWord;

	int m_iCursorPos_Y;
	int m_iCursorPos_Y_PassWord;

	int m_iID_CursorPos;
	int m_iPassWord_CursorPos;

	bool m_bDone;
	bool m_bCheck;

public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

private :
	void RenderInfo();
	void SetID();
	void SetPassWord();

public :
	string GetName_String();
	bool GetDone_Bool()
	{
		return m_bDone;
	}
	void SetAccount_pointer(CObj* _account)
	{
		m_pRefAccount = _account;
	}

public:
	CAccount();
	virtual ~CAccount();
};

