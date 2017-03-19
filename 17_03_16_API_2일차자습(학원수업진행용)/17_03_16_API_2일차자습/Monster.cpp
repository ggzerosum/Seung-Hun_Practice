#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
	init();
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::init()
{
	m_hWnd = GetDC(g_hWnd);
	this->SetInfo(300, 300, 50, 50);
}

void CMonster::Progress()
{

}

void CMonster::Render()
{
	Rectangle
	(
		m_hWnd,
		m_Info.iX - m_Info.iSizeX / 2,
		m_Info.iY - m_Info.iSizeY / 2,
		m_Info.iX + m_Info.iSizeX / 2,
		m_Info.iY + m_Info.iSizeY / 2
	);
}

void CMonster::Release()
{
	ReleaseDC(g_hWnd, m_hWnd);
}