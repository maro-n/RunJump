
#include "Title.h"

Title::Title() {
	// 画像の初期化
	images_[BACK] = loadTexture(ResKey::TITLE_BACK);
	images_[LOGO] = loadTexture(ResKey::TITLE_LOGO);
	images_[GAME_START] = loadTexture(ResKey::GAME_START);

	// 音声の初期化
	sounds_[BGM] = loadMedia(ResKey::TITLE_BGM);
	sounds_[CLICK] = loadMedia(ResKey::TITLE_CLICK);

	change_color_game_start = Color::black;

	anima_ = 0;
}

void Title::update() {
	// BGMが鳴ってなければループ再生
	if (!sounds_[BGM].isPlaying()) {
		sounds_[BGM].play();
		sounds_[BGM].looping(true);
	}

	// 左クリックかエンターでシーンを抜ける
	if (GetApp.isPushButton(GLFW_MOUSE_BUTTON_LEFT) ||
			GetApp.isPushKey(GLFW_KEY_ENTER)) {
		sounds_[BGM].stop();
		sounds_[CLICK].play();
		SceneManager::getInstance().changeScene(createScene<GameMain>());
	}
	
	// 演出用変数の初期化
	anima_ += 0.05f;
	change_color_logo_.r() = std::abs(std::sin(anima_));
	change_color_logo_.g() = 0.0f;
	change_color_logo_.b() = std::abs(std::cos(anima_));

	change_color_game_start.a() = std::abs(std::sin(anima_));
}

void Title::draw() {

	// タイトル画像
	drawTextureBox(Window::left, Window::down, WindowSize::WIDTH, WindowSize::HEIGHT,
		0, 0, WindowSize::WIDTH, WindowSize::HEIGHT,
		images_[BACK],
		Color::white);

	// タイトルロゴ
	drawTextureBox(0 - 1024 / 2, 512 / 2, 1130, 160,
		0, 512, 565, 80,
		images_[LOGO],
		change_color_logo_);

	// GAMESTART描画
	drawTextureBox(0 - 360, 0 - 480, 922, 461,
		0, 0, 512, 256,
		images_[GAME_START],
		change_color_game_start);
}
