#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int value)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *complete_tree(int elements[], struct node *root, int i, int size)
{
    if (i < size)
    {
        if (root == NULL)
        {
            root = create_node(elements[i]);
        }
        root->left = complete_tree(elements, root->left, 2 * i + 1, size);
        root->right = complete_tree(elements, root->right, 2 * i + 2, size);
    }
    return root;
}

void print_bt(struct node *root, int space, int height)
{
    if (root == NULL)
    {
        return;
    }

    space += height;

    print_bt(root->right, space, height);
    printf("\n");

    for (int i = height; i < space; ++i)
    {
        printf(" ");
    }

    printf("%d", root->data);
    printf("\n");
    print_bt(root->left, space, height);
}

void free_tree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int tree_height(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    return left_height > right_height ? left_height + 1 : right_height + 1;
}

int leaf_count(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return leaf_count(root->left) + leaf_count(root->right);
    }
}

void print_inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

int bst(struct node *root, long min, long max)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data <= min || root->data >= max)
    {
        return 0;
    }
    return bst(root->left, min, root->data) && bst(root->right, root->data, max);
}

int isValidBST(struct node *root)
{
    return bst(root, LONG_MIN, LONG_MAX);
}

int is_balanced(struct node *root)
{
    if (root == NULL)
    {
        return 1;
    }

    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    if (abs(left_height - right_height) <= 1 && is_balanced(root->left) && is_balanced(root->right))
    {
        return 1;
    }

    return 0;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return create_node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

struct node *delete_node(struct node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > k)
    {
        root->left = delete_node(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = delete_node(root->right, k);
        return root;
    }

    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        struct node *parent = root;
        struct node *successor = root->right;
        while (successor->left != NULL)
        {
            parent = successor;
            successor = successor->left;
        }

        if (successor != root)
        {
            parent->left = successor->right;
        }
        else
        {
            parent->right = successor->right;
        }
        root->data = successor->data;
        free(successor);
        return root;
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int elements[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &elements[i]);
    }
    size = sizeof(elements) / sizeof(elements[0]);
    struct node *root = NULL;
    root = complete_tree(elements, root, 0, size);

    int space = 0;
    int height = 5;
    print_bt(root, space, height);
    int h_tree = tree_height(root);
    printf("Height of the Binary Tree: %d\n", h_tree);
    int node_count = leaf_count(root);
    printf("Leaf count of the Binary Tree: %d\n", node_count);
    print_inorder(root);
    printf("\n");
    if (isValidBST(root))
    {
        printf("The tree is a BST.\n");
    }
    else
    {
        printf("The tree is not a BST.\n");
    }
    if (is_balanced(root))
        printf("The binary tree is balanced.\n");
    else
        printf("The binary tree is not balanced.\n");

    int node_to_delete;
    printf("The value to delete:");
    scanf("%d", &node_to_delete);
    root = delete_node(root, node_to_delete);
    print_bt(root, space, height);

    free_tree(root);
    return 0;
}
