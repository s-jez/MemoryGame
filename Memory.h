#pragma once
#ifndef MEMORY_H
#define MEMORY_H
#include <string>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "HighScore.h"

namespace MemoryGame 
{
	class Memory 
	{
		public:
			Memory(int rows, int cols);
			int getRows();
			int getCols();

			Card& getCard(int row, int col);
			Player* getPlayer();
			HighScore* getHighScore();

			void createBoardWithCards();
			bool CheckForMatch(int row1, int col1, int row2, int col2);
			bool getIsStarted();
			void setIsStarted(bool isStarted);
			bool checkForEnd();
			bool getProcessingClick();
			void setProcessingClick(bool isProc);

			int getFirstSelectedCardRow();
			int getFirstSelectedCardCol();
			void setFirstSelectedCardRow(int row);
			void setFirstSelectedCardCol(int col);

			int getSecondSelectedCardRow();
			int getSecondSelectedCardCol();
			void setSecondSelectedCardRow(int row);
			void setSecondSelectedCardCol(int col);
			void resetSelectedCards();
		private:
			Player* player;
			HighScore* highScore;
			std::vector<std::vector<Card>> board;
			int rows, cols;
			int firstSelectedCardRow, firstSelectedCardCol, secondSelectedCardRow, secondSelectedCardCol;
			bool isProcessingClick, isStarted;
	};
}
#endif