#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

namespace MemoryGame 
{
	class Player 
	{
		public:
			Player();
			std::string getPlayerName();
			void setPlayerName(std::string pName);
			int getPlayerStep();
			void setPlayerStep(int step);
		private:
			std::string playerName;
			int step;
	};
}
#endif