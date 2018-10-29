// Author: Jacob Hough
// CS1300 Spring 2018
// Recitation: 205 - Harshini Muthukrishnan
// Cloud9 Editor Link: https://ide.c9.io/houghelpuff/csci1300
// Homework 7
//I got help from Telly the TA... mostly on the weekend before spring break as well at TAs who had 
//office hours thar where 

#include <iostream>
#include <fstream>
#include "math.h"
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

int split(string sentence, char seperator, string words[], int size) { //split function for splitting lines

    if(sentence.length() == 0) { //if the string is empty...
        return 0; //return 0
    }

    int num_substrings = 1; //int for a count 
    int previous = 0;
    string new_sentence = ""; //empty string to append 
    int index = 0; //index for the original string 
    int last_index = 0; //index for the substring

    for(int i = 0; i < sentence.length(); i++) { //for loop to find the seperator 
        if(sentence[i] != seperator) { //if the character at i isn't the seperator given 
            new_sentence += sentence[i]; //append the empty string with the character at i
    }

        else { //else
            words[index] = new_sentence; //sets word at index to the new index
            index++; //inrements index
            num_substrings++; //increments the substrings count
            last_index = i + 1; 
            new_sentence = ""; //set new sentence to empty 
        }
    }


    words[index] = sentence.substr(last_index, sentence.length()); //get last substring

    return num_substrings; //return number of substrings in the sentence
}

string putLower(string str){ //function to put strings to lower case
    
    for(int i = 0; i < str.length(); i++){ //for every character in the string passed in by the parameter
         str[i] = tolower(str[i]); //sets str[i] equal to it's lowercase equivelent 
    }
    return str; //returns str
}

User::User(){ //defines the default constructor 
    name = "NONE"; //sets name to none
    numRating = 0; //sets the number of ratings for that user to 0
    
    for(int  i=0; i < 100; i++){ //for every rating in the array of ratings
        ratings[i] = 0; //set each rating at set i to 0
    }
    
}

User::User(string str, int ratingsArray[], int ratingSize){ //defines a user that takes parameters
    name = str; //sets name equal to str
    numRating = ratingSize; //sets the number of ratings to the rating size passed in by the parameter 
    
    for(int n=0; n < ratingSize; n++){ //for every rating in the array
        ratings[n] = ratingsArray[n]; //sets every rating at spot i to the ratings passed in by the user
    }
}

string User::getName(){ //gets the name of the user
    return name; //returns the name
}

void User::setName(string str){ //sets the name 
    name = str; //sets the name to the string passed by the user
}

int User::getNumRatings(){ //gets the number of ratings
    return numRating; // returns the number of ratings 
}

void User::setNumRatings(int n){ //sets the number of ratings
    numRating = n; //sets the number of ratings to the int passed by that user
}

int User::getRatingAt(int n){ //gets the rating at an index
    if(n >= numRating) //if the int passed by the user is larger than the number of ratings...
        return -1000; //return -1000
        
    else //else
        return ratings[n]; //return the rating at spot n
}

int User::setRatingAt(int index, int rating){ //sets the rating at an index
    if(index >= numRating) //if the int passed by the user is larger than the number of ratings...
        return -1000; //return -1000
        
    else if(rating == -5 || rating == -3 || rating == 0 || rating == 1 || rating == 3 || rating == 5){ //else if the rating passed by the user is a -5,-3,0,1,3,5...
        ratings[index] = rating; //ratings at the index passed is set to the rating passed 
        return 1; //return 1
    }
    
    else{ //else
        cout << "Invalid input!" << endl; //cout invalid input
        return -1; //return -1
    }
        
}

Book::Book(){ //defines the default constructor for a book object 
    author = "NONE"; //sets the author to NONE
    title = "NONE"; //sets the title to NONE
}

Book::~Book(){ } //deconstructor 

Book::Book(string t, string a){ //defines the constructor to take parameter 
    title = t; //sets the title to the first string passed
    author = a; //sets the author equal to the second string passed
}

string Book::getTitle(){ //gets the title of the book 
    return title; //returns the title 
}

void Book::setTitle(string str){ //sets the title of the book
    title = str; //sets the title of the book to the string passed in 
}

string Book::getAuthor(){ //gets the author of a book
    return author; //returns the author 
}

void Book::setAuthor(string str){ //sets the author of a book
    author = str; //sets the author to the string passed in 
}

Library::Library(){ } //defines the default constructor for a library 


void Library::loadData(string booksPath, string ratings){ //loads the data into the program from files
    ifstream bookList; //creates a stream for the list of books
    bookList.open(booksPath); //opens the books file
    ifstream ratingsList; // creates a stream for the list of users
    ratingsList.open(ratings); //opens the users file
    string str; //string for spliting 
    string author; //string to store the author's name
    string title; //string to store the title 
    string lowerAuthor = ""; //empty string to set the author to lower case
    string lowerTitle = ""; //empty string to set the title to lower case
    string name; //string to store the name
    string lowerName = ""; //string to set the name to lower case
    string userRatings[100]; //array for user ratings
    string bookArray[2]; //array to store the title and the author of the book
    
    int i = 0; //counter variable
    
    if(!(bookList.is_open() || ratingsList.is_open())){ //if either of the files didn't open successfully
        cout << "Launch Unsuccessful" << endl; //prints launch unsuccessful
        cout << "Error! books or ratings file could not be found"; //prints error... books or ratings file could not be found 
        bookList.close(); //closes the files
        ratingsList.close();
    }
    
    else{ //else
    
        while(getline(bookList,str)){ //while there's still a line in the books file
                //str = str.substr(0, str.length()-1); //gets rid of the \r character at the end of every line
            
                split(str, ',', bookArray, 2); //splits each line at the comma, seperating the auhtor from the title and setting the author to bookArray index 0 and title to index 1
                
               
            
                author = (bookArray[0]); //sets author equal to bookArray at index 0
                title = (bookArray[1]); //sets title equal to bookArray to index 1
                
                Book newBook(title,author); //creates a new book object for each line with title and author
            
                books[i] = newBook; //sets the book at index i to the new book object just created 
                ++i; //increments i
                
        }
        numBooks = i+1; //sets numBooks to the index of the book array plus 1 since the start index was 0
    
            bookList.close(); //closes booklist 
            int j = 0; //initilizes another counter variable 
        
        while(getline(ratingsList,str)){ //while there is still lines in ratings.txt
            
            // 1. Take a line of the form "<name>,1 2 3 4 ..."
            split(str, ',', bookArray, 2);
            
            // 2. Split on "," to produce ["<name>", "1 2 3 4 ..."]
            // 3. Assign the first element to a user's name
            name = bookArray[0];
            
            lowerName = ""; 
            for(int i = 0; i < name.length(); i++){
                lowerName += tolower(name[i]);
            }
            // 4. Split the second element on " " to produce ["1", "2", "3", ...]
            split(bookArray[1], ' ', userRatings, 100);
            
            // 5. atoi each rating
            int ratings[100];
            for (int i = 0; i < 100; i++) {
                if (userRatings[i].length() != 0) {
                    ratings[i] = stoi(userRatings[i]);
                }
            }

            User newUser(lowerName, ratings, 100); //creates a new user object with the info taken from the file 
            
            users[j] = newUser; //sets the user at j to the new user made every time through the while loop
            ++j; //increments j
        }
        numUsers = j; //int that keeps track of the number of users
        ratingsList.close(); //closes the file
        cout << "Data Loaded successfully!" << endl; //prints that the data was loaded successfully 
    }
    
    
}

void Library::viewRatings(){ // defines the function to get the ratings for a user


        int c = 0; //int to keep track of the number of books iterated through the for loop
        for(int n = 0; n < numBooks; n++){ //for loop to iterate through the ratings of bools

            if(users[currentUseridx].getRatingAt(n) != 0){ //if the rating at n isn't zero (zero means the book hasn't been rated)...
                if(c == 0){ //if c is zero
                    cout << "Here are the books that you have rated:" << endl; //cout the line 'Here are the books you have rated'
                }

                c++; 
                cout << "Title : " << putLower(books[n].getTitle()) << endl; //prints the title 
                cout << "Rating : " << users[currentUseridx].getRatingAt(n) << endl; //prints the rating
                cout << "------------------------------" << endl; //prints the line seperating them 

            }
        }
        if(c == 0)
            cout << "You have not rated any books as yet:" << endl; //cout they don't have any ratings yet
        
    }

    void Library::addBook(string name, string author){

        Book newBook(name, author);
        books[numBooks - 1] = newBook;
    }
    
void Library::rateABook(){ //defines the function to rate a book 
    string book_to_rate; //string to store the book the user wants to rate
    string lowerBook; //string to store the lower case equilalent of the string
    int bookRating; //int to store the rating the user wants to rate the book 
    bool isBook = true; //bool to see if the book is actually a book in the system 
    string yesNo;
    string author;
    
        cout << "Enter the name of the book that you would like to rate:" << endl; //cout to prompt the user for the book 
        cin.ignore(); 
        getline(cin, book_to_rate); //gets the name of the book the user wants to rate and sets to book_to_rate... you have to use get line because there are spaces and cin stops at sapces
        
        lowerBook = putLower(book_to_rate); // sets lowerBook to the lowercase equivalent to book_to_rate

        
        for(int n = 0; n < numBooks; n++){ //for loop to iterate through the books in the books array
            if(putLower(books[n].getTitle()) == lowerBook){ //if the lowercase title from the array is the same a lowerBook...
                cout << "Enter your rating of the book: " << endl; //asks for the rating of the book from the user
                cin >> bookRating; //cin sets the rating given by the user to bookRating
                cout << "Success!\nThank-you. The rating for the book titled " << books[n].getTitle() << " has been updated to " << bookRating << endl; //couts that the rating was a success
                users[currentUseridx].setRatingAt(n, bookRating); //changes the rating for that user
                isBook = false; //sets is book to false so it skips the if statement below
            }
        }
        if(isBook == true){ //if is book is true (that means that the if statement above didn't run)..
            cout << "The book you requested does not exist in the database. Would you like to add it?" << endl; //tells the user that the book doesn't exist in the system
            cin >> yesNo;
            if(putLower(yesNo) == "yes"){
                cout << "Please make sure the title of the book is spelled correctly" << endl;
                cin.ignore();
                getline(cin, lowerBook);
                cout << "Who is the author?" << endl;
                cin.ignore();
                getline(cin, author); 
                addBook(lowerBook, author);
            } 
            else{
                cout << "Ok, sorry for the inconvernience!" << endl;
            }
        }
}

int Library::SimilarityScore(int index1, int index2){ //defines the function to calculate the similarity score of 2 users (index1 and index 2)
    int SS = 0; //int to store the score each time it's calculated
    for(int i = 0; i < users[index1].getNumRatings(); i++){ //for each rating for user 1
       SS += pow(users[index1].getRatingAt(i) - users[index2].getRatingAt(i), 2); //adds the similarity score to SS
    }
    return SS; //returns SS
}

void Library::getRecs(int index){ //defines a function to compares the 2 similarity scores and gets a list of recomendations
    int bestSSD = 9999; //int for the best score (set it high, because the lower the score, the better)
    int SSD = 0; //int to store the similarity score each time around
    int indexMostSim; //int to store the index of the user most similar to the one passed by the user
    int bookCount = 0; //keeps trrack of the number of books reccomended since it shouldn't be more than 10 
    bool flag = true; //flag to see if there are any recommendations for the user
    
    for(int i = 0; i < numUsers; i++){ //for loop to find the similarity score between the user and all the other users
        SSD = SimilarityScore(index, i); //find the similarity at the index passed in and i and stores it in SSD
        if(SSD <= bestSSD && i != index){ //if the SSD found is lower than the bestSSD AND i isn't the index (so you don't find yourself)...
            bestSSD = SSD; //bestSSD is set to SSD
            indexMostSim = i; //indexMostSim is set to spot i
        }
    }

    
    for(int n = 0; n < numBooks; n++){ //for loop to go through the books and see what the most similar user rated a 3 or higher and the user using the function hasn't rated the book
        if(bookCount < 10 && users[index].getRatingAt(n) == 0 && users[indexMostSim].getRatingAt(n) >= 3) //if bookCount is less than 10 AND the user calling the function hasn't rated the book AND the most similar user rated it higher than a 3...
        {
            //sets creates 2 string variables; one for a lowercase equivalent to the title and one for the lowercase equivalent to the author
            string lowert = putLower(books[n].getTitle());
            string lowera = putLower(books[n].getAuthor());
            if(bookCount == 0){ //if the bookCount is 0
                cout << "Here are some of the books that we think you would like" << endl;  //tells the user that we found books that they might like
            }
            bookCount++; //increments the bookCount
            cout << lowert << " by " << lowera << endl; //prints the book and the author for the user
            flag = false; //sets the falg to false so it doesn't run the if statement later
        }
    }
    
    if(flag == true){ //if the flag is true (it didn't go through the if statement above)
        cout << "There are no recommendations for you at present" << endl; //tell the user there isn't any recomendations for them 
    }

    
}

void Library::quit(){
    ofstream userSave; //creates an ofstream for writing only
    userSave.open("ratings.txt"); //opens a new file 
    
    if(!(userSave.is_open())){ //if the file doesn't open 
        cout << "Please enter a valid file name" << endl;
    }
    
    for(int i=0; i < numUsers; i++){ //iterates through the users to re-write the file
        userSave << users[i].getName() << ","; //puts the name of the user from the array at i
        for(int j = 0; j < numBooks; j++){ //iterates through the ratings to re-write the ratings on the new file
            userSave << users[i].getRatingAt(j) << " "; //adds each rating with a space 
        }
        userSave << endl; //ends the line after each user
    }
    userSave.close(); //closes the file
}


void Library::login(){
    string name; //string to store the name given 
    string lowerName = ""; //string to store the lowercase equivalent to the name 
    bool validName = true; //bool to see if the name is a valid name
    char choice; //character to store the mensu choice of the user
    char lowerChoice; //char to store the lowercase equivalent to the menu choice 
    bool validChoice = true; //bool to check if the choice of the user was a valid input 
    bool playing = true; //bool to see if the user quit or not
    
    cout << "Welcome to the Library, What is your name?:" << endl; //asks the user for their name 
    getline(cin, name); //get line stores the name given in name
    
    if(name.length() == 0){ //if the string name is empty  
        validName = false; //valid name is set to false
    }
    
    while(!validName){ //while valid name is false (there was invalid input)
        cout << "You provided an empty user name, Please provide a valid user name to login or register:\nEnter your name again:" << endl; //ask the user to enter valid input
        getline(cin, name); //get line stores the name typed in name
        
        if(name.length() != 0) //checks to see if name has something in it
            validName = true; //sets validName to true, kicking out of the while loop next time around
            
        else //else
            validName = false; //validName stays false causing the while loop to run until they enter a name
    }
    

    
    lowerName = putLower(name); //sets lowerName to the lowercase equivalent of name
    
    bool flag = true; //flag to keep track of whether the user has been in the library or not

    for(int n = 0; n < numUsers; n++){ //for loop to run through the users
        string tempName = users[n].getName(); //makes a temporary name that gets updated every iteration 
            if(lowerName == tempName){ //if lowername is equal to temp name...
                cout << "Welcome back, " << name << endl; //welcomes the user back
                currentUseridx = n; //sets currentUseridx to n
                flag = false; //sets flag to false since we found the user in the array
            } 

    }
    if(flag == true){//if the flag is true (the if statement above didn't run, so we didn't find a user in the array, therefor it is a new user)
        cout << "Welcome to the Library, " << name << endl; //welcomes the user to the library 
            User addNewUser; //creates a new user object called addNewUser
                    addNewUser.setName(lowerName); //sets the name of the new user to the lowername 
                    addNewUser.setNumRatings(numBooks);
                    numUsers++;
                    users[numUsers - 1] = addNewUser; //spot j in the users array is set equal to addNewUser
                    currentUseridx = numUsers - 1; //currentUseridx is equal to j
                }
    
    while(playing){ //while playing is true
    
        
        cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl; //prompts the user to enter a choice
        cin >> choice; //cins the input to choice
    
        lowerChoice = tolower(choice); //makes the choice lowercase
    
    
        if(lowerChoice == 'v'){ //if lowerChoice is equal v...
            viewRatings(); //run viewRatings
        }
    
    
        else if(lowerChoice == 'r'){ //else if lowerChoice is r
            rateABook(); //run rateABook
        }
        
        else if(lowerChoice == 'g'){ //else if lowerChoice is g
            getRecs(currentUseridx); //run getRecs at the currentUseridx
        }
        
        else if(lowerChoice == 'q'){ //else if lowerChocice is q
            playing = false; //set playing to false
            quit();
            cout << "Data successfully saved. Goodbye!" << endl; //tell the user the data was saved successfully
        }
        
        else{ //else
            cout << "Please input a valid choice" << endl; //please input a valid choice 
        }
    }
    
}



int main()
{
    
    Library library1; //creates a library 
    
    library1.loadData("books.txt", "ratings.txt"); //load the data from the files
    library1.login(); //run login on the library 
    
    
    
}