//============================================================
//
//	ブロックヘッダー [block.h]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	二重インクルード防止
//************************************************************
#ifndef _BLOCK_H_
#define _BLOCK_H_

//************************************************************
//	インクルードファイル
//************************************************************
#include "object3D.h"

//************************************************************
//	クラス定義
//************************************************************
// ブロッククラス
class CBlock : public CObject3D
{
public:
	// 種類列挙
	enum EType
	{
		TYPE_FIELD = 0,	// 通常地面
		TYPE_WALL,		// 壁判定
		TYPE_POINT,		// スタート/ゴール
		TYPE_MAX		// この列挙型の総数
	};

	// コンストラクタ
	CBlock();

	// デストラクタ
	~CBlock() override;

	// オーバーライド関数
	HRESULT Init(void) override;	// 初期化
	void Uninit(void) override;		// 終了
	void Update(const float fDeltaTime) override;	// 更新
	void Draw(CShader *pShader = nullptr) override;	// 描画

	// 静的メンバ関数
	static CBlock *Create	// 生成
	( // 引数
		const EType type,			// 種類
		const D3DXVECTOR3& rPos,	// 位置
		const D3DXVECTOR3& rSize	// 大きさ
	);

	// メンバ関数
	void SetType(const EType type);	// 種類設定

private:
	// メンバ変数
	EType m_type;	// 種類
};

#endif	// _BLOCK_H_
