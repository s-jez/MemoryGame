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

			std::vector<Card> cards;
			std::string getCardPath(int index);
			bool CheckForMatch(int index1, int index2);

			void setIsStarted(bool isStarted);
			bool getIsStarted();

			void setProcessingClick(bool isProcessingClick);
			bool getProcessingClick();

			void setFirstSelectedCardIndex(int index);
			int getFirstSelectedCardIndex();
			void setSecondSelectedCardIndex(int index);
			int getSecondSelectedCardIndex();
			void resetSelectedCardsIndexes();
		private:
			void createCards();
			int isStarted, firstSelectedCardIndex, secondSelectedCardIndex;
			bool isProcessingClick;
	};
}
#endif