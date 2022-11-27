#include "HighScoreManager.h"

HighScoreManager::HighScoreManager()
{
	max_scores = 3;
}

void HighScoreManager::add_score(Score score)
{
	sf::Text text;
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Red);
	text.setPosition(100, high_scores.size() * 40);

	if (high_scores.size() >= max_scores)
	{
		Score lowest_score = high_scores[0];
		int lowest_score_index = 0;

		for (int i = 1; i < high_scores.size(); i++)
		{
			if (high_scores[i].score < lowest_score.score)
			{
				memcpy(&lowest_score, &high_scores[i], sizeof(Score));
				lowest_score_index = i;
			}
		}

		if (score.score > lowest_score.score)
		{
			memcpy(&high_scores[lowest_score_index], &score, sizeof(Score));
			text.setString("Name: " + (string)score.name + " | Score: " + to_string(score.score));
			score_texts[lowest_score_index] = text;
		}
	}
	else
	{
		high_scores.push_back(score);
		write_file(score);
		text.setString("Name: " + (string)score.name + " | Score: " + to_string(score.score));
		score_texts.push_back(text);
	}
}

void HighScoreManager::write_file(const Score score)
{
	file.open("ScoreList.dat", ios::out | ios::binary);
	if (file.is_open())
	{
		file.write((char*)&score, sizeof(Score));
		file.close();
	}
}

void HighScoreManager::read_file()
{
	file.open("ScoreList.dat", ios::in | ios::binary | ios::beg);
	string line;

	while (getline(file, line))
	{
		cout << line << endl;
	}

	file.close();
}

void HighScoreManager::remove_score(Score& score)
{
	for (int i = 0; i < high_scores.size(); i++)
	{
		if (high_scores[i] == score)
		{
			high_scores.erase(high_scores.begin() + i);
			score_texts.erase(score_texts.begin() + i);
		}
	}
}

void HighScoreManager::draw_leaderboard(sf::RenderWindow& window, sf::Font font)
{
	for (sf::Text& text : score_texts)
	{
		text.setFont(font);
		window.draw(text);
	}
}