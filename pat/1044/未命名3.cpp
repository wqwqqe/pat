#include<iostream>
#include<vector>
using namespace std;
int n,money;
vector<int> dia;
vector<int>  result;
void func(int i,int &j,int &temp){
	int left=i,right=n;
	while(left<right){
		int mid=(left+right)/2;
		if((dia[mid]-dia[i-1])>=money){
			right=mid;
		}else{
			left=mid+1;
		}
	}
	j=right;
	temp=dia[j]-dia[i-1];
}
int main(){
	scanf("%d %d",&n,&money);
	dia.resize(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&dia[i]);
		dia[i]+=dia[i-1];
	}
	int min=dia[n];
	for(int i=1;i<=n;i++){
		int j,temp;
		func(i,j,temp);
		if(temp>min) continue;
		if(temp>=money){
			if(temp<min){
				result.clear();
				min=temp;
			}
			result.push_back(i);
			result.push_back(j);

		}
	}
	for(int i=0;i<result.size();i=i+2){
		printf("%d-%d\n",result[i],result[i+1]);
	}
	return 0;
}
