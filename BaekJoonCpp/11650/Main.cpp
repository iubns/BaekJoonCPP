#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	vector<pair<int, int>> pointers;
	int pointerCount;
	cin >> pointerCount;
	pointers.resize(pointerCount);

	for (int index = 0; index < pointerCount; index++) {
		cin >> pointers[index].first >> pointers[index].second;
		pointers[index];
	}

	sort(pointers.begin(), pointers.end());
	for (int index = 0; index < pointerCount; index++) {
		cout << pointers[index].first << ' ' << pointers[index].second << '\n';
	}

	return 0;
}
