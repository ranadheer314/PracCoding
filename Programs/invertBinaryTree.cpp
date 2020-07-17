#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int value;
	node* left;
	node* right;
};

struct node* newNode(int x) {
	struct node* nod = (struct node*)malloc(sizeof(struct node));
	nod->value = x;
	nod->left = nod->right = NULL;
	return(nod);
}

void inorder(struct node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->value << " ";
	inorder(root->right);

}
void mir(struct node* root) {
	if (root == NULL) {
		return;
	}
	struct node* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	mir(root->left);
	mir(root->right);

}

int main() {
	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(9);
	inorder(root);
	printf("\n");
	mir(root);
	inorder(root);

	return 0;
}
