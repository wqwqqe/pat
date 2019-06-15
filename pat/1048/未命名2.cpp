#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> coin;
int func(int i,int j,int sum){
	int left=i+1,right=j;
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(coin[mid]+coin[i]>sum){
			right=mid;
		}else if(coin[mid]+coin[i]<sum){
			left=mid+1;
		}else{
			return mid;
		}
	}
	return 0;
}

int main(){
	int n,sum;
	scanf("%d %d",&n,&sum);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		coin.push_back(temp);
	}
	sort(coin.begin(),coin.end());
	for(int i=0;i<n-1;i++){
		int a=func(i,n,sum);
		if(a==0){
			continue;
		}else{
			printf("%d %d",coin[i],coin[a]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
