#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

struct Score
{
    char name[255];
    int score;

    bool operator==(const Score sc)
    {
        return strcmp(sc.name, name) == 0 && sc.score == score;
    }
};

class HighScoreManager
{
private:
    HighScoreManager();
    ~HighScoreManager() { }
    static HighScoreManager* instance;
    int max_scores;
    fstream file;
    vector<Score> high_scores;
    vector<sf::Text> score_texts;

public:
    static HighScoreManager* get_instance()
    {
        if (instance == nullptr)
        {
            instance = new HighScoreManager();
        }
        return instance;
    }
    
    void add_score(const Score score);
    void write_file(const Score score);
    void read_file();
    void remove_score(Score& score);
    void draw_leaderboard(sf::RenderWindow& window, sf::Font font);
};