#include "HighScore.h"
#include <fstream>
#include "Player.h"

namespace MemoryGame
{
	void HighScore::saveHighScore(Player* player)
	{
		std::ofstream outFile("highscores.txt", std::ios::app);
		if (!outFile) {
			throw std::runtime_error("Could not open file");
		}
		outFile << player->getPlayerName() << " " << player->getPlayerTime() << std::endl;
		outFile.close();
	}
	void HighScore::readHighScores()
	{
		std::ifstream inFile("highscores.txt", std::ios::in);
		if (!inFile) {
			throw std::runtime_error("Could not open file");
		}
		PlayerScore playerScore;
		while (inFile >> playerScore.playerName >> playerScore.playerTime) {
			if (inFile.fail()) {
				throw std::runtime_error("Error reading data from file");
			}
			scores.push_back(playerScore);
		}
		inFile.close();
	}
	std::vector<PlayerScore> HighScore::getScores()
	{
		// Bubble sort scores
		for (int i = 0; i < scores.size(); i++) {
			for (int j = i + 1; j < scores.size(); j++) {
				if (scores[i].playerTime > scores[j].playerTime) {
					PlayerScore temp = scores[i];
					scores[i] = scores[j];
					scores[j] = temp;
				}
			}
		}
		return scores;
	}
}