/// Title: Lab 2 - main.cpp
//
// Purpose: Practice using structs and sorted arrays by implementing  a naive algorithm for performing
// sentiment analysis on movie reviews.
//
// Class: CSC 2430 Winter 2022
// Author: Kaddijatou Baldeh
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "database.h"

using namespace std;

// Forward declarations
bool BuildDatabase(const string& fileName, int capacity, Record records[], int& size);
double AnalyzeReview(const Record records[], int size, const string& review);

/**
Main program:

First prompts the user for a movie review file which is used to generate a database of
words, each word being stored by a count of its occurrences and the total score
associated with it.

Then the main program will repeatedly prompt the user to enter the text of a review
at console.  When the user enters return the review text is scored using the word database
and a prediction for the rating is printed.

 */

int main() {
    // Declaration of word database structure
    //      NOTE: Main program is only allowed to access
    //      word database using the interface functions
    //      defined in database.h
    const int CAPACITY  = 20000;
    Record records[CAPACITY];
    int size;
    // End word database structure declaration

    string fileName;
    string review;

    int numberWords;
    int maxOccurrences;
    int minOccurrences;
    double maxScore;
    double minScore;

    // For timing BuildDatabase
    chrono::time_point<chrono::steady_clock> start;
    chrono::time_point<chrono::steady_clock> end;

    // Get name of file containing movie reviews
    cout << "Enter name of movie review file: ";
    getline(cin, fileName);
    if (fileName.length()== 0) {
        fileName = "movieReviews.txt";
    }

    // Build database from movie review file
    start = chrono::steady_clock::now();
    if (!BuildDatabase(fileName, CAPACITY, records, size)) {
        return 1;
    }
    end = chrono::steady_clock::now();
    cout << chrono::duration<double,milli>(end-start).count() << "ms" << endl;

    // Display some information about the database to
    // check if it seems correct
    GetInfoAboutDatabase(records, size, numberWords,
                         maxOccurrences, minOccurrences, maxScore, minScore);
    cout << "Number of Words:                   " << numberWords << endl;
    cout << "Max # of occurrences for any word: " << maxOccurrences << endl;
    cout << "Min # of occurrences for any word: " << minOccurrences << endl;
    cout << "Max score for any word:            " << maxScore << endl;
    cout << "Min score for any word:            " << minScore << endl;

    // Now prompt user for reviews to analyze
    cout << "Enter review you want to analyze: ";
    getline(cin, review);
    while (review.length() > 0) {
        double score;

        score = AnalyzeReview(records, size, review );
        cout << "The review has an average value of " << score << endl;
        cout << "Enter review you want to analyze: ";
        getline(cin, review);
    }
    return 0;
}

// Reads the file consisting of movie review -- one per line, with numerical rating at the start of
// the line.  Breaks the review text into words using blanks as the delimiter, and inserts each
// word into the database along with the rating for the review
// Parameters:
//      filename - name of movie review file
//      database - the word database
// Returns:
//      true indicates database successfully built, false indicates a problem
// Error Handling:
//      THe function will print an appropriate error message to cerr and return false in these two cases
//          - the file could not be opened
//          - the database capacity isn't  large enough to fit all words in the review file
//
bool BuildDatabase(const string& fileName, int capacity, Record records[], int& size) {
    int numberWords, maxOccurrences,minOccurrences;
    double maxScore, minScore;
    // to open the input file using ifstream
    ifstream in;
    in.open(fileName);
    // Check if file open fails and print error message
    if (!in.is_open()) {
        cerr << "Error: the file could not be opened.";
        return false;
    }

    // loop that continues until you hit the end of the file.
    while (!in.eof()) {
        string line;
        int strNumber;

        (getline(in, line)); // reads the lines from the file
        istringstream inSS(line);
        string word;
        //extract scores from file
        inSS >> strNumber;// reads the numerical rating
        int score = strNumber;
        // Call InitDatabase to initialize the database
        InitDatabase(capacity, records, size);
        // loop to add word in database from the file
        while(inSS >> word){
            //add word ro record database
            AddWordToDatabase(capacity, records, size, word, score);
        }
    }
    GetInfoAboutDatabase(records, size, numberWords, maxOccurrences, minOccurrences,maxScore, minScore);
    return true;
}

// Splits the review text into words and averages the scores of all the words that are found
// to produce a score for the review.
// Parameters:
//      database - the word database
//      review - the movie review text
// Returns:
//      true indicates database successfully built, false indicates a problem
double AnalyzeReview(const Record records[], int size, const string& review) {
    string word;
    int occurrences;
    double averageScore;

    //break the review entry into words
    istringstream inSS(review);
    word = review;

    FindWordInDatabase(records, size, word, occurrences, averageScore);
    return averageScore;
}