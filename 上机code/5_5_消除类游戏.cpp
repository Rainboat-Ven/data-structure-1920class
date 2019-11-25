#include<iostream>
using namespace std;

int main() {
	int m, n;
	int game[30][30] = {0};
	int flag[30][30] = {0};
	cin >> n;
	cin >> m;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> game[i][j];
		}
	}
	int f1, f2, f3;
	for (i = 0; i < n; i++) {
		f1 = 0;
		f2 = 1;
		f3 = 2;
		while (f3 < m) {
			if (game[i][f1] == game[i][f2]) {
				if (game[i][f2] == game[i][f3]) {
					flag[i][f1] = 1;
					flag[i][f2] = 1;
					flag[i][f3] = 1;
				}
			}
			f1++;
			f2++;
			f3++;
		}
	}
	for (j = 0; j < m; j++) {
		f1 = 0;
		f2 = 1;
		f3 = 2;
		while (f3 < n) {
			if (game[f1][j] == game[f2][j]) {
				if (game[f2][j] == game[f3][j]) {
					flag[f1][j] = 1;
					flag[f2][j] = 1;
					flag[f3][j] = 1;
				}
			}
			f1++;
			f2++;
			f3++;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (flag[i][j] == 1) {
				cout << 0 << ' ';
			}
			else {
				cout << game[i][j] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}