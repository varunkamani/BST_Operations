#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;
node* Insert(struct node *tree,int data);
node* Delete(struct node *tree,int data);
void Inorder(struct node *tree);
void preorder(struct node *tree);
void Postorder(struct node *tree);
node* FindMin(struct node *tree);
node* FindMax(node *tree);
main()
{

	int choice,data,option=1;
	while(option)
	{
	cout<<"\n\n1.Add Element\n";
	cout<<"2.Delete Element\n";
	cout<<"3.Inorder\n";
	cout<<"4.Preorder\n";
	cout<<"5.Postorder\n";
	cout<<"6.Find Minimum element\n";
	cout<<"7.Find Maximum element\n";
	cout<<"8.Exit\n";
	cout<<"Enter your choice :\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Your Element : ";
			cin>>data;
			root=Insert(root,data);
			break;
		case 2:
			cout<<"Your Element : ";
			cin>>data;
			root=Delete(root,data);
			cout<<data<<" Deleted\n";
			break;
		case 3:
			cout<<"Inorder : \n";
			Inorder(root);
			break;
		case 4:
			cout<<"Preorder : \n";
			preorder(root);
			break;
		case 5:
			cout<<"Postorder : \n";
			Postorder(root);
			break;
		case 6:
			{
			//When we declare new variable in swutch case it must be placed in block
			node* newnode = FindMin(root);;
			cout<<"Minimum element in tree is "<<newnode->data<<"\n";
			}
			break;
		case 7:
			{
			node* newnode = FindMax(root);
			cout<<"Maximum element in tree is "<<newnode->data<<"\n";
			}	
			break;	
		case 8:
			option=0;	
			break;
	        default:
			cout<<"Wrong choice\n";
			break;
	}
	}
	return 0;
}
node* FindMax(node* tree)
{
	while(tree->right!=NULL)
	{
		tree=tree->right;
	}
	return tree;
}
node* Insert(struct node *tree,int data)
{
	if(tree==NULL)
	{
		struct node *newnode = new node();
		newnode->data = data;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	else if(tree->data > data)
	{
		tree->left = Insert(tree->left,data);
	}
	else if(tree->data < data)
	{
		tree->right = Insert(tree->right,data);
	}
	return tree;
}
void preorder(struct node *tree)
{
	if(tree == NULL)
	{
		return;
	}
	
		cout<<tree->data<<" ";
		preorder(tree->left);
		preorder(tree->right);
	
}
void Postorder(struct node *tree)
{
	if(tree == NULL)
	{
		return;
	}
	
		Postorder(tree->left);
		Postorder(tree->right);
		cout<<tree->data<<" ";
	
}
void Inorder(struct node *tree)
{
	if(tree == NULL)
	{
		return;
	}
	
	Inorder(tree->left);
	cout<<tree->data<<" ";
	Inorder(tree->right);
	
}
node* FindMin(struct node *tree)
{
	while(tree->left != NULL)
	{
		tree=tree->left;
	}
	return tree;
}
node* Delete(struct node *tree,int data)
{
	if(tree == NULL)
	{
		return tree;
	}
	else if(tree->data < data)
	{
		tree->right=Delete(tree->right,data);
	}
	else if(tree->data > data)
	{
		tree->left=Delete(tree->left,data);
	}
	else
	{
		if(tree->right==NULL && tree->left == NULL)
		{
			delete tree;
			tree=NULL;
		}
		else if(tree->right==NULL)
		{
			struct node *newnode = tree;
			tree=tree->left;
			delete newnode;
		}
		else if(tree->left == NULL)
		{
			struct node *newnode = tree;
			tree=tree->right;
			delete newnode;
		}
		else
		{
			struct node *newnode = FindMin(tree->right);
			tree->data=newnode->data;
			tree->right=Delete(tree->right,newnode->data);
				
		}
	}
	return tree;
}
