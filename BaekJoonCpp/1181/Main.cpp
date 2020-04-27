
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

	int wordCount;
	cin >> wordCount;
	vector<pair<int, string>> words;

	words.resize(wordCount);
	for (int index = 0; index < wordCount; index++) {
		cin >> words[index].second;
		words[index].first = words[index].second.length();
	}
	sort(words.begin(), words.end());

	cout << words[0].second << '\n';
	for (int index = 1; index < wordCount; index++) {
		if (words[index - 1] == words[index]) {
			continue;
		}
		cout << words[index].second << '\n';
	}
	return 0;
}
