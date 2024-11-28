#pragma once
#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

namespace MemoryGame 
{
	class Card 
	{
		public:
			Card(std::string value);
			std::string getValue();
			bool isRevelead();
			void reveal();
			void hide();
		private:
			std::string value;
			bool isRevealed;
	};
}
#endif