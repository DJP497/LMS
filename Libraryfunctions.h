#ifndef LIBRARY_FUNCTIONS_H
#define LIBRARY_FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <sstream>

#include "book.h"

using namespace std;

void readBooksFile(Book bookList[], int& bookCount); // reads book info from file and store it in book array
void listAllBooks(Book bookList[], int bookCount);  //  prints information of all books in the library
void addBook(Book bookList[], int& bookCount);     // user is able to add a book to the book array
void lookUpBook(Book bookList[], int bookCount);  // user is able to look up a book by specific criteria and prints info of matching books
void generateReport(Book bookList[], int bookCount); // generate a report to "library_report.txt"
void borrowBook(Book bookList[], int bookCount); // find a book by title and update the availability to false
void returnBook(Book bookList[], int bookCount); // find a book by title and update the availability to true
void updateBookFile(const Book bookList[], int bookCount); // update the value with new values of the books     
void displayMenu();                                     

#endif // LIBRARY_FUNCTIONS_H

