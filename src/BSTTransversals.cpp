/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inodr_trav(struct node*, int*, int*);
void preodr_trav(struct node*, int*, int*);
void postodr_trav(struct node*, int*, int*);

void inorder(struct node *root, int *arr){
	int i = 0;
	if (root != NULL)
	{
		inodr_trav(root, &i, arr);
	}
	
}
void preorder(struct node *root, int *arr){

	int i = 0;
	if (root != NULL)
	{
		preodr_trav(root, &i, arr);
	}
}
void postorder(struct node *root, int *arr){
	int i = 0;
	if (root != NULL)
	{
		postodr_trav(root, &i, arr);
	}
	
}
void inodr_trav(struct node* root, int *i, int *arr)
{
	if (root != NULL&&arr!=NULL)
	{
		inodr_trav(root->left, i, arr);
		arr[*i] = root->data;
		printf("i val & data is %d\t%d\n", *i, root->data);
		++*i;
		inodr_trav(root->right, i, arr);
	}
}
void preodr_trav(struct node*root, int *i, int *arr)
{
	if (root != NULL&&arr!=NULL)
	{
		arr[*i] = root->data;
		++*i;
		preodr_trav(root->left, i, arr);

		preodr_trav(root->right, i, arr);
	}
}
void postodr_trav(struct node*root, int *i, int* arr)
{
	if (root != NULL&&arr!=NULL)
	{
		postodr_trav(root->left, i, arr);
		postodr_trav(root->right, i, arr);
		arr[*i] = root->data;
		++*i;
	}
}

