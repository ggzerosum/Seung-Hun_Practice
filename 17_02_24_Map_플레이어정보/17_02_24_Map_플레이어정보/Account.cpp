#include "Account.h"

#include "PlayerInfo_List.h"

CAccount::CAccount()
	: m_bDone(false), m_pRefAccount(nullptr), m_bCheck(true)
{
}


CAccount::~CAccount()
{
}

void CAccount::Initialize()
{

}
void CAccount::Progress()
{

}
void CAccount::Render()
{
	system("cls");
	
	if (m_bDone)
	{
		COORD i;
		i.X = MY_CURSORPOS_X - 10;
		i.Y = MY_CURSORPOS_Y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);

		cout << "���̵� ������ �Ϸ��Ͽ����ϴ�. ESCŰ�� ���� �޴��� ���ư��ּ���" << endl;

		if (m_bCheck)
		{
			i.X += 12;
			i.Y += 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << "���̵� ���� �����Ͽ����ϴ�." << endl;
		}
		else
		{
			i.X += 12;
			i.Y += 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
			cout << "������ ���̵� �����մϴ�." << endl;
		}
	}
	else
	{
		RenderInfo();

		SetID();
		SetPassWord();

		m_bCheck = CPlayerInfo_List::GetInst()->AddList(m_pRefAccount); //�ڱ� �ڽ��� ���� ������. ���̵� ������ �Ǿ���.
		m_bDone = true;
	}
}
void CAccount::Release()
{

}

void CAccount::RenderInfo()
{
	COORD i;
	i.X = MY_CURSORPOS_X;
	i.Y = MY_CURSORPOS_Y;

	m_iCursorPos_Y = i.Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
	cout << "���̵�   �Է� : ";
	m_iID_CursorPos = i.X + 18;

	i.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), i);
	cout << "��й�ȣ �Է� : ";
	m_iPassWord_CursorPos = i.X + 18;
	m_iCursorPos_Y_PassWord = i.Y;
}

void CAccount::SetID()
{
	COORD j;
	j.X = m_iID_CursorPos;
	j.Y = m_iCursorPos_Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), j);
	cin >> m_sPlayer_ID;
}

void CAccount::SetPassWord()
{
	COORD j;
	j.X = m_iPassWord_CursorPos;
	j.Y = m_iCursorPos_Y_PassWord;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), j);
	cin >> m_iPlayer_PassWord;
}

string CAccount::GetName_String()
{
	return m_sPlayer_ID;
}