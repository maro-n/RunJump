#pragma once

#include <iostream>
#include <memory>
#include "../lib/appSingleton.h"
#include "Scene.h"

enum class SceneType {
	TITLE,
	GAMEMAIN,
	RESULT,

	ALLSCENE,
};

	template <class T>
	std::shared_ptr<T> createScene() {
		return std::make_shared<T>();
	}
