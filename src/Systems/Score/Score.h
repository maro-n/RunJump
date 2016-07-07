#pragma once

#include "../../lib/appSingleton.h"

class Score {
private:
	Score() = default;
	Score(Score&) = delete;

public:
	static unsigned int current_score;
	static unsigned int high_score;

	static void dispScore(const Texture&, const Vec2f&,
		const Vec2f&, const unsigned int);
};