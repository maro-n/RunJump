
#include "GameMain.h"

GameMain::GameMain() {
	// 画像の読み込み
	images_[BACK_FIRST] = loadTexture("GAME_BACK_FIRST");
	images_[BACK_SECOND] = loadTexture("GAME_BACK_SECOND");
	images_[BACK_THIRD] = loadTexture("GAME_BACK_THIRD");
	images_[NUMBER] = loadTexture("NUMBER");

	// 音声の初期化
	sounds_[BGM] = loadMedia("GAMEMAIN_BGM");
}

void GameMain::update() {
	// BGMが鳴ってなければループ再生
	if (!sounds_[BGM].isPlaying()) {
		sounds_[BGM].gain(0.2f);
		sounds_[BGM].play();
		sounds_[BGM].looping(true);
	}

	if (isExit()) {
		sounds_[BGM].stop();

		SceneManager::getInstance().changeScene(createScene<Result>());
		return;
	}

	Score::current_score = player_.run_distance_ / player_.velocity_.x();
	assert(Score::current_score != 0);

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
	// スコアの表示
	{
		const Vec2f offset = Vec2f(Window::right - 350, Window::down + 150);
		const Vec2f score_size = Vec2f(100, 100);
		Score::dispScore(images_[NUMBER],
			offset,
			score_size,
			Score::current_score);
	}

	player_.draw();
}

bool GameMain::isExit() {
	if (player_.exit_) {
		return true;
	}

	return false;
}

