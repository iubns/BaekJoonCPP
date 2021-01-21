#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}


int main()
{
	init();

	int lineCount;
	cin >> lineCount;

	vector<vector<int>> data;

	int input = 0;
	data.push_back(vector<int> {});
	for (int lineIndex = 1; lineIndex <= lineCount; lineIndex++) {
		vector<int> line;
		for (int numindex = 0; numindex < lineIndex; numindex++) {
			cin >> input;
			if (lineIndex == 1) {
				line.push_back(input);
				continue;
			}

			if (numindex == lineIndex - 1)
			{
				input += data[lineIndex - 1][numindex - 1];
			}
			else {
				input += max(data[lineIndex - 1][numindex - 1], data[lineIndex - 1][numindex]);
			}
			line.push_back(input);
		}
		data.push_back(line);
	}

	int maxNum = 0;
	for (int index = 0; index < lineCount; index++) {
		maxNum = max(data[lineCount][index], maxNum);
	}
	cout << maxNum;

	return 0;
}