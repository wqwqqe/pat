#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> a;
int n,p;
/*
int func(int i,long long temp){
	int left=i,right=n;
	while(left<right){
		int middle=(left+right)/2;
		if(a[middle]==temp) return middle;
		if(a[middle]<temp) left=middle+1;
		if(a[middle]>temp) right=middle-1;
	}
	return right;
}
*/
int main(){
	scanf("%d %d",&n,&p);
	a.resize(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	int maxn=0;
	int b;
	for(int i=0;i<n;i++){
		long long temp=a[i]*p;
		for(int j=i+maxn;j<n;j++){
			if(a[j]<=temp){
				b=j-i+1;
				if(b>maxn) maxn=b;
			}else{
				break;
			}
		}
	}
	cout<<maxn;
	return 0;
}

