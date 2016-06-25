
#pragma once

#include "../lib/appSingleton.h"
#include "../Resources/ResKey.h"
#include <vector>

// プレイヤーの管理クラス
class Player {
private:

	enum PlayerTex {
		RUN,
		JUMP,
		GOOD_JUMP,
		EXCELLENT_JUMP,
		SMOKE,

		TEX_MAX,
	};
	Texture images_[TEX_MAX];

	enum PlayerMed {
		RUNNING,
		JUMP,
		NICE_JUMP,
		JUMP_KEEP,

		MEDIA_MAX
	};
	Media sounds_[MEDIA_MAX];

  Vec2f pos_;
  const Vec2f size_;
  Vec2f cut_pos_;
  const Vec2f cut_size_;

	int animation_count_;
	
	void run();
	int run_value_;
	Vec2f velocity_;

	int jump_rate_;
	int jump_count_;
	float acceleration_;
	void jump();
	bool jumpable();

	void onCeiling();
	void onGround();

public:
  Player();

	int run_distance_;
	int run_for_animation_;

	bool exit_;

  // getterとsetter
  const Vec2f& getPos() const {
    return pos_;
  }
  const Vec2f& getSize() const {
    return size_;
  }
  Vec2f& getCutPos() {
    return cut_pos_;
  }
  void setCutPos(const Vec2f& cut_pos) {
    cut_pos_ = cut_pos;
  }
  const Vec2f& getCutSize() const {
    return cut_size_;
  }

  void draw();
  void update();
};
