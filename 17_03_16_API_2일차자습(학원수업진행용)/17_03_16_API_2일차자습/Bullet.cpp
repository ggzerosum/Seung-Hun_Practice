#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::init()
{
	m_hDC = GetDC(g_hWnd);
	m_fBulletSpeed = 10;
}

void CBullet::Progress()
{
	m_Info.iY -= m_fBulletSpeed;
}

void CBullet::Render()
{
	Ellipse
	(
		m_hDC								,
		m_Info.iX - m_Info.iSizeX / 2		,
		m_Info.iY - m_Info.iSizeY / 2		,
		m_Info.iX + m_Info.iSizeX / 2		,
		m_Info.iY + m_Info.iSizeY / 2
	);
}

void CBullet::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
}