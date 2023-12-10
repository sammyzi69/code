#include <iostream>
#include <string.h>
using namespace std;
class Sort{
	public:
		struct Student{
			char name[20];
			int Roll;
			float marks;
		};
		Student S[3];
		void set_array();
		void Insertion_sort();
		void Display();
};
			
		void Sort::set_array(){
			int count =0;
			while(count<3){
				cout<<"Enter the name of the student :";
				cin>>S[count].name;
				cout<<"Enter the Roll number of the studebnt :";
				cin>>S[count].Roll;
				cout<<"Enter the marks of the student :";
				cin>>S[count].marks;
				count++;
		}
	}
		
		
		void Sort::Insertion_sort(){
			for(int i=1;i<3;i++){
				for(int j=i;j>0;j--){
					if((strcmp(S[j-1].name,S[j].name))>0){
					
						Student Key;
						Key = S[j];
						S[j]=S[j-1];
						S[j-1]=Key;
					}
				}
			}
			
		}
		
		void Sort::Display(){
			for(int i =0;i<3;i++){
			cout<<"the name of the Student is :"<<S[i].name<<endl;
			cout<<"the Roll of the Student is :"<<S[i].Roll<<endl;
			cout<<"the marks of the Student is :"<<S[i].marks<<endl;
			}
		}
		
int main(){
	Sort SO;
	int ch;
	do{
		cout<<"Enter the choice: ";
		cin>>ch;
		switch(ch){
			case 1:{
				SO.set_array();
				break;
			}
			case 2:{
				SO.Insertion_sort();
				break;
			}
			case 3:{
				SO.Display();
				break;
			}
		};
		
	}while(ch!=4);
}
