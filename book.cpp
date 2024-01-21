#include "book.h"
                       // parameterized constructor to set book object with values
Book::Book(string title, string author, int year, string genre, bool available)
    : title(title), author(author), year(year), genre(genre), available(available) {}

string Book::getTitle() const { return title; }        // getters for retrieving information about a book; title

string Book::getAuthor() const { return author; }      // gets author

int Book::getYear() const { return year; }            // gets the year of book

string Book::getGenre() const { return genre; }        // gets the genre

string Book::getAvailabilityStatus() const { return (available ? "Available" : "Not Available"); } // if available is true
                                                                                             // return available otherwise not available
void Book::setTitle(string newTitle) { title = newTitle; }  // updates title with new value

void Book::setAuthor(string newAuthor) { author = newAuthor; } // updates author with new value

void Book::setYear(int newYear) { year = newYear; }           // updates year with new value

void Book::setGenre(string newGenre) { genre = newGenre; }  // updates genre with new value

void Book::setAvailabilityStatus(bool newAvailability) { available = newAvailability; } // updates book availability status

void Book::printBookDetails() const {                                           // prints book details
    cout << "Title: " << title << "\nAuthor: " << author << "\nYear: " << year
        << "\nGenre: " << genre << "\nAvailability: " << getAvailabilityStatus() << "\n";
}
