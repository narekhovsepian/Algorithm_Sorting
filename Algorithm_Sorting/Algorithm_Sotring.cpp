#include"Algorithm_Sotring.h"

void Algorithm_Sorting::merge_sort(int* arr, int l, int m, int r) {


	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; ++i) {
		L[i] = arr[l + i];

	}
	for (j = 0; j < n2; ++j) {
		R[j] = arr[m + j + 1];
	}
	i = 0; j = 0; k = l;
	while (i < n1&&j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k;
	}
	while (i < n1) {
		arr[k] = L[i];
		++i;
		++k;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		++j;
		++k;

	}
}
int Algorithm_Sorting::partition(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
		if (pivot >= arr[j]) {
			++i;
			swap(&arr[i], &arr[j]);

		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;

}
void Algorithm_Sorting::swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



void Algorithm_Sorting::Merge(int* arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		Merge(arr, l, m);
		Merge(arr, m + 1, r);
		merge_sort(arr, l, m, r);
	}

}
void Algorithm_Sorting::Quick(int* arr, int  low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		Quick(arr, low, pi - 1);
		Quick(arr, pi + 1, high);

	}

}

void Algorithm_Sorting::Bubble(int* arr, const int& size) {
	for (int i = size - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

}
void Algorithm_Sorting::Insertion(int* arr, const int& size) {
	for (int i = 0; i < size; ++i) {
		int j, key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;

		}
		arr[j + 1] = key;
	}

}

void Algorithm_Sorting::Selection(int* arr, const int& size) {
	int key;
	for (int i = 0; i < size - 1; ++i) {
		key = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[key] > arr[j]) {
				key = j;
			}
		}
		swap(&arr[key], &arr[i]);
	}

}

Algorithm_Sorting* Algorithm_Sorting::_instance = 0;


Algorithm_Sorting* Algorithm_Sorting::getInstance() {
	if (!_instance) {
		_instance = new Algorithm_Sorting();
	}
	return _instance;

}
Algorithm_Sorting::Algorithm_Sorting() {}


