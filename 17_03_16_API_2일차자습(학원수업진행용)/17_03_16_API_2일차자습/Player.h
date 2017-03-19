#pragma once

#include "Man.h"

class CPlayer : public CMan
{
private :
	DWORD m_dwKey;
	HDC m_hWnd;
	float m_fSpeed;
	//std::list<CObj*> m_BulletList;

	int m_iCount; // �Ѿ� ������ �����ϰ� �����ϱ����� �������;
	float m_fStand;
	int m_iDestinationCount;
	float m_fStandardTime;
	float m_fPlusNum;
	float m_fBulletDelay; //���ϴ� ������ �ð� �Է�(1 / 1000);

public :
	virtual void init();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
private :
	void GetKey();
	void Move();
	void MakeBullet();

public:
	CPlayer();
	virtual ~CPlayer();
};

