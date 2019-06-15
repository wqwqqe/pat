#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int>  result;
int main(){
	int n,money;
	scanf("%d %d",&n,&money);
	vector<int> dia(n);
	for(int i=0;i<n;i++){
		scanf("%d",&dia[i]);
	}
	int min=999;
	int flag=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=dia[j];
			if(sum>=money){
				int d=sum-money;
				if(d==min){
					result.push_back(i+1);
					result.push_back(j+1);
					flag=flag+2;
					break;
				}else if(d>min){
					break;
				}else{
					result.clear();
					result.push_back(i+1);
					result.push_back(j+1);
					min=d;
					flag=2;
					break;
				}
			}
		}
	}
	int i=0;
	do{
		printf("%d-%d\n",result[i],result[i+1]);
		i=i+2;
	}while(i<flag);
	return 0;
}
