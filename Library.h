#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
using namespace std;

class Library{
    private:
        Book books[100]; //creates an array of book objects
        User users[100]; //creates an array of user objects
        int numBooks; //int for number of books
        int numUsers; //int for number of users
        int currentUseridx; //int to keep track of the index of the current user
        
    public:
        Library(); //default constructor
        void loadData(string,string); //loads the data from the files
        void login(); //login for the user
        void viewRatings(); //views the ratings for the user
        void rateABook(); //rate a book
        int SimilarityScore(int,int); //find the similarity score
        void getRecs(int index); //gets recomendations for the user
        void quit();
        void addBook(string,string);
};

#endif