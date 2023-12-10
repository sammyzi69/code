#include <iostream>
using namespace std;
struct node{
	char data;
	node*left;
	node*right;
		};
		
struct Stacknode{
			node* data;
			Stacknode *next;
		};

class Stack{
	public:
		Stacknode*top;
		Stack(){
			Stacknode*top =NULL;
		}
		bool isEmpty();
		void push(node* val);
		node* pop();
		node* Show_top();
};
	bool Stack::isEmpty(){
		if(top==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	
	void Stack::push(node* val){
		Stacknode *temp = new Stacknode();
		temp->data =val;
		temp->next =top;
		top=temp;
	}
	
	node* Stack::pop(){
		if(isEmpty()){
			return NULL;
		}
		else{
			node* X;
			Stacknode *temp;
			X=top->data;
			temp=top;
			top=top->next;
			delete(temp);
			return X;
		}
	}
	node* Stack::Show_top(){
		if(isEmpty()){
			return NULL;
		}
		else{
			return top->data;
		}
	}
	
	class Tree{
		public:
			node* postfix_tree();
			node* prefix_tree();
			char postfix[20]="ab+cd-*";
			char prefix[20]="*+ab-cd";
			Stack S;
			void inorder(node *p);
			void postorder(node *p);
			void preorder(node *p);
	};
	
	void Tree::preorder(node *p){
		if(p!=NULL){
			cout<<p->data;
			preorder(p->left);
			preorder(p->right);
		}
	}
	
	void Tree::postorder(node*p){
		if(p!=NULL){
			postorder(p->left);
			postorder(p->right);
			cout<<p->data;
		}
	}
	
	void Tree::inorder(node*p){
		if(p!=NULL){
			inorder(p->left);
			cout<<(p->data);
			inorder(p->right);
		}
	}
	
	node* Tree::prefix_tree(){
		int i,j;
		node*p;
		for(i=0;prefix[i]!='\0';i++){
		}
		i--;
		for(;i>=0;i--){
			if(isalnum(prefix[i])){
				p=new node();
				p->data=prefix[i];
				p->left=NULL;
				p->right=NULL;
				S.push(p);
			}
			else{
				p=new node();
				p->data=prefix[i];
				p->left=S.pop();
				p->right=S.pop();
				S.push(p);
			}
		}
		return S.pop();
	}
	
	node* Tree::postfix_tree(){
		int i;
		node*p;
		for(i=0;postfix[i]!='\0';i++){
			if(isalnum(postfix[i])){
				p=new node();
				p->data=postfix[i];
				p->left=NULL;
				p->right=NULL;
				S.push(p);
			}
			else{
				p=new node();
				p->data=postfix[i];
				p->right=S.pop();
				p->left=S.pop();
				S.push(p);
			}
		}
		return S.pop();
				}
	
	int main(){
		Tree T;
		node *New=T.postfix_tree();
		node *New2=T.prefix_tree();
		T.inorder(New);
		cout<<endl;
		T.postorder(New2);
		cout<<endl;
		T.preorder(New);
		
	}
