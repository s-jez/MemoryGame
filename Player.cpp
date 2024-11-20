#include "Player.h"

MemoryGame::Player::Player()
{
	playerTime = 0;
	playerName = "";
}

int MemoryGame::Player::getPlayerTime()
{
	return playerTime;
}

void MemoryGame::Player::setPlayerTime(int playerTime)
{
	this->playerTime = playerTime;
}

void MemoryGame::Player::countTime()
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
