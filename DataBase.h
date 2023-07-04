//ʵ��txt���ݿ⣬ LibrarySystem library1("libary_db3.txt")��libary_db3.txtΪ���ݿ�·����ʵ��һ���������ݿ⡣
#include <string>

struct Book {
    std::string bookName;
    std::string authorName;
    int year;
    int quantity;
    int bookId;
};

class LibrarySystem {
public:
    LibrarySystem(const std::string& path);
    void addBook(const std::string& bookName, const std::string& authorName, int quantity, int year); //Change the structure
    void removeBook(const int& bookID);
  //  void removeBook(const string& bookName);
  //  void returnBook(const string& bookName);
    void returnBook(const int& bookID);
    void searchBook(const std::string& bookName);
    void printDatabase(); //Change the structure
    void clearDatabase();
    Book* findBookById(int bookId);
    Book* getBooks(); 
    int getNumBooks(); 

private:
    std::string databaseFileName;
    int numBooks;
    Book* books;
    int getNextBookId();
    void loadDatabase();//Change the structure
    void saveDatabase();// //Change the structure
};
