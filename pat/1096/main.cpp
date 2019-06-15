#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long int a,j;
	cin>>a;
	long int max=sqrt(a)+1;
	int result=0,first;
	for(int i=2;i<max;i++){
		int flag=1;
		for(j=i;j<max;j++){
			flag*=j;
			if(a%flag!=0) break;
		}
		if(j-i>result){
			result=j-i;
			first=i;
		}
	}
	if(result==0){
		cout<<1<<endl;
		cout<<a;
	}else{
		cout<<result<<endl;
		for(int i=0;i<result;i++){
			cout<<first+i;
			if(i!=result-1) cout<<'*';
		}
	}
	return 0;
} 
