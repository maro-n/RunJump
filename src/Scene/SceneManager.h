
#pragma once

#include <memory>
#include "Scene.h"
#include "Title.h"

// �V�[���J�ڂ��Ǘ�����N���X
class SceneManager {
private:
	SceneManager();
	SceneManager(SceneManager&) = delete;

	std::shared_ptr<Scene> previous_scene;
	std::shared_ptr<Scene> current_scene;

public:
	// �V���O���g��
	static SceneManager& getInstance() {
		static SceneManager scene_manager;
		return scene_manager;
	}

	void changeScene(const std::shared_ptr<Scene>& scene_manager);

	bool exit();
	
	void update();
	void draw();
};
