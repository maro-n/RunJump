
#include "Result.h"

Result::Result() {
	// �摜�̏�����
	images_[RESULT_BACK] = loadTexture("TITLE_BACK");
	images_[RESULT_INFO] = loadTexture("RESULT_INFO");
	images_[BACK_TO_TITLE] = loadTexture("BACK_TO_TITLE");
	images_[NUMBER] = loadTexture("NUMBER");
}

void Result::update() {
	// ���N���b�N���G���^�[�L�[�Ń^�C�g����
	if (GetApp.isPushButton(GLFW_MOUSE_BUTTON_LEFT) ||
		GetApp.isPushKey(GLFW_KEY_ENTER)) {
		SceneManager::getInstance().changeScene(createScene<Title>());
	}
}

void Result::draw() {
	// ���ʉ�ʕ\��
	// FIXME:���U���g�̔w�i�����߂���\��
	drawTextureBox(0 - 2048 / 2, 0 - 1024 / 2, 2048, 1024,
		0, 0, 2048, 1024,
		images_[RESULT_BACK],
		Color::white);

	// ���U���g����\��
	drawTextureBox(0 - 2048 / 2, 0 - 1024 / 2, 2048, 1024,
		0, 0, 2048, 1024,
		images_[RESULT_INFO],
		Color::white);

	// �uReturn to Title�v��\��
	drawTextureBox(0 - 400, 0 - 700, 512, 256,
		0, 0, 512, 256,
		images_[BACK_TO_TITLE],
		Color(0, 0, 1),
		0,
		Vec2f(1.5, 1.5),
		Vec2f(0, 0));
}
