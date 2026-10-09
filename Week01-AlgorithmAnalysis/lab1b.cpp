#include <iostream>
#include <algorithm>
using namespace std;

class SortAnalyser {
public:
	void bubbleSort(int arr[], int n, long long& counter) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1 - i; j++) {
				counter++;                // count comparison
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
			}
		}
	}

	void selectionSort(int arr[], int n, long long& counter) {
		for (int i = 0; i < n - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < n; j++) {
				counter++;
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				int temp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
			}
		}
	}

	void insertionSort(int arr[], int n, long long& counter) {
		for (int i = 1; i < n; i++) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0) {
				counter++;
				if (arr[j] > key) {
					arr[j + 1] = arr[j];
					j--;
				}
				else {
					break;
				}
			}
			arr[j + 1] = key;
		}
	}
};

// Helper: copy array
void copyArr(int src[], int dst[], int n) { for (int i = 0; i < n; i++) dst[i] = src[i]; }

// Helper: print array
void printArr(int a[], int n) { for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? " " : "\n"); }

int main() {
	SortAnalyser sa;
	long long c;
	int tmp[10];

	// -- Random array --
	int rand10[] = { 64,34,25,12,22,11,90,45,7,80 };
	int n = 10;

	c = 0; copyArr(rand10, tmp, n); sa.bubbleSort(tmp, n, c);
	cout << "TC1 bubble sorted: "; printArr(tmp, n);
	cout << "TC1 comparisons: " << c << endl;

	c = 0; copyArr(rand10, tmp, n); sa.selectionSort(tmp, n, c);
	cout << "TC2 selection sorted: "; printArr(tmp, n);
	cout << "TC2 comparisons: " << c << endl;

	c = 0; copyArr(rand10, tmp, n); sa.insertionSort(tmp, n, c);
	cout << "TC3 insertion sorted: "; printArr(tmp, n);
	cout << "TC3 comparisons: " << c << endl;

	// -- Already sorted --
	int sorted10[] = { 1,2,3,4,5,6,7,8,9,10 };
	c = 0; copyArr(sorted10, tmp, n); sa.bubbleSort(tmp, n, c);
	cout << "TC4 bubble on sorted, comparisons: " << c << endl;

	c = 0; copyArr(sorted10, tmp, n); sa.insertionSort(tmp, n, c);
	cout << "TC5 insertion on sorted, comparisons: " << c << endl;

	// -- Reverse sorted --
	int rev10[] = { 10,9,8,7,6,5,4,3,2,1 };
	c = 0; copyArr(rev10, tmp, n); sa.bubbleSort(tmp, n, c);
	cout << "TC6 bubble on reverse, comparisons: " << c << endl;

	c = 0; copyArr(rev10, tmp, n); sa.insertionSort(tmp, n, c);
	cout << "TC7 insertion on reverse, comparisons: " << c << endl;

	return 0;
}
