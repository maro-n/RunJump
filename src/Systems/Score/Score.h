#pragma once

#include "../../lib/appSingleton.h"
#include "../../lib/font.hpp"

class Score {
public:
	Score();

	static std::string intToString(int);

	static Font font_;

	static unsigned int current_score;
	static unsigned int high_score;
};