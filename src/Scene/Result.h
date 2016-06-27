
#pragma once

#include "../lib/appSingleton.h"
#include "../lib/common.h"
#include "Scene.h"
#include "../Resources/ResKey.h"
#include "SceneFactory.h"
#include "SceneManager.h"
#include "Title.h"
#include "GameMain.h"
#include "../Systems/Score/Score.h"

class Result : public Scene {
private:
	enum ResultTex {
		RESULT_BACK,
		RESULT_INFO,
		BACK_TO_TITLE,
		NUMBER,

		MAX,
	};
	Texture images_[MAX];

public:
	Result();

	void update() override;
	void draw() override;
};
