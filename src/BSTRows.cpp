/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void rowstore(struct node*, int, int*, int*);
int height(struct node* root);

int* BSTRighttoLeftRows(struct node* root)
{
	if (root != NULL)
	{
		int ht, *arr, i = 0, j = 1;
		arr = (int*)malloc(5 * sizeof(int));
		ht = height(root);
		for (j = 1; j <= ht; j++)
		{
			rowstore(root, j, &i, arr);
		}
		return arr;
	}
	else
	{
		return NULL;
	}
}
void rowstore(struct node*root, int ht, int* i, int *arr)
{
	if (ht == 0 || root == NULL)
	{
		return;
	}
	if (ht == 1)
	{
		arr[*i] = root->data;
		++*i;
	}
	else
	{
		rowstore(root->right, ht - 1, i, arr);
		rowstore(root->left, ht - 1, i, arr);
	}
}
int height(struct node* root)
{
	if (!root)
	{
		return -1;
	}
	else if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	else
	{
		int left_ht = height(root->left);
		int right_ht = height(root->right);
		if (left_ht >= right_ht)
		{
			return(left_ht + 1);
		}
		else
		{
			return(right_ht + 1);
		}
	}
}
