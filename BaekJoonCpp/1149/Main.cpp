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

	int houseCount;
	cin >> houseCount;

	vector<vector<int>> data;

	int input = 0;

	for (int index = 0; index < houseCount; index++) {
		vector<int> house;
		for (int colorIndex = 0; colorIndex < 3; colorIndex++) {
			cin >> input;

			if (index == 0) {
				house.push_back(input);
				continue;
			}

			if (colorIndex == 0) {
				input += min(data[index - 1][1], data[index - 1][2]);
			}
			else if (colorIndex == 1) {
				input += min(data[index - 1][0], data[index - 1][2]);
			}
			else if (colorIndex == 2) {
				input += min(data[index - 1][0], data[index - 1][1]);
			}
			house.push_back(input);
		}
		data.push_back(house);
	}

	int minPoint = INT32_MAX;
	for (int index = 0; index < 3; index++) {
		minPoint = min(minPoint, data[houseCount - 1][index]);
	}

	cout << minPoint;

	return 0;
}