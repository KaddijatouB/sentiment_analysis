// Title: Lab 2 - Database.cpp
//
// Purpose: **<implementing functions to build a database for movie review files >
//
// Class: CSC 2430 Winter 2022
// Author: **<Kaddijatou Baldeh>**

#ifndef RECORD_H
#define RECORD_H

//
// THIS FILE SHOULD NOT BE MODIFIED
//

#include <string>
using std::string;

class Record {
public:
    string GetWord() const;
    int GetCount() const;
    int GetScoreTotal() const;

    void SetWord(string word);
    void SetCount(int count);
    void SetScoreTotal(int scoreTotal);

private:
    string _word;
    int _count;
    int _scoreTotal;
};

#endif //RECORD_H