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
	int flag[1000] = { 0 };//��ʾλ��
	ball ball_[100];
	int i;
	int x;
	for (i = 0; i < n; i++) {
		//��ʼ��
		cin >> x;
		flag[x]++;
		ball_[i].v = 1;
		ball_[i].x = x;
	}
	int ti;
	for (ti= 0; ti < t; ti++) {
		//��ÿһʱ�̽����ж��޸�
		for (i = 0; i < n; i++) {
			//С�������ƶ�
			flag[ball_[i].x]--;
			ball_[i].x = ball_[i].x + ball_[i].v;
			flag[ball_[i].x]++;
		}
		for (i = 0; i < n; i++) {
			//�����ж��ٶȵı仯
			if (ball_[i].x == 0 || ball_[i].x == L || flag[ball_[i].x] == 2) {
				ball_[i].v = 0 - ball_[i].v;
			}
		}
	}
	for (i = 0; i < n; i++) {
		//���λ��
		cout << ball_[i].x<<" ";
	}
	return 0;
}