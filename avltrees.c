#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
    int height;
};
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct node *new_node(struct node *root, int key)
{
    root = (struct node *)malloc(sizeof(struct node));
    (root)->key = key;
    (root)->left = NULL;
    (root)->right = NULL;
    (root)->height = 0;
    return root;
}
void add_avl_tree(struct node **root, int key)
{
    if (*root == NULL)
    {
        *root = new_node(*root, key);
        return;
    }
    else if (key > (*root)->key)
    {
        add_avl_tree(&((*root)->right), key);
    }
    else if (key <= (*root)->key)
    {
        add_avl_tree(&((*root)->left), key);
    }
}
struct node *right_rotation(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
void read_avl_tree(struct node *tree)
{
    if (tree == NULL)
    {
        printf("Tree is null!");
        return;
    }
    printf("%3d", tree->key);
    if (tree->left != NULL)
        read_avl_tree(tree->left);
    if (tree->right != NULL)
        read_avl_tree(tree->right);
}

int main()
{
    struct node *tree = NULL;
    add_avl_tree(&tree, 10);
    add_avl_tree(&tree, 10);
    add_avl_tree(&tree, 5);
    add_avl_tree(&tree, 7);
    add_avl_tree(&tree, 9);
    add_avl_tree(&tree, 50);
    read_avl_tree(tree);
    return 0;
}