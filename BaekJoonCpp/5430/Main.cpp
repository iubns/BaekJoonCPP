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

	int testCaseCount;
	cin >> testCaseCount;

	for (int index = 0; index < testCaseCount; index++) {
		vector<int> arr;
		bool reverce = false;

		string commands;
		cin >> commands;

		int arraySize;
		cin >> arraySize;
		arr.resize(arraySize);

		char temp;
		cin >> temp;
		if (arraySize == 0) {
			cin >> temp;
		}
		for (int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++) {
			cin >> arr[arrayIndex];
			cin >> temp;
		}

		int startPint = 0; int endPoint = arraySize - 1;
		while (commands.length()) {
			char command = commands[0];
			switch (command) {
			case 'R':
				reverce = !reverce;
				break;
			case 'D':
				if (endPoint >= startPint) {
					if (reverce == false) {
						startPint++;
					}
					else {
						endPoint--;
					}
				}
				else {
					cout << "error" << '\n';
					goto exitTestCase;
				}
				break;
			default:
				break;
			}
			commands.erase(0, 1);
		}

		cout << '[';
		if (reverce == false) {
			for (int arrayIndex = startPint; arrayIndex <= endPoint; arrayIndex++) {
				cout << arr[arrayIndex] << (arrayIndex != endPoint ? ',' : ']');
			}
		}
		else {
			for (int arrayIndex = endPoint; startPint <= arrayIndex; arrayIndex--) {
				cout << arr[arrayIndex] << (arrayIndex != startPint ? ',' : ']');
			}
		}
		if (endPoint + 1 == startPint) {
			cout << ']';
		}
		cout << '\n';
	exitTestCase:
		continue;
	}

	return 0;
}
