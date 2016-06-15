
#pragma once

#include "../lib/appSingleton.h"
#include "../lib/common.h"
#include "Scene.h"
#include "../Resources/ResKey.h"
#include "SceneFactory.h"
#include "SceneManager.h"
#include "Title.h"
#include "Result.h"
#include "../Player/Player.h"

class GameMain : public Scene {
private:
	Player player_;

	enum GameMainTex {
		BACK_FIRST,
		BACK_SECOND,
		BACK_THIRD,
		RUN,
		JUMP,
		GOOD_JUMP,
		EXCELLENT_JUMP,
		SMOKE,
		NUMBER,

		MAX,
	};
	Texture images_[MAX];

	bool isExit();

public:
	GameMain();

	void update() override;
	void draw() override;
};
