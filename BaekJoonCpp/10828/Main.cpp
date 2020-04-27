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

	vector<int> stack;
	int size = 0;
	stack.resize(10000);


	int commandCount;
	cin >> commandCount;

	for (int index = 0; index < commandCount; index++) {
		string command;
		cin >> command;

		if (command == "push") {
			int value;
			cin >> value;
			stack[size] = value;
			size++;
		}
		else if (command == "pop") {
			size--;
			if (size < 0) {
				size = 0;
				cout << -1 << '\n';
				continue;
			}
			cout << stack[size] << '\n';
		}
		else if (command == "size") {
			cout << size << '\n';
		}
		else if (command == "empty") {
			cout << (size == 0 ? 1 : 0) << '\n';
		}
		else if (command == "top") {
			if (size == 0) {
				cout << -1 << '\n';
				continue;
			}
			cout << stack[size - 1] << '\n';
		}
	}

	return 0;
}
