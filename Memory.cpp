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
		createCards();
		isStarted = false;
		isProcessingClick = false;
		firstSelectedCardIndex = -1;
		secondSelectedCardIndex = -1;
	}
	bool Memory::getIsStarted() 
	{
		return isStarted;
	}
	void Memory::setIsStarted(bool isStarted)
	{
		this->isStarted = isStarted;
	}
	std::string Memory::getCardPath(int index)
	{
		return cards[index].getImagePath();
	}
	bool Memory::CheckForMatch(int index1, int index2)
	{
		return cards[index1].getImagePath() == cards[index2].getImagePath();
	}
	void Memory::createCards()
	{
		cards.clear();
		for (int i = 1; i <= (rows * cols) / 2; i++) {
			string cardPath = "images/card" + to_string(i) + ".png";
			if (fs::exists(cardPath)) {
				cards.push_back(Card(cardPath));
				cards.push_back(Card(cardPath));
			}
		}
		if (cards.size() < rows * cols) return; // check if enough images in the images folder
		shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()())); // shuffle cards
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

