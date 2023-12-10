#include <iostream>
#include <string.h>
using namespace std;
class Search{
	public:
		struct Student{
			char name[20];
			int Roll;
			float marks;
		};
		void create_student_roll_call();
		void Bsearch(char val[20]);
		Student S[3];
		int high=3,low=0;
};
	
	void Search::create_student_roll_call(){
		int count=0;
		while(count<3){
			cout<<"enter the name of the Student";
			cin>>S[count].name;
			cout<<"enter the Roll Number of the Student";
			cin>>S[count].Roll;
			cout<<"enter the marks of the Student";
			cin>>S[count].marks;
			count++;
		}
	}
	
	void Search::Bsearch(char val[20]){
		int mid;
		while(low<=high){
			mid=(high+low)/2;
			if(strcmp(S[mid].name,val)==0){
				cout<<val<<" is present at the "<<mid<<" index value";
				return;
			}
			else if(strcmp(val,S[mid].name)){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
	}

int main(){
	Search Sh;
	int ch;
	do{
		cin>>ch;
		switch(ch){
			case 1:{
				Sh.create_student_roll_call();
				break;
			}
			case 2:{
				char Input[20];
				cin>>Input;;
				Sh.Bsearch(Input);
				break;
			}
		}
	}while(ch!=3);
}


