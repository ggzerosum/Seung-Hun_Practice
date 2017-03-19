#include "Stage_MakeAccount.h"

#include "ObjFactory.h"
#include "Account.h"
#include "CstageMgr.h"

CStage_MakeAccount::CStage_MakeAccount()
	: m_pNewAccount(nullptr)
{
}


CStage_MakeAccount::~CStage_MakeAccount()
{
	if (m_pNewAccount != nullptr)
	{
		delete m_pNewAccount;
		m_pNewAccount = nullptr;
	}
}

void CStage_MakeAccount::Initialize()
{
	m_pNewAccount = CObjFactory<CAccount>::CreateObj();
}
void CStage_MakeAccount::Progress()
{
	m_pNewAccount->Progress();
}
void CStage_MakeAccount::Render()
{
	if (!(((CAccount*)m_pNewAccount)->GetDone_Bool()))
	{
		((CAccount*)m_pNewAccount)->SetAccount_pointer(m_pNewAccount);
	}

	m_pNewAccount->Render();

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		CStageMgr::GetInst()->SetScene(SCENE_IDS_MENU);
	}
}
void CStage_MakeAccount::Release()
{

}