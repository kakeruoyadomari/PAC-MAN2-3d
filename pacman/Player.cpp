#include "Player.h"

void Player::UpData()
{
	this->x++;
}

void Player::Draw() const
{
	DrawFormatString(20, 20, 0xffffff, "%d", this->x);
}
