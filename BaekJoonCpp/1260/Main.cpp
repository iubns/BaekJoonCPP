#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int pointCount, lineCount, startPoint;

int maxtrix[1001][1001] = { 0, };
int dfsVisited[1001] = { 0, };
int bfsVisited[1001] = { 0, };

void dfs(int currentPoint) {
	cout << currentPoint << ' ';
	dfsVisited[currentPoint] = 1;
	for (int index = 1; index <= pointCount; index++) {
		if (dfsVisited[index])
		{
			continue;
		}
		if (maxtrix[currentPoint][index]) {
			dfs(index);
		}
	}
}

void bfs() {
	queue<int> bfsQueue;
	int currentPoint = startPoint;
	cout << currentPoint << ' ';
	bfsQueue.push(currentPoint);
	bfsVisited[currentPoint] = 1;

	while (!bfsQueue.empty())
	{
		currentPoint = bfsQueue.front();
		bfsQueue.pop();

		for (int index = 1; index <= pointCount; index++) {
			if (bfsVisited[index]) {
				continue;
			}
			if (maxtrix[currentPoint][index]) {
				bfsQueue.push(index);
				bfsVisited[index] = 1;
				cout << index << ' ';
			}
		}
	}
}

int main()
{
	init();

	cin >> pointCount >> lineCount >> startPoint;

	int fistPoint, secondPoint;
	for (int index = 0; index < lineCount; index++) {
		cin >> fistPoint >> secondPoint;
		maxtrix[fistPoint][secondPoint] = 1;
		maxtrix[secondPoint][fistPoint] = 1;
	}

	dfs(startPoint);
	cout << endl;
	bfs();

	return 0;
}