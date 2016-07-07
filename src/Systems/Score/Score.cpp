
#include "Score.h"

unsigned int Score::current_score;
unsigned int Score::high_score;

void Score::dispScore(const Texture& texture_,
	const Vec2f& offset_, const Vec2f& size_,
	const unsigned int score_) {
	// 100‚ÌˆÊ
	if (score_ >= 100) {
		int hundred_distance = score_ / 100;
		drawTextureBox(offset_.x(), offset_.y(), size_.x(), size_.y(),
			50 * hundred_distance, 0, 50, 70,
			texture_,
			Color::white);
	}

	// 10‚ÌˆÊ
	if (score_ >= 10) {
		int ten_distance = score_ % 100 / 10;
		drawTextureBox(offset_.x() + 100, offset_.y(), size_.x(), size_.y(),
			50 * ten_distance, 0, 50, 70,
			texture_,
			Color::white);
	}

	// 1‚ÌˆÊ
	if (score_ >= 0) {
		int one_distance = score_ % 10;
		drawTextureBox(offset_.x() + 200, offset_.y(), size_.x(), size_.y(),
			50 * one_distance, 0, 50, 70,
			texture_,
			Color::white);
	}
}