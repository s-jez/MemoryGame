#include "Player.h"

namespace MemoryGame 
{
	Player::Player()
	{
		step = 0;
		playerName = "";
	}
	std::string Player::getPlayerName()
	{
		return playerName;
	}
	void Player::setPlayerName(std::string pName)
	{
		this->playerName = pName;
	}
	int Player::getPlayerStep()
	{
		return step;
	}
	void Player::setPlayerStep(int step)
	{
		this->step = step;
	}
}
