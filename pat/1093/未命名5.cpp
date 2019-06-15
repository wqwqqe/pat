#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size(),cp=0,ct=0,result=0;
	for(int i=0;i<n;i++){
		if(s[i]=='T') ct++;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='P') cp++;
		if(s[i]=='T') ct--;
		if(s[i]=='A') result=(result+(ct*cp)%1000000007)%1000000007;
	}
	cout<<result;
	return 0;
}
