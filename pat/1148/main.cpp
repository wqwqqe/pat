#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<n+1;i++) cin>>a[i];
	for(int i=1;i<n+1;i++){
		for(int j=i+1;j<n+1;j++){
			vector<int> lies,c(n+1,1);
			c[i]=-1;
			c[j]=-1;
			for(int k=1;k<=n;k++){
				if(a[k]*c[abs(a[k])]<0) lies.push_back(k);
			}
			if(lies.size()==2&&(c[lies[0]]+c[lies[1]]==0)){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution";
	return 0;
} 
