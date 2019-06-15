#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool fun(int a,int b){
	return a<b;
}
int main(){
	int a,n,m;
	vector<int> b;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a;
			b.push_back(a);
		}
	}
	sort(b.begin(),b.end(),fun);
	int flag,nums1=0,nums2=0;
	int N=b.size();
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			if(b[i]==b[j]){
				nums2++;
			}else{
				i=j-1;
				break;
			}
		}
		if(nums1<nums2){
			nums1=nums2;
			flag=i;
		}
		nums2=0;
	}
	cout<<b[flag];
	return 0;
} 
