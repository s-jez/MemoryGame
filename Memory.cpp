#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "Memory.h"
#include "Card.h"

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
		highScore = new HighScore();
		createBoardWithCards();
	}
	int Memory::getRows()
	{
		return rows;
	}
	int Memory::getCols()
	{
		return cols;
	}
	bool Memory::getIsStarted() 
	{
		return isStarted;
	}
	void Memory::setIsStarted(bool isStarted)
	{
		this->isStarted = isStarted;
	}
	Card& Memory::getCard(int row, int col)
	{
		return board[row][col];
	}
	bool Memory::CheckForMatch(int row1, int col1, int row2, int col2)
	{
		if (board[row1][col1].isRevelead() == board[row2][col2].isRevelead())
		{
			return board[row1][col1].getValue() == board[row2][col2].getValue();
		}
		return false;
	}
	void Memory::createBoardWithCards()
	{
		std::vector<Card> cards;
		player = new Player();
		for (int i = 1; i <= (rows * cols) / 2; i++) {
			cards.push_back(Card(std::to_string(i)));
			cards.push_back(Card(std::to_string(i)));
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
	bool Memory::checkForEnd()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j].isRevelead() == false)
				{
					return false;
				}
			}
		}
		highScore->saveHighScore(player);
		return true;
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
	bool Memory::getProcessingClick()
	{
		return isProcessingClick;
	}
	void Memory::setProcessingClick(bool isProc)
	{
		this->isProcessingClick = isProc;
	}
	void Memory::resetSelectedCards()
	{
		firstSelectedCardRow = -1;
		firstSelectedCardCol = -1;
	}
	Player* Memory::getPlayer()
	{
		return player;
	}
	HighScore* Memory::getHighScore()
	{
		return highScore;
	}
}

