#ifndef QUICKSORT_H
#define QUICKSORT_H

//对arr[l...r]部分进行partition操作
//返回p,使得arr[l...p-1] < arr[p];arr[p+1...r] > arr[p]
template<typename T>
int __partition(T arr[], int l, int r){
	swap(arr[rand() % (r - l + 1) + l], arr[l]);
	T v = arr[l];

	//arr[l+1...j] < v;arr[j+1...i) > v
	int j = l;
	for (int i = l + 1; i <= r; i++){
		if (arr[i] < v){
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}
//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r){
	/*if (l >= r)
	return;*/
	if (r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}


template<typename T>
void quickSort(T arr[], int n){
	srand(time(NULL));
	__quickSort(arr, 0, n - 1);
}

//对arr[l...r]部分进行partition操作
//返回p,使得arr[l...p-1] < arr[p];arr[p+1...r] > arr[p]
template<typename T>
int __partition2(T arr[], int l, int r){
	swap(arr[rand() % (r - l + 1) + l], arr[l]);
	T v = arr[l];

	//arr[l+1...i) <= v;arr(j...r] >= v;
	int i = l + 1, j = r;
	while (true) {
		while (i <= r && arr[i] < v) i++;
		while (j >= l + 1 && arr[j] > v) j--;
		if (i > j) break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[l], arr[j]);
	return j;
}
//对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort2(T arr[], int l, int r){
	/*if (l >= r)
	return;*/
	if (r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition2(arr, l, r);
	__quickSort2(arr, l, p - 1);
	__quickSort2(arr, p + 1, r);
}


template<typename T>
void quickSort2(T arr[], int n){
	srand(time(NULL));
	__quickSort2(arr, 0, n - 1);
}

//三路快速排序处理 arr[l...r]
//将arr[l...r]分为 < v;==v;>v 三部分
//之后递归对 < v;> v两部分继续进行三路快速排序
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {
	if (r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	//partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	int lt = l; //arr[l+1...lt] < v
	int gt = r + 1; //arr[gt...r] > v
	int i = l + 1;//arr[lt+1...i] == v
	while (i < gt){
		if (arr[i] < v){
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v){
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else{
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}
template <typename T>
void quickSort3Ways(T arr[], int n){
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}
#endif