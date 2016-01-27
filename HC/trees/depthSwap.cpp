#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node *newNode(int val)
{
    if (val == -1)
        return nullptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void constructTree(struct node *root, int n)
{
    struct node *parent = root;
    queue<struct node *> q;
    int val;
    q.push(parent);
    while(n && !q.empty()) {
            parent = q.front();
            q.pop();
            if (parent == nullptr)
                continue;
            cin >> val;
            cout << " For parent " << parent->data << endl;;
            struct node *curr = newNode(val);
            if (curr) {
	                cout << " Adding left child " << curr->data << endl;
	                parent->left = curr;
	                q.push(parent->left);
	            }
            cin >> val;
            curr = newNode(val);
            if (curr) {
	                cout << " Adding right child " << curr->data << endl;
	                parent->right = curr;
	                q.push(parent->right);
	            }
            n =- 2;
        }
}

void swapAtDepth(struct node *root, int sdepth)
{
    struct node *marker = newNode(0);
    queue<struct node *>q;
    q.push(root);
    int depth = 1;
    q.push(marker);
    while(!q.empty()) {
            struct node *curr = q.front();
            q.pop();
            if (curr == marker) {
	                depth++;
	                continue;
	            }
            if (depth == sdepth) {
	                struct node *temp = curr->right;
	                curr->right = curr->left;
	                curr->left = temp;
	            }
            else {
	                q.push(curr->left);
	                q.push(curr->right);
	            }
        }
}

void inOrder(struct node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, t;
    int depth;
    cin >> n;
    struct node *root = newNode(1);
    cout << "Construct tree" << endl;
    constructTree(root, n - 1);
    cout << "Tree done" << endl;
    inOrder(root);
    cout << endl;
    cin >> t;
    while(t--) {
            cin >> depth;
            swapAtDepth(root, depth);
            inOrder(root);
            cout << endl;
        }
    return 0;
}

