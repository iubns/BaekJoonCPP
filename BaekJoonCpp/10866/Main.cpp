#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	vector<int> queueArray;
	int commandCount;
	cin >> commandCount;
	queueArray.resize(20002);
	int startPoint = 10001, size = 0;

	for (int index = 0; index < commandCount; index++) {
		string command;
		cin >> command;
		if (command == "push_front") {
			cin >> queueArray[startPoint--];
			size++;
		}
		else if (command == "push_back") {
			cin >> queueArray[startPoint + ++size];
		}
		else if (command == "pop_front") {
			if (size <= 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[++startPoint] << '\n';
			size--;
		}
		else if (command == "pop_back") {
			if (size <= 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[startPoint + size--] << '\n';
		}
		else if (command == "size") {
			cout << size << '\n';
		}
		else if (command == "empty") {
			cout << (size == 0 ? 1 : 0) << '\n';
		}
		else if (command == "front") {
			if (size <= 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[startPoint + 1] << '\n';
		}
		else if (command == "back") {
			if (size <= 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[startPoint + size] << '\n';
		}
	}

	return 0;
}
