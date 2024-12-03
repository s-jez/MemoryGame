#pragma once
#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <string>
#include <vector>
#include "Player.h"

namespace MemoryGame
{
	class HighScore
	{
		public:
			void saveHighScore(Player* player);
			void readHighScores();
			std::vector<Player> getPlayersScore();
		private:
			std::vector<Player> scores;
	};
}
#endif