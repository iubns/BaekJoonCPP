#include <iostream>
#include <map>
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

	map<int, int> numberMap;

	int numberSize;
	cin >> numberSize;

	int input;
	for (int index = 0; index < numberSize; index++)
	{
		cin >> input;
		auto result = numberMap.find(input);
		if (result == numberMap.end()) {
			numberMap.insert(make_pair(input, 1));
		}
		else
		{
			(*result).second++;
		}
	}

	cin >> numberSize;
	for (int index = 0; index < numberSize; index++) {
		cin >> input;
		auto result = numberMap.find(input);
		if (result == numberMap.end()) {
			cout << 0 << ' ';
		}
		else {
			cout << (*numberMap.find(input)).second << ' ';
		}
	}

	return 0;
}
