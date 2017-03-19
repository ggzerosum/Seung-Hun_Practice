#include "Stage_Menu.h"

#include "CstageMgr.h"

extern bool EXIT;

CStage_Menu::CStage_Menu()
{
}


CStage_Menu::~CStage_Menu()
{
}

void CStage_Menu::Initialize()
{

}
void CStage_Menu::Progress()
{

}
void CStage_Menu::Render()
{
	system("cls");

	COORD i;
	i.X = MY_CURSORPOS_X;
	i.Y = MY_CURSORPOS_Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
	cout << "F1 . 로   그   인";

	i.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
	cout << "F2 . 아이디 만들기";

	i.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
	cout << "F3 . 종  료 하  기";

	i.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);


	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		CStageMgr::GetInst()->SetScene(SCENE_IDS_LoginAccount);
	}

	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		CStageMgr::GetInst()->SetScene(SCENE_IDS_MakeAccount);
	}

	if (GetAsyncKeyState(VK_F3) & 0x8000)
	{

		EXIT = false;
	}
}
void CStage_Menu::Release()
{

}