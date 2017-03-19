#pragma once

#include "Define.h"

class CObj;
class CMainGame
{
private :
	HDC m_hWnd;
	CObj* m_pCObj_player;
	CObj* m_pCObj_monster[MAX];

public :
	void Init();
	void Progress();
	void Render();
	void Release();

public:
	CMainGame();
	~CMainGame();
};