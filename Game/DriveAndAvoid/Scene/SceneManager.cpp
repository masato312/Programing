#include"SceneManager.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"
#include"TitleScene.h"
#include"GemeMainScene.h"
#include"ResultScene.h"
#include"HelpScene.h"
#include"RankingDispScene.h"
#include"RankingInputScene.h"

SceneManager::SceneManager() :current_scene(nullptr)
{

}

SceneManager::~SceneManager()
{

}

//�V�[���}�l�W���[�@�\�F����������
void SceneManager::Initialize()
{
	//�E�B���h�E�̃^�C�g����ݒ�
	SetMainWindowText("Drave&Avoid");

	//�E�B���h�E���[�h�ŋN��
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK)
	{
		throw("�E�B���h�E���[�h�ŋN���ł��܂���ł���\n");
	}

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		throw("Dx���C�u�������������ł��܂���ł���\n");
	}

	//�`��w�菈��
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)
	{
		throw("�`���̎w�肪�ł��܂���ł���\n");
	}

	//�^�C�g���V�[������n�܂�
	ChangeScene(eScenetype::E_TITLE);
}

//�V�[���}�l�[�W���[�@�\:�X�V����
void SceneManager::Update()
{
	//�t���[���J�n���ԁi�}�C�N���a�j���擾
	LONGLONG start_time = GetNowHiPerformanceCount();

	//���C�����[�v
	while (ProcessMessage() != -1)
	{

		//1�t���[��������̎��Ԃɓ��B������A�X�V�y�ѕ`�揈�����s��
		if ((now_time - start_time) >= DELTA_SECOND)
		{
			//�t���[���J�n���Ԃ��X�V����
			start_time = now_time;

			//���͋@�\�F�X�V����
			InputControl::Updata();

			//�X�V�����i�߂�l�͎��̃V�[�����j
			eScenetype next = current_scene->Update();

			//�`�揈��
			Draw();

			//�G���h���I������Ă�����A�Q�[�����I������
			if (next == eScenetype::E_END)
			{
				break;
			}
			//���݂̃V�[���Ǝ��̃V�[��������Ă�����A�؂�ւ��������s��
			if (next != current_scene->GetNowScene())
			{
				ChangeScene(next);
			}
		}
		//ESCAPE���[�������ꂽ��A�Q�[�����I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
}

//�V�[���}�l�[�W���[�@�\:�I��������
void SceneManager::Finalize()
{
	//�V�[�����̍폜
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
		current_scene = nullptr;
	}
	//Dx���C�u�����̎g�p���I������
	DxLib_End();
}

//�V�[���}�l�W���[�@�\�`�揈��
void SceneManager::Draw()const
{
	//��ʂ̏�����
	ClearDrawScreen();

	//�V�[���̕`��
	current_scene->Draw();

	//����ʂ̓��e��\��ʂɔ��f
	ScreenFlip();
}

//�V�[���؂�ւ�����
void SceneManager::ChangeScene(eScenetype scene_type)
{
	//�V�[���𐶐�����(Scenebase���p������Ă��邩�H)
	SceneBase* newScene = dynamic_cast<SceneBase*>(CreateScene(scene_type));

	//�G���[�`�F�b�N
	if (new_Scene == nullptr)
	{
		throw("�V�[���������ł��܂���ł����B\n");
	}

	//�O��V�[���̏I�����������s��
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	//�V�������������V�[���̏��������s��
	new_scene->Initialize();

	//���݂̃V�[���̍X�V
	current_scene = new_scene;
}

//�V�[����������
SceneBase* SceneManager::CreateScene(eScenetype scene_type)
{
	//�����i�V�[���^�C�v�j�ɂ���āA��������V�[�������肷��
	switch(scene_type)
	{
	case eScenetype::E_TITLE:
		return new TitleScene;
	case eScenetype::E_MAIN:
		return new GameMainScene;
	case eScenetype::E_RESULT:
		return new ResultScene;
	case eScenetype::E_HELP:
		return new HelpScene;
	case eScenetype::E_RANKING_DISP:
		return new RankingDispScene;
	case eScenetype::E_RANKING_INPUT:
		return new RankingInputScene;
	default:
		return nullptr;
	}
}