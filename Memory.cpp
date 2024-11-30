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
		firstSelectedCardRow = -1;
		firstSelectedCardCol = -1;
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
	bool Memory::CheckForMatch(int row1, int col1, int row2, int col2)
	{
		if (board[row1][col1].isRevelead() == board[row2][col2].isRevelead())
		{
			return board[row1][col1].getValue() == board[row2][col2].getValue();
		}
		return false;
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
	int Memory::getFirstSelectedCardRow()
	{
		return firstSelectedCardRow;
	}
	void Memory::setFirstSelectedCardRow(int row)
	{
		this->firstSelectedCardRow = row;
	}
	int Memory::getFirstSelectedCardCol()
	{
		return firstSelectedCardCol;
	}
	void Memory::setFirstSelectedCardCol(int col)
	{
		this->firstSelectedCardCol = col;
	}
	void Memory::setSecondSelectedCardRow(int row)
	{
		this->secondSelectedCardRow = row;
	}
	int Memory::getSecondSelectedCardRow()
	{
		return secondSelectedCardRow;
	}
	void Memory::setSecondSelectedCardCol(int col)
	{
		this->secondSelectedCardCol = col;
	}
	int Memory::getSecondSelectedCardCol()
	{
		return secondSelectedCardCol;
	}
	void Memory::resetSelectedCards()
	{
		firstSelectedCardRow = -1;
		firstSelectedCardCol = -1;
	}
	bool Memory::getProcessingClick()
	{
		return isProcessingClick;
	}
	void Memory::setProcessingClick(bool isProcessingClick)
	{
		this->isProcessingClick = isProcessingClick;
	}
}

