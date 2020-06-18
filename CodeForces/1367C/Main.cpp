#include <iostream>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

char input[200000];
int numSize, k, kCount = 0, result = 0;
bool check(int targetIndex) {
	int startIndex = targetIndex - k;
	startIndex = startIndex < 0 ? 0 : startIndex;
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
			if (input[index] == '1') {
				index += k;
				continue;
			}
			for (int targetIndex = index - k < 0 ? 0 : index - k; targetIndex <= index + k && targetIndex < numSize; targetIndex++) {
				if (input[targetIndex] == '1') {
					index = targetIndex + k;
					goto loopContinue;
				}
			}
			result++;
			input[index] = '1';
			index += k;
		loopContinue:
			continue;
		}
		cout << result << endl;
	}
	return 0;
}