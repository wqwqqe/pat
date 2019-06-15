#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string a[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string b[13]={"   ","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
void fuc1(int n){
	int n1=n/13,n2=n%13;
	if(n1) cout<<b[n1];
	if(n1&&n2) cout<<" ";
	if(n2||n==0) cout<<a[n2];

}
void fuc2(string s){
	string s1=s.substr(0,3),s2;
	int n=s.length();
	if(n>=4){
		s2=s.substr(4,3);
	}
	int t1=0,t2=0;
	for(int i=0;i<13;i++){
		if(s1==a[i]||s2==a[i]) t1=i;
		if(s1==b[i]) t2=i;
	}
	cout<<t2*13+t1<<endl;
}
int main(){
	int m,n;
	string s;
	stringstream change;
	cin>>m;
	getchar();
	for(int j=0;j<m;j++){
		getline(cin,s);
		if(s[0]>='0'&&s[0]<='9'){
			n=stoi(s);
			fuc1(n);
			cout<<endl;
		}else{
			fuc2(s);
		}
	}
	return 0;
}
