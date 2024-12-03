#include "Player.h"

namespace MemoryGame 
{
	Player::Player()
	{
		playerTime = 0;
		playerName = "";
	}
	int Player::getPlayerTime()
	{
		return playerTime;
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
	std::string Player::getPlayerFormattedTime()
	{
		int minutes = playerTime / 60;
		int seconds = playerTime % 60;
		return std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
	}
	int Player::convertTimeToSeconds(std::string fTime)
	{
		int minutes = std::stoi(fTime.substr(0, fTime.find(":")));
		int seconds = std::stoi(fTime.substr(fTime.find(":") + 1));
		return minutes * 60 + seconds;
	}
}
