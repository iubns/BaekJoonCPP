#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int queenCount;
int queens[15];
int result = 0;

void chck(int depth) {
	if (depth == queenCount) {
		result++;
		return;
	}

	for (int terget = 0; terget < queenCount; terget++) {
		for (int index = 0; index <= depth; index++) {
			if (index == depth)
			{
				queens[index] = terget;
				chck(depth + 1);
				break;
			}

			if (queens[index] == terget) {
				break;
			}

			if (abs(queens[index] - terget) == abs(index - depth)) {
				break;
			}
		}
	}
}

int main()
{
	init();
	cin >> queenCount;

	chck(0);
	cout << result;
}