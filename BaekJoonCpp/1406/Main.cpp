#include <iostream>
#include <vector>
#include <list>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	list<char> note;

	string defaultValue;
	cin >> defaultValue;

	for (string::const_iterator it = defaultValue.begin(); it != defaultValue.end(); it++) {
		note.push_back(*it);
	}

	int commandCount = 0;
	cin >> commandCount;

	auto iterator = note.end();

	char command, value;
	for (int index = 0; index < commandCount; index++) {
		cin >> command;
		switch (command)
		{
		case'L':
			if (iterator != note.begin()) {
				iterator--;
			}
			break;
		case'D':
			if (iterator != note.end()) {
				iterator++;
			}
			break;
		case'B':
			if (iterator != note.begin()) {
				iterator--;
				iterator = note.erase(iterator);
			}
			break;
		case'P':
			cin >> value;
			note.insert(iterator, value);
			break;
		default:
			break;
		}
	}

	for (auto iterator = note.begin(); iterator != note.end(); iterator++) {
		cout << *iterator;
	}
	return 0;
}
