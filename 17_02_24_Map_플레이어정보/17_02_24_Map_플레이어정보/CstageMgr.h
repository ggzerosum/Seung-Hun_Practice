#pragma once

#include "Include.h"

class CStage;
class CStageMgr
{
private :
	static CStageMgr* m_pInst;
public :
	static CStageMgr* GetInst()
	{
		if (m_pInst == nullptr)
		{
			m_pInst = new CStageMgr;
		}

		return m_pInst;
	}

private :
	CStage* m_pSceneMgr;
public :
	CStage* SetScene(SCENE_ID _sceneids);

	void Progress();
	void Render();
	void Release();

private :
	CStageMgr();
public:
	~CStageMgr();
};