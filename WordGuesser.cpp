#include <iostream>
#include <string>
#include"FileIO.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include"Word.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* filename = "words.txt";
    vector<Word> words = Read_File(filename);
    srand(time(NULL));
    getchar();
    //words[0].Print();
    vector<char> letters;
    char letter;
    bool Running = true;
    int index;
    Word word;
    char menu;
    while (Running)
    {
        cout << "1.Играть\n2.Выход\n\nВыберите пункт из меню: ";
        cin >> menu;
        cout << menu;
        switch (menu)
        {
        case '1':

            index = rand() % (words.size());
            word = words[index];
            while (!word.Victory())
            {
                system("cls");
                word.PrintQuestion();
                word.Print();
                cin >> letter;
                if (!In(letter, letters))
                {
                    word.Guess(letter);
                    letters.push_back(letter);
                    letters.push_back(UpDown(letter));
                }
                else
                {
                    cout << "Уже было..." << endl;
                }
                system("pause");
            }
            letters.clear();
            word.GuessedLetters.clear();
            system("cls");
            word.Print();
            break;
        case '2':
            Running = false;
            break;
        }

    }
    Write_File(filename, words);
    return 0;
}
