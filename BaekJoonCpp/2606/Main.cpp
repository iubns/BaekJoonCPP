#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int grid[101][101] = { 0, };

	int computerNum = 0, lineNum = 0;
	cin >> computerNum >> lineNum;

	int first = 0, second = 0;
	for (int index = 0; index < lineNum; index++) {
		cin >> first >> second;

		grid[first][second] = 1;
		grid[second][first] = 1;
	}

	queue<int> infectedComputer;
	infectedComputer.push(1);
	int visited[101] = { 0, };
	int visitedCount = 0;

	int node = 0;
	while (!infectedComputer.empty())
	{
		node = infectedComputer.front();
		infectedComputer.pop();
		if (visited[node]) {
			continue;
		}

		visited[node] = 1;
		visitedCount++;

		for (int index = 1; index <= computerNum; index++) {
			if (grid[node][index]) {
				infectedComputer.push(index);
			}
		}
	}

	cout << visitedCount - 1;


	return 0;
}