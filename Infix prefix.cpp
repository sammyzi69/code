#include <iostream>
using namespace std;


class Stack{
	public:
		struct node{
			char data;
			node *link;
		};
		bool isEmpty();
		node*top=NULL;
		void push(char val);
		char pop();
		char show_top();
		void Display_Stack();
	
};		

		bool Stack::isEmpty(){
			if(top==NULL){
				return true;
			}
			else{
				return false;
			}
		}

		void Stack::push(char val){
			node *temp = new node();
			temp->data=val;
			temp->link=top;
			top=temp;
			}
		
		char Stack::pop(){
			if (isEmpty()){
				return 'N';
			}
			else{
				char x=top->data;
				node *temp=top;
				top=top->link;
				delete temp;
				return x;
			}
	}
		
		char Stack::show_top(){
			if(isEmpty()){
				return 'N';
			}
			else{
				return top->data;
			}
		}
		
		void Stack::Display_Stack(){
			node *temp;
			temp = top;
			while(temp!=NULL){
				cout<<temp->data<<"  ";
			}
		}
		
		
class Infix_Prefix{
	public:
		Stack S;
		void infix_prefix();
		char infix[20]="(2+3-1)*8/2";
		char prefix[20];
		char Rprefix[20];
		void Postfix(char infix[20]);
		char reverced[20];
		void reverse(char Arr[20],char Arr2[20]);
		void Evaluate();
		int Preferance(char x);
		int solve(int a,int b,char token);
		
		
		
};
		
		int Infix_Prefix::solve(int a,int b,char token){
			if(token=='+'){
				return a+b;
			}
			if(token=='-'){
				return a-b;
			}
			if(token=='*'){
				return a*b;
			}
			if(token=='/'){
				return a/b;
			}
		}
		void Infix_Prefix::infix_prefix(){
			char Rinfix[20];
			reverse(infix,Rinfix);
			Postfix(Rinfix);
			reverse(prefix,Rprefix);
		}
		
		void Infix_Prefix::Evaluate(){
			int i,result,x,y;
			char token;
			Stack S;
			for(i =0;Rprefix[i]!='\0';i++){}
			i--;
			for(;i>=0;i--){
				if(isalnum(Rprefix[i])){
					S.push(Rprefix[i]);
				}
				else{
					x=S.pop()-'0';
				
					y=S.pop()-'0';
					token =Rprefix[i];
					result=solve(x,y,token);
					S.push(result+'0');
				}
			}
				result=S.pop()-'0';
				cout<<"result is : "<<result;
		}
		
		void Infix_Prefix::reverse(char Arr[20],char Arr2[20]){
			int i,j;
			for(i=0;Arr[i]!='\0';i++){
			}
			i--;
			for(j=0;i>=0;j++,i--){
				if(Arr[i]=='('){
					Arr2[j]=')';
				}
				else if(Arr[i]==')'){
					Arr2[j]='(';
				}
				else{
					Arr2[j]=Arr[i];
				}
				}
				Arr2[j]='\0';
		}
		
		int Infix_Prefix::Preferance(char x){
				if(x=='('){
					return 0;
				}			
				else if (x=='+'||x=='-'){
					return 1;
				}
				else if(x=='*'||x=='/'){
					return 2;
				}
				return 3;
		}
		
		
		void Infix_Prefix::Postfix(char infix[20]){
			int i,j=0;
			char token,x;
			for(i =0;infix[i]!='\0';i++){
				token=infix[i];
				if(isalnum(token)){
					prefix[j]=infix[i];
					j++;
				}
				else{
					if(token=='('){
						S.push(token);	
					}
					else if(token==')'){
						while((x=S.pop())!='('){
						prefix[j]=x;
						j++;
						}
					}
					else{
						while(S.isEmpty()!=1&&Preferance(token)<=Preferance(S.show_top())){
							prefix[j]=S.pop();
							j++;
						}
						S.push(token);
					}
				}
			}
			while(S.isEmpty()!=1){
				prefix[j]=S.pop();
				j++;
			}
			prefix[j]='\0';
		}
	int main(){
		Infix_Prefix IP;
		IP.infix_prefix();
		for(int a=0;IP.Rprefix[a]!='\0';a++){
			cout<<IP.Rprefix[a]<<" ";
		}
		IP.Evaluate();
	}
