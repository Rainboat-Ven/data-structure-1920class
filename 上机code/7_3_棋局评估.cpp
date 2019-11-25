#include<iostream>
using namespace std;

#define MAX 1e8

int chess[3][3];

int score() {
	int blank = 0;
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (chess[i][j] == 0) {
				blank++;
			}
		}
	}
	int flag = (blank & 1) ? -1 : 1;//���ո�Ϊ������������ż������Bob����ҪӮ�ˣ�flag=-1
	//�����
	for (i = 0; i < 3; i++) {
		if (chess[i][0]!=0&&chess[i][0] == chess[i][1] && chess[i][0] == chess[i][2]) {
			return flag * (blank + 1);
		}
	}
	//�����
	for (j = 0; j < 3; j++) {
		if (chess[0][j] != 0 && chess[0][j] == chess[1][j] && chess[0][j] == chess[2][j]) {
			return flag * (blank + 1);
		}
	}
	//���Խ���
	if (chess[0][0] && chess[0][0] == chess[1][1] && chess[0][0] == chess[2][2]) {
		return flag * (blank + 1);
	}
	if (chess[0][2] && chess[0][2] == chess[1][1] && chess[2][0] == chess[1][1]) {
		return flag * (blank + 1);
	}
	//ƽ��
	if (blank == 0) return 0;
	//���δ��
	return MAX;
}

int search(int f) {
	int S = score();
	if (S != MAX) return S;//�ѽ��������ط���
	
	int nowS=(f==1?-MAX:MAX);
	int reS;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (chess[i][j] == 0) {
				chess[i][j] = f;
				reS = (f == 1) ? search(2) : search(1);
				if (f == 1) {
					if (nowS < reS) nowS = reS;
				}
				else {
					if (nowS > reS) nowS = reS;
				}
				chess[i][j] = 0;
			}
		}
	}
	return nowS;
}

int main() {
	int T;
	cin >> T;
	int i, j;
	while (T) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				cin >> chess[i][j];
			}
		}
		cout << search(1) << endl;
		T--;
	}
	
	return 0;
}