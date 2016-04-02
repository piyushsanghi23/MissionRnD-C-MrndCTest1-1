/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1==NULL || *head2 == NULL)
		return -1;

	int length = 0;

	struct node *head;
	struct node *h1 = *head1;
	struct node *h2 = *head2;
	
	if (h1->data > h2->data){
		head = h2;
		h2 = h2->next;
		length++;
	}
	else{
		head = h1;
		h1 = h1->next;
		length++;
	}

	struct node *p = head;

	while (h1 != NULL & h2 != NULL)
	{
		if (h1->data > h2->data){
			p->next = h2;
			h2 = h2->next;
		}
		else{
			p->next = h1;
			h1 = h1->next;
		}
		length++;
	}

	while (h2 != NULL)
	{
		p->next = h2;
		h2 = h2->next;
		length++;
	}

	while (h1 != NULL)
	{
		p->next = h1;
		h1 = h1->next;
		length++;
	}

	p->next = head;

	head1 = &head;

	return length;
	
}