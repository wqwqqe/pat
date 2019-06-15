#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp1(long long a,long long b){
	return a<b;
}
int main(){
	int n;
	vector<long long> result;
	long long a;
	for(int i=0;i<2;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a;
			result.push_back(a);
		}
	}
	n=result.size();
	sort(result.begin(),result.end(),cmp1);
	cout<<result[n+1/2];
	return 0;
}
