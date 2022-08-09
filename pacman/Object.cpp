#include "Object.h"

void Object::UpData()
{
}

void Object::Draw() const
{
	DrawFormatString(20, 20, 0xffffff, "%d", this->x);
}
