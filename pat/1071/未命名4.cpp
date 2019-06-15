#include<iostream>
#include<cctype>
#include<map>
using namespace std;
int main(){
	string s,t;
	getline(cin,s);
	map<string,int> m;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(isalnum(s[i])){
			s[i]=tolower(s[i]);
			t+=s[i];
		}
		if(!isalnum(s[i])||i==n-1){
			if(t.size()!=0) m[t]++;
			t="";
		}
	}
	int maxn=0;
	for(auto i=m.begin();i!=m.end();i++){
		if(i->second>maxn){
			t=i->first;
			maxn=i->second;
		}
	}
	cout<<t<<" "<<maxn;
	return 0;
}
