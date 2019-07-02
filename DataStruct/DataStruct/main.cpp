#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "selectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"
#include "HeapSort.h"
using namespace std;

template<typename T>
void __shifDown(T arr[], int n, int k){
	while (2 * k + 1 < n){
		int j = 2 * k + 1;
		if (j + 1 < n && arr[j + 1] > arr[j])
			j += 1;
		if (arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

template<typename T>
void heapSort(T arr[], int n){
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shifDown(arr, n, i);
	for (int i = n - 1; i > 0; i--){
		swap(arr[0], arr[i]);
		__shifDown(arr, i, 0);
	}
}
int main() {
	int n = 1000000;
	cout << "Test for Random Array,size = " << n << ",random range [0," << n << "]" << endl;
	int *arr = SortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	int *arr4 = SortTestHelper::copyIntArray(arr, n);
	int *arr5 = SortTestHelper::copyIntArray(arr, n);
	int *arr6 = SortTestHelper::copyIntArray(arr, n);
	int *arr7 = SortTestHelper::copyIntArray(arr, n);
	
	SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
	SortTestHelper::testSort("quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);
	SortTestHelper::testSort("Quick Sort 3", quickSort3Ways, arr4, n);
	SortTestHelper::testSort("heap Sort", heapSort1, arr5, n);
	SortTestHelper::testSort("heap Sort", heapSort2, arr6, n);
	SortTestHelper::testSort("heap Sort", heapSort, arr7, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout << endl;

	int swapTimes = 100;
	cout << "Test for Random Nearly ordered Array,size = " << n << ",swap time = [0," << swapTimes << "]" << endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr, n);
	arr3 = SortTestHelper::copyIntArray(arr, n);
	arr4 = SortTestHelper::copyIntArray(arr, n);
	arr5 = SortTestHelper::copyIntArray(arr, n);
	arr6 = SortTestHelper::copyIntArray(arr, n);
	arr7 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
	SortTestHelper::testSort("quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort", quickSort2, arr3, n);
	SortTestHelper::testSort("Quick Sort 3", quickSort3Ways, arr4, n);
	//SortTestHelper::testSort("insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort1, arr5, n);
	SortTestHelper::testSort("Heap Sort", heapSort2, arr6, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr7, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
 
	cout << "Test for Random Array,size = " << n << ",random range [0,10]" << endl;
	arr = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr, n);
	arr3 = SortTestHelper::copyIntArray(arr, n);
	arr4 = SortTestHelper::copyIntArray(arr, n);
	arr5 = SortTestHelper::copyIntArray(arr, n);
	arr6 = SortTestHelper::copyIntArray(arr, n);
	arr7 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
	SortTestHelper::testSort("quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort", quickSort2, arr3, n);
	SortTestHelper::testSort("Quick Sort 3", quickSort3Ways, arr4, n);
	SortTestHelper::testSort("heap sort", heapSort1, arr5, n);
	SortTestHelper::testSort("heap sort", heapSort2, arr6, n);
	SortTestHelper::testSort("heap sort", heapSort, arr7, n);
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout << endl;
	
	return 0;
}