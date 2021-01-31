#include <iostream>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int cawCount = 0, width = 0, height = 0, size = 0;
	cin >> cawCount >> width >> height >> size;

	int result = (width / size) * (height / size);
	cout << (result > cawCount ? cawCount : result) << endl;

	return 0;
}