#include<iostream>
using namespace std;
string arr1[10], arr2[10]; int arr3[10];
void add(string x, string y, int z,int counter) {
	if (counter > 10) { cout << "no more space"; }
	arr1[counter] = x;
	arr2[counter] = y;
	arr3[counter] = z;
} // using a function to store the book's info
void list(int counter) {
		for (int i = 0;i < counter;i++) {
			if (arr1[i] == "deleted") {
				continue;
			}
			cout << arr1[i] << " by " << arr2[i] << "  (" << arr3[i] << ")\n";
		}// printing all the books 
	
}
void search(string x,int counter) {
	int checking=0;
	for (int i=0; i < counter+1 ;i++) {
		if (arr1[i] == "deleted") {
			continue;
		}
	    if (x == arr1[i]) {
			cout << arr1[i] << " by " << arr2[i] << "  (" << arr3[i] << ")";
			++checking;
		}
	}
	if (checking == 0) {
		cout << "couldn't find it \n";
	}
}
void deletee(string x,int counter) {
	for(int i=0;i<counter+1;i++)
		if (x == arr1[i]) {//making sure the search function won't find this book even thoug it is not actually deleted
			arr1[i] = "deleted";
			arr2[i] = "null";
	}
}
void counting(string x, int counter) {
	int n_of_books=0;
	for (int i = 0;i < counter+1;i++) {
		if (arr2[i] == x) {
			n_of_books += 1;
		}
	}
	cout << n_of_books;
}
	int main() {
	string book_name, author_name;
	int year, x,counter=0;
	const int max = 10;
		while (true) {
			cout << "\n== Digital Bookshelf Menu ==\n";
			cout << "1 - Add a new book\n";
			cout << "2 - List all books\n";
			cout << "3 - Search for a book by title\n";
			cout << "4 - Delete a book\n";
			cout << "5 - Count books by an author\n";
			cout << "6 - Exit\n";
			cout << "Enter your choice: ";
			cin >> x;
			switch (x) { // asking what the user want to do
			case 1:
				cout << "please enter the title of the book:\n";
				cin >> book_name;
				cout << "please enter the author's name:\n ";
				cin >> author_name;
				cout << "please enter the year";
				cin >> year;
				add(book_name, author_name, year, counter);
				counter += 1;// trying to know how many books to decide how many time the loop will run
				cout << "book was added successfully!!";
				break;
			case 2:
				if (counter == 0) {
					cout << "you didn't add any book yet\n";
					break;
				}
				list(counter);
				break;
			case 3:
				if (counter == 0) {
					cout << "you didn't add any book yet\n";
					break;
				}
				cout << "please enter the book's title:";
				cin >> book_name;
				search(book_name, counter);
				break;
			case 4:
				if (counter == 0) {
					cout << "you didn't add any book yet\n";
					break;
				}
				cout << "please enter the book's title:";
				cin >> book_name;
				deletee(book_name, counter);
				cout << "book was deleted successfully!!";
				break;
			case 5:
				if (counter == 0) {
					cout << "you didn't add any book yet\n";
					break;
				}
				cout << "please enter the author's name:";
				cin >> author_name;
				counting(author_name, counter);
				break;
			case 6:
				return 0;
			}
		}
	}
