#include <iostream>
using namespace std;
class Cqueue{
	public:
		int Arr[7];
		int n=7;
		void Enqueue(int val);
		void Dequeue();
		void Display();
		int front=-1,rear=-1;
};
		
		
		void Cqueue::Enqueue(int value){
			if(front==0&&rear==n-1||front== rear+1){
				cout<<"\noverflow";
				return;
			}
			if(front==-1){
				front=0;
				rear=0;
			}
			
			
			else{
				if(rear==n-1){
					rear=0;
				}
				else{
					rear=rear+1;
				}
			}
			Arr[rear]=value;
		}
		void Cqueue::Dequeue(){
			if(front==-1){
				cout<<"\noverflow";
				return;
				
			}
			if(front==rear){
				front=-1;
				rear=-1;
			}
			else{
				if(front==n-1){
					front=0;
				}
				else{
					front=front+1;
				}
			}
		}
		
		void Cqueue::Display(){
			int f=front,r=rear;
			if(front==-1){
				cout<<"Empty";
				return;
			}
			if(f<=r){
				while(f<=r){
					cout<<Arr[f]<<" ";
					f++;
				}
			}
			else{
				while(f<(n)){
					cout<<Arr[f]<"  ";
					f++;
				}
				f=0;
				while(f<=r){
					cout<<Arr[f]<<" ";
					f++;
				}
			}
		}
int main(){
	Cqueue CQ;
	int ch;
	do{
		cin>>ch;
		switch(ch){
			case 1:{
				int val;
				cout<<"enter the value";
				cin>>val;
				CQ.Enqueue(val);
				break;
			}
			case 2:{
				CQ.Dequeue();
				break;
			}
			case 3:{
				CQ.Display();
				break;
			}
		};
	}while(ch!=4);
}
