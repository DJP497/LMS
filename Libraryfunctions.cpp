#include "libraryfunctions.h"


void readBooksFile(Book bookList[], int& bookCount) {
    ifstream inputFile("books.txt");                   // open the file "books.txt" for reading

    if (!inputFile) {                                 // if not open inputfile 
        cout << "Error opening the file 'books.txt'\n"; // prints error message if not able to open file
        return;
    }

    string line;                                     // string to store each line from file
    while (getline(inputFile, line)) {                // loop through each line in file
        stringstream ss(line);                        // treats string line as a line of characters

        string tempTitle, tempAuthor, tempGenre, tempStatus; // stores temporary values
        int tempYear;

        getline(ss, tempTitle, ',');                       // tokenizes the line using commas as the delimiter
        getline(ss, tempAuthor, ',');
        ss >> tempYear;
        ss.ignore();                         //ignores the next character in stream cause its a comma 
        getline(ss, tempGenre, ',');
        getline(ss, tempStatus, ',');

        bookList[bookCount].setTitle(tempTitle);                  // sets values for current book in array
        bookList[bookCount].setAuthor(tempAuthor);
        bookList[bookCount].setYear(tempYear);
        bookList[bookCount].setGenre(tempGenre);
        bookList[bookCount].setAvailabilityStatus(tempStatus[0] == '1');

        bookCount++;                                          // increments bookcount by + 1

        if (bookCount >= 100) {                              // checks if the max amount of books is reached
            cout << "Warning: Maximum capacity of the library reached (100 books).\n"; // prints max book count reached
            break;
        }
    }

    inputFile.close();                                       // close input file
}

void listAllBooks(Book bookList[], int bookCount) {      // function to list details for all books in library
    if (bookCount == 0) {                               // checks if library is empty
        cout << "The library is empty.\n";             // if empty, exits the function
        return;
    }

    for (int i = 0; i < bookCount; ++i) {             // loop through each book in the library
        bookList[i].printBookDetails();              // print details of current book
        cout << "-----------------\n";               // for format
    }
}

void addBook(Book bookList[], int& bookCount) {       //function to add a new book to the library
    string title, author, genre;                      // variables to store book info
    int year;
    cout << "Enter book title: ";             // prompts user to enter a book title after user chooses selected option
    cin.ignore();                             // ignore newline characters left in input buffer
    getline(cin, title);                      // reads line including spaces
    cout << "Enter author: ";                 // prompts user to enter author name
    getline(cin, author);                     
    cout << "Enter year of publication: ";    // prompts user to enter year of publication
    cin >> year;
    cout << "Enter genre: ";                  // prompts user to enter a genre 
    cin.ignore();
    getline(cin, genre);

    
    bookList[bookCount] = Book(title, author, year, genre, true);  // add the book to the array
    bookCount++;

    cout << "Book added successfully.\n";                      
}

void lookUpBook(Book bookList[], int bookCount) {  // function to look up book by a specified criteria
    if (bookCount == 0) {                          // checks if library is empty
        cout << "The library is empty.\n";
        return;
    }

    string criteria, key;                         // variables to store user input
    cout << "Enter the criteria (title, author, year, genre): "; // prompt user to enter search criteria for book
    cin >> criteria;
    cout << "Please enter the " << criteria << ": "; // prompts user to enter search key
    do {
        getline(cin, key);                // ensures key is not empty
    } while (!key.length());

    cout << endl;
    bool found = false;                                                // to track if matching book is found
    for (int i = 0; i < bookCount; ++i) {                              // loop through each book in library
        if (criteria == "title" && bookList[i].getTitle() == key) {       // checks if criteria matches and print details
            bookList[i].printBookDetails();                               // if match is found 
            found = true;
        }
        else if (criteria == "author" && bookList[i].getAuthor() == key) {
            bookList[i].printBookDetails();
            found = true;
        }
        else if (criteria == "year" && bookList[i].getYear() == stoi(key)) { // stoi to convert string key to an int for book year
            bookList[i].printBookDetails();
            found = true;
        }
        else if (criteria == "genre" && bookList[i].getGenre() == key) {
            bookList[i].printBookDetails();
            found = true;
        }
    }

    if (!found) {                                                  // if no books are found 
        cout << "No books found with the specified criteria.\n";   // print no books are found to user
    }
}

void generateReport(Book bookList[], int bookCount) { // function for generating report 
    ofstream outputFile("library_report.txt");        // open output file for writing report

    if (!outputFile) {                               // if not open output file
        cout << "Error creating the file 'library_report.txt'\n";  // prompt error
        return;
    }

    int totalBooks = bookCount;                      // variables for storing stats info in report
    int availableBooks = 0;
    int autobiographies = 0;
    int booksAfter2000 = 0;

    for (int i = 0; i < bookCount; ++i) {           // loops through each book in library to gather stats about book
        if (bookList[i].getAvailabilityStatus() == "Available") {     // checks if book is available
            availableBooks++;
        }

        if (bookList[i].getGenre() == "Autobiography") {    // checks if book genre is autobiography
            autobiographies++;
        }

        if (bookList[i].getYear() > 2000) {                // checks if book was published after the year 2000
            booksAfter2000++;
        }
    }

    
    outputFile << "Total books in the library: " << totalBooks << "\n";      // write the report to the file
    outputFile << "Available books: " << availableBooks << "\n";
    outputFile << "Autobiographies in the library: " << autobiographies << "\n";
    outputFile << "Books published after 2000: " << booksAfter2000 << "\n";

    cout << "Report generated successfully.\n";

    outputFile.close();                                        //closes the output file
}

void borrowBook(Book bookList[], int bookCount) { // function for borrowing a book from library
    if (bookCount == 0) {                        // checks if library is empty
        cout << "The library is empty.\n";
        return;
    }

    string title;                              // variable that will store title of book to be borrowed
    cout << "Enter the title of the book to borrow: ";  // prompt user to enter title of book
    cin.ignore();                                      // ignores newline character in input buffer
    getline(cin, title);                              // get whole line including spaces

    bool found = false;                              // track if book is found
    for (int i = 0; i < bookCount; ++i) {            // loop through each book in library 
        if (bookList[i].getTitle() == title) {      // checks if book title matches input title
            if (bookList[i].getAvailabilityStatus() == "Available") { // checks if book is available
                bookList[i].setAvailabilityStatus(false); // when book is borrowed sets availabilty to "Not available"     
                cout << "Book borrowed successfully.\n";  
            }
            else {
                cout << "Book is not available for borrowing.\n"; // book is not available
            }
            found = true;
            break;                  // breaks loop if book is found            
        }
    }

    if (!found) {                    // if not found
        cout << "Book not found.\n"; // prompt to console book not found
    }
}

void returnBook(Book bookList[], int bookCount) {   // function for returning a book  
    if (bookCount == 0) {                          // check library if empty
        cout << "The library is empty.\n";
        return;
    }

    string title;                                    //variable that will store title of book to be returned
    cout << "Enter the title of the book to return: "; // prompt user to enter title of book to return
    cin.ignore();                                      //ignores newline characters in input buffer
    getline(cin, title);                               // gets whole line including spaces

    bool found = false;                               // track if book is found
    for (int i = 0; i < bookCount; ++i) {            // loop through each book in library
        if (bookList[i].getTitle() == title) {      // checks if book title matches input
            if (bookList[i].getAvailabilityStatus() == "Available") {  // checks if book is available
                cout << "Book is already available. No need to return.\n"; 
            }
            else {
                bookList[i].setAvailabilityStatus(true); // sets availability status to "available" as book is returned
                cout << "Book returned successfully.\n";
            }
            found = true;
            break;                            // break loop since book is found
        }
    }

    if (!found) {                            // if not found
        cout << "Book not found.\n";        // print "book not found"
    }
}

void updateBookFile(const Book bookList[], int bookCount) {  // function to update .txt file with info from booklist array
    ofstream outputFile("books.txt");                       // open output file for writing

    if (!outputFile) {                                     // if not open outputfile
        cout << "Error opening the file 'books.txt'\n";    // prompts an error for attempting to open file
        return;
    }

    for (int i = 0; i < bookCount; ++i) {                 // loop through each book in book list array
        outputFile << bookList[i].getTitle() << ","       // write book info to the file 
            << bookList[i].getAuthor() << ","
            << bookList[i].getYear() << ","
            << bookList[i].getGenre() << ","
            << bookList[i].getAvailabilityStatus() << "\n";
    }

    outputFile.close();                                 // closes the output file
}

void displayMenu() {                                      // function to display menu options to user in console
    cout << "\nLibrary Management System Menu\n";        // display library menu 
    cout << "1. List all books\n";
    cout << "2. Add a book\n";
    cout << "3. Look up a book by criteria\n";
    cout << "4. Generate a report\n";
    cout << "5. Borrow a book\n";
    cout << "6. Return a book\n";
    cout << "7. Exit\n";
}
