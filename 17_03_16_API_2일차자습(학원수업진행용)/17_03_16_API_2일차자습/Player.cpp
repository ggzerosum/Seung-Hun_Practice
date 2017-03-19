#include "stdafx.h"
#include "Player.h"

#include "KeyMgr.h"
#include "ObjFactory.h"
#include "ObjMgr.h"

CPlayer::CPlayer()
{
	init();
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::init()
{
	m_hWnd = GetDC(g_hWnd);
	m_dwKey = 0;
	
	m_iCount = 0;
	m_iDestinationCount = 0;
	m_fStandardTime = 0.0;
	m_fStand = 1000.0;
	m_fPlusNum = FRAME / m_fStand;

	//변수 초기값
	m_fSpeed = 5.0;
	m_fBulletDelay = BULLET_DELAYTIME;

	this->SetInfo(100,100 , 40,40);

	m_fStandardTime = m_fBulletDelay / m_fStand;

	for (float i = 0; i < m_fStandardTime;)
	{
		i += m_fPlusNum;
		m_iDestinationCount++;
	}
}

void CPlayer::Progress()
{
	GetKey();
	Move();

	MakeBullet(); //현재 플레이어의 위치에서 불렛생성해서 날린다. 순서는 Move 다음에 올 것;
}

void CPlayer::Render()
{
	Rectangle
	(
		m_hWnd								,
		m_Info.iX - m_Info.iSizeX / 2		,
		m_Info.iY - m_Info.iSizeY / 2		,
		m_Info.iX + m_Info.iSizeX / 2		,
		m_Info.iY + m_Info.iSizeY / 2
	);
}

void CPlayer::Release()
{
	ReleaseDC(g_hWnd, m_hWnd);
}

void CPlayer::GetKey()
{
	m_dwKey = GET_SINGLETON(CKeyMgr)->GetKey();
}

void CPlayer::Move()
{
	if (m_dwKey & KEY_UP)
	{
		m_Info.iY -= m_fSpeed;
	}
	if (m_dwKey & KEY_DOWN)
	{
		m_Info.iY += m_fSpeed;
	}

	if (m_dwKey & KEY_LEFT)
	{
		m_Info.iX -= m_fSpeed;
	}
	if (m_dwKey & KEY_RIGHT)
	{
		m_Info.iX += m_fSpeed;
	}
}

void CPlayer::MakeBullet()
{
	if (m_iDestinationCount <= m_iCount)
	{
		if (m_dwKey & KEY_SPACE)
		{
			m_iCount = 0;
			GET_SINGLETON(CObjMgr)->AddObject(OBJ_BULLET, CObjFactory<CBullet>::CreateObj(GetInfo().iX, GetInfo().iY, GetInfo().iSizeX / 2, GetInfo().iSizeY / 2));
			//m_BulletList.push_back(CObjFactory<CBullet>::CreateObj(GetInfo().iX, GetInfo().iY, GetInfo().iSizeX / 2, GetInfo().iSizeY / 2));
		}
	}
	else
	{
		m_iCount++;
	}

}