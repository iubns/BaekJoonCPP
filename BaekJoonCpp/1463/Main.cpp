#include <iostream>
#include <queue>
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

	int input = 0;
	cin >> input;

	queue<vector<int>> numQueue;
	numQueue.push(vector<int>{input, 0});

	int currentNum = 0;
	while (true)
	{
		vector<int> currentNum = numQueue.front();
		numQueue.pop();

		if (currentNum[0] == 1) {
			cout << currentNum[1] << endl;
			return 0;
		}

		if (currentNum[0] % 3 == 0) {
			numQueue.push(vector<int>{currentNum[0] / 3, currentNum[1] + 1});
		}
		if (currentNum[0] % 2 == 0) {
			numQueue.push(vector<int>{currentNum[0] / 2, currentNum[1] + 1});
		}
		numQueue.push(vector<int>{currentNum[0] - 1, currentNum[1] + 1});
	}

	return 0;
}