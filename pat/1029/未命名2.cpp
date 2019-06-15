#include<iostream>
using namespace std;
int k[200005];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
	}
	k[n]=0x7fffffff;
	int temp,count=0;
	scanf("%d",&m);
	int flag=(n+m+1)/2;
	int i=0;
	for(int j=0;j<m;j++){
		scanf("%d",&temp);
		while(k[i]<temp){
			count++;
			if(count==flag) cout<<k[i];
			i++;
		}
		count++;
		if(count==flag) cout<<temp;
	}
	while(i<n){
		count++;
		if(count==flag) cout<<k[i];
		i++;
	}
	return 0;
}
