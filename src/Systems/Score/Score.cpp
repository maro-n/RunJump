
#include "Score.h"

unsigned int Score::current_score;
unsigned int Score::high_score;

Font Score::font_("res/digital.ttf");

Score::Score() {}

std::string Score::intToString(int num) {
	std::stringstream ss;
	ss << num;
	return ss.str();
}