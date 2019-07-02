#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <algorithm>
#include "InsertionSort.h"
#include "SortTestHelper.h"
using namespace std;
//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge(T arr[], int l, int mid, int r){
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++){
		if (i > mid){
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r){
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]){
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}
}
//�ݹ�ʹ�ù鲢���򣬶�arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[],int l,int r){
	if (r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	int mid = (r + l) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}
template<typename T>
void mergeSort(T arr[], int n){
	__mergeSort(arr, 0, n - 1);
}

template<typename T>
void mergeSortBU(T arr[], int n){
	for (int sz = 1; sz <= n; sz += sz)
		for (int i = 0; i + sz < n; i += sz + sz)
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
}
#endif