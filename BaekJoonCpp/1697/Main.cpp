#include <iostream>
#include <queue>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int visited[100000 * 2] = { 0, };
int main()
{
	init();

	int start, target;
	cin >> start >> target;

	queue<vector<int>> postionQueue;
	postionQueue.push(vector<int>{start, 0});
	while (true)
	{
		vector<int> currentPostion = postionQueue.front();
		postionQueue.pop();
		if (visited[currentPostion[0]]) {
			continue;
		}
		visited[currentPostion[0]] = 1;
		if (currentPostion[0] > target) {
			postionQueue.push(vector<int>{ currentPostion[0] - 1, currentPostion[1] + 1 });
			continue;
		}
		else if (currentPostion[0] == target) {
			cout << currentPostion[1] << endl;
			return 0;
		}
		else {
			if (currentPostion[0] > 0)
				postionQueue.push(vector<int>{ currentPostion[0] - 1, currentPostion[1] + 1});
			postionQueue.push(vector<int>{ currentPostion[0] + 1, currentPostion[1] + 1});
			if (visited[currentPostion[0] * 2] < 100000 * 2)
				postionQueue.push(vector<int>{ currentPostion[0] * 2, currentPostion[1] + 1});
		}
	}
	return 0;
}