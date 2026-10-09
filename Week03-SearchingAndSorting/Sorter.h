#pragma once
class Sorter {
public:
	void mergeSort(int arr[], int l, int r); // recursive
	void quickSort(int arr[], int low, int high, long long& count); // last-element pivot
	void quickSortM3(int arr[], int low, int high, long long& count); // median-of-three pivot
private:
	void merge(int arr[], int l, int m, int r);
	int partition(int arr[], int low, int high, long long& count);
	int partitionM3(int arr[], int low, int high, long long& count);
	int medianOfThree(int arr[], int low, int high); // returns pivot index
};