#include "Player.h"

void Player::UpDate()
{
	this->x++;
}

void Player::Animaition()
{
}

void Player::Draw() const
{
	DrawFormatString(20, 40, 0xffffff, "%d", this->x);
}
