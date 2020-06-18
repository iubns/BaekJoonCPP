#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

string input;
int numSize, k, kCount = 0, result = 0;
bool check(int targetIndex) {
	int startIndex = targetIndex - k;
	startIndex = startIndex < 0 ? 0 : startIndex;
	for (int index = startIndex; index <= targetIndex + k && index < input.size(); index++) {
		if (input[index] == '1') {
			return false;
		}
	}
	return true;
}


int main()
{
	init();
	
	int time;
	cin >> time;

	for (int timeCount = 0; timeCount < time; timeCount++) {
		kCount = 0, result = 0;
		cin >> numSize >> k;
		cin >> input;
		for (int index = 0; index < numSize; index++) {
			if (check(index)) {
				result++;
				input[index] = '1';
				index += k;
			}
		}
		cout << result << endl;
	}
	return 0;
}