#include <iostream>
#include <stack>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int time, currentPoint = 1;
	cin >> time;

	stack<int> stack;
	string result = "";
	for (int index = 0; index < time; index++)
	{
		int target;
		cin >> target;

		while (currentPoint <= target)
		{
			stack.push(currentPoint++);
			result += "+\n";
		}
		if (stack.top() != target) {
			cout << "NO";
			return 0;
		}
		result += "-\n";
		stack.pop();
	}

	cout << result;

	return 0;
}
