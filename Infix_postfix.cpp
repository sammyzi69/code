#include <iostream>
using namespace std;
	struct node{
		char data;
		node*link;
	};
	static void swap(int A,int B){
		int Z=A;
		A=B;
		B=Z;
		
	}
	class Stack{
		public:
			bool isEmpty();
			void Push(char val);
			char pop();
			char Show_top();
			void display_stack();
			node *top= NULL;
	};
	bool Stack::isEmpty(){
		if(top==NULL){
			return true;
		}
		else{
			return false;
		}
		
	}
	void Stack::Push(char val){
		node*temp= new node();
		temp->data=val;
		temp->link=top;
		top=temp;
	}
	char Stack::pop(){
		if (isEmpty()){
			cout<<"Stack is Empty";
		}
		else{
			node*temp = top;
			char x = temp->data;
			top = top->link;
			delete(temp);
			return x;
		}
	}
	char Stack::Show_top(){
		if(isEmpty()){
			cout<<"Stack is Empty";
		}
		else{
			return top->data;
		}
	}
	void Stack::display_stack(){
		if(isEmpty()){
			cout<<"Stack is Empty";
		}
		else{
			node*temp=top;
			while(temp!=NULL){
				cout<<temp->data<<"   ";
				temp=temp->link;
				}
			cout<<"\n";
		}
	}
	class PostFix{
		public:
			void infix_postfix();
			int evaluate(int op1,int op2,char op);
			void Evaluation();
			int precedence(char x);
			void Display_postfix();
			char infix[20]="2*4-6/3";
			char postfix[20];
			void Evsluation();		
	};
	PostFix::precedence(char x){
		if(x=='(')
 			return 0;
		if(x=='+' || x=='-')
 			return 1;
		if(x=='*' || x=='/')
			return 2;
 		return 3;
	}
	void PostFix::infix_postfix(){
		Stack S;
		int i,j=0;
		char token,x;
		for(i=0;infix[i]!='\0';i++){
			token=infix[i];
			if(isalnum(token)){
				postfix[j]=token;
				j++;
			}
			else{
				if(token=='('){
					S.Push(token);
				}
				else if(token==')'){
					while((x=S.pop())!='('){
						postfix[j]=x;
						j++;
					}
				}
				else{
					while(S.isEmpty()!=1&&precedence(token)<=precedence(S.Show_top())){
						postfix[j]=S.pop();
						j++;
					}
					S.Push(token);
				}
			}
		}
		while(S.isEmpty()!=1){
			postfix[j]=S.pop();
			j++;
		}
		postfix[j]='\0';
		}
	void PostFix::Display_postfix(){
		int i=0;
		while(postfix[i]!='\0'){
			cout<<postfix[i]<<"  ";
			i++;
	}
}
	void PostFix::Evaluation(){
		Stack S;
		int result;
		for (int i =0;postfix[i]!='\0';i++){
			if(isalnum(postfix[i])){
				S.Push(postfix[i]);
			}
			else{
				int A = S.pop()-'0';
				int B = S.pop()-'0';
				char token=postfix[i];
				result=evaluate(B,A,token);
				S.Push(result+'0');
		}
	}
	result =S.pop()-'0';
	cout<<"\nresult="<<result;
}
	int PostFix::evaluate(int op1,int op2,char op){
		if(op=='+'){
			return op1+op2;
		}
		if(op=='-'){
			return op1-op2;
		}
		if(op=='*'){
			return op1*op2;
		}
		if(op=='/'){
			return op1/op2;
		}
	}
	int main(){
		PostFix P;
		P.infix_postfix();
		P.Display_postfix();
		P.Evaluation();
	}
	
