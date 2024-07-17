//============================================================
//
//	�u���b�N�w�b�_�[ [block.h]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	��d�C���N���[�h�h�~
//************************************************************
#ifndef _BLOCK_H_
#define _BLOCK_H_

//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "object3D.h"

//************************************************************
//	�N���X��`
//************************************************************
// �u���b�N�N���X
class CBlock : public CObject3D
{
public:
	// ��ޗ�
	enum EType
	{
		TYPE_FIELD = 0,	// �ʏ�n��
		TYPE_WALL,		// �ǔ���
		TYPE_POINT,		// �X�^�[�g/�S�[��
		TYPE_MAX		// ���̗񋓌^�̑���
	};

	// �R���X�g���N�^
	CBlock();

	// �f�X�g���N�^
	~CBlock() override;

	// �I�[�o�[���C�h�֐�
	HRESULT Init(void) override;	// ������
	void Uninit(void) override;		// �I��
	void Update(const float fDeltaTime) override;	// �X�V
	void Draw(CShader *pShader = nullptr) override;	// �`��

	// �ÓI�����o�֐�
	static CBlock *Create	// ����
	( // ����
		const EType type,			// ���
		const D3DXVECTOR3& rPos,	// �ʒu
		const D3DXVECTOR3& rSize	// �傫��
	);

	// �����o�֐�
	void SetType(const EType type);	// ��ސݒ�

private:
	// �����o�ϐ�
	EType m_type;	// ���
};

#endif	// _BLOCK_H_
