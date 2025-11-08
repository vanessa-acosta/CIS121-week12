#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

void read_data(string first[], string last[], double gpa[], int size);
void display_data(string first[], string last[], double gpa[], int size);
void display_reverse(string first[], string last[], double gpa[], int size);

int main() {
	const int SIZE = 10;
	string first[SIZE];
	string last[SIZE];
	double gpa[SIZE];
	
	read_data(first, last, gpa, SIZE);

	cout << "Student List:" << endl;
	display_data(first, last, gpa, SIZE);

	cout << "\nStudent List in Reverse:" << endl;
	display_reverse(first, last, gpa, SIZE);
 
	return 0;
}

void read_data(string first[], string last[], double gpa[], int size) {
	ifstream infile("students.txt");

	for (int i = 0; i < size; i++) {
		infile >> first[i] >> last[i] >> gpa[i];
	}

	infile.close();
}

void display_data(string first[], string last[], double gpa[], int size) {
	for (int i = 0; i < size; i++) {
		cout << first[i] << " " << last[i] << " " << gpa[i] << endl;
	}
}

void display_reverse(string first[], string last[], double gpa[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		cout << first[i] << " " << last[i] << " " << gpa[i] << endl;
	}
}