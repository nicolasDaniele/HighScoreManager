#include <HighScoreManager.h>
#include <SFML/Graphics.hpp>

HighScoreManager* HighScoreManager::instance = nullptr;

int main()
{
	Score s1;
	memcpy(s1.name, "John", sizeof("John"));
	s1.score = 200;

	Score s2;
	memcpy(s2.name, "Anna", sizeof("Anna"));
	s2.score = 222;

	Score s3;
	memcpy(s3.name, "Peter", sizeof("Peter"));
	s3.score = 156;

	Score s4;
	memcpy(s4.name, "Mary", sizeof("Mary"));
	s4.score = 50;

	Score s5;
	memcpy(s5.name, "Steven", sizeof("Steven"));
	s5.score = 350;

	HighScoreManager::get_instance()->add_score(s1);
	HighScoreManager::get_instance()->add_score(s2);
	HighScoreManager::get_instance()->add_score(s3);
	HighScoreManager::get_instance()->add_score(s4);
	HighScoreManager::get_instance()->add_score(s5);

	sf::RenderWindow window(sf::VideoMode(800, 600), "HIGH-SCORES");
	sf::Font font;
	if (!font.loadFromFile("Assets/Fonts/Arcadepix_Plus.ttf"))
	{
		cout << "Could not load font" << endl;
	}
	HighScoreManager::get_instance()->remove_score(s1);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		HighScoreManager::get_instance()->draw_leaderboard(window, font);
		window.display();
	}

	return 0;
}