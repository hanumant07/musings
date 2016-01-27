/*
 * You are given a pointer to the root of a binary search tree and a value to be
 * inserted into the tree. Insert this value into its appropriate position in
 * the binary search tree and return the root of the updated binary tree. You
 * just have to complete the function.
 *
 * Author: Hanumant Singh <hanumant07@gmail.com>
 */

/*
 * struct node
 * {
 * int data;
 * node * left;
 * node * right;
 * }node;
 */
node * newNode(int value)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->right = temp->left = nullptr;
    return temp;
}
node * insert(node * root, int value)
{
   /* If the tree is empty, return a new node */
    if (root == NULL) return newNode(value);
    /* Otherwise, recur down the tree */
    if (value < root->data)
        root->left  = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    /* return the (unchanged) node pointer */
    return root;
}
