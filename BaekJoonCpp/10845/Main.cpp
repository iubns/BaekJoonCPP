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
	queueArray.resize(10001);
	int startPoint = 0, endPoint = 0;

	for (int index = 0; index < commandCount; index++) {
		string command;
		cin >> command;
		if (command == "push") {
			cin >> queueArray[endPoint++];
		}
		else if (command == "pop") {
			if (startPoint >= endPoint) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[startPoint++] << '\n';
		}
		else if (command == "size") {
			cout << endPoint - startPoint << '\n';
		}
		else if (command == "empty") {
			cout << (endPoint - startPoint == 0 ? 1 : 0) << '\n';
		}
		else if (command == "front") {
			if (startPoint >= endPoint) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[startPoint] << '\n';
		}
		else if (command == "back") {
			if (startPoint >= endPoint) {
				cout << -1 << '\n';
				continue;
			}
			cout << queueArray[endPoint - 1] << '\n';
		}
	}

	return 0;
}
