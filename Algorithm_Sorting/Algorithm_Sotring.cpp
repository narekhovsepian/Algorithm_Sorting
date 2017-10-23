#include"Algorithm_Sotring.h"


int Algorithm_Sorting::partition(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
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
void Algorithm_Sorting::Quick(int* arr, int low, int high) {

	if (low < high) {
		int mid = partition(arr, low, high);

		Quick(arr, low, mid - 1);
		Quick(arr, mid + 1, high);
	}
}
void  Algorithm_Sorting::merge_sort(int* arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; ++i) {
		L[i] = arr[l + i];

	}
	for (int j = 0; j < n2; ++j) {
		R[j] = arr[m + 1 + j];
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
	while (j < n2) {
		arr[k] = R[j];
		++j;
		++k;
	}
}
void Algorithm_Sorting::Merge(int* arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		Merge(arr, l, m);
		Merge(arr, m + 1, r);
		merge_sort(arr, l, m, r);
	}
}
void Algorithm_Sorting::Selection(int* arr, const int& size) {
	int i, j, k;
	for (i = 0; i < size; ++i) {
		k = i;
		for (j = i + 1; j < size - 1; ++j) {
			if (arr[k] > arr[j]) {
				k = j;
			}
			swap(&arr[k], &arr[i]);
		}
	}
}
void Algorithm_Sorting::Insertion(int* arr, const int& size) {
	for (int i = 1; i < size; ++i) {
		int j, key = arr[i];
		for (j = i - 1; j >= 0; --j) {
			if (arr[i] < arr[j]) {
				arr[j + 1] = arr[j];
			}
		}
		swap(&key, &arr[j]);
	}

}
void Algorithm_Sorting::Bubble(int* arr, const int& size) {
	for (int i = size - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
