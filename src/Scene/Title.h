
#pragma once

#include "../lib/appSingleton.h"
#include "../lib/common.h"
#include "Scene.h"
#include "../Resources/ResKey.h"
#include "SceneFactory.h"
#include "SceneManager.h"
#include "GameMain.h"

// タイトルシーン
class Title : public Scene {

private:

	// 演出用変数
	float anima_;
	Color change_color_logo_;
	Color change_color_game_start;

	// 画像一覧
	enum TitleTex {
		BACK,
		LOGO,
		GAME_START,

		TEX_MAX,
	};
	Texture images_[TEX_MAX];

	// 音声一覧
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
