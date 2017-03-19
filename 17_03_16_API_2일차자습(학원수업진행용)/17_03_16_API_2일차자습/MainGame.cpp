#include "stdafx.h"
#include "MainGame.h"

#include "KeyMgr.h"
#include "ObjFactory.h"
#include "ObjMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Init()
{
	m_hWnd = GetDC(g_hWnd);

	//m_pCObj_player = CObjFactory<CPlayer>::CreateObj(400, 500, 40, 40);
	//
	//for (int i = 0; i < MAX; i++)
	//{
	//	m_pCObj_monster[i] = CObjFactory<CMonster>::CreateObj((130 * i / 2) + 80, 100, 60, 60);
	//}

	GET_SINGLETON(CObjMgr)->AddObject(OBJ_PLAYER, CObjFactory<CPlayer>::CreateObj(400, 500, 40, 40));

	for (int i = 0; i < MAX; i++)
	{
		GET_SINGLETON(CObjMgr)->AddObject(OBJ_MONSTER, CObjFactory<CMonster>::CreateObj((130 * i / 2) + 80, 100, 60, 60));
	}
}

void CMainGame::Progress()
{
	GET_SINGLETON(CKeyMgr)->KeyCheck();

	GET_SINGLETON(CObjMgr)->Progress();

	//m_pCObj_player->Progress();

	//for (int i = 0; i < MAX; i++)
	//{
	//	m_pCObj_monster[i]->Progress();
	//}
}

void CMainGame::Render()
{
	//버퍼지우는 용도
	Rectangle
	(
		m_hWnd,
		0,
		0,
		WINSIZE_X,
		WINSIZE_Y
	);

	GET_SINGLETON(CObjMgr)->Render();

	////버퍼쓰기
	//m_pCObj_player->Render();
	//
	//for (int i = 0; i < MAX; i++)
	//{
	//	m_pCObj_monster[i]->Render();
	//}
}

void CMainGame::Release()
{

}