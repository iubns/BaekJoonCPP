#include <iostream>
#include <stack>
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

	int time = 0, count = 0, input = 0, start = 0, target = 0, result = 0;
	cin >> time;

	vector<int> nums;
	stack<int> numStack;
	for (int index = 0; index < time; index++) {
		cin >> count;
		nums.push_back(0);
		for (int numIndex = 0; numIndex < count; numIndex++) {
			cin >> input;
			nums.push_back(input);
		}

		// 0 -> 그룹 아님, -1 -> 그룹임, -2 -> 판단 대기중
		for (int numIndex = 1; numIndex <= count; numIndex++) {
			bool group = false;
			target = numIndex;
			while (true)
			{
				if (nums[target] == 0 || nums[target] == -1) {
					group = false;
					break;
				}
				if (nums[target] == target) {
					nums[target] = -1;
					group = false;
					break;
				}
				if (nums[target] == -2) {
					group = true;
					start = target;
					break;
				}
				numStack.push(target);
				int temp = target;
				target = nums[temp];
				nums[temp] = -2;
			}

			while (!numStack.empty())
			{
				auto front = numStack.top();
				numStack.pop();
				nums[front] = group ? -1 : 0;
				if (group) {
					group = start != front;
				}
			}
		}


		for (int numIndex = 1; numIndex <= count; numIndex++) {
			if (nums[numIndex] == 0) {
				result++;
			}
		}
		cout << result << endl;
		result = 0;
		nums.clear();
	}


	return 0;
}