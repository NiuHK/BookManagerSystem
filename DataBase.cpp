#include "DataBase.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

LibrarySystem::LibrarySystem(const std::string& path) {
    databaseFileName = path;
    loadDatabase();
}

void LibrarySystem::addBook(const std::string& bookName, const std::string& authorName, int quantity, int year) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookName == bookName) {
            // 图书已存在，增加数量
            books[i].quantity += quantity;
            saveDatabase();
            return;
        }
    }

    // 图书不存在，添加新条目
    int bookId = getNextBookId();

    // 扩展数组大小
    Book* newBooks = new Book[numBooks + 1];
    for (int i = 0; i < numBooks; i++) {
        newBooks[i] = books[i];
    }
    delete[] books;
    books = newBooks;

    // 添加新图书
    books[numBooks].bookName = bookName;
    books[numBooks].authorName = authorName;
    books[numBooks].quantity = quantity;
    books[numBooks].bookId = bookId;
    books[numBooks].year = year;
    numBooks++;

    saveDatabase();
}

void LibrarySystem::removeBook(const int & bookID) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookId == bookID) {
            // 图书存在，减少数量
            books[i].quantity--;
            if (books[i].quantity <= 0) {
                // 数量减少为零时，从数组中删除
                for (int j = i; j < numBooks - 1; j++) {
                    books[j] = books[j + 1];
                }
                numBooks--;
            }
            saveDatabase();
            cout << "Book removed (lib) successfully." << endl;
            return;
        }
    }
    cout << "Book not found in the database." << endl;
}
//void LibrarySystem::removeBook(const string& bookName) {
//    for (int i = 0; i < numBooks; i++) {
//        if (books[i].bookName == bookName) {
//            // 图书存在，减少数量
//            books[i].quantity--;
//            if (books[i].quantity <= 0) {
//                // 数量减少为零时，从数组中删除
//                for (int j = i; j < numBooks - 1; j++) {
//                    books[j] = books[j + 1];
//                }
//                numBooks--;
//            }
//            saveDatabase();
//            return;
//        }
//    }
//    cout << "Book not found in the database." << endl;
//}
void LibrarySystem::returnBook(const int& bookID) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookId== bookID) {
            // 图书存在，减少数量
            books[i].quantity--;
                numBooks--;
            }
            saveDatabase();
            return;
        }
  cout << "Book not found in the database." << endl;
    }
   
    


void LibrarySystem::printDatabase() {
    loadDatabase();//输出前先从库初始化
    cout << "----- Database -----" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Book ID: " << books[i].bookId << endl;
        cout << "Book Name: " << books[i].bookName << endl;
        cout << "Author: " << books[i].authorName << endl;
        cout << "Quantity: " << books[i].quantity << endl;
        cout << "Publish Year: " << books[i].year << endl;
        cout << "-------------------" << endl;
    }
    cout << "----- End of Database -----" << endl;
}

void LibrarySystem::clearDatabase() {
    delete[] books;
    books = nullptr;
    numBooks = 0;
    saveDatabase();
}

int LibrarySystem::getNextBookId() {
    int maxId = 0;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookId > maxId) {
            maxId = books[i].bookId;
        }
    }
    return maxId + 1;
}

void LibrarySystem::loadDatabase() {
    ifstream databaseFile(databaseFileName);
    if (!databaseFile) {
        cout << "Database file not found. Creating a new database." << endl;
        books = nullptr;
        numBooks = 0;
        return;
    }

    // 获取文件中的图书数量
    string line;
    getline(databaseFile, line);
    stringstream ss(line);
    ss >> numBooks;

    // 分配图书数组的内存
    books = new Book[numBooks];

    // 读取每本图书的信息
    for (int i = 0; i < numBooks; i++) {
        getline(databaseFile, line);
        stringstream ss(line);
        ss >> books[i].bookId >> books[i].bookName >> books[i].authorName >> books[i].quantity>> books[i].year;
    }

    databaseFile.close();
}

void LibrarySystem::saveDatabase() {
    ofstream databaseFile(databaseFileName);
    if (!databaseFile) {
        cout << "Failed to save database." << endl;
        return;
    }

    // 写入图书数量
    databaseFile << numBooks << endl;

    // 写入每本图书的信息
    for (int i = 0; i < numBooks; i++) {
        databaseFile << books[i].bookId << " " << books[i].bookName << " " << books[i].authorName << " " << books[i].quantity << " "<< books[i].year <<endl;
    }

    databaseFile.close();
}


void LibrarySystem::searchBook(const std::string& searchQuery) {
    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookName == searchQuery || books[i].authorName == searchQuery) {
            std::cout << "Book ID: " << books[i].bookId << std::endl;
            std::cout << "Book Name: " << books[i].bookName << std::endl;
            std::cout << "Author: " << books[i].authorName << std::endl;
            std::cout << "Quantity: " << books[i].quantity << std::endl;
            std::cout << "-------------------------" << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Book not found in the database." << std::endl;
    }
}

Book* LibrarySystem::findBookById(int bookId) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookId == bookId) {
            return &books[i];
        }
    }
    return nullptr;
}
Book* LibrarySystem::getBooks() {
    return books;
}

int LibrarySystem::getNumBooks() {
    return numBooks;
}
