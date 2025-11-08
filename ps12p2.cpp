#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

void read_data(string city[], int population[], int& count);
void display_data(const string city[], const int population[], int count);
int sequential_search(const string city[], int count, string key);

int main() {
	const int SIZE = 50;
	string city[SIZE];
	int population[SIZE];
	int count = 0;

	read_data(city, population, count);

	display_data(city, population, count);

	string key;

	cout << "\nEnter city name (Ctrl+Z to stop): ";

	while (cin >> key) {
		int index = sequential_search(city, count, key);

		if (index != -1)
			cout << city[index] << " has a population of " << population[index] << endl;
		else
			cout << key << " not found" << endl;

		cout << "\nEnter city name (Ctrl+Z to stop): ";
	}

	cout << "\nGoodbye. Have a nice day." << endl;

	return 0;
}

void read_data(string city[], int population[], int& count) {
	ifstream infile("cities.txt");
	while (infile >> city[count] >> population[count]) {
		count++;
	}
	infile.close();
}

void display_data(const string city[], const int population[], int count) {
	cout << fixed << showpoint;
	for (int i = 0; i < count; i++) {
		cout << city[i] << " " << population[i] << endl;
	}
}

int sequential_search(const string city[], int count, string key) {
	for (int i = 0; i < count; i++) {
		if (city[i] == key)
			return i;
	}
	return -1;
}