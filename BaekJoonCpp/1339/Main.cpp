#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

vector<pair<char, int>> chars;

bool compare(pair<char, int> a, pair<char, int> b) {
	return a.second > b.second;
}

int getNumber(char c) {
	for (int index = 0; index < 10; index++) {
		if (c == chars[index].first)
		{
			return 9 - index;
		}
	}
	return 0;
}

int main()
{
	init();

	int stringCount;
	cin >> stringCount;

	vector<string> strings;
	strings.resize(stringCount);

	for (char c = 'A'; c <= 'Z'; c++) {
		chars.push_back(make_pair(c, 0));
	}

	for (int index = 0; index < stringCount; index++)
	{
		cin >> strings[index];
		while (strings[index].length() < 8)
		{
			strings[index] = '0' + strings[index];
		}
		for (int col = 0; col < 8; col++) {
			if (strings[index][col] < 'A' || strings[index][col] > 'Z') {
				continue;
			}
			chars[strings[index][col] - 'A'].second += pow(10, 8 - col);
		}
	}

	sort(chars.begin(), chars.end(), compare);

	int result = 0;
	for (int row = 0; row < stringCount; row++) {
		for (int col = 0; col < 8; col++) {
			if (strings[row][col] != '0') {
				strings[row][col] = getNumber(strings[row][col]) + 48;
			}
		}
		result += atoi(strings[row].c_str());
	}

	cout << result;
	return 0;
}
