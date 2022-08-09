#include "Player.h"

void Player::UpData()
{
	this->x++;
}

void Player::Draw() const
{
	DrawFormatString(20, 40, 0xffffff, "%d", this->x);
}
