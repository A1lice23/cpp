#include <bits/stdc++.h>

using namespace std;

struct node{
	char left;
	char right;
};

vector<node> t(30);

void preorder(char node){
	if(node == '.') return;

	cout << node;
	preorder(t[node].left);
	preorder(t[node].right);
}

void inorder(char node){
	if(node == '.') return;
	
	inorder(t[node].left);
	cout << node;
	inorder(t[node].right);
}

void postorder(char node){
	if(node == '.') return;

	postorder(t[node].left);
	postorder(t[node].right);
	cout << node;
}

int main(){	
	int n;
    char rt, l, r;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> rt >> l >> r;		
		t[rt].left = l;
		t[rt].right = r;
	}
	
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	
	return 0;
}
