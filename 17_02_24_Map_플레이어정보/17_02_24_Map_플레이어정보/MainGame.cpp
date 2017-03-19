#include "MainGame.h"

#include "CstageMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	CStageMgr::GetInst()->SetScene(SCENE_IDS_MENU);


	//���� ���� �������� �̰ɷ�..
	CONSOLE_CURSOR_INFO cur;
	cur.bVisible = false;
	cur.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
}

void CMainGame::Progress()
{
	CStageMgr::GetInst()->Progress();

}

void CMainGame::Render()
{
	CStageMgr::GetInst()->Render();

}

void CMainGame::Release()
{

}