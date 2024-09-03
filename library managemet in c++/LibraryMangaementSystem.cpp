#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

    Book(int id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author), isIssued(false) {}

    void display() const {
        std::cout << "ID: " << id 
                  << ", Title: " << title 
                  << ", Author: " << author 
                  << ", Issued: " << (isIssued ? "Yes" : "No") 
                  << "\n";
    }
};

class Library {
private:
    std::vector<std::shared_ptr<Book>> books;

    std::shared_ptr<Book> findBook(int id) {
        auto it = std::find_if(books.begin(), books.end(), [id](const std::shared_ptr<Book>& book) {
            return book->id == id;
        });
        if (it != books.end()) {
            return *it;
        }
        return nullptr;
    }

public:
    void addBook(int id, const std::string& title, const std::string& author) {
        if (findBook(id)) {
            std::cerr << "Error: Book with ID " << id << " already exists.\n";
            return;
        }
        books.push_back(std::make_shared<Book>(id, title, author));
        std::cout << "Book added: " << title << " by " << author << "\n";
    }

    void issueBook(int id) {
        auto book = findBook(id);
        if (!book) {
            std::cerr << "Error: Book not found.\n";
            return;
        }
        if (book->isIssued) {
            std::cerr << "Error: Book is already issued.\n";
        } else {
            book->isIssued = true;
            std::cout << "Book issued: " << book->title << "\n";
        }
    }

    void returnBook(int id) {
        auto book = findBook(id);
        if (!book) {
            std::cerr << "Error: Book not found.\n";
            return;
        }
        if (!book->isIssued) {
            std::cerr << "Error: Book was not issued.\n";
        } else {
            book->isIssued = false;
            std::cout << "Book returned: " << book->title << "\n";
        }
    }

    void searchBook(const std::string& keyword) {
        std::vector<std::shared_ptr<Book>> foundBooks;
        for (const auto& book : books) {
            if (book->title.find(keyword) != std::string::npos || book->author.find(keyword) != std::string::npos) {
                foundBooks.push_back(book);
            }
        }

        if (foundBooks.empty()) {
            std::cout << "No books found for keyword: " << keyword << "\n";
        } else {
            std::cout << "Books found:\n";
            for (const auto& book : foundBooks) {
                book->display();
            }
        }
    }

    void displayBooks() const {
        if (books.empty()) {
            std::cout << "No books in the library.\n";
            return;
        }
        for (const auto& book : books) {
            book->display();
        }
    }
};

class User {
private:
    const std::string username = "Root";
    const std::string password = "Admin@123";
    bool loggedIn = false;

public:
    bool login(const std::string& user, const std::string& pass) {
        if (user == username && pass == password) {
            loggedIn = true;
            std::cout << "Login successful. Welcome, " << username << "!\n";
            return true;
        } else {
            std::cerr << "Error: Invalid username or password.\n";
            return false;
        }
    }

    void logout() {
        if (loggedIn) {
            loggedIn = false;
            std::cout << "Logout successful. Goodbye!\n";
            std::cout<<"Thank you for choosing us ";
        } else {
            std::cerr << "Error: No user is currently logged in.\n";
        }
    }

    bool isLoggedIn() const {
        return loggedIn;
    }
};

int main() {
    User user;
    Library library;
    int choice, id;
    std::string title, author, keyword, username, password;

    // User login
    do {
        std::cout<<"Develop by Ajit Adhikari\n ";
        std::cout<<"Username and password will written on line 110 and 111 thank you \n ";
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
    } while (!user.login(username, password));

    do {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Issue Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Search Book\n";
        std::cout << "5. Display Books\n";
        std::cout << "6. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter book ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                std::cout << "Enter book ID to issue: ";
                std::cin >> id;
                library.issueBook(id);
                break;

            case 3:
                std::cout << "Enter book ID to return: ";
                std::cin >> id;
                library.returnBook(id);
                break;

            case 4:
                std::cout << "Enter title to search: ";
                std::cin.ignore();
                std::getline(std::cin, keyword);
                library.searchBook(keyword);
                break;

            case 5:
                library.displayBooks();
                break;

            case 6:
                user.logout();
                break;

            default:
                std::cerr << "Error: Invalid choice. Please try again.\n";
        }
    } while (user.isLoggedIn());

    return 0;
}
