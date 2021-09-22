#include <iostream>

using namespace std;

int main()
{
	cout<<"Please enter a integer"<<endl;
	int num;
	cin>>num;
	bool exist=false;
	for(int i=0;1<<i<=num;i++){
		if(1<<i==num){
			exist=true;
		}
	}
	if(exist){
		cout<<"True"<<endl;
	}else{
	    cout<<"False"<<endl;	
	}
	
	return 0;
}
