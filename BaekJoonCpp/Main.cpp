#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int stairsPoint[301] = { 0, };
int stairsCount = 0;
int maxPoint = 0;
int go(int point, int position, int stepCount) {
	point += stairsPoint[position];
	if (position > stairsCount) {
		return 0;
	}

	if (position == stairsCount) {
		maxPoint = maxPoint > point ? maxPoint : point;
	}

	if(stepCount < 2)
	go(point, position + 1, stepCount + 1);
	go(point, position + 2, 1);
}

int main()
{
	init();
	
	cin >> stairsCount;

	for (int index = 1; index <= stairsCount; index++) {
		cin >> stairsPoint[index];
	}

	go(0, 0, 0);
	cout << maxPoint;

	return 0;
}