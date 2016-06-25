#pragma once
#include <map>
#include <string>
#include "../lib/appEnv.hpp"

// ���\�[�X�ꗗ�ɉ摜�p�X��R�Â�
const std::map<std::string, std::string> tex_path = {
	// �^�C�g��
	{ "TITLE_BACK", "res/title_back.png" },
	{ "TITLE_LOGO", "res/title.png" },
	{ "GAME_START", "res/game_start.png" },
		
	// �Q�[��
	{ "GAME_BACK_FIRST", "res/field.png" },
	{ "GAME_BACK_SECOND", "res/field2.png" },
	{ "GAME_BACK_THIRD", "res/field3.png" },
	{ "NUMBER", "res/number.png" },

	// �v���C���[�֘A
	{ "RUN", "res/run.png" },
	{ "JUMP", "res/jump.png" },
	{ "GOOD_JUMP", "res/Good.png" },
	{ "EXCELLENT_JUMP", "res/Excellent.png" },
	{ "SMOKE", "res/smoke.png" },
		
	// ���U���g
	{ "RESULT_INFO", "res/result.png" },
	{ "BACK_TO_TITLE", "res/Return to Title.png" },
};	
		
// ���\�[�X�ꗗ�ɉ����t�@�C����R�Â�
static const std::map<std::string, std::string> med_path = {
	// �^�C�g��
	{ "TITLE_BGM", "res/title_bgm.wav" },
	{ "TITLE_CLICK", "res/se.wav" },

	// �Q�[���{��
	{ "GAMEMAIN_BGM", "res/game_bgm.wav" },
	
	// �v���C���[
	{ "PLAYER_RUNNING", "res/running.wav" },
	{ "PLAYER_JUMP", "res/jump.wav" },
	{ "PLAYER_NICE_JUMP", "res/nice_jump.wav" },
	{ "PLAYER_JUMP_KEEP", "res/smoke_sound.wav" },

	// ���U���g
	{ "" , "" },
	{ "" , "" },
	{ "" , "" },
};

// �摜�ǂݍ���
static Texture loadTexture(std::string key) {
	return Texture(tex_path.find(key)->second);
}

// �����ǂݍ���
static Media loadMedia(std::string key) {
	return Media(med_path.find(key)->second);
}