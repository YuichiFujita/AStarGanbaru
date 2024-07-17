//============================================================
//
//	タイトル画面ヘッダー [sceneTitle.h]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	二重インクルード防止
//************************************************************
#ifndef _SCENE_TITLE_H_
#define _SCENE_TITLE_H_

//************************************************************
//	インクルードファイル
//************************************************************
#include "scene.h"

//************************************************************
//	前方宣言
//************************************************************
class CTitleManager;	// タイトルマネージャークラス

//************************************************************
//	クラス定義
//************************************************************
// タイトル画面クラス
class CSceneTitle : public CScene
{
public:
	// コンストラクタ
	explicit CSceneTitle(const EMode mode);

	// デストラクタ
	~CSceneTitle() override;

	// オーバーライド関数
	HRESULT Init(void) override;	// 初期化
	void Uninit(void) override;		// 終了
	void Update(const float fDeltaTime) override;	// 更新

	// 静的メンバ関数
	static CTitleManager *GetTitleManager(void);	// タイトルマネージャー取得

private:
	// 静的メンバ変数
	static CTitleManager *m_pTitleManager;	// タイトルマネージャー
};

#endif	// _SCENE_TITLE_H_
