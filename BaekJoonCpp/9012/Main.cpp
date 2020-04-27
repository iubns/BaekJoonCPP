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

	string parenthreses;
	for (int index = 0; index < time; index++)
	{
		int parenthresesCount = 0;
		cin >> parenthreses;
		for (int index = 0; index < parenthreses.length(); index++) {
			parenthreses[index] == 40 ? parenthresesCount++ : parenthresesCount--;
			if (parenthresesCount < 0) {
				break;
			}
		}

		if (parenthresesCount == 0) {
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}
