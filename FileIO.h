#pragma once
#include<vector>
#include<string>
#include"FileIO.h"
#include"Word.h"
#include<cstdio>

vector<Word> Read_File(const char* filename);
void Write_File(const char* filename, vector<Word> words);