#include<iostream>
using namespace std;

int G[1001][1001];
int closedge[1001];
int n, m;

int minimum() {
	int minnum=INT_MAX;
	int minnow=0;
	int i;
	for ( i = 1; i <= n; i++) {
		if (closedge[i] >0 && closedge[i] < minnum) {
			minnum = closedge[i];
			minnow = i;
		}
	}
	return minnow;
}

int main() {
	cin >> n;
	cin >> m;
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			G[i][j] = INT_MAX;
		}
	}
	int a, b;
	for (i = 1; i <= m; i++) {
		cin >> a;
		cin >> b;
		cin >> G[a][b];
		G[b][a] = G[a][b];
	}
	//
	int k = 1;
	int minway = 0;
	for (j = 1; j <= n; j++) {
		if (j != k) {
			closedge[j] = G[k][j];
		}
	}
	closedge[k] = 0;
	for (i = 2; i <= n; i++) {
		k = minimum();
		minway = minway + closedge[k];
		closedge[k] = 0;
		for (j = 1; j <= n; j++) {
			if (G[k][j] < closedge[j]) {
				closedge[j] = G[k][j];
			}
		}
	}
	cout << minway;
	return 0;
}