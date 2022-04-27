// Title: Lab 2 - Record.cpp
//
// Purpose: **<implement accessors and mutators to access data members of record database
//
// Class: CSC 2430 Winter 2022
// Author: **<Kaddijatou Baldeh>

#include "record.h"

string Record::GetWord()const{
    return _word;
}
int Record::GetCount()const{
    return _count;
}
int Record::GetScoreTotal()const{
    return _scoreTotal;
}
void Record::SetWord(string word) {
    _word = word;
}
void Record::SetCount(int count) {
    _count = count + 1;
}
void Record::SetScoreTotal(int scoreTotal) {
    _scoreTotal = scoreTotal;

}

