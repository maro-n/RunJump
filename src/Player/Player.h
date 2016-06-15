
#pragma once

#include "../lib/appSingleton.h"
#include "../Resources/ResKey.h"
#include <vector>

// プレイヤーの管理クラス
class Player {
private:

	enum PlayerState {
		Running,
		Jumping,
	};

	Texture image_;

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
