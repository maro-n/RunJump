
#include "SceneManager.h"

SceneManager::SceneManager() : animation_(0.f) {
	// 開始時はタイトルから
	current_scene = std::make_shared<Title>();
	previous_scene = nullptr;
}

void SceneManager::changeScene(const std::shared_ptr<Scene>& scene) {
	previous_scene = current_scene;
	current_scene = scene;
}

bool SceneManager::exit() {
	if (GetApp.isPushKey(GLFW_KEY_ESCAPE)) {
		return true;
	}
	return false;
}

void SceneManager::update() {
	current_scene->update();
}

void SceneManager::draw() {
	current_scene->draw();
}
