#include "MainGame.h"

#include "Include.h"

bool EXIT = true;
int main()
{
	CMainGame MainPro;

	MainPro.Initialize();

	while (EXIT)
	{
		MainPro.Progress();
		MainPro.Render();

		Sleep(50);
	}
	
	/*string a("I LOVE U");
	cout << a << endl;
	cout << "������ : " << a.size() << endl;

	a.insert(1,"Really");
	cout << a << endl;
	cout << "������ : " << a.size() << endl;*/

	/*string* sA = new string;
	cout << *sA << endl;
	cout << sizeof(*sA) << endl;

	sA->append("�ȳ��ϼ���");
	cout << sizeof(*sA) << endl;

	cout << *sA << endl;*/
}