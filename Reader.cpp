#include "Reader.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
Reader::Reader(const std::string& readerId) : readerId(readerId) {
    // Load reader's data from file
    ifstream readerFile(readerId + ".txt");
    if (readerFile) {
        int bookId;
        while (readerFile >> bookId) {
            borrowedBooks.push_back(bookId);
        }
        readerFile.close();
    }
}

void Reader::borrowBook(int bookId) {
    // Check if the book exists in the database
    LibrarySystem library("library_db.txt");
    Book* books = library.getBooks();
    int numBooks = library.getNumBooks();
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookId == bookId) {
            // Book found in the database, add it to the reader's borrowed books
            borrowedBooks.push_back(bookId);
            saveData();
            sortBookIds();
            library.removeBook(bookId);//remove from library
            cout << "Book borrowed successfully." << endl;
            return;
        }
    }

    cout << "Book not found in the database." << endl;
}

void Reader::returnBook(int bookId) {
    // Check if the book is borrowed by the reader
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == bookId) {
            // Book found in the reader's borrowed books, remove it
            borrowedBooks.erase(it);
            saveData();
            sortBookIds();
            LibrarySystem library("library_db.txt");
            library.returnBook(bookId);//return to library
            cout << "Book returned successfully." << endl;
            return;
        }
    }

    cout << "Book not borrowed by the reader." << endl;
}

void Reader::printBorrowedBooks() {
    // Print the borrowed books of the reader
    if (borrowedBooks.empty()) {
        cout << "No books borrowed by the reader." << endl;
        return;
    }

    cout << "Borrowed Books: " << endl;
    for (int bookId : borrowedBooks) {
        cout << bookId << endl;
    }
}

void Reader::searchBooks(const std::string& searchTerm) {
    // Search for books by title or author in the database
    LibrarySystem library("library_db.txt");
    Book* books = library.getBooks();
    int numBooks = library.getNumBooks();

    bool found = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookName == searchTerm || books[i].authorName == searchTerm) {
            cout << "Book ID: " << books[i].bookId << endl;
            cout << "Book Name: " << books[i].bookName << endl;
            cout << "Author: " << books[i].authorName << endl;
            cout << "Quantity: " << books[i].quantity << endl;
            cout << "-------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Book not found in the database." << endl;
    }
}

void Reader::saveData() {
    // Save reader's borrowed books to file
    ofstream readerFile(readerId + ".txt");
    if (!readerFile) {
        cout << "Failed to save reader's data." << endl;
        return;
    }

    for (int bookId : borrowedBooks) {
        readerFile << bookId << endl;
    }

    readerFile.close();
}
void Reader::sortBookIds() {
    // Sort the book IDs in ascending order
    sort(borrowedBooks.begin(), borrowedBooks.end());
}

void Reader::clearDatabase() {
    // Clear the reader's database by removing the file
    string filename = readerId + ".txt";
    if (remove(filename.c_str()) != 0) {
        cout << "Failed to clear reader's database." << endl;
    }
    else {
        borrowedBooks.clear();
        cout << "Reader's database cleared successfully." << endl;
    }
}