#pragma once
#include <map>
#include <string>
#include "../lib/appEnv.hpp"

// リソース一覧
enum ResKey {
	// タイトル
	// 画像
	TITLE_BACK,
	TITLE_LOGO,
	GAME_START,
	
	// 音楽
	TITLE_BGM,
	TITLE_CLICK,

	// ゲーム
	GAME_BACK_FIRST,
	GAME_BACK_SECOND,
	GAME_BACK_THIRD,
	RUN,
	JUMP,
	GOOD_JUMP,
	EXCELLENT_JUMP,
	SMOKE,
	NUMBER,

	// リザルト
	RESULT_INFO,
	BACK_TO_TITLE,

	MAX,
};

// リソース一覧に画像パスを紐づけ
const std::map<int, std::string> tex_path = {
	// タイトル
	{ TITLE_BACK, "res/title_back.png" },
	{ TITLE_LOGO, "res/title.png" },
	{ GAME_START, "res/game_start.png" },

	// ゲーム
	{ GAME_BACK_FIRST, "res/field.png" },
	{ GAME_BACK_SECOND, "res/field2.png" },
	{ GAME_BACK_THIRD, "res/field3.png" },
	{ RUN, "res/run.png" },
	{ JUMP, "res/jump.png" },
	{ GOOD_JUMP, "res/Good.png" },
	{ EXCELLENT_JUMP, "res/Excellent.png" },
	{ SMOKE, "res/smoke.png" },
	{ NUMBER, "res/number.png" },

	// リザルト
	{ RESULT_INFO, "res/result.png" },
	{ BACK_TO_TITLE, "res/Return to Title.png" },
};

// リソース一覧に音声ファイルを紐づけ
static const std::map<int, std::string> med_path = {
	// タイトル
	{ TITLE_BGM, "res/title_bgm.wav" },
	{ TITLE_CLICK, "res/se.wav" },
};

// 画像読み込み
static Texture loadTexture(int key) {
	return Texture(tex_path.find(key)->second);
}

// 音声読み込み
static Media loadMedia(int key) {
	return Media(med_path.find(key)->second);
}