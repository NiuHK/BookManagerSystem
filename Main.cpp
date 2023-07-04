#include <iostream>
#include "Reader.h"
using namespace std;
int main() {

    LibrarySystem library1("library_db.txt");
    library1.clearDatabase();
     library1.addBook("Book1", "Author1", 5,1020);
    library1.addBook("Book2", "Author2", 3,1001);
    library1.addBook("Book3", "Author3", 2,1002);
    library1.printDatabase();
    cout << endl;

    Reader reader1("0000");
    reader1.borrowBook(1);
    reader1.borrowBook(3);
    reader1.printBorrowedBooks();
    reader1.clearDatabase();
    reader1.printBorrowedBooks();
    cout << endl;
    library1.printDatabase();

    return 0;
}


