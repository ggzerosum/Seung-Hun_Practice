#include "CstageMgr.h"

#include "Stage_Menu.h"
#include "Stage_MakeAccount.h"
#include "Stage_LoginAccount.h"

CStageMgr* CStageMgr::m_pInst = nullptr;

CStageMgr::CStageMgr()
{
	m_pSceneMgr = nullptr;
}


CStageMgr::~CStageMgr()
{
}

CStage* CStageMgr::SetScene(SCENE_ID _sceneids)
{
	if (m_pSceneMgr != nullptr)
	{
		delete m_pSceneMgr;
		m_pSceneMgr = nullptr;
	}


	switch (_sceneids)
	{
	case SCENE_IDS_MENU :
		m_pSceneMgr = new CStage_Menu;
		break;

	case SCENE_IDS_MakeAccount :
		m_pSceneMgr = new CStage_MakeAccount;
		break;

	case SCENE_IDS_LoginAccount :
		m_pSceneMgr = new CStage_LoginAccount;
		break;
	}

	m_pSceneMgr->Initialize();

	return m_pSceneMgr;
}

void CStageMgr::Progress()
{
	if (m_pSceneMgr != nullptr)
		m_pSceneMgr->Progress();
}

void CStageMgr::Render()
{
	if (m_pSceneMgr != nullptr)
		m_pSceneMgr->Render();
}

void CStageMgr::Release()
{
	if (m_pSceneMgr != nullptr)
		m_pSceneMgr->Release();
}