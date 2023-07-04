#pragma once
//ʵ��txt���ݿ⣬ LibrarySystem library1("libary_db3.txt")��libary_db3.txtΪ���ݿ�·����ʵ��һ���������ݿ⡣

#include"globals.h"
using namespace std;



    bool addBook(const std::string& bookName, const std::string& authorName, int quantity, int year); //Change the structure
    bool addBook(const int bookID);
    void removeBook(const int bookID);
    //  void removeBook(const string& bookName);
    //  void returnBook(const string& bookName);
   // void returnBook(const int bookID);
    void searchBook(const std::string& bookName);
    void printDatabase(); //Change the structure
    void clearDatabase();
    Book* findBookById(int bookId);
    Book* getBooks();
    int getNumBooks();
   bool printSimpleItem(int bookId); //Change the structure//ͨ��bookId������Ϣ
    int getNextBookId();
    void loadDatabase();//Change the structure
    void saveDatabase();// //Change the structure