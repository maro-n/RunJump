#pragma once

#include "appEnv.hpp"

#define GetApp AppSingleton::getInstance()

// �E�B���h�E�̃T�C�Y
enum WindowSize {
	WIDTH  = 2048,
	HEIGHT = 1024,
};

// AppEnv���V���O���g���ɂ���N���X
class AppSingleton {
private:
	AppSingleton() = default;
	AppSingleton(AppSingleton&) = delete;

public:
	// �C���X�^���X���擾
	static AppEnv& getInstance() {
		static AppEnv app(WindowSize::WIDTH, WindowSize::HEIGHT, false, true);
		return app;
	}
};