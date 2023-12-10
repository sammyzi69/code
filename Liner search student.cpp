#include <iostream>
using namespace std;
struct Student{
	int Roll;
	char name[20];
	float marks;
};

class Student1{
	public:
		int m;
		Student S[20];
		void create(int n);
		void Display();
		void Search();
};

		void Student1::create(int n){
			m=n;
			for(int i=0;i<n;i++){
				cout<<"enter the name:";
				cin>>S[i].name;
				cout<<"enter the roll number:";
				cin>>S[i].Roll;
				cout<<"enter the marks:";
				cin>>S[i].marks;
			}
			
		}
		void Student1::Display(){
			for(int i=0;i<m;i++){
				cout<<"name of the student :"<<S[i].name<<endl;
				cout<<"Roll No. of student :"<<S[i].Roll<<endl;
				cout<<"marks of the student :"<<S[i].marks<<endl;
			}
			
		}
		
		void Student1::Search(){
			//the fuction searches the student by its roll number
			int R;
			int flag;
			cout<<"enter the roll number you wish to search in the list : ";
			cin>>R;
			for(int i=0;i<m;i++){
				if(S[i].Roll==R){
					cout<<"found the student record at indix value  "<<i;
					flag=1;
					return;
				}
			}
			if(flag!=1){
					cout<<"the entry doesn't exist in the record";
				}
		}
		
int main(){
	Student1 S1;
	S1.create(3);
	S1.Display();
	S1.Search();
}
