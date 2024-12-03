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
		if (player->getPlayerName() != "") {
			outFile << player->getPlayerName() << " " << player->getPlayerFormattedTime() << std::endl;
		}
		outFile.close();
	}
	void HighScore::readHighScores()
	{
		std::ifstream inFile("highscores.txt", std::ios::in);
		if (!inFile) {
			throw std::runtime_error("Could not open file");
		}
		std::string playerName;
		std::string playerTime;

		while (inFile >> playerName >> playerTime) {
			Player player;
			player.setPlayerName(playerName);
			player.setPlayerTime(player.convertTimeToSeconds(playerTime));
			scores.push_back(player);
		}
		inFile.close();
	}
	std::vector<Player> HighScore::getPlayersScore()
	{
		for (int i = 0; i < scores.size(); i++) {
			for (int j = i + 1; j < scores.size(); j++) {
				if (scores[i].getPlayerTime() > scores[j].getPlayerTime()) {
					Player temp = scores[i];
					scores[i] = scores[j];
					scores[j] = temp;
				}
			}
		}
		return scores;
	}
}