#include<iostream>
using namespace std;

typedef struct {
	int v;
	int x;
}ball;

int main() {
	int n, L, t;
	cin >> n;
	cin >> L;
	cin >> t;
	int flag[1000] = { 0 };//表示位置
	ball ball_[100];
	int i;
	int x;
	for (i = 0; i < n; i++) {
		//初始化
		cin >> x;
		flag[x]++;
		ball_[i].v = 1;
		ball_[i].x = x;
	}
	int ti;
	for (ti= 0; ti < t; ti++) {
		//对每一时刻进行判断修改
		for (i = 0; i < n; i++) {
			//小球依次移动
			flag[ball_[i].x]--;
			ball_[i].x = ball_[i].x + ball_[i].v;
			flag[ball_[i].x]++;
		}
		for (i = 0; i < n; i++) {
			//依次判断速度的变化
			if (ball_[i].x == 0 || ball_[i].x == L || flag[ball_[i].x] == 2) {
				ball_[i].v = 0 - ball_[i].v;
			}
		}
	}
	for (i = 0; i < n; i++) {
		//输出位置
		cout << ball_[i].x<<" ";
	}
	return 0;
}