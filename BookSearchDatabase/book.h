#define BOOK_H
#include <iostream>
#include <string>
#include <iomanip>


//#include "book.h"
using namespace std;
class Book                                   //creating the class
{

public:
    long ISBN;                               //creating a long int to hold the ISBN number
    string author;                           //string to hold the Authors name
    string title;                            //stream to hold the book's title.
    

public:
    
    Book();                                  //Default constructor
    const void Print(ofstream&);             //calling the print function from book.cpp
    void GetData(ifstream&);                 //calling the funciton from book.cpp to assign the ISBN, Author and titles from the file
    const long GetISBN();                    //function to grab the ISBN from book.cpp

};