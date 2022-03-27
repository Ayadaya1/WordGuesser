#include <iostream>
#include <string>
#include"FileIO.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include"Word.h"

using namespace std;

vector<Word> Read_File(const char* filename)
{
    ifstream in;
    vector<Word> words;
    string word;
    string question;
    in.open(filename);
    while (!in.eof())
    {
        getline(in, word);
        getline(in, question);
        Word new_word(word, question);
        if (word.size() != 0 && question.size() != 0)
        {
            words.push_back(new_word);
        }
        else
        {
            in.close();
        }
    }
    cout << "Загружено " << words.size() << " слов.";
    return words;
}
void Write_File(const char* filename, vector<Word> words)
{
    ofstream out;
    out.open(filename);
    for (int i = 0; i < words.size(); i++)
    {
        out << words[i].word << endl << words[i].question << endl;
    }
    out.close();
}