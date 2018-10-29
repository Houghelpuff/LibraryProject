#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User{
    private:
        string name; //string for the name
        int ratings[100]; //array for ratings
        int numRating; //int for number of ratings on the array 
    
    public:
        User(); //default contructor 
        User(string, int[], int); //constructor that takes parameters
        string getName(); //gets the name of the user
        void setName(string); //sets the name of the user
        int getNumRatings(); //gets the number of ratings for the user
        void setNumRatings(int); //sets the number of ratings for the user
        int getRatingAt(int); //gets the rating at a certain index of the array 
        int setRatingAt(int, int); //sets the rating to something at a certain index
        
};

#endif