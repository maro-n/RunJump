
// Frameworkの全てをインクルード
#include "lib/framework.hpp"
#include "Scene/SceneManager.h"
#include "lib/appSingleton.h"
#include "Scene/SceneFactory.h"

int main() {
	GetApp;

	SceneManager::getInstance();

	// メインループ
	while (GetApp.isOpen() && !SceneManager::getInstance().exit()) {
		// 開始
		GetApp.begin();

		GetApp.bgColor(Color(0.5f, 0.5f, 0.5f));

		// 各シーンの更新及び描画
		SceneManager::getInstance().update();
		SceneManager::getInstance().draw();

		// 終了
		GetApp.end();
	}
}
