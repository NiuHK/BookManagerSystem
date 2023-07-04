#ifndef READER_H
#define READER_H
#include "DataBase.h"
#include <string>
#include <vector>

class Reader {
public:
    Reader(const std::string& readerId);
    void borrowBook(int bookId);
    void returnBook(int bookId);
    void printBorrowedBooks();//Change the structure
    void searchBooks(const std::string& searchTerm);
    void saveData();
    void sortBookIds();
    void clearDatabase();
private:
    std::string readerId;
    std::vector<int> borrowedBooks;
};

#endif  // READER_H
