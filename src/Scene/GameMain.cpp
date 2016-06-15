
#include "GameMain.h"

GameMain::GameMain() {
	// 画像の読み込み
	images_[BACK_FIRST] = loadTexture(ResKey::GAME_BACK_FIRST);
	images_[BACK_SECOND] = loadTexture(ResKey::GAME_BACK_SECOND);
	images_[BACK_THIRD] = loadTexture(ResKey::GAME_BACK_THIRD);
	images_[RUN] = loadTexture(ResKey::RUN);
	images_[JUMP] = loadTexture(ResKey::JUMP);
	images_[GOOD_JUMP] = loadTexture(ResKey::GOOD_JUMP);
	images_[EXCELLENT_JUMP] = loadTexture(ResKey::EXCELLENT_JUMP);
	images_[SMOKE] = loadTexture(ResKey::SMOKE);
	images_[NUMBER] = loadTexture(ResKey::NUMBER);
}

void GameMain::update() {
	if (isExit()) {
		SceneManager::getInstance().changeScene(createScene<Result>());
	}

	player_.update();
}

void GameMain::draw() {
	// 背景（１枚目）
	drawTextureBox(Window::left - player_.run_for_animation_, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
		0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
		images_[BACK_FIRST],
		Color::white);

	// TIPS:背景二枚目は走った距離に応じて切り替える
	if (player_.run_distance_ / WindowSize::WIDTH < 2) {
	// 背景（レーン）
		drawTextureBox(Window::left - player_.run_for_animation_ + WindowSize::WIDTH, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
			0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
			images_[BACK_FIRST],
			Color::white);
	}
	// 背景（レーン＆土）
	else if (player_.run_distance_ / WindowSize::WIDTH >= 2 &&
				   player_.run_distance_ / WindowSize::WIDTH < 3) {
		drawTextureBox(Window::left - player_.run_for_animation_ + WindowSize::WIDTH, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
			0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
			images_[BACK_SECOND],
			Color::white);
	}
	// 背景（土の上）
	else if (player_.run_distance_ / WindowSize::WIDTH >= 3) {
		// 跳んでからは常に土である必要があるので
		// 一枚目も上書き
		drawTextureBox(Window::left - player_.run_for_animation_, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
			0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
			images_[BACK_THIRD],
			Color::white);

		drawTextureBox(Window::left - player_.run_for_animation_ + WindowSize::WIDTH, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
			0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
			images_[BACK_THIRD],
			Color::white);
	}

	player_.draw();
}

bool GameMain::isExit() {
	if (player_.exit_) {
		return true;
	}

	return false;
}

