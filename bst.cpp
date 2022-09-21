#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

class bst
{
public:
    NODE root;
    bst()
    {
        root = NULL;
    }
    void insertN();
    void deleteN();
    void search();
    void inorder(NODE);
    void preorder(NODE);
    void postorder(NODE);
};

void bst::insertN()
{
    NODE temp, prev, cur;
    int item;
    cout << "Enter the item to be inserted: ";
    cin >> item;
    temp = new node;
    temp->data = item;
    temp->right = temp->left = NULL;
    if (root == NULL)
    {
        root = temp;
        return;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->data)
        {
            cout << "Duplicate items not allowed.!" << endl;
            delete (temp);
            return;
        }
        cur = (item < cur->data) ? cur->left : cur->right;
    }
    (item < prev->data) ? prev->left = temp : prev->right = temp;
}

void bst::deleteN()
{
    NODE temp, cur, prev, next;
    int item;
    cout << "Enter the item to be deleted: ";
    cin >> item;
    if (root == NULL)
    {
        cout << "Tree is empty.!" << endl;
        return;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        if (item == cur->data)
            break;
        prev = cur;
        cur = (item < cur->data) ? cur->left : cur->right;
    }
    if (cur == NULL)
    {
        cout << "Item does not exist in the tree.!" << endl;
        return;
    }
    if (cur->left == NULL)
        temp = cur->right;
    else if (cur->right == NULL)
        temp = cur->left;
    else
    {
        next = cur->right;
        while (next->left != NULL)
            next = next->left;
        next->left = cur->left;
        temp = cur->right;
    }
    if (prev == NULL)
        root = temp;
    else if (prev->left == cur)
        prev->left = temp;
    else
        prev->right = temp;

    delete (cur);
}

void bst::search()
{
    NODE cur;
    int item;
    cout << "Enter the item to be searched: ";
    cin >> item;
    cur = root;
    while (cur != NULL && cur->data != item)
    {
        cur = (item < cur->data) ? cur->left : cur->right;
    }
    if (cur == NULL)
    {
        cout << "Item does not exist on the tree.!" << endl;    
        return;
    }
    cout << "Key item found.!!!" << endl;
}

void bst::inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " --> ";
        inorder(root->right);
    }
}

void bst::preorder(NODE root)
{
    if (root != NULL)
    {
        cout << root->data << " --> ";
        preorder(root->left);
        preorder(root->right);
    }
}

void bst::postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " --> ";
    }
}

int main()
{
    bst B;
    int ch;
    while (1)
    {
        cout << "\n1. Insert\t2. Delete\n3. Inorder, Preorder & Postorder\n4. Search\t5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            B.insertN();
            break;
        case 2:
            B.deleteN();
            break;
        case 3:
            cout << "Inorder traversal : ";
            B.inorder(B.root);
            cout << "\nPreorder traversal : ";
            B.preorder(B.root);
            cout << "\nPostorder traversal : ";
            B.postorder(B.root);
            break;
        case 4:
            B.search();
            break;
        case 5:
            exit(0);
        default:
            cout << "Enter correct choice: ";
            break;
        }
    }
    return 0;
}