#pragma once

#include <GL/glew.h>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void initialize(float x, float y, float width, float height);
	void render();

private:
	float mX, mY, mWidth, mHeight;
	GLuint mVboID;
};

