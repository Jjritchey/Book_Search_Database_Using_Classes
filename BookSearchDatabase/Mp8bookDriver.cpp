//Justin Ritchey, 7/25/2020 Machine Problem 8. This program is desigined to read a list of books into an array. Then simulate a search using ISBN's to find those books in the array.

#include "book.h"                                               //including he header file
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int main()
{
    
    Book book[10];                                          //creating 10 spot array to hold book's
    ifstream FileArray;                                     //opening file that has the books for the array
    FileArray.open("mp8bookarray.txt");      
    ifstream ISBNfile;                                      //Opening file with ISBN's to search for
    ISBNfile.open("mp8bookISBN.txt");
    ofstream BookSearch;                                    //creating output file tol hold the cout values
    BookSearch.open("BookSearchOutput.txt");
    
   
    for (int i = 0;i < 10;i++)
    {
        book[i].GetData(FileArray);                         //assining bookarray.txt to the array using the getdata function in book.cpp
    }
    
    
    for (int i = 0;i < 10;i++)
    {
        book[i].Print(BookSearch);                         //printing out the array of books using the print fucntion in book.cpp
    }

    cout << "\n";                                          //spacing between the database and the ISBN lookup
    BookSearch << "\n";
    cout << "Searching the Database using the given ISBN: \n\n";    
    BookSearch << "Searching the Database using the given ISBN: \n\n";
    
    while (!ISBNfile.eof())                                //loop to search the array using the ISBN file
    {
        
        long ISBNnumber = 0;                               //Holds the ISBN number from the file being searched for    
        string text = "";                                  //Holds the ISBN number in string format

        if (ISBNfile.is_open())
        {
            getline(ISBNfile, text);                       //getting the ISBN to check in string format
            ISBNnumber = atol(text.c_str());               //converting the ISBN from a string to a long int
        }                                
       
        int counter = 0;                                   //Using counter to find if the ISBN is in the database or not

        while (counter <= 10)                              //starting loop to search through the array for the given ISBN number
        {
            if (book[counter].GetISBN() == ISBNnumber)     //Calling the function getisbn on the array to see if it matches
            {
                cout << "The ISBN: " << ISBNnumber << ", has been found in our database: \n";
                BookSearch << "The ISBN: " << ISBNnumber << ", has been found in our database: \n";

                book[counter].Print(BookSearch);          
                break;
            }

            else if (book[counter].GetISBN() != ISBNnumber)    //if they don't match, add one to the counter to check next array value
            {
                counter++;
            }

            if (counter == 10)                                 //if the counter gets to 10 then the book in not in the collection
            {
                cout << "The ISBN: " << ISBNnumber << ", could not be found in our collection \n\n";
                BookSearch << "The ISBN: " << ISBNnumber << ", could not be found in our collection \n\n";
            }
        }
    }
    return 0;
}