/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void swap_data(struct node*, struct node*);
void inoder_travel(struct node *, struct node**, struct node**, struct node **);
void fix_bst(struct node *root){
	if (root == NULL)
	{
		return;
	}
	else
	{
		struct node *temp1 = NULL, *temp2 = NULL, **loop;
		loop = (struct node**)malloc(1 * sizeof(struct node));
		loop[0] = NULL;
		inoder_travel(root, &temp1, &temp2, loop);
		swap_data(temp1, temp2);
	}
}
void inoder_travel(struct node *root, struct node**temp1, struct node**temp2, struct node **loop)
{
	if (root == NULL)
		return;
	inoder_travel(root->left, temp1, temp2, loop);
	if (loop[0] != NULL){
		if (root->data < loop[0]->data){
			if (*temp1 == NULL)
			{
				*temp1 = loop[0];
				*temp2 = root;
			}
			else
				*temp2 = root;
		}
	}
	loop[0] = root;
	inoder_travel(root->right, temp1, temp2, loop);
}
void swap_data(struct node *temp1, struct node* temp2)
{
	int aux;
	aux = temp1->data;
	temp1->data = temp2->data;
	temp2->data = aux;
}
