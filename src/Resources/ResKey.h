#pragma once
#include <map>
#include <string>
#include "../lib/appEnv.hpp"

// ���\�[�X�ꗗ
enum ResKey {
	// �^�C�g��
	// �摜
	TITLE_BACK,
	TITLE_LOGO,
	GAME_START,
	
	// ���y
	TITLE_BGM,
	TITLE_CLICK,

	// �Q�[��
	GAME_BACK_FIRST,
	GAME_BACK_SECOND,
	GAME_BACK_THIRD,
	RUN,
	JUMP,
	GOOD_JUMP,
	EXCELLENT_JUMP,
	SMOKE,
	NUMBER,

	// ���U���g
	RESULT_INFO,
	BACK_TO_TITLE,

	MAX,
};

// ���\�[�X�ꗗ�ɉ摜�p�X��R�Â�
const std::map<int, std::string> tex_path = {
	// �^�C�g��
	{ TITLE_BACK, "res/title_back.png" },
	{ TITLE_LOGO, "res/title.png" },
	{ GAME_START, "res/game_start.png" },

	// �Q�[��
	{ GAME_BACK_FIRST, "res/field.png" },
	{ GAME_BACK_SECOND, "res/field2.png" },
	{ GAME_BACK_THIRD, "res/field3.png" },
	{ RUN, "res/run.png" },
	{ JUMP, "res/jump.png" },
	{ GOOD_JUMP, "res/Good.png" },
	{ EXCELLENT_JUMP, "res/Excellent.png" },
	{ SMOKE, "res/smoke.png" },
	{ NUMBER, "res/number.png" },

	// ���U���g
	{ RESULT_INFO, "res/result.png" },
	{ BACK_TO_TITLE, "res/Return to Title.png" },
};

// ���\�[�X�ꗗ�ɉ����t�@�C����R�Â�
static const std::map<int, std::string> med_path = {
	// �^�C�g��
	{ TITLE_BGM, "res/title_bgm.wav" },
	{ TITLE_CLICK, "res/se.wav" },
};

// �摜�ǂݍ���
static Texture loadTexture(int key) {
	return Texture(tex_path.find(key)->second);
}

// �����ǂݍ���
static Media loadMedia(int key) {
	return Media(med_path.find(key)->second);
}