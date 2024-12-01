#include "Card.h"

namespace MemoryGame 
{
	Card::Card(std::string value)
	{
		this->value = value;
		isRevealed = false;
	}
	std::string Card::getValue()
	{
		return value;
	}
	bool Card::isRevelead()
	{
		return isRevealed;
	}
	void Card::reveal()
	{
		isRevealed = true;
	}
	void Card::hide()
	{
		isRevealed = false;
	}
}