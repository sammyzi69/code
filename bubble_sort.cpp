#include<iostream>
#include<string.h>
using namespace std;

typedef struct Student{
	int roll_num;
	char name[20];
	float marks;
	}stud;
	
void create(stud s[20],int n);
void display(stud s[20],int n);
void bubble_sort(stud s[20],int n);

void create(stud s[20],int n){
		int i;
		for(i=0;i<n;i++){
			cout<<"\n Enter The Roll Number:";
			cin>>s[i].roll_num;
			
			cout<<"\n Enter The Name:";
			cin>>s[i].name;
			
			cout<<"\n Enter The Marks";
			cin>>s[i].marks;
			}
		}
	
void display(stud s[20],int n){
	int i;
	cout<<"\n\t"<<"Roll Number"<<"\t";
	cout<<"Name"<<"\t"<<"Marks";
	
	for(i=0;i<n;i++){
		cout<<"\n";
		cout<<"\t"<<s[i].roll_num<<"\t";
		cout<<s[i].name<<"\t"<<s[i].marks;
		}
		
	}
	
void bubble_sort(stud s[20],int n){
	int i,j;
	stud temp;
	
	for(i=1;i<n;i++){
		for(j=0;j<n-1;j++){
			if(s[j].roll_num>s[j+1].roll_num){
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				}
			}
		}
	}

int main(){
	stud s[20];
	int ch,n,key,result;
	
	do{
		cout<<"\n 1) Create Student Database";
		cout<<"\n 2) Display Student Database";
		cout<<"\n 3) Bubble Sort";
		cout<<"\n 4) Exit";
		cout<<"\n Enter The Choice:";
		
		cin>>ch;
		switch(ch){
			
			case 1:cout<<"\n Enter The Number Of Records";
			cin>>n;
			create(s,n);
			break;
			
			case 2:display(s,n);
			break;
			
			case 3:bubble_sort(s,n);
			display(s,n);
			break;
			
			case 4:return 0;
			default:cout<<"Invalid!!!Choice,Enter Correctly";
			}
		}while(ch!=4);
	}	
				
	