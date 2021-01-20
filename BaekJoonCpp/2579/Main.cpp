#include <iostream>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}


int main()
{
	init();

	int stairsPoint[301] = { 0, };
	int stairsBestPoint[301] = { 0, };
	int stairsCount = 0;
	int maxPoint = 0;

	cin >> stairsCount;

	for (int index = 1; index <= stairsCount; index++) {
		cin >> stairsPoint[index];
	}

	stairsBestPoint[1] = stairsPoint[1];
	stairsBestPoint[2] = stairsPoint[1] + stairsPoint[2];
	stairsBestPoint[3] = (stairsPoint[1] > stairsPoint[2] ? stairsPoint[1] : stairsPoint[2]) + stairsPoint[3];

	for (int index = 4; index <= stairsCount; index++) {
		stairsBestPoint[index] = stairsBestPoint[index - 3] + stairsPoint[index - 1] > stairsBestPoint[index - 2] ? stairsBestPoint[index - 3] + stairsPoint[index - 1] : stairsBestPoint[index - 2];
		stairsBestPoint[index] += stairsPoint[index];
	}

	cout << stairsBestPoint[stairsCount];

	return 0;
}