#pragma once

#define WINSIZE_X 800
#define WINSIZE_Y 600

#define FRAME_TIME 10
const float FRAME = 10.0; //1 / 1000 ÃÊ;
#define BULLET_DELAYTIME 100 //1 / 1000 ÃÊ;

#define MAX 10


extern HWND g_hWnd;

///Key Bit
#define KEY_UP			0x1
#define KEY_DOWN		0x2
#define KEY_LEFT		0x4
#define KEY_RIGHT		0x8
#define KEY_SPACE		0x10

///singleton
#define DECLARE_SINGLETON(type)\
	static type* GetInst()\
{\
	static type* pInst = new type;\
\
	if (pInst == nullptr)\
	{\
		pInst = new type;\
	}\
	return pInst;\
}\
	static void DestroyInst()\
{\
	type* pInst = GetInst();\
	if (pInst != nullptr)\
{\
	delete pInst;\
	pInst = nullptr;\
}\
}

#define GET_SINGLETON(type) (type::GetInst())
#define DESTROY_SINGLETON(type) ((type::GetInst())->DestroyInst())