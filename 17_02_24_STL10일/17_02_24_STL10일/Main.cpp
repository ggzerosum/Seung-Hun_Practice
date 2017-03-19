#include <iostream>
#include <Windows.h>

#include <string>
#include <vector>
#include <map>
#include <list>



//#define ListIter map<string, list<CObj*>>::iterator

typedef struct __Info
{
	int iKor;
	int iEng;
	int iMath;

	__Info() {};
	__Info(int _iKor, int _iEng, int _iMath) : iKor(_iKor), iEng(_iEng), iMath(_iMath) {};
}INFO;

//Base Class
class CObj
{
protected :
	INFO m_tInfo;

public :
	INFO GetInfo()
	{
		return m_tInfo;
	}
	void SetInfo(INFO _info)
	{
		m_tInfo = _info;
	}
	
public :
	virtual void Initialize() = 0;
	virtual void Progress() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public :
	CObj() {};
	virtual ~CObj() {};
};
//End


//Derived Class
class CStudent : public CObj
{
public :
	virtual void Initialize()
	{
		m_tInfo.iKor = 10;
		m_tInfo.iEng = 10;
		m_tInfo.iMath = 10;
	}
	virtual void Progress()
	{

	}
	virtual void Render()
	{
		using namespace std;
		cout << "����" << m_tInfo.iKor << endl;
		cout << "����" << m_tInfo.iEng << endl;
		cout << "����" << m_tInfo.iMath << endl << endl;
	}
	virtual void Release()
	{

	}

public :
	CStudent() 
	{

	};

	virtual ~CStudent() 
	{

	};
};
//End


///fnc
template <typename DataType>
CObj* CreateObj()
{
	CObj* pObj = new DataType;
	pObj->SetInfo(SetScore());
	
	return pObj;
}

INFO SetScore()
{
	using namespace std;

	int ikor;
	int ieng;
	int imath;

	cout << "���� ���� �Է� : "; cin >> ikor;
	cout << "���� ���� �Է� : "; cin >> ieng;
	cout << "���� ���� �Է� : "; cin >> imath;

	INFO i = INFO(ikor, ieng, imath);

	return i;
}
//end

int main()
{
	using namespace std;
	map<string, list<CObj*>> MapList;

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime < GetTickCount())
		{
			dwTime = GetTickCount();

			if (GetAsyncKeyState(VK_F1))
			{
				system("cls");

				string str;
				cout << "�л� �̸� �Է� : "; cin >> str;

				MapList.find(str);
				map<string, list<CObj*>>::iterator iter = MapList.find(str);

				if (iter == MapList.end())
				{
					list<CObj*> ObjList;
					ObjList.push_back(CreateObj<CStudent>());
					
					MapList.insert(make_pair(str, ObjList));
				}
				else
				{
					(iter->second).push_back(CreateObj<CStudent>());
				}
			}

			if (GetAsyncKeyState(VK_F2))
			{
				//��ü ���
				system("cls");

				for (map<string, list<CObj*>>::iterator iter = MapList.begin(); iter != MapList.end(); iter++)
				{
					cout << "�л� �̸� : " << iter->first << endl;
					
					for (list<CObj*>::iterator iter2 = (iter->second).begin(); iter2 != (iter->second).end(); iter2++)
					{

						(*iter2)->Render();
					}

				}
			}

			if (GetAsyncKeyState(VK_F3))
			{
				//�̸����� ã��
				system("cls");

				string str;
				cout << "ã���� �ϴ� �̸� �Է� : "; cin >> str;

				bool BREAK = false;
				for (map<string, list<CObj*>>::iterator iter = MapList.begin(); iter != MapList.end(); iter++)
				{
					if (str == (*iter).first)
					{
						for (list<CObj*>::iterator iter2 = (iter->second).begin(); iter2 != (iter->second).end(); iter2++)
						{
							(*iter2)->Render();
						}

						BREAK = true;
					}

					if (BREAK)
						break;
				}

				if (!(BREAK))
					cout << "�ڷ᳻�� �����ϴ�. ã�� ���߽��ϴ�." << endl;
			}

			if (GetAsyncKeyState(VK_F4))
			{
				//�����ϱ�
				system("cls");

				string str;
				cout << "�����Ϸ��� �̸� �Է� : "; cin >> str;

				map<string, list<CObj*>>::iterator iter = MapList.find(str);

				//if ()

			}

		}
	}


	return 0;
}
