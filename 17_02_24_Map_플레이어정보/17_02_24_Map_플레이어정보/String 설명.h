#pragma once


http://yotop93.blogspot.kr/2015/04/string.html
	 

참고할 것

string클래스를 이용한 문자열 사용




1.string 클래스 개요

c++에서 문자열을 다루는 방법은 C - 스트링과 string 클래스 이 두가지가 있다.

C - 스트링은 C언어에서 사용해오던 전통적인 문자열로서, '\0'로 끝나는 문자배열을 문자열로 취급하는 방법이다.반면 string은 C++ 표준 라이브러리에서 제공하는 클래스로서, 문자열을 객체로 다룬다.

string 클래스느를 사용하기 위해서는 다음 코드가 필요하다




#include <string>

using namespace std;



string 클래스는 문자열의 크기에 따라 메모리 크기를 조절하므로 사용하기 매우 편리하다

다음은 "I love " 문자열에 "C++"을 연결하는 코드이다.




string str = "i love "; // str은 'I', ' ', 'l', 'o', 'v', 'e', ' '의 7개 문자로 구성

str.append("C++"); //str은 "I love C++"이 된다







2. string 객체 생성 및 출력

1. string 객체 생성

string 클래스의 생성자를 이용하여 다음과 같이 다양하게 문자열을 생성할 수 있다.

문자열의 크기에는 제한이 없다.




string str; //빈 문자열을 가진 스트링 객체

string address("서울시 성북구 정릉동 892-2"); //문자열 리터럴로 초기화

string copyAddress(adress); //address를 복사한 copyAddress 생성




							//C-스트링 (char [] 배열)으로부터 스트링 객체 생성

char text[] = { 'l', 'o', 'v', 'e', ' ', 'c', '+', '+', '\0' }; //C-스트링

string title(text); //"Love C++"을 가진 string 객체 생성




2. string 객체가 가진 문자열 출력

string 객체의 문자열은 cout << 를 이용하여 쉽게 화면에 출력할 수 있다




cout << address << endl; // "서울시 성북구 정릉동 892-2" 출력

cout << title << endl; // "Love C++" 출력




3. string 객체의 동적 생성

스트링 객체 역시 new 와 delete 연산자를 이용하여 동적으로 생성하고 반환할 수 있다.




string *p = new string("C++"); // 스트링 객체 동적 생성

cout << *p; // "C++" 출력

p->append(" Gtreat!!"); // p가 가리키는 스트링이 "C++ Great!!"가 됨

cout << *p; // "C++ Great!!"를 출력

delete p; // 스트링 객체 반환




string 클래스의 주요 생성자

string()--->빈문자열을 가진 스트링 객체 생성

string(string& str)--->str을 복사한 새로운 스트링 객체 생성




다음은 string 클래스를 이용한 문자열 생성 및 출력하는 예제이다






3. string 객체에 문자열 입력

1.sgring 객체에 문자열 입력

cin >> 을 이용하여 키보드로부터 string 객체에 문자열을 입력받을수 있다

키보드로부터 이름을 입력받아 name에 저장하는 코드이다




string name;

cin >> name;



>> 연산자는 사용하기 쉽지만, 공백문자가 입력되면 그 앞까지 하나의 문자열로 다루기 때문에 공백문자를 포함하는 문자열을 읽어 들일 수 없다.이런 문제는<string>헤더파일에 선언된 getline() 전역함수를 이용하면 된다 getline() 으로 문자열을 입력받는 예를 들면 다음과 같다.




string name;

getline(con, name, '\n'); // '\n'을 만날때가지 키보드 (cin)로부터 문자열을 읽어 name에                                   저장

이 getline()의 첫 번째 인자에는 cin을, 두 번째 인자에는 string 객체를, 세 번째 인자에는 문자열의 마지막을 표시하는 구분 문자(delimiter)를 준다.앞의 코드는 '\n'을 만날때까지 입력된 문자들을 name 객체에 문자열로 저장하는 코드이다.




string 배열과 문자열 키 입력 응용









다음은 string 클래스의 주요 멤버 함수이다




string append(string& str)------>문자열 뒤에 str 추가

string& append(string& str, int pos, int n)------> 문자열의 pos위치에 str 문자열 중 n                                                                      개 문자 삽입, pos가 0이면 맨 앞에 삽입

int compare(string& str)------>문자열과 str을 비교하여 같으면 0을, 사전 순으로 현재문                                            자열이 앞에 오면 음수, 뒤에 오면 양수 리턴

string substr(int pos, int n)------> pos위치부터 n개 문자를 새로운 서브스트링으로 생성
리턴
int size()------>문자열의 길이 리턴, 문자열의 길이를 바이트 수(영어 문자 개수)
int legth()------> 문자열의 길이 리턴, size()와 동일



4.문자열 다루기

1. 문자열 치환

문자열 치환은 간단히 = 연산자를 이용한다




string a = "java", b = "C++";

a = b; // a = "C++"이 된다.





2. 문자열 비교

문자열 비교는 compare()함수를 이용한다.이 함수는 두 문자열이 같으면 0, str보다 사전 순으로 앞에 오면 음수, 뒤에 오면 양수를 리턴한다.다음 코드를 보자




string name = "kitae";

string alias = "kito";

int res = name.compare(alias); // name과 alias를 비교한다.

if (res == 0) cout << "두 문자열이 같다"; // name 과 alias가 동일

else if (res < 0) cout << name << " < " << alias << endl; // name이 앞에 옴

else cout << alias << " < " << name << endl; // name이 뒤에 옴




문자열 크기 비교는 다음의 비교연산자를 이용하면 보다 효과적이다




if (name == alias) cout << "두 문자열이 같다";

if (name < alias) cout << name << "이" << alias << "보다 사전에서 먼저 나온다";




3.문자열 연결

두 개의 문자열을 연결하기 위해 append()함수를 이용한다 다음은 "I" 문자열 끝에 "love"를 추가하는 예이다.




string a("I");

a.append("love"); // a = "I love"




문자열 연결은 + , +=연산자를 이용하여 쉽게 작성할 수 있다.




string a("I love C++");

string b(".");

string c;

c = a + b; // a, b문자열에는 변화가 없고c = "I love C++."로 변경됨

c += b; // b문자열에는 변화가 없고 c = "I love C++.."로 변경됨




4. 문자열 삽입

string 클래스는 문자열에 새로운 문자열이나 문자의 삽입 삭제가 간으하며, 문자열의 일부분을 다른 문자들로 변경할 수 있다.다음은 insert() 함수를 이용하여 a의 인덱스2 위치에 "really"문자열을 삽입하는 코드이다.

string a("I love C++");
a.insert(2, "really"); // a = "I really love C++"

다음은 reaplace()함수를 이용하여 a의 인덱스 2부터 11개의 문자("really love")를 "study"로 대치한다

a.replace(2, 11, "study"); // a = "I study C++"



5 문자열 길이

문자열 길이는 문자열에 포함된 문자 개수를 말하며, length()와 size()함수는 문자열의 길이를 리턴한다.길이와는 달리 string 객체의 내부 메모리 용량을 리턴하는 capacity() 도 있다.용량은 자동으로 조절되므로 개발자가 신경 쓸 필요 없다.

string a("I study C++");
int length = a.length(); // "I study C++" 의 문자개수는 11이다 length = 11
int size = a.size(); // length()와 동일하게 작동 size = 11
int capacity = a.capaity(); // 스트링 a의 현재 용량 capacity = 31 변할 수 있다.


6. 문자열 삭제

erase()는 문자열의 일부분을 삭제하고 clear() 는 완전히 삭제한다.




string a("I love C++");
a.erase(0, 7); // a의 처음부터 7개의 문자 삭제. a = "C++"로 변경
a.clear(); // a = ""


7. 서브스트링

substr() 함수를 사용하면 문자열에서 일부분을 발췌한 문자열(서브스트링)을 얻을 수 있다.




string b = "I love C++";

string c = b.substr(2, 4); // b의 인덱스 2에서 4개의 문자 리턴. c = "love"

string d = b.substr(2); // b의 인덱스 2에서 끝까지 문자열 리턴 d = "love C++"




8. 문자열 검색



문자열 내에 특정 문자열이 존재하는지 검색하는 기능은 많은 응용에서 사용된다.
fInd() 는 문자열에서 특정문자나 문자열을 발견하면 첫 번째 인덱스를 리턴한다.
만약 발견하지 못하면 - 1을 리턴한다

string e = "I love C++";
int index = e.find("love"); // e 에서 "love" 검색. 인덱스 2 리턴
index = e.find("love", index + 1); // e 의 인덱스 3 부터 "love"검색 인덱스 7리턴
index = e.find("C#"); // e에서 "C#"을 발견할 수 없음. -1 리턴
index = e.find('v', 7); // e의 인덱스 7부터 'v'문자 검색 인덱스 9 리턴 


9. 문자열에 있는 각 문자 얻기
at() 함수와[] 연산자는 문자열의 특정 위치에 있는 문자를 리턴한다

string f("I love C++");
char ch1 = f.at(7); // 문자열 f의 인덱스 7에 있는 문자 리턴 ch1 = 'c'
char ch2 = f[7]; // f.at(7)과 동일한 표현


10. 문자열의 숫자변환 stoi()


문자열을 숫자로 변환하는 전역함수 stoi() 함수를 <string>헤더 파일에 삽입하였다

string year = "2014";
int n = stoi(year); // n은 정수 2014를 가짐
					// int n = atoi(year.c_str()); // 비주얼 c++2008 이하



11. 문자다루기

string은 문자열만 다루지 만자를 다루는 기능은 없다.문자를 다루는 함수는 <locale> 헤더파일에 존재한다 다음은 <local>헤더파일에 있는 toupper(), isdigit(), isalpha()함수를 사용하는 예이다.

string a = "hello";
for (int n = 0; i < a.length(); i++)
{
	a[i] = toupper(a[i]); // a가 "HELLO"로 변경

}
cout << a; // "HELLO"출력
if (insdigit9a[0]) cout << "숫자";
else if (isalpha(a.at(0))) cout << "문자"; // a[0]은 문자 'H'