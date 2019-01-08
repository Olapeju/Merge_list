//A program that merges two ordered list objects of integers into a single ordered list object of integers.  



#include<assert.h>
#include <iostream>



struct Node //linked list node
{
	int data;
	struct Node* next;
};


void MoveNode(struct Node** destination, struct Node** source) //This function takes the node from one list and move it to the destination list
{
	struct Node* newNode = *source;
	assert(newNode != nullptr);

	*source = newNode->next; //moving the source pointer
	newNode->next = *destination;

	*destination = newNode; //pointing to new node
}


struct Node* SortedMerge(struct Node* list1, struct Node* list2) //this function takes two list
{
	struct Node dummy; //dummy node

	struct Node* tailPtr = &dummy;

	dummy.next = nullptr;
	while (1)
	{
		if (list1 == nullptr)
		{
			tailPtr->next = list2; //if one list becomes empty, it uses the remaining elements in the other list
			break;
		}
		else if (list2 == nullptr)
		{
			tailPtr->next = list1;
			break;
		}
		if (list1->data <= list2->data) //checks if each element in list one is less than or equal to each element in list two
			MoveNode(&(tailPtr->next), &list1);
		else
			MoveNode(&(tailPtr->next), &list2);

		tailPtr = tailPtr->next;
	}
	return(dummy.next);
}




void push(struct Node** head_ref, int new_data) //this function inserts a new node at the beginning of the linked list
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data; //insert data
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


void displayList(struct Node *node) //this function prints the elements in the linked list
{
	while (node != nullptr)
	{
		std::cout << node->data << " ";
		
		node = node->next; //continue the display of each element
	}
}
