#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

map<char, int>chars;

int getNumber(char c) {
	int index = 0;
	int value = (*chars.find(c)).second;

	for (auto iter = chars.begin(); iter != chars.end(); iter++) {
		if ((*iter).second > value) {
			index++;
		}
	}

	return 9 - index;
}

int main()
{
	init();

	int stringCount;
	cin >> stringCount;

	vector<string> strings;
	strings.resize(stringCount);

	for (int index = 0; index < stringCount; index++)
	{
		cin >> strings[index];
		while (strings[index].length() < 8)
		{
			strings[index] = '0' + strings[index];
		}
	}

	for (int col = 0; col < 8; col++) {
		for (int row = 0; row < stringCount; row++) {
			if (strings[row][col] != '0') {
				chars.insert(make_pair(strings[row][col], 0));
				(*chars.find(strings[row][col])).second += (pow(10, col));
			}
		}
	}

	for (int row = 0; row < stringCount; row++) {
		for (int col = 0; col < 8; col++) {
			if (strings[row][col] != '0') {
				strings[row][col] = getNumber(strings[row][col]) + 48;
			}
		}
	}

	int result = 0;
	for (int row = 0; row < stringCount; row++) {
		result += atoi(strings[row].c_str());
	}

	cout << result;
	return 0;
}
