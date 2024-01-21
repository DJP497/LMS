#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book {                                   // declares book class                 
private:
    string title;                               // instance variables are set to private
    string author;
    int year;
    string genre;
    bool available;

public:
    Book() = default;                         // default constructor
    Book(string title, string author, int year, string genre, bool available); // paremeterized constructor

    string getTitle() const;                      // accessor functions also called the getters; gets book info
    string getAuthor() const;
    int getYear() const;              
    string getGenre() const;
    string getAvailabilityStatus() const;

    void setTitle(string newTitle);                   // mutator functions also called the setters; modifies book info 
    void setAuthor(string newAuthor);                     
    void setYear(int newYear);
    void setGenre(string newGenre);
    void setAvailabilityStatus(bool newAvailability);

    void printBookDetails() const;                    // function to output details of book
};


#endif // BOOK_H
