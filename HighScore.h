#pragma once
#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <string>
#include <vector>
#include "Player.h"

namespace MemoryGame
{
	struct PlayerScore {
		std::string playerName;
		std::string playerTime;
	};
	class HighScore
	{
		public:
			void saveHighScore(Player* player);
			void readHighScores();
			std::vector<PlayerScore> getScores();
		private:
			std::vector<PlayerScore> scores;
	};
}
#endif