//============================================================
//
//	�Q�[����ʏ��� [sceneGame.cpp]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "sceneGame.h"
#include "manager.h"
#include "camera.h"
#include "gameManager.h"
#include "pause.h"

//************************************************************
//	�萔�錾
//************************************************************
namespace
{

}

//************************************************************
//	�ÓI�����o�ϐ��錾
//************************************************************
CGameManager *CSceneGame::m_pGameManager = nullptr;	// �Q�[���}�l�[�W���[
CPause		 *CSceneGame::m_pPause		 = nullptr;	// �|�[�Y

//************************************************************
//	�q�N���X [CSceneGame] �̃����o�֐�
//************************************************************
//============================================================
//	�R���X�g���N�^
//============================================================
CSceneGame::CSceneGame(const EMode mode) : CScene(mode)
{

}

//============================================================
//	�f�X�g���N�^
//============================================================
CSceneGame::~CSceneGame()
{

}

//============================================================
//	����������
//============================================================
HRESULT CSceneGame::Init(void)
{
	// �V�[���̏�����
	if (FAILED(CScene::Init()))
	{ // �������Ɏ��s�����ꍇ

		// ���s��Ԃ�
		assert(false);
		return E_FAIL;
	}

	// �|�[�Y�̐���
	m_pPause = CPause::Create();
	if (m_pPause == nullptr)
	{ // ��g�p���̏ꍇ

		// ���s��Ԃ�
		assert(false);
		return E_FAIL;
	}

	// �Q�[���}�l�[�W���[�̐���
	m_pGameManager = CGameManager::Create();
	if (m_pGameManager == nullptr)
	{ // ��g�p���̏ꍇ

		// ���s��Ԃ�
		assert(false);
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//============================================================
//	�I������
//============================================================
void CSceneGame::Uninit(void)
{
	// �Q�[���}�l�[�W���[�̔j��
	SAFE_REF_RELEASE(m_pGameManager);

	// �|�[�Y�̔j��
	SAFE_REF_RELEASE(m_pPause);

	// �V�[���̏I��
	CScene::Uninit();
}

//============================================================
//	�X�V����
//============================================================
void CSceneGame::Update(const float fDeltaTime)
{
	// �Q�[���}�l�[�W���[�̍X�V
	assert(m_pGameManager != nullptr);
	m_pGameManager->Update(fDeltaTime);

	// �|�[�Y�̍X�V
	assert(m_pPause != nullptr);
	m_pPause->Update(fDeltaTime);

	if (!m_pPause->IsPause())
	{ // �|�[�Y���ł͂Ȃ��ꍇ

		// �V�[���̍X�V
		CScene::Update(fDeltaTime);
	}

#ifdef _DEBUG
	else
	{ // �|�[�Y���̏ꍇ

		CCamera *pCamera = GET_MANAGER->GetCamera();	// �J�������
		if (pCamera->GetState() == CCamera::STATE_CONTROL)
		{ // �J�����������Ԃ̏ꍇ

			// �J�����̍X�V
			pCamera->Update(fDeltaTime);
		}
	}
#endif	// _DEBUG
}

//============================================================
//	�Q�[���}�l�[�W���[�擾����
//============================================================
CGameManager *CSceneGame::GetGameManager(void)
{
	// �C���X�^���X���g�p
	assert(m_pGameManager != nullptr);

	// �Q�[���}�l�[�W���[�̃|�C���^��Ԃ�
	return m_pGameManager;
}

//============================================================
//	�|�[�Y�擾����
//============================================================
CPause *CSceneGame::GetPause(void)
{
	// �C���X�^���X���g�p
	assert(m_pPause != nullptr);

	// �|�[�Y�̃|�C���^��Ԃ�
	return m_pPause;
}
