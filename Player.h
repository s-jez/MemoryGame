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
			int getPlayerTime();
			void setPlayerTime(int playerTime);
			void countTime();
		private:
			std::string playerName;
			int playerTime;
	};
}
#endif