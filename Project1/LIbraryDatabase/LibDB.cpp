#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book 
{
    string title;
    vector<string> authors;
    string catalogNumber;
    vector<string> subjects;
    string publisher;
    int yearOfPublication;
    bool isCirculating;
};

struct LibraryT 
{
    vector<Book> books;
};

void AddBook(LibraryT&);
void SearchBySubject(const LibraryT& , const  string&);
void DisplayAllBooks(const LibraryT&);

int main() 
{
    LibraryT libdata;
    
    libdata.books = 
    {
    {"The C++ Programming Language", {"Bjarne Stroustrup"}, "0321992784", {"Programming", "C++"}, "Addison-Wesley", 2013, true},
    {"Effective C++: 55 Specific Ways to Improve Your Programs and Designs", {"Scott Meyers"}, "0321334876", {"Programming", "C++"}, "Addison-Wesley", 2005, true},
    {"C++ Primer", {"Stanley B. Lippman", "Josée Lajoie", "Barbara E. Moo"}, "0321992784", {"Programming", "C++"}, "Addison-Wesley", 2012, true},
    {"C++ Concurrency in Action", {"Anthony Williams"}, "1617294698", {"Programming", "C++"}, "Manning Publications", 2019, true},
    {"The C++ Standard Library: A Tutorial and Reference", {"Nicolai M. Josuttis"}, "0321623215", {"Programming", "C++"}, "Addison-Wesley", 2012, true}
    };

    while (true) 
    {
        int choice;
        cout << "\nLibrary Catalog System\n";
        cout << "1. Add a new book\n";
        cout << "2. Search by subject\n";
        cout << "3. Display all books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: " << endl, cin >> choice;;
        
        switch (choice) 
        {
            case 1:
                AddBook(libdata);
                break;
            case 2: 
            {
                string subject;
                cout << "Enter subject to search: ";
                getline(cin >> ws, subject);
                SearchBySubject(libdata, subject);
                break;
            }
            case 3:
                DisplayAllBooks(libdata);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}

void AddBook(LibraryT& library) 
{
    Book newBook;
    cout << "Enter book title: ";
    getline(cin >> ws, newBook.title);
    
    cout << "Enter up to 5 authors (enter 'done' when finished):\n";
    for (int i = 0; i < 5; ++i) 
    {
        string author;
        getline(cin >> ws, author);
        if (author == "done") break;
        newBook.authors.push_back(author);
    }
    
    cout << "Enter catalog number: ";
    getline(cin >> ws, newBook.catalogNumber);
    
    cout << "Enter up to 5 subject headings (enter 'done' when finished):\n";
    for (int i = 0; i < 5; ++i) 
    {
        string subject;
        getline(cin >> ws, subject);
        if (subject == "done") break;
        newBook.subjects.push_back(subject);
    }
    
    cout << "Enter publisher: ";
    getline(cin >> ws, newBook.publisher);
    
    cout << "Enter year of publication: ";
    cin >> newBook.yearOfPublication;
    
    cout << "Is the book circulating? (1 for yes, 0 for no): ";
    cin >> newBook.isCirculating;
    
    library.books.push_back(newBook);
}

void SearchBySubject(const LibraryT& library, const string& subject) 
{
    for (const auto& book : library.books) 
    {
        bool subjectFound = false;
        
        for (const auto& subj : book.subjects) 
        {
            if (subj == subject) 
            {
                subjectFound = true;
                break;
            }
        }

        if (subjectFound) 
        {
            cout << "Title: " << book.title << endl ;
            cout << "First Author: " << (book.authors.empty() ? "N/A" : book.authors[0]) << endl ;
            cout << "Catalog Number: " << book.catalogNumber << "\n\n";
        }
    }
}


void DisplayAllBooks(const LibraryT& library) 
{
    for (const auto& book : library.books) 
    {
        cout << "Title: " << book.title << endl ;
        cout << "Authors: ";
        
        for (const auto& author : book.authors) 
        {
            cout << author << (author == book.authors.back() ? "" : ", ");
        }
        
        cout << "\nCatalog Number: " << book.catalogNumber << endl ;
        cout << "Subjects: ";
        
        for (const auto& subject : book.subjects) 
        {
            cout << subject << (subject == book.subjects.back() ? "" : ", ");
        }
        
        cout << "\nPublisher: " << book.publisher << endl ;
        cout << "Year of Publication: " << book.yearOfPublication << endl ;
        cout << "Is Circulating: " << (book.isCirculating ? "Yes" : "No") << endl ;
        cout << "----------------------------------------"<< endl;
    }
}
