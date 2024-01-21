#include "book.h"
#include "libraryfunctions.h"

using namespace std;

int main() {
    const int maxBooks = 100;                             //assumes a maximum capacity of 100 books
    Book bookList[maxBooks];
    int bookCount = 0;                                     // starting point

                                                    
    readBooksFile(bookList, bookCount);                     // read books from file

    int choice;
    do {                                                    // loop to repeat menu
       
        displayMenu();                                      // function for displaying menu

        
        cout << "Enter your choice: ";                  // get user choice
        cin >> choice;

        
        switch (choice) {                                   // perform action based on user choice
        case 1:
            listAllBooks(bookList, bookCount);
            break;
        case 2:
            addBook(bookList, bookCount);
            break;
        case 3:
            lookUpBook(bookList, bookCount);
            break;
        case 4:
            generateReport(bookList, bookCount);
            break;
        case 5:
            borrowBook(bookList, bookCount);
            break;
        case 6:
            returnBook(bookList, bookCount);
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice. Please try again.\n";    // if user enters an invalid option it prints an error message
        }
    } while (choice != 7);

   
    updateBookFile(bookList, bookCount);                      // Update the book file before exiting

    return 0;
}
