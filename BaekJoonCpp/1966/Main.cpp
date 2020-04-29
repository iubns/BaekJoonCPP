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

	int testCaseCount;
	cin >> testCaseCount;

	for (int index = 0; index < testCaseCount; index++) {
		vector<int> orderCount;
		orderCount.resize(9);

		queue<pair<int, int>> papers;
		int paperCount, targetIndex;
		cin >> paperCount >> targetIndex;
		for (int paperIndex = 0; paperIndex < paperCount; paperIndex++) {
			int order;
			cin >> order;

			orderCount[order - 1]++;
			papers.push(make_pair(order, paperIndex));
		}

		int count = 0;
		while (!papers.empty()) {
			auto front = papers.front();
			int heightPaperCount = 0;
			for (int orderIndex = front.first + 1; orderIndex <= 9; orderIndex++) {
				heightPaperCount |= orderCount[orderIndex - 1];
			}

			if (heightPaperCount == 0) {
				++count;
				papers.pop();
				orderCount[front.first - 1]--;
				if (front.second == targetIndex) {
					cout << count << '\n';
					break;
				}
			}
			else {
				papers.pop();
				papers.push(front);
			}
		}
	}

	return 0;
}
