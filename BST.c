#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int num;
    struct node* left;
    struct node* right;
}node;
node* createNode(int num)
{
    node* tmp=malloc(sizeof(node));
    tmp->num=num;
    tmp->right=NULL;
    tmp->left=NULL;
    return tmp;
}
node* insert(node* node,int tmp)
{
    if(node==NULL)
    {
        return(createNode(tmp));
    }
    if(tmp > node->num)
    {
        node->right=insert(node->right,tmp);
    }
    else if(tmp < node->num)
    {
        node->left=insert(node->left,tmp);
    }
    return node;
}
void inorder(node* node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\n",node->num);
        inorder(node->right);
    }
}
int left_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->left;
    }
    return ht;
}
int right_height(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->right;
    }
    return ht;
}
int count(node* root)
{
    if (root == NULL)
        return 0;
    int lh = left_height(root);
    int rh = right_height(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + count(root->left) + count(root->right);
}
void preorder(node* node)
{
    if(node==NULL)
        return;
    printf("%d\n",node->num);
    preorder(node->left);
    preorder(node->right);
}
void postorder(node* node)
{
    if(node==NULL)
        return;
    preorder(node->left);
    preorder(node->right);
    printf("%d\n",node->num);
}
int smlele(node* node)
{
    if(node->left==NULL)
        return node->num;
    return smlele(node->left);
}
int largeele(node* node)
{
    if(node->right==NULL)
        return node->num;
    return largeele(node->right);
}
node* inorderpre(node* root)
{
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
    
}
node* Delete(node* node,int key)
{
    if(node==NULL) return node;
    else if(key > node->num) return node->right=Delete(node->right,key);
    else if(key < node->num) return node->left=Delete(node->left,key);
    if(node->left==NULL&&node->right==NULL)
    {
        free(node);
        return NULL;
    }
    else
    {
        struct node* tmp=inorderpre(node);
        node->num=tmp->num;
        node->left=Delete(node->left,tmp->num);
    }
    return node;
}
int main(void)
{
    node* root=NULL;
    int num,x;
    while (1)
    {
        printf("\n1.Insert an Element\n");
        printf("2.Print Tree in Inorder Traversal\n");
        printf("3.Print Tree in Postorder Traversal\n");
        printf("4.Print Tree in Preorder Traversal\n");
        printf("5.Print smallest Element in BST\n");
        printf("6.Print greatest Element in BST\n");
        printf("7.Delete an Element\n");
        printf("8.Print Number of Nodes in BST\n");
        printf("9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            printf("\nEnter Element: ");
            scanf("%d",&num);
            if(root==NULL) root=insert(root,num);
            insert(root,num);
            break;
        case 2:
            printf("Tree Displayed in Inorder Traversal\n");
            inorder(root);
            break;
        case 3:
            printf("Tree Displayed in Postorder Traversal\n");
            postorder(root);
            break;
        case 4:
            printf("Tree Displayed in Preorder Traversal\n");
            preorder(root);
            break;
        case 5:
            printf("\nSmallest Element in BST: %d\n",smlele(root));
            break;
        case 6:
            printf("\nGreatest Element in BST: %d\n",largeele(root));
            break;
        case 7:
            int key;
            printf("\nEnter Element to be Deleted: ");
            scanf("%d",&key);
            Delete(root,key);
            break;
        case 8:
            printf("\nNo of Nodes in BST: %d\n",count(root));
            break;
        case 9:
            exit(0);
        default:
            printf("\nInvalid Choice!!!\n");
            break;
        }
    }
    
}