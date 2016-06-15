
#include "GameMain.h"

GameMain::GameMain() {
	// ‰æ‘œ‚Ì“Ç‚İ‚İ
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
	// ”wŒii‚P–‡–Új
	drawTextureBox(Window::left - player_.run_for_animation_, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
		0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
		images_[BACK_FIRST],
		Color::white);

	// TIPS:”wŒi“ñ–‡–Ú‚Í‘–‚Á‚½‹——£‚É‰‚¶‚ÄØ‚è‘Ö‚¦‚é
	if (player_.run_distance_ / WindowSize::WIDTH < 2) {
	// ”wŒiiƒŒ[ƒ“j
		drawTextureBox(Window::left - player_.run_for_animation_ + WindowSize::WIDTH, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
			0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
			images_[BACK_FIRST],
			Color::white);
	}
	// ”wŒiiƒŒ[ƒ“•“yj
	else if (player_.run_distance_ / WindowSize::WIDTH >= 2 &&
				   player_.run_distance_ / WindowSize::WIDTH < 3) {
		drawTextureBox(Window::left - player_.run_for_animation_ + WindowSize::WIDTH, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
			0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
			images_[BACK_SECOND],
			Color::white);
	}
	// ”wŒii“y‚Ìãj
	else if (player_.run_distance_ / WindowSize::WIDTH >= 3) {
		// ’µ‚ñ‚Å‚©‚ç‚Íí‚É“y‚Å‚ ‚é•K—v‚ª‚ ‚é‚Ì‚Å
		// ˆê–‡–Ú‚àã‘‚«
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

