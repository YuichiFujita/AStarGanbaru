//============================================================
//
//	ゲーム画面処理 [sceneGame.cpp]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	インクルードファイル
//************************************************************
#include "sceneGame.h"
#include "manager.h"
#include "camera.h"
#include "gameManager.h"
#include "pause.h"

//************************************************************
//	定数宣言
//************************************************************
namespace
{

}

//************************************************************
//	静的メンバ変数宣言
//************************************************************
CGameManager *CSceneGame::m_pGameManager = nullptr;	// ゲームマネージャー
CPause		 *CSceneGame::m_pPause		 = nullptr;	// ポーズ

//************************************************************
//	子クラス [CSceneGame] のメンバ関数
//************************************************************
//============================================================
//	コンストラクタ
//============================================================
CSceneGame::CSceneGame(const EMode mode) : CScene(mode)
{

}

//============================================================
//	デストラクタ
//============================================================
CSceneGame::~CSceneGame()
{

}

//============================================================
//	初期化処理
//============================================================
HRESULT CSceneGame::Init(void)
{
	// シーンの初期化
	if (FAILED(CScene::Init()))
	{ // 初期化に失敗した場合

		// 失敗を返す
		assert(false);
		return E_FAIL;
	}

	// ポーズの生成
	m_pPause = CPause::Create();
	if (m_pPause == nullptr)
	{ // 非使用中の場合

		// 失敗を返す
		assert(false);
		return E_FAIL;
	}

	// ゲームマネージャーの生成
	m_pGameManager = CGameManager::Create();
	if (m_pGameManager == nullptr)
	{ // 非使用中の場合

		// 失敗を返す
		assert(false);
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//============================================================
//	終了処理
//============================================================
void CSceneGame::Uninit(void)
{
	// ゲームマネージャーの破棄
	SAFE_REF_RELEASE(m_pGameManager);

	// ポーズの破棄
	SAFE_REF_RELEASE(m_pPause);

	// シーンの終了
	CScene::Uninit();
}

//============================================================
//	更新処理
//============================================================
void CSceneGame::Update(const float fDeltaTime)
{
	// ゲームマネージャーの更新
	assert(m_pGameManager != nullptr);
	m_pGameManager->Update(fDeltaTime);

	// ポーズの更新
	assert(m_pPause != nullptr);
	m_pPause->Update(fDeltaTime);

	if (!m_pPause->IsPause())
	{ // ポーズ中ではない場合

		// シーンの更新
		CScene::Update(fDeltaTime);
	}

#ifdef _DEBUG
	else
	{ // ポーズ中の場合

		CCamera *pCamera = GET_MANAGER->GetCamera();	// カメラ情報
		if (pCamera->GetState() == CCamera::STATE_CONTROL)
		{ // カメラが操作状態の場合

			// カメラの更新
			pCamera->Update(fDeltaTime);
		}
	}
#endif	// _DEBUG
}

//============================================================
//	ゲームマネージャー取得処理
//============================================================
CGameManager *CSceneGame::GetGameManager(void)
{
	// インスタンス未使用
	assert(m_pGameManager != nullptr);

	// ゲームマネージャーのポインタを返す
	return m_pGameManager;
}

//============================================================
//	ポーズ取得処理
//============================================================
CPause *CSceneGame::GetPause(void)
{
	// インスタンス未使用
	assert(m_pPause != nullptr);

	// ポーズのポインタを返す
	return m_pPause;
}
