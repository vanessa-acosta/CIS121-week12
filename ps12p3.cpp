#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

void read_data(string first[], string last[], double salary[], int size);
void display_data(string first[], string last[], double salary[], int size);
int search_lastname(string last[], int size, string target);

int main() {
	const int SIZE = 10;
	string first[SIZE];
	string last[SIZE];
	double salary[SIZE];
	string target;
	int position;

	read_data(first, last, salary, SIZE);

	cout << "\nEmployee List:" << endl;
	display_data(first, last, salary, SIZE);

	cout << "\nEnter last name to search (Ctrl+Z to stop): ";
	while (cin >> target) {
		position = search_lastname(last, SIZE, target);

		if (position == -1)
			cout << target << " not found." << endl;
		else {
			cout << "First name: " << first[position] << endl;
			cout << "Last name: " << last[position] << endl;
			cout << "Salary: $" << fixed << setprecision(2) << salary[position] << endl;
		}

		cout << "\nEnter last name to search (Ctrl+Z to stop): ";
	}

	return 0;
}

void read_data(string first[], string last[], double salary[], int size) {
	ifstream infile("empldata.txt");
	for (int i = 0; i < size; i++) {
		infile >> first[i] >> last[i] >> salary[i];
	}
	infile.close();
}

void display_data(string first[], string last[], double salary[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "First name: " << first[i] << endl;
		cout << "Last name: " << last[i] << endl;
		cout << "Salary: $" << fixed << setprecision(2) << salary[i] << endl;
		cout << "-------------------------" << endl;
	}
}

int search_lastname(string last[], int size, string target) {
	for (int i = 0; i < size; i++) {
		if (last[i] == target)
			return i;
	}
	return -1;
}