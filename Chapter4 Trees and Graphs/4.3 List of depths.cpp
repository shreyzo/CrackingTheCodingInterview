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

void printLL(Node* node) {
	while(node!=NULL) {
		cout<<node->val<<" ";
		node=node->right;
	}
	cout<<endl;
}

vector<Node*> convert(Node* node){
	queue<Node *> q;
	q.push(node);
	vector<Node *> res;
	while(!q.empty()) {
		Node* head = q.front();
		Node* temp = head;
		int n=q.size();
		for(int i=0; i<n; i++) {
			if(q.front()->left!=NULL) {
				q.push(q.front()->left);
			}
			if(q.front()->right!=NULL) {
				q.push(q.front()->right);
			}
			q.pop();
			if(i!=n-1){
				temp->right=q.front();
				temp=temp->right; 
			}
			else {
				temp->right=NULL;
			}
						
		} 
		res.push_back(head);
	}
	return res;

}


int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	vector<Node *> res = convert(root);
	
	for(int i=0; i<res.size(); i++) {
		printLL(res[i]);
	}
	
	return 0;
} 
