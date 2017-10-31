#include<iostream>

#include"Algorithm_Sotring.h"
int main() {
	int* a = new int[8]
	{ 1, 5, 0, 1, 6, 2, 10, 3 };


	Algorithm_Sorting* b = Algorithm_Sorting::getInstance();

	//b->Bubble(a, 8);
	//b->Selection(a, 8);
	//b->Insertion(a, 8);
	//b->Bubble(a, 8);
	//b->Merge(a, 0, 7);
	b->Quick(a, 0, 7);

	for (int i = 0; i < 8; ++i) {
		std::cout << a[i] << "   ";
	}


	system("pause");
	return 0;
}