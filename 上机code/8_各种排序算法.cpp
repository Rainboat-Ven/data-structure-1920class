#include<iostream>
using namespace std;

int start_[1000];
int end_[1000];
int TR[1000];
int n;

void printend() {
	for (int i = 0; i < n; i++) {
		cout << end_[i] << ' ';
	}
	cout << endl;
}
//交换排序
void SwapSort() {
	for (int i = 0; i < n; i++) {
		end_[i] = start_[i];
	}
	int L = n;
	int i=0;
	int j=1;
	int ex;
	while (L) {
		i = 0;
		j = 1;
		while (j < L) {
			if (end_[i] > end_[j]) {
				ex = end_[i];
				end_[i] = end_[j];
				end_[j] = ex;
			}
			i++;
			j++;
		}
		L--;
	}
	printend();
}
//选择排序
void SelectSort() {
	for (int i = 0; i < n; i++) {
		end_[i] = start_[i];
	}
	int end_i = 0;
	int L = 0;
	int minnow = INT_MAX;
	int min_i;
	while (L != n) {
		minnow = end_[L];
		min_i = L;
		for (int i = L; i < n; i++) {
			if (end_[i] < minnow) {
				minnow = end_[i];
				min_i = i;
			}
		}
		end_[min_i] = end_[L];
		end_[L] = minnow;
		L++;
	}
	printend();
}
//归并排序
void Merge(int start_p, int div_p,int end_p) {
	int i = start_p;
	int j = div_p + 1;
	int k = start_p;
	while (k <=end_p) {
		if (i <= div_p && j <= end_p) {
			if (end_[i] < end_[j]) {
				TR[k] = end_[i++];
			}
			else {
				TR[k] = end_[j++];
			}
		}
		else if (i > div_p) {
			TR[k] = end_[j++];
		}
		else {
			TR[k] = end_[i++];
		}
		k++;
	}
	for (i = start_p; i <= end_p; i++) {
		end_[i] = TR[i];
	}
}
void MSort(int start_p, int end_p) {
	//先拆分，后归并
	if (start_p==end_p) end_[start_p] = start_[start_p];
	else {
		int div_p = (start_p + end_p) / 2;//要拆分的长度
		MSort(start_p, div_p);//拆分为s...m
		MSort(div_p+1,end_p);//拆分为m+1...t
		Merge(start_p,div_p,end_p);//进行归并
	}
}
void MergeSort() {
	MSort(0, n-1);
	printend();
}
//快速排序
int Partition(int low, int high) {
	int re;
	re = end_[low];
	int pivotkey = end_[low];
	while (low < high) {
		while (low < high && end_[high] >= pivotkey) high--;
		end_[low] = end_[high];
		while (low < high && end_[low] <= pivotkey) low++;
		end_[high] = end_[low];
	}
	end_[low] = re;
	return low;
}
void QSort(int low,int high) {
	if (low < high) {
		int pivotloc = Partition(low, high);
		QSort(low, pivotloc - 1);
		QSort(pivotloc + 1, high);
	}
}
void QuickSort() {
	for (int i = 0; i < n; i++) {
		end_[i] = start_[i];
	}
	QSort(0, n - 1);
	printend();
}
//堆排序
void HeapAdjust(int len,int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if (left<len && end_[left] > end_[maxIdx])     maxIdx = left;
	if (right<len && end_[right] > end_[maxIdx])     maxIdx = right;
	if (maxIdx != index)
	{
		swap(end_[maxIdx], end_[index]);
		HeapAdjust(len, maxIdx);
	}
}
void HeapSort() {
	for (int i = 0; i < n; i++) {
		end_[i] = start_[i];
	}
	for (int i = n/2-1; i >= 0; i--) {
		HeapAdjust(n,i);
	}
	for (int i = n - 1; i >= 1; i--) {
		swap(end_[0], end_[i]);
		HeapAdjust(i,0 );
	}
	printend();
}

int main(){
	cout << "输入数据规模：";
	int i;
	cin >> n;
	cout << "依次输入数据：\n";
	for (i = 0; i < n; i++) {
		cin >> start_[i];
	}
	cout << "\n交换排序：";
	SwapSort();
	cout << "\n选择排序：";
	SelectSort();
	cout << "\n归并排序：";
	MergeSort();
	cout << "\n快速排序：";
	QuickSort();
	cout << "\n堆排序：";
	HeapSort();
	return 0;
}