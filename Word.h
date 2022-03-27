#pragma once
#include<string>
#include<vector>

using namespace std;

char UpDown(char c);
bool In(char c, vector<char> chars);

struct Word
{
    string word;
    string question;
    vector<char> GuessedLetters;
public:
    Word();
    Word(string p_word, string p_question);
    void Print();
    void Guess(char letter);
    bool Victory();
    void PrintQuestion();
};