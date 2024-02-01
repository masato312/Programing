#pragma once

//�V�[�����
enum eScenetype
{
	E_TITLE,
	E_MAIN,
	E_HELP,
	E_RANKING_DISP,
	E_RANKING_INPUT,
	E_RESULT,
	E_END
};

//���V�[���N���X
class SceneBase
{
public:
	SceneBase() {}

	//����������
	virtual void Initialize(){}
	//�X�V����
	virtual eScenetype Update()
	{
		return GetNowScene();
	}
	//�`�揈��
	virtual void Draw() const {}
	//�I��������
	virtual void Finalize() {}
	
	//���݂̃V�[�������擾
	virtual eScenetype GetNowScene() const = 0;
};