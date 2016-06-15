
#pragma once

#include "../lib/appSingleton.h"
#include "../lib/common.h"
#include "Scene.h"
#include "../Resources/ResKey.h"
#include "SceneFactory.h"
#include "SceneManager.h"
#include "GameMain.h"

// �^�C�g���V�[��
class Title : public Scene {

private:

	// ���o�p�ϐ�
	float anima_;
	Color change_color_logo_;
	Color change_color_game_start;

	// �摜�ꗗ
	enum TitleTex {
		BACK,
		LOGO,
		GAME_START,

		TEX_MAX,
	};
	Texture images_[TEX_MAX];

	// �����ꗗ
	enum TitleMed {
		BGM,
		CLICK,

		MEDIA_MAX,
	};
	Media sounds_[MEDIA_MAX];

public:
	Title();

	void update() override;
	void draw() override;
};
