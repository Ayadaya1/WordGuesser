#include "Word.h"
#include <string>
#include<vector>
#include<iostream>

using namespace std;

char UpDown(char c)
{
    if ((c >= 'а' && c <= 'я'))
    {
        //cout << c;
        return c - 32;
    }
    else if (c == 'ё')
        return c - 16;
    else if (c >= 'A' && c <= 'Я')
        return c + 32;
    else if (c == 'Ё')
        return c + 16;
    else
        return c;
}
bool In(char c, vector<char> chars)
{
    for (int i = 0; i < chars.size(); i++)
    {
        if (c == chars[i])
            return true;
    }
    return false;
}


Word::Word()
{
    word = "";
    question = "";
}

Word::Word(string p_word, string p_question)
{
    word = p_word;
    question = p_question;
}
void Word::Print()
{
    for (int i = 0; i < word.length(); i++)
    {
        int check = 0;
        for (int j = 0; j < GuessedLetters.size(); j++)
        {
            if (GuessedLetters[j] == i)
            {
                cout << word[i];
                check++;
            }
        }
        if (!check)
            cout << '_';
    }
    cout << " (" << word.size() << " букв)";
    cout << endl;
}

void Word::Guess(char letter)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (UpDown(letter) == word[i])
        {
            GuessedLetters.push_back(i);
            cout << "Right!" << endl;
        }
    }
}

bool Word::Victory()
{
    if (GuessedLetters.size() == word.length())
        return true;
    return false;
}
void Word::PrintQuestion()
{
    cout << question << endl;
}