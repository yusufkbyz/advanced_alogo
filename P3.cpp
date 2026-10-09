#include <iostream>
#include "Sorter.h"
#include <vector>
#include <algorithm>
using namespace std;

void Sorter::merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m;
	vector<int> L(n1), R(n2);
	for (int i = 0;i < n1;i++) L[i] = arr[l + i];
	for (int j = 0;j < n2;j++) R[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void Sorter::mergeSort(int arr[], int l, int r) {
	if (r - l <= 0) {
		return;
	}
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

int Sorter::partition(int arr[], int low, int high, long long& count) {
	int i = low - 1;
	int pivot = arr[high];
	for (int j = low; j < high; j++) {
		count++;
		if (arr[j] < pivot) {
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	int temp2 = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp2;
	return i + 1;
}

void Sorter::quickSort(int arr[], int low, int high, long long& count) {
	if (high - low <= 0) {
		return;
	}
	int pivot = partition(arr, low, high, count);
	quickSort(arr, low, pivot - 1, count);
	quickSort(arr, pivot + 1, high, count);
}

void swapValues(int& a, int& b) {
	if (b < a) {
		int temp = a;
		a = b;
		b = temp;
	}
}

int Sorter::medianOfThree(int arr[], int low, int high) {
	int mid = low + (high - low) / 2;
	swapValues(arr[low], arr[mid]);
	swapValues(arr[low], arr[high]);
	swapValues(arr[mid], arr[high]);

	int temp = arr[high];
	arr[high] = arr[mid];
	arr[mid] = temp;
	return high;
}

int Sorter::partitionM3(int arr[], int low, int high, long long& count) {
	medianOfThree(arr, low, high);
	return partition(arr, low, high, count);
}

void Sorter::quickSortM3(int arr[], int low, int high, long long& count) {
	if (high - low <= 0) {
		return;
	}
	int pivot = partitionM3(arr, low, high, count);
	quickSortM3(arr, low, pivot - 1, count);
	quickSortM3(arr, pivot + 1, high, count);
}

int main() {
	Sorter s; int tmp[8];
	long long count = 0;
	int a[] = { 64,25,12,22,11,90,45,34 }; int n = 8;
	// mergeSort
	copy(a, a + n, tmp); s.mergeSort(tmp, 0, n - 1);
	cout << "MS: "; for (int x : tmp) cout << x << " "; cout << endl;
	// quickSort
	copy(a, a + n, tmp); s.quickSort(tmp, 0, n - 1, count);
	cout << "QS: "; for (int x : tmp) cout << x << " "; cout << endl;
	// worst-case for quickSort: sorted array
	int sorted[] = { 1,2,3,4,5,6,7,8 };
	copy(sorted, sorted + n, tmp); s.quickSort(tmp, 0, n - 1, count);
	cout << "QS sorted: "; for (int x : tmp) cout << x << " "; cout << endl;
	// quickSortM3 on same sorted array
	copy(sorted, sorted + n, tmp); s.quickSortM3(tmp, 0, n - 1, count);
	cout << "QSM3 sorted: "; for (int x : tmp) cout << x << " "; cout << endl;
	return 0;
}