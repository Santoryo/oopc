#include "employee.h"													// Defines class Employee
#include "map.h"														// Defines template Map<Key, Value>
#include <iostream>
#include "book.h"

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);
void addDuplicateEmployee(Database& database);
void findNonExistentKey(Database& database);
void testEmployees();

typedef string Title;
typedef Map<Title, Book> Library;

void addBooks(Library& library);
void makeBookAvailable(Library& library, Title title);
void addDuplicateBook(Library& library);
void testCopy(Library& lib);
void testLibrary();

int main() {
	cout << boolalpha;
	testEmployees();
	testLibrary();

};

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}


void addDuplicateEmployee(Database& database)
{
	try
	{
		database.add(510212881, Employee("Adam Nowak", "secretary", 55));
	}
	catch(...)
	{
		cout << "Duplicates cannot be added" << endl;
	}
}

void findNonExistentKey(Database& database)
{
	cout << "Testing key finding" << endl;
	int arr[3] = {1231321, 510212881, 761028073};

	for(int i = 0; i < 3; i++)
	{
		Employee* test = database.find(arr[i]);
		cout << "Looking for key " << arr[i] << endl;
		if(test == nullptr)
		{
			cout << "The key doesnt exist" << endl;
		}
		else
		{
			cout << arr[i] << ": " << *test << endl;
		}
	}
}

void addBooks(Library& library)
{
	library.add("Harry Potter", Book("J. K. Rowling", "fantasy", 300, false));
	library.add("1984", Book("George Orwell", "dystopian", 350, true));
	library.add("Hobbit", Book("J. R. R. Tolkien", "fantasy", 320, true));
}

void makeBookAvailable(Library& library, Title title)
{
	Book* bookPtr;
	bookPtr = library.find(title);

	if(bookPtr == nullptr)
	{
		cout << "The book '" << title << "' doesn't exist in Library Database" << endl;
	}
	else
	{
		cout << "Book '" << title << "' has been updated (availability false -> true)" << endl;
		bookPtr->isAvailable = true;
	}
}

void addDuplicateBook(Library& library)
{
	try
	{
		library.add("Hobbit", Book("J. R. R. Tolkien", "fantasy", 320, true));
		cout << "Added Hobbit" << endl;
	}
	catch(...)
	{
		Book* bookPtr = library.find("Hobbit");
		cout << "Duplicates cannot be added, the book exists: " << *bookPtr << endl;
	}
}

void testCopy(Library& library)
{
	Library copy(library);
	cout << "Copied library: "<< endl;
	cout << copy << endl;
}

void testEmployees()
{
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;

	addDuplicateEmployee(database);
	findNonExistentKey(database);

}


void testLibrary()
{
	cout << endl;
	Library lib;
	addBooks(lib);
	Library newLib = lib;
	newLib.add("Lord of The Rings", Book("J. R. R. Tolkien", "fantasy", 1178, false));
	makeBookAvailable(newLib, "Hobbit");
	makeBookAvailable(lib, "Romeo and Juliet");

	cout << "Original library: " << endl << lib << endl;
	cout << "New modified library: " << endl << newLib << endl;

	lib = newLib;

	cout << "Library after the assigment: " << endl << lib << endl;

	addDuplicateBook(lib);
	testCopy(lib);

}