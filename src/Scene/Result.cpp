
#include "Result.h"

Result::Result() {
	// 画像の初期化
	images_[RESULT_BACK] = loadTexture("TITLE_BACK");
	images_[RESULT_INFO] = loadTexture("RESULT_INFO");
	images_[BACK_TO_TITLE] = loadTexture("BACK_TO_TITLE");
	images_[NUMBER] = loadTexture("NUMBER");
}

void Result::update() {
	// 左クリックかエンターキーでタイトルへ
	if (GetApp.isPushButton(GLFW_MOUSE_BUTTON_LEFT) ||
		GetApp.isPushKey(GLFW_KEY_ENTER)) {
		SceneManager::getInstance().changeScene(createScene<Title>());
	}
}

void Result::draw() {
	// 結果画面表示
	// FIXME:リザルトの背景を決めたら表示
	drawTextureBox(0 - 2048 / 2, 0 - 1024 / 2, 2048, 1024,
		0, 0, 2048, 1024,
		images_[RESULT_BACK],
		Color::white);

	// リザルト情報を表示
	drawTextureBox(0 - 2048 / 2, 0 - 1024 / 2, 2048, 1024,
		0, 0, 2048, 1024,
		images_[RESULT_INFO],
		Color::white);

	// 「Return to Title」を表示
	drawTextureBox(0 - 400, 0 - 700, 512, 256,
		0, 0, 512, 256,
		images_[BACK_TO_TITLE],
		Color(0, 0, 1),
		0,
		Vec2f(1.5, 1.5),
		Vec2f(0, 0));

	// スコアの表示
	{
		const Vec2f score_size = Vec2f(100, 150);

		const Vec2f now_score_offset = Vec2f(12.5f, -15.0f);
		dispScore(images_[NUMBER],
			now_score_offset, score_size,
			current_score);

		const Vec2f high_score_offset = Vec2f(12.5f, -285.0f);
		dispScore(images_[NUMBER],
			high_score_offset, score_size,
			high_score);
	}
}
