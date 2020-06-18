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

	int time;
	cin >> time;

	for (int timeCount = 0; timeCount < time; timeCount++) {
		int indexSize, even = 0, odd = 0;
		cin >> indexSize;
		for (int index = 0; index < indexSize; index++) {
			int input;
			cin >> input;
			if (input % 2 != index % 2) {
				if (index % 2 == 0) {
					odd++;
				}
				else {
					even++;
				}
			}
		}
		if (even == odd) {
			cout << even << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}