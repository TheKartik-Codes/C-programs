#include <stdio.h>
#include<stdlib.h>

//A structure to represent a node of binary tree
struct node
{
    int data;// data of the node
    struct node *left;//self referencing pointer to indicate a left node
    struct node *right;//self referencing pointer to indicate a right node
};


struct node* createbinarytree()
{
    return NULL;
}

struct node* createnode( int data )
{
    struct node*newnode;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
}

void insert(struct node**root,int data)
{
    if ( *root==NULL )
    {
        *root=createnode(data);
    }
    else if ( data < (*root)->data )
    {
        insert(&(*root)->left,data);
    }
    else
    {
        insert(&(*root)->right,data);
    }
}


void inorder(struct node*root )
{
    if ( root==NULL )
        return;
        
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
}

struct node* searchnode(struct node* root, int target )
{
    if (root==NULL || root->data==target )
    {
        return root;
    }
    else if ( target < root->data )
    {
        searchnode(root->left,target);
    }
    else
    {
        searchnode(root->right,target);
    }
}

void postorder(struct node*root )
{
    if ( root==NULL )
        return;
    
    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
}

void preorder(struct node*root )
{
    if ( root==NULL )
        return;
     
    printf("\t%d",root->data);
    postorder(root->left);
    postorder(root->right);
}


int countnode(struct node*root)
{
    if ( root==NULL )
    {
         return 0;
    }
    
    return 1+countnode(root->left)+countnode(root->right);
}


int main()
{
    int choice,data;
    
    struct node *bt;
    
    printf("\n--------Binary tree operations--------\n");
    printf("\n1.Create a binary tree.");
    printf("\n2.Insert data to binary tree.");
    printf("\n3.Search in binary tree");
    printf("\n4.Inorder traversal.");
    printf("\n5.Postorder traversal.");
    printf("\n6.Preorder traversal");
    printf("\n7.Count the nodes.");
    printf("\n8.Exit ");
    
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 : 
                   bt=createbinarytree();
                   printf("\nCreated an empty binary tree.\n");
                   break;
                  
            case 2 : 
                   printf("\nEnter data: ");
                   scanf("%d",&data);
                   insert(&bt,data);
                   break;
             
             
            case 3 : 
                   printf("\nEnter the element you want to search:");
                   scanf("%d",&data);
                   struct node* found=searchnode(bt,data);
                   
                   if (found )
                   {
                       printf("\n%d found in tree.",data);
                   }
                   else 
                   {
                       printf("\n%d not found in tree.",data);
                   }
                   break;
           
            case 4 :
                   printf("\nInorder traversal: \n");
                   inorder(bt);
                   break;
            
            case 5 :
                    printf("\nPostorder traversal:\n");
                    postorder(bt);
                    break;
            
            case 6 : 
                   printf("\nPreorder traversal:\n");
                   preorder(bt);
                   break; 
                   
            case 7 :
                   int count=countnode(bt);
                   printf("\nTotal nodes are %d.",count);
                   break;
                   
            case 8: 
                  printf("\nProgram execution successful.\n");
                  exit(0);
            
            default:
                   printf("\nWrong choice.\n");
                    
        }
        
    }while( choice != 8 );
    return 0;
  }