#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end(),cmp1);
	int i=0;
	while(i<n&&a[i]>i+1) i++;
	cout<<i;
	return 0;
}
