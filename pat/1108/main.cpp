#include <iostream>
#include <cctype>
#include<algorithm>
#include<cstdio>
#include<sstream> 
using namespace std;
bool isLegal(string s){
	int flag=0,flag1=0;
	int n=s.size();
	int a=n;
	double num;
	stringstream change;
	for(int i=0;i<n;i++){
		if(!isdigit(s[i])&&s[i]!='.'&&s[i]!='-'){
			return false;
		}
		if(s[i]=='-'&&i!=0) return false;
		if(s[i]=='.'){
			flag++;
			a=i;
		}
		if(s[i]=='-'){
			flag1++;
		}
	}
	if(flag1>1) return false;
	if(flag>1) return false;
	if(n-a>3) return false;
	change<<s;
	change>>num;
	if(num>1000||num<-1000) return false;
	return true;
}
double changToNum(string s){
	stringstream a;
	a<<s;
	double sum;
	a>>sum;
	return sum;
}
int main(){
	int n;
	cin>>n;
	string s;
	double sum=0.0;
	int num=0;
	for(int i=0;i<n;i++){
		cin>>s;
		if(isLegal(s)){
			sum+=changToNum(s);
			num++;
		}else{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
	}
	sum=sum/num;
	if(num==1){
		printf("The average of 1 number is %.2f",sum);
	}else if(num==0){
		printf("The average of 0 numbers is Undefined");
	}else{
		printf("The average of %d numbers is %.2f",num,sum);
	}
	return 0;
}
