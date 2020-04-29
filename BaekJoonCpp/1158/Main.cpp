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

	int peopleCount, gap, currentPoint = 1;
	cin >> peopleCount >> gap;

	vector<int> people;
	people.resize(peopleCount + 1);
	for (int index = 0; index <= peopleCount; index++) {
		people[index] = index;
	}

	gap--;
	cout << '<';
	while (peopleCount > 0)
	{
		currentPoint += gap;
		while (currentPoint > peopleCount) {
			currentPoint -= peopleCount;
		}
		cout << people[currentPoint] << (peopleCount == 1 ? "" : ", ");
		people.erase(people.begin() + currentPoint);
		peopleCount--;
	}

	cout << '>' << endl;
	return 0;
}
