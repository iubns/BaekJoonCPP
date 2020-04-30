#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
	for (int index = 0; index < time; index++) {
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << 1 << '\n';
			break;
		case 2:
			cout << 2 << '\n';
			break;
		case 3:
			cout << 4 << '\n';
			break;
		case 4:
			cout << 7 << '\n';
			break;
		case 5:
			cout << 13 << '\n';
			break;
		case 6:
			cout << 24 << '\n';
			break;
		case 7:
			cout << 44 << '\n';
			break;
		case 8:
			cout << 81 << '\n';
			break;
		case 9:
			cout << 149 << '\n';
			break;
		case 10:
			cout << 274 << '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}
