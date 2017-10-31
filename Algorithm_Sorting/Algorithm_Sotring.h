#pragma once
#include <iostream>

class Algorithm_Sorting {

public:

	void Quick(int*, int, int);
	void Merge(int*, int, int);
	void Selection(int*, const int&);
	void Insertion(int*, const int&);
	void Bubble(int*, const int&);
	static Algorithm_Sorting* getInstance();
private:
	Algorithm_Sorting();
private:
	static Algorithm_Sorting* _instance;
	int partition(int*, int, int);
	void swap(int*, int*);
	void merge_sort(int*, int, int, int);


};
