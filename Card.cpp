#include "Card.h"

namespace MemoryGame {
	Card::Card(std::string imagePath)
	{
		this->imagePath = imagePath;
	}
	std::string Card::getImagePath()
	{
		return imagePath;
	}
}