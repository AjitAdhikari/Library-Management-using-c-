# Library Management System

## Overview

This Library Management System is a C++ project designed to allow users to manage books in a library. Users can add, issue, return, search, and display books. The system includes basic user authentication and uses object-oriented principles to manage books and users. This project is ideal for learning C++ and object-oriented programming (OOP) concepts such as classes, inheritance, polymorphism, and memory management using smart pointers.

## Features

- User authentication with a username and password.
- Manage books: Add, issue, return, search, and display books.
- Use of smart pointers (`std::shared_ptr`) to manage memory.
- Error handling for invalid operations like issuing or returning a non-existent book.
- Command-line interface with a simple menu for interaction.
  
## Technologies Used

- **Programming Language**: C++
- **Memory Management**: Smart Pointers (`std::shared_ptr`)
- **Error Handling**: Standard error messages and validation
- **Object-Oriented Programming**: Classes, objects, and methods

## Installation

To run this project, you need a C++ compiler. You can use any C++ IDE or compile the code using the terminal.

### Steps to Install

1. **Clone this repository**:
    ```bash
    git clone https://github.com/yourusername/Library-Management-System.git
    cd Library-Management-System
    ```

2. **Compile the code**:
    Use a C++ compiler like `g++`:
    ```bash
    g++ -o library_management_system main.cpp
    ```

3. **Run the application**:
    After compiling, run the application:
    ```bash
    ./library_management_system
    ```

## Usage

1. **Login**: Enter the username and password to access the library system.
   - Default credentials:
     - Username: `Root`
     - Password: `Admin@123`

2. **Menu Options**:
   - **Add Book**: Add a new book to the system by providing an ID, title, and author.
   - **Issue Book**: Issue a book by entering its ID. A book can only be issued if it is available.
   - **Return Book**: Return a previously issued book using its ID.
   - **Search Book**: Search for books by title or author. Enter a keyword, and the system will display matching books.
   - **Display Books**: View all books in the library along with their status (issued or available).
   - **Logout**: Log out from the system to end the session.

3. **Exit**: The program will continue running until the user logs out.

## Code Structure

### Classes:
- **Book**: Represents a book with attributes like ID, title, author, and issued status.
- **Library**: Manages a collection of books and operations such as adding, issuing, returning, and searching for books.
- **User**: Handles the user login/logout functionality.

### Key Functions:
- `addBook()`: Adds a new book to the library.
- `issueBook()`: Issues a book to a user if available.
- `returnBook()`: Returns an issued book.
- `searchBook()`: Searches for books based on a keyword (title or author).
- `displayBooks()`: Displays all books in the library with their status.

## Performance

- The system performs operations like adding, issuing, and returning books efficiently using a vector of shared pointers.
- Book search and display operations are optimized using linear search.

## Planned Improvements

- **Advanced User Authentication**: Implement a more secure login system with encrypted passwords.
- **Book Details Enhancement**: Include more book details (e.g., genre, publication year).
- **Database Integration**: Save book data to a file or database for persistence.
- **Graphical User Interface (GUI)**: Develop a GUI for better user experience.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch (feature-branch).
3. Commit your changes.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See LICENSE for details.

## Contact

For any questions or collaboration opportunities, feel free to reach out via [your email/contact].
