/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
void finding_leaf_nodes(struct node *, struct  node *, struct node *, int * );
void root_distance(struct node *, struct node *, int, int *);
int least_distance(struct node *, struct node * , struct node *);
struct node * common_root(struct node * root, struct node * leaf, struct node * temp);

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	else
	{
		int least = -1;
		finding_leaf_nodes(root, root, temp, &least);
		return least;
	}
}
void root_distance(node * node1, node * node2, int count, int * r){
	if (node1 == NULL || node2 == NULL)
		return;
	if (node1 == node2){
		*r = count;
		return;
	}
	else if (node1->data < node2->data){
		root_distance(node1->right, node2, count + 1, r);
	}
	else if (node1->data > node2->data){
		root_distance(node1->left, node2, count + 1, r);
	}
}
int least_distance(node * root, node * node1, node * node2){
	int x = 0, y = 0;
	node * sub = common_root(root, node1, node2);
	root_distance(sub, node1, 0, &x);
	root_distance(sub, node2, 0, &y);
	return  (x + y);
}

void  finding_leaf_nodes(struct node * org_root, struct  node * root, struct node * temp, int * r){
	if (root == NULL)
		return;
	if (root->left == NULL&&root->right == NULL){
		int distance = least_distance(org_root, root, temp);
		if (*r == -1)
			*r = distance;
		else if (distance < *r)
			*r = distance;
		return;
	}
	else{
		finding_leaf_nodes(org_root, root->left, temp, r);
		finding_leaf_nodes(org_root, root->right, temp, r);
		return;
	}
}
struct node * common_root(node * root, node * leaf, node * temp)
{
	if (leaf == NULL || temp == NULL)
		return NULL;
	else{
		if (leaf->data < root->data && temp->data < root->data){
			return common_root(root->left, leaf, temp);
		}
		else if (leaf->data > root->data && temp->data > root->data){
			return common_root(root->right, leaf, temp);
		}
		else
		{
			return root;
		}
	}
}
