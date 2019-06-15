#include<iostream>
#include<string>
using namespace std;
int b[18000000]={0};
int main(){
	int a,n,m;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a;
			b[a]+=1;
		}
	}
	a=b[0];
	int max=0;
	for(int i=1;i<18000000;i++){
		if(a<b[i]){
			a=b[i];
			max=i;
		}
	}
	cout<<max;
	return 0;
} 
