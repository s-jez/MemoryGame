#include "Memory.h"
#include "Card.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

namespace MemoryGame
{
	Memory::Memory(int rows, int cols) : rows(rows), cols(cols)
	{
		if ((rows * cols) % 2 != 0) {
			throw std::invalid_argument("Size of the board must be even.");
		}
		isStarted = false;
		isProcessingClick = false;
		firstSelectedCardIndex = -1;
		secondSelectedCardIndex = -1;
		createCards();
	}
	bool Memory::getIsStarted() 
	{
		return isStarted;
	}
	void Memory::setIsStarted(bool isStarted)
	{
		this->isStarted = isStarted;
	}
	std::string Memory::getCardValue(int index)
	{
		return cards[index].getValue();
	}
	bool Memory::CheckForMatch(int index1, int index2)
	{
		return cards[index1].getValue() == cards[index2].getValue();
	}
	void Memory::createCards()
	{
		for (int i = 1; i <= (rows * cols) / 2; i++) {
			cards.push_back(Card(to_string(i)));
			cards.push_back(Card(to_string(i)));
		}
		shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));

		board.resize(rows, std::vector<Card>(cols, Card("")));
		int index = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0 ; j < cols; j++) 
			{
				board[i][j] = cards[index];
				index++;
			}
		}
	}
	bool Memory::getProcessingClick()
	{
		return isProcessingClick;
	}
	void Memory::setProcessingClick(bool isProcessingClick)
	{
		this->isProcessingClick = isProcessingClick;
	}
	int Memory::getFirstSelectedCardIndex()
	{
		return firstSelectedCardIndex;
	}
	void Memory::setFirstSelectedCardIndex(int index)
	{
		this->firstSelectedCardIndex = index;
	}
	int Memory::getSecondSelectedCardIndex()
	{
		return secondSelectedCardIndex;
	}
	void Memory::setSecondSelectedCardIndex(int index)
	{
		this->secondSelectedCardIndex = index;
	}
	void Memory::resetSelectedCardsIndexes()
	{
		this->firstSelectedCardIndex = -1;
		this->secondSelectedCardIndex = -1;
	}
}

