#include <iostream>

using namespace std;

class Book {
private:
    string title, author, ISBN, dateAdd;
    bool availability;

public:
    // Constructor
    Book() {}
    Book(string t, string a, string i, string d, bool avail) 
        : title(t), author(a), ISBN(i), dateAdd(d), availability(avail) {}

    // Set Book Details
    void setBookDetails(string t, string a, string i, string d, bool avail) {
        title = t;
        author = a;
        ISBN = i;
        dateAdd = d;
        availability = avail;
    }

    // Display Book Details
    void displayBookDetails() {
        cout << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nISBN: " << ISBN
             << "\nDate Added: " << dateAdd
             << "\nAvailability: " << (availability ? "Available" : "Borrowed") 
             << endl;
    }

    // Borrow Book
    bool borrowBook() {
        if (availability) {
            availability = false;
            cout << "\n✅ Book borrowed successfully!\n";
            return true;
        } else {
            cout << "\n❌ Sorry, this book is already borrowed.\n";
            return false;
        }
    }

    // Return Book
    void returnBook() {
        if (!availability) {
            availability = true;
            cout << "\n✅ Book returned successfully!\n";
            cout << "\n This book available now\n";
           
        } else {
            cout << "\n⚠️ This book is already available.\n";
        }
    }

    // Get ISBN for sorting and searching
    string getISBN() const {
        return ISBN;
    }

    // Check Availability
    bool isAvailable() const {
        return availability;
    }
};

// **Selection Sort Function**
void selectionSort(Book arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].getISBN() < arr[minIdx].getISBN()) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// **Display the list of books**
void displayAllBooks(Book arr[], int size) {
    cout << "\n📚 Library Book List:\n";
    for (int i = 0; i < size; i++) {
        arr[i].displayBookDetails();
        cout << "---------------------------\n";
    }
}

int main() {
    //An array with 5 books
    Book library[5] = {

        Book("1984", "George Orwell", "1234567890", "2023-01-01",true),
        Book("To Kill a Mockingbird", "Harper Lee", "0987654321", "2023-01-02", true),
        Book("The Great Gatsby", "F. Scott Fitzgerald", "1122334455","2023-01-03", true),
        Book("Moby Dick", "Herman Melville", "2233445566","2023-01-04",true),
        Book("War and Peace", "Leo Tolstoy", "3344556677", "2023-01-05", true)
    };

    // **Sort the array using Selection Sort**
    selectionSort(library, 5);

    // **Display the sorted book list**
    displayAllBooks(library, 5);

    while (true) {
        int choice;
        cout << "\n Choose an option:\n";
        cout << "1️ Borrow a book\n";
        cout << "2️ Return a book\n";
        cout << "3️ Show book list\n";
        cout << "0️ Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        string isbn;
        cout << "\n Enter ISBN: ";
        cin >> isbn;

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == isbn) {
                found = true;
                if (choice == 1) {
                    library[i].borrowBook();
                } else if (choice == 2) {
                    library[i].returnBook();
                }
                break;
            }
        }

        if (!found) {
            cout << "\n⚠️ Book not found.\n";
        }

        if (choice == 3) {
            displayAllBooks(library, 5);
        }
    }

    return 0;
}
