#include "Player.h"

namespace MemoryGame 
{
	Player::Player()
	{
		playerTime = 0;
		playerName = "";
	}
	std::string Player::getPlayerTime()
	{
		int minutes = playerTime / 60;
		int seconds = playerTime % 60;
		return std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
	}
	void Player::setPlayerTime(int time)
	{
		this->playerTime = time;
	}
	void Player::incrementTime()
	{
		playerTime++;
	}
	std::string Player::getPlayerName()
	{
		return playerName;
	}
	void Player::setPlayerName(std::string pName)
	{
		this->playerName = pName;
	}
}
