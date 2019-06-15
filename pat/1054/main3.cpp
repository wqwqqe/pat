#include<iostream>
#include<map>
using namespace std;
int main(){
	int a,n,m;
	map<int,int> b;
	scanf("%d %d",&m,&n);
	int half=n*m/2;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a);
			b[a]++;
			if(b[a]>half){
				printf("%d",a);
				return 0;
			}
		}
	}
	return 0;

} 
