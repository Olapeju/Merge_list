#include "Header.h"
//#include<assert.h>
#include<iostream>
using namespace std;



int main()
{
	//declaring list and setting them to null pointer
	struct Node* finalList = nullptr;
	struct Node* firstList = nullptr;
	struct Node* secondList = nullptr;

	//initializing the first list with integers
	push(&firstList, 60);
	push(&firstList, 48);
	push(&firstList, 26);
	push(&firstList, 15);


	//initializing the second list with integers
	push(&secondList, 55);
	push(&secondList, 30);
	push(&secondList, 22);

	
	finalList = SortedMerge(firstList, secondList);
	

	cout << ("The new Merged Linked List is: \n");
	displayList(finalList);

	
	system("pause");
}
