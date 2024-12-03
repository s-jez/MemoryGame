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
			std::string getPlayerFormattedTime();
			int convertTimeToSeconds(std::string fTime);
			int getPlayerTime();
			void setPlayerTime(int time);
			void incrementTime();
		private:
			std::string playerName;
			int playerTime;
	};
}
#endif