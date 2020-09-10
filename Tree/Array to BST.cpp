#include<iostream>
using namespace std;
int n;
typedef struct node
{
    int data;
    struct node* left,*right;
    node(int x)
    {
        data =x;
        left=NULL;
        right=NULL;
    }
}node;
node* create(int a[],int l,int r)
{
    
    if(l>r)return NULL;
    int mid=l+(r-l)/2;
   
    node* temp=new node(a[mid]);
    temp->left=create(a,l,(mid-1));
    temp->right=create(a,(mid+1),r);
    return temp;
}

void preorder(node* root)
{
    if(root==NULL){return;}
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    
	    cin>>n;
	    int a[n],ans[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    node* root=create(a,0,n-1);
	    preorder(root);
	    cout<<endl;
	}
	return 0;
}
