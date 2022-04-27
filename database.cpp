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
    // iterate through the records database  ot check for word
    for (size_t i = 0; i < size; ++i) {
        // if the word is found in the record increases the word count
        if (records[i].GetWord() == word) {
            records[i].SetCount(1);
            return true;
        }
    }
    // iterate through the records database and check if it is at full capacity
    if (size != capacity) {
        // adds word to database if it does not exist
        records[size].SetWord(word);
        records[size].SetCount(1);
        records[size].SetScoreTotal(score);
        size += 1;
    } else{
        cerr << "Error: the file is at full capacity.";
        return false;
    }

    return true;
}

void FindWordInDatabase(const Record records[], int size,
                        const string& word, int& occurrences, double& averageScore){
    double count = 0;
    //loop to find occurrence of word and keep
    for (int i = 0; i < size; ++i){
        if(records[i].GetWord() == word) {
            occurrences += records[i].GetCount(); // get total occurrences
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

    for (size_t i = 0; i < size; ++i) {
        // To calculate the total number of words in database
        numberWords += records[i].GetCount();
        // To calculate min and max scores and their averages
        if (records[i].GetCount() < minOccurrences) {
            minOccurrences = records[i].GetCount(); // word with the lowest number of occurrences
        }
        if (records[i].GetCount() > maxOccurrences) {
            maxOccurrences = records[i].GetCount();// word with the highest number of occurrences
        }
        if (records[i].GetScoreTotal() > minScore) {
            minScore = minOccurrences / records[i].GetScoreTotal();// word with the highest number average scores
        }
        if (records[i].GetScoreTotal() < maxScore) {
            maxScore = maxOccurrences / records[i].GetScoreTotal();// word with the highest number average scores
        }
    }
}
