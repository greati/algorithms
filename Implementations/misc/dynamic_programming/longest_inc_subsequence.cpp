#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	
	int in[] = {5,2,8,6,3,6,9,7};
	int L[8], answer = 1;

	for (int & a : L) a = 1;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < i; ++j) {
			if (in[j] < in[i]) {
				L[i] = max(L[i], 1 + L[j]);
			}
		}
		answer = max(answer, L[i]);
	}

	cout << answer << endl;	
	return 0;
}
