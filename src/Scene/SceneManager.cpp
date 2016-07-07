
#include "SceneManager.h"

SceneManager::SceneManager() : animation_(0.0f) {
	// �J�n���̓^�C�g������
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
//
//// �t�F�[�h�A�E�g
//bool SceneManager::fadeOut() {
//	if (animation_ < 1.0f) { animation_ += 0.05f; }
//	return animation_ < 1.0f;
//}
//
//// �t�F�[�h�C��
//bool SceneManager::fadeIn() {
//	if (animation_ > 0) { animation_ -= 0.05f; }
//	return animation_ > 0;
//}
//

void SceneManager::update() {
	current_scene->update();
}

void SceneManager::draw() {
	current_scene->draw();
}
