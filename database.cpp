// Title: Lab 2 - Database.cpp
//
// Purpose: **<implementing functions to build a database for movie review files >
//
// Class: CSC 2430 Winter 2022
// Author: **<Kaddijatou Baldeh>**

#include "database.h"
#include <string>
#include <iostream>

using std:: cout;
using std:: endl;
using std::cerr;

// This is the value used to score a word not found in the database
const double NEUTRAL = 2.0;


void InitDatabase(int capacity, Record records[], int& size){

    size = 0;
    capacity = CAPACITY;
    records[capacity];

}

bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score) {
    // iterate through the record database  ot check for word
    for (size_t i = 0; i < capacity; ++i) {
        if(word != ""){
            // if the word is found in the record increases the word count
            if (records[i].GetWord() == word) {
                records[i].SetCount(1);
                records[i].SetScoreTotal(score);
                return true;
            }else{
                // adds word to database if it does not exist
                records[i].SetWord(word);
                records[i].SetCount(1);
                records[i].SetScoreTotal(score);
                size++;
                return true;
            }
        }
    }
    if(size >= capacity){
        cerr << "Error: the file is at full capacity." << endl;
    }
    return false;
}

void FindWordInDatabase(const Record records[], int size,
                        const string& word, int& occurrences, double& averageScore){
    double count = 0;
    //loop to find occurrence of word and keep
    for (int i = 0; i < size; ++i){
        if(records[i].GetWord() == word) {
            occurrences += records[i].GetCount();
            count += records[i].GetScoreTotal();
        }
    }
    // average calculations
    if(occurrences == 0){
        averageScore = NEUTRAL;
    }else{
        averageScore = count/occurrences;
    }

}

void GetInfoAboutDatabase(const Record records[], int size,
                          int& numberWords, int& maxOccurrences, int& minOccurrences, double& maxScore, double& minScore){

    numberWords = 0;
    maxOccurrences = records[0].GetCount();
    minOccurrences = records[0].GetCount();
    maxScore = records[0].GetScoreTotal();
    minScore = records[0].GetScoreTotal();
    for (size_t i = 0; i < size; ++i) {
        numberWords += records[i].GetCount();
        // To calculate min and max scores and their averages
        if (records[i].GetCount() < minOccurrences) {
            minOccurrences = records[i].GetCount(); // word with the lowest number of occurrences
        }
        if (records[i].GetCount() > maxOccurrences) {
            maxOccurrences = records[i].GetCount();// word with the highest number of occurrences
        }
        if (records[i].GetScoreTotal() < minScore) {
            minScore = records[i].GetScoreTotal();// word with the highest number average scores
        }
        if (records[i].GetScoreTotal() > maxScore) {
            maxScore = records[i].GetScoreTotal();// word with the highest number average scores
        }
    }

}
