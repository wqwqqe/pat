#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==0){
		printf("Yes\n");
		printf("0");
		return 0;
	}
	vector<int> c;
	int i=0;
	while(a){
		c.push_back(a%b);
		a/=b;
		i++;
	} 
	int n=c.size();
	int flag=0;
	int temp1,temp2;
	for(int j=0;j<n;j++){
		temp1=c[j];
		temp2=c[n-j-1];
		if(temp1!=temp2){
			flag=1;
			break;
		}
	}
	flag==1?printf("No\n"):printf("Yes\n");
	for(int j=n-1;j>0;j--){
		printf("%d ",c[j]);
	}
	printf("%d",c[0]);
	return 0;
}


