#pragma once

#include "appEnv.hpp"

#define GetApp AppSingleton::getInstance()

// ウィンドウのサイズ
enum WindowSize {
	WIDTH  = 2048,
	HEIGHT = 1024,
};

// AppEnvをシングルトンにするクラス
class AppSingleton {
private:
	AppSingleton() = default;
	AppSingleton(AppSingleton&) = delete;

public:
	// インスタンスを取得
	static AppEnv& getInstance() {
		static AppEnv app(WindowSize::WIDTH, WindowSize::HEIGHT, false, true);
		return app;
	}
};