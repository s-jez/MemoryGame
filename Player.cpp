#include "Player.h"

namespace MemoryGame 
{
	MemoryGame::Player::Player()
	{
		playerTime = 0;
		playerName = "";
	}
	std::string MemoryGame::Player::getPlayerTime()
	{
		int minutes = playerTime / 60;
		int seconds = playerTime % 60;
		return std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
	}
	void MemoryGame::Player::setPlayerTime(int time)
	{
		this->playerTime = time;
	}
	void MemoryGame::Player::incrementTime()
	{
		playerTime++;
	}
	std::string MemoryGame::Player::getPlayerName()
	{
		return playerName;
	}
	void MemoryGame::Player::setPlayerName(std::string pName)
	{
		this->playerName = pName;
	}
}
