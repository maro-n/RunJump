
#include "Player.h"
#include <string>

// �v���C���[�̏�����
Player::Player() :
	pos_(Vec2f(-680, -380)),
	size_(Vec2f(150, 225)),
	cut_pos_(Vec2f::Zero()),
	cut_size_(Vec2f(100, 150)),
	animation_count_(0),
	run_value_(0),
	velocity_(25, 0),
	jump_rate_(10),
	jump_count_(0),
	acceleration_(0),
	run_distance_(0),
	run_for_animation_(0),
	exit_(false)
{
	// �摜�̏�����
	images_[RUN] = loadTexture("PLAYER_RUN");
	images_[GOOD_JUMP] = loadTexture("PLAYER_GOOD_JUMP");
	images_[EXCELLENT_JUMP] = loadTexture("PLAYER_EXCELLENT_JUMP");
	images_[SMOKE] = loadTexture("PLAYER_SMOKE");

	// �����̏�����
	sounds_[RUNNING] = loadMedia("PLAYER_RUNNING");
	sounds_[JUMP] = loadMedia("PLAYER_JUMP");
	sounds_[NICE_JUMP] = loadMedia("PLAYER_NICE_JUMP");
	sounds_[JUMP_KEEP] = loadMedia("PLAYER_JUMP_KEEP");
}

// ����A�j���[�V�����Ə���
void Player::run() {
	animation_count_++;
	run_distance_ += velocity_.x();
	if (run_for_animation_ <= 2000) {
		run_for_animation_ += velocity_.x();
	}
	else {
		run_for_animation_ = 0;
	}
}

// ���ׂ��Ԃ��`�F�b�N
bool Player::jumpable() {
	const int jumpable_area = 250;

	if (((WindowSize::WIDTH * 3) - jumpable_area) < run_distance_) {
		return true;
	}

	return false;
}

void Player::foul() {
	if (WindowSize::WIDTH * 3 + 100 < run_distance_) {
		exit_ = true;
	}
}

// ���ԁi�d�͂Ȃǂ̏����j
void Player::jump() {
	const float gravity = -0.2f;

	velocity_.y() = velocity_.y() + acceleration_;
	pos_.y() = pos_.y() + (acceleration_ * 0.5) + velocity_.y();

	if (jumpable()) {
		
		if (GetApp.isPushKey(GLFW_KEY_SPACE)) {
			if (jump_count_ < 3) {
				// �W�����v�̕]��
				//if () { jump_rate = }

				sounds_[JUMP].play();
				acceleration_ = jump_rate_ + gravity;
				jump_count_++;
			}
		}
		else {
			acceleration_ = gravity;
		}
	}
}

// �V��ɃL�������G��Ă��邩�ǂ���
void Player::onCeiling() {
	const int ceiling_height = (WindowSize::HEIGHT * 0.5) - size_.y();

	if (pos_.y() >= ceiling_height) {
		pos_.y() = ceiling_height;
		velocity_.y() = 0;
	}
}

// �n�ʂɃL�������G��Ă��邩�ǂ���
void Player::onGround() {
	const int ground_height = -380;

	if (pos_.y() <= ground_height) {
		pos_.y() = ground_height;
		velocity_.y() = 0;

		if (jump_count_ >= 3) {
			exit_ = true;
		}
	}
}

// �`��
void Player::draw() {
	drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
		cut_pos_.x(), cut_pos_.y(), cut_size_.x(), cut_size_.y(),
		images_[RUN],
		Color(1, 1, 1));
}

// �X�V
void Player::update() {
	onCeiling();
	onGround();

	run();
	jump();

	foul();

	const int animation_minute = 3;
	const int animation_num = 7;

	// �؂蔲���ʒu�𓮓I�ɕύX���ăA�j���[�V����������
	run_value_ = (animation_count_ / animation_minute) % animation_num;
	cut_pos_.x() = (cut_size_.x() * run_value_);
}
