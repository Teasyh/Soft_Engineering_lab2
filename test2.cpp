#include <iostream>

using namespace std;

int maxprofit(int stock[],int days);

int main()
{
	cout<<"Please enter days and stock price "<<endl;
	int days;
	while(1){
		cin>>days;
		if(days>10000 || days<1){
			cout<<"Days should between 1 and 10000 "<<endl;
		}else{
			break;
		}
	} 
	
	int stock[days];
	for(int i=0;i<days;i++){
		cin>>stock[i];
	}
	int profit=maxprofit(stock,days);
	cout<<profit;
	return 0;
 } 
 
int maxprofit(int stock[],int days){
	int profit=0;
	for(int i=0;i<days;i++){
		for(int j=i+1;j<days;j++){
			if(stock[j]-stock[i]>profit){
				profit=stock[j]-stock[i];
			}
		}
	}
	return profit;
}

