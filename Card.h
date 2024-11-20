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
			Card(std::string imagePath);
			std::string getImagePath();
		private:
			std::string imagePath;
	};
}
#endif