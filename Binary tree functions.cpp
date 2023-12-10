#include <iostream>
using namespace std;
		struct node{
			int data;
			
			node*left=NULL;
			node*right=NULL;
		};


class binary_tree{
	public:
		node* Search(int val,node *root);
		node *root= NULL;
		node* insert(int val,node *root);
		node* Delete(node* root,int key);
		void save_root(node*bt);
		void Display(node*root);
		node* find_min(node* right);
		//The display occurs by the transversals
		
		
};
		
		node* binary_tree::find_min(node *r)
		{
			while(r->left!=NULL)
				{
				r=r->left;
				}
			return r;
			}
		
		
		
		node* binary_tree::Delete(node*root,int key){
			node *temp;
if(root==NULL)
{
return NULL;
}

if(key<root->data)
{
root->left=Delete(root->left,key);
return root;
}
if(key>root->data)
{
root->right=Delete(root->right,key);
return root;
}
//element found
//no child
if(root->left==NULL&root->right==NULL)
{
temp=root;
delete temp;
return NULL;
}
//one child
if(root->left!=NULL&&root->right==NULL)
{
temp=root;
root=root->left;
delete temp;
return root;
}

if(root->left==NULL&&root->right!=NULL)
{
temp=root;
root=root->right;
delete temp;
return root;
}
//both child present
temp=find_min(root->right);
root->data=temp->data;
root->right=Delete(root->right,temp->data);
return root;
}
		
		node* binary_tree::Search(int val,node *root){
			node *temp=root;
			while(temp!=NULL){
				if(temp->data==val){
					return temp;
				}
				if(temp->data>val){
					temp=temp->left;
				}
				else{
					temp=temp->right;
				}
				
			}
			return NULL;
		}
		
		
		void binary_tree::save_root(node*bt){
			root=bt;
		}
		
		node* binary_tree::insert(int val,node *root){
			node *p,*q,*r,*save;
			p=new node();
			p->data=val;
			p->left=NULL;
			p->right=NULL;
			if(root==NULL){
				return p;
			
			
			q=root;
			r=root;
			}
			else{
				r=root;
				while(r!=NULL){
					q=r;
					if(val>r->data){
						r=r->right;
					}
					else{

						r=r->left;
						
					}
				}
				if(val<q->data){
					q->left=p;
				
				}
				else{
					q->right=p;
				
				}
			}
			return root;
		}
		
		void binary_tree::Display(node *root){
			if(root!=NULL){
				Display(root->left);
				cout<<(root->data)<<"  ";
				Display(root->right);
			}
		}
		
int main(){
	binary_tree BT;
	int ch;
		do{
		cin>>ch;
	switch(ch){
		case 1:{
			node*bt=new node();
			int value;
			cout<<"enter the value";
			cin>>value;
			bt=BT.insert(value,BT.root);
			BT.save_root(bt);
			break;
		}
		case 2:{
			BT.Display(BT.root);
			break;
		}
		case 3:{
			int value;
			cout<<"enter the search";
			cin>>value;
			node *N;
			N=BT.Search(value,BT.root);
			if(N==NULL){
				cout<<0;
			}
			else{
				cout<<N->data;
			}
			break;
		}
		case 4:{
			int dlt;
			cout <<"enter the deletion";
			cin>>dlt;
			BT.Delete(BT.root,dlt);
			break;
		}
	};
}while(ch!=5);
}

