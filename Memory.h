#pragma once
#ifndef MEMORY_H
#define MEMORY_H
#include <string>
#include <vector>
#include "Card.h"


namespace MemoryGame 
{
	class Memory 
	{
		public:
			Memory(int rows, int cols);
			int rows, cols;
			std::vector<std::vector<Card>> board;

			std::string getCardValue(int row, int col);
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
			std::vector<Card> cards;
			int firstSelectedCardRow, firstSelectedCardCol, secondSelectedCardRow, secondSelectedCardCol;
			bool isProcessingClick, isStarted;
			void createBoardWithCards();
	};
}
#endif