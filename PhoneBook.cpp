
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Contact {
	string firstname;
	string lastname;
	string number;

};
bool compareFunction(Contact a, Contact b) { return a.lastname < b.lastname; }


class PhoneBook {
	vector<Contact> List;
public:
	void addRecord(string first, string last, string num) {
		List.push_back({ first, last, num });
		sort(List.begin(), List.end(), compareFunction);
	}
	void removeRecord(int x) {
		cout << List[x].firstname << " " << List[x].lastname << " is successfully deleted.\n";
		List.erase(List.begin() + x);
	}
	void printlist() {
		for (int x = 0; x < List.size(); x++) {
			cout << x+1 << " - " << List[x].firstname << " " << List[x].lastname << ": " << List[x].number << "\n";
		}
	}
	void exit() {
		List.clear();
	}

};

int main()
{
	PhoneBook theBook;
	cout << "Welcome to your phonebook,";
	int run = 1;
	while (run) {
		int i;
		string first;
		string last;
		string number;
		int x;
		cout << "\nWhat do you want to do?\n1 - Add Record\n2 - Remove Record\n3 - Print Book\n4 - Exit\n";
		while (1)
		{
			getline(cin, number);
			istringstream iss(number);
			iss >> i;
			if (iss.fail())
			{
				iss.clear();
				iss.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, please enter an integer" << endl;
			}
			if (!iss.fail())
				break;
		}
		switch (i)
		{
		case 1:
			cout << "Enter Name \n";
			getline(cin, first);
			cout << "Enter  Last Name \n";
			getline(cin, last);
			cout << "Enter Number \n";
			getline(cin, number);
			theBook.addRecord(first, last, number);
			break;
		case 2:
			cout << "Enter the index number of the record you want to remove (If you dont know the index number type -1 and print book to learn) \n";
			while (1)
			{
				getline(cin, number);
				istringstream iss(number);
				iss >> x;
				if (iss.fail())
				{
					iss.clear();
					iss.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong input, please enter an integer" << endl;
				}
				if (!iss.fail())
					break;
			}
			if (x != -1) {
			theBook.removeRecord(x - 1);
			break;
			}
			else {
				theBook.printlist();
				break;
			}
		case 3:
			theBook.printlist();
			break;
		case 4:
			run=0;
			break;
		default:
			cout << "Invalid input please type an accurate value.\n";
			break;
		}

	}
	theBook.exit();

}