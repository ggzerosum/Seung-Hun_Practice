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
	cout << "사이즈 : " << a.size() << endl;

	a.insert(1,"Really");
	cout << a << endl;
	cout << "사이즈 : " << a.size() << endl;*/

	/*string* sA = new string;
	cout << *sA << endl;
	cout << sizeof(*sA) << endl;

	sA->append("안녕하세요");
	cout << sizeof(*sA) << endl;

	cout << *sA << endl;*/
}