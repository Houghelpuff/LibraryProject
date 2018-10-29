#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book{
    private:
        string title; //private string for the title
        string author; //private string for the author
    
    public:
        Book(); //default constructor
        ~Book(); //destructor
        Book(string title, string author); //constructor that takes parameters
        string getTitle(); //gets the title
        void setTitle(string); //sets the title
        string getAuthor(); //gets the author
        void setAuthor(string); //sets the author
};


#endif