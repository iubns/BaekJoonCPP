#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int legnth, charSize;
vector<char> chars;
vector<char> result;

void next(int insertCount, int depth) {
	if (depth == charSize) {
		if (legnth == insertCount) {
			int vowel = 0;
			for (int index = 0; index < legnth; index++) {
				switch (result[index])
				{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowel++;
					break;
				default:
					break;
				}
			}

			if (vowel < 1 || legnth - vowel < 2) {
				return;
			}

			for (int index = 0; index < legnth; index++) {
				cout << result[index];
			}
			cout << '\n';
		}
		return;
	}

	if (insertCount > legnth) {
		return;
	}

	result[insertCount] = chars[depth];
	next(insertCount + 1, depth + 1);
	next(insertCount, depth + 1);
}

int main()
{
	init();

	cin >> legnth >> charSize;
	chars.resize(charSize);
	result.resize(legnth + 1);

	for (int index = 0; index < charSize; index++)
	{
		cin >> chars[index];
	}

	sort(chars.begin(), chars.end());

	next(0, 0);

	return 0;
}
