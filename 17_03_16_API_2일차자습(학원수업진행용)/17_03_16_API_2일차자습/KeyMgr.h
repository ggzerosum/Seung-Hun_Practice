#pragma once

#include "Include.h"

class CKeyMgr
{
public :
	DECLARE_SINGLETON(CKeyMgr)

private :
	DWORD m_dwKey;
public :
	void KeyCheck();
	DWORD GetKey() const;

public:
	CKeyMgr();
	~CKeyMgr();
};

