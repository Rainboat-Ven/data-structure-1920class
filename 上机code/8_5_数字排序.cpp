#include<iostream>
using namespace std;

int main() {
	int flag[1001] = {0};
	int n;
	cin >> n;
	int i;
	int j = 0;
	while (j<n) {
		cin >> i;
		flag[i]++;
		j++;
	}
	n = 0;
	for (j = 1; j <= 1000; j++) {
		if (flag[j] != 0) {
			n++;
		}
	}
	j = 1;
	int max=0;
	int mi;
	while (n) {
		j = 0;
		max = 0;
		for (int m = 1; m <= 1000; m++) {
			if (flag[m] > max) {
				max = flag[m];
				mi = m;
			}
		}
		cout << mi << ' ' << flag[mi] << endl;
		flag[mi] = 0;
		n--;
	}

	return 0;
}