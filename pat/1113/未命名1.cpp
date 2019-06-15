#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	int n1=n/2;
	long long s1=0,s2=0;
	for(int i=0;i<n1;i++){
		s1+=a[i];
	}
	for(int i=n1;i<n;i++){
		s2+=a[i];
	}
	printf("%d %lld",n-2*n1,s2-s1);
	return 0;
} 
