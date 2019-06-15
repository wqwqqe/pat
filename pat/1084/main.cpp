#include<iostream>
#include<cstdio>
#include<map>
#include<cctype>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n1=s1.size(),n2=s2.size();
	map<char,int> a;
	map<char,int> b;
	for(int i=0;i<n2;i++){
		s2[i]=toupper(s2[i]);
		a[s2[i]]++;
	}
	for(int i=0;i<n1;i++){
		s1[i]=toupper(s1[i]);
		if(!a[s1[i]]){
			if(!b[s1[i]]){
				printf("%c",toupper(s1[i]));
				b[s1[i]]++;
			}
		}
	}
	return 0;
}
