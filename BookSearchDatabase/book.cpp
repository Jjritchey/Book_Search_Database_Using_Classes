#include "book.h"                                               //including he header file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

Book::Book()                                                     //default constructor   
{
    author = "No Name";                                          //Setting author name 
    title = "Unknown Title";                                     //Setting booktitles name
    ISBN = 0;                                                    //Setting ISBN 
} 

void Book::GetData(ifstream& FileArray)                         //Creating a function to get the ISBN, title and author nams into variables of the file
{
    string text = "";                                           //hold the string value for the ISBN before converting
    int counter = 0;                                            //counter to continue the loop until the file is complete


    if (FileArray.good()) getline(FileArray, author);
    {
        for (int i = 0;i < counter;i++)

        getline(FileArray, author);                              //assinging authors name to variable
        getline(FileArray, title);                               //assinging book's title to variable
        
        getline(FileArray, text);                                //grabbing the ISBN from the string and then converting to a long int
        ISBN = atol(text.c_str());

        counter++;
    }
}


const long Book::GetISBN()
{
    return ISBN;                                              //sending the ISBN number back when called
}

const void Book::Print(ofstream& BookSearch)                  //Making a print fucntiont to be called to print out the book detials
{

    cout << "Author  : " << left << author << endl;           //formatting
    BookSearch << "Author  : " << left << author << endl;
    cout << "Title   : " << left << title << endl;
    BookSearch << "Title   : " << left << title << endl;
    cout << "ISBN    : " << left << ISBN << endl;
    BookSearch << "ISBN    : " << left << ISBN << endl;
    cout << "\n";
    BookSearch << "\n";
}