#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	
	Node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
}; 

void Preorder(Node* node) {
	if(node==NULL) return;
	cout<<node->val<<" ";
	Preorder(node->left);
	Preorder(node->right);
}



Node* MinimalTree(int lower, int upper, int arr[]) {
	
	if(lower>upper) return NULL;
	int mid = (lower+upper)/2;
	Node* node = new Node(arr[mid]);
	node->left = MinimalTree(lower,mid-1,arr);
	node->right = MinimalTree(mid+1,upper,arr);
	return node;
}

int main() {
	int arr[]={1,2,3,4,6,7,8};
	
	Preorder(MinimalTree(0, 6, arr));
	return 0;
} 
