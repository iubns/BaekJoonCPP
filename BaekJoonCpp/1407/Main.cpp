#include <iostream>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

long long clac(long long num) {
	long long result = 0, count = 1;
	while (num != 0)
	{
		if (num % 2 == 0) {
			result += num / 2 * count;
		}
		else {
			result += (num / 2 + 1) * count;
		}
		num /= 2;
		count *= 2;
	}
	return result;
}

int main()
{
	init();

	long long first, second;

	cin >> first >> second;

	cout << clac(second) - clac(first - 1);
	return 0;
}