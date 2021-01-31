#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

const int arraySize = 1000001;
int num[arraySize];
int main()
{
	init();

	fill_n(num, arraySize, -1);

	stack<vector<int>> numStack;

	int size = 0, input = 0;

	cin >> size;

	for (int index = 0; index < size; index++) {
		cin >> input;
		if (numStack.empty())
		{
			numStack.push({ input,index });
			continue;
		}

		auto top = numStack.top();
		if (input <= top[0]) {
			numStack.push({ input,index });
			continue;
		}

		while (top[0] < input)
		{
			num[top[1]] = input;
			numStack.pop();
			if (numStack.empty()) {
				break;
			}
			top = numStack.top();
		}
		numStack.push({ input,index });
	}

	for (int index = 0; index < size; index++) {
		cout << num[index] << ' ';
	}
	cout << endl;


	return 0;
}