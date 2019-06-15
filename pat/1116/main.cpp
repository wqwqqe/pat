#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool isprime(int a){
	int n=sqrt(a)+1;
	for(int i=2;i<n;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
int book[10000];
int book1[10000];
int main(){
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		book[a]=i+1;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		printf("%04d: ",a);
		book1[a];
		if(book[a]==0){
			printf("Are you kidding?\n");
		}else if(book[a]==1){
			if(book1[a]){
				printf("Checked\n");
			}else{
				printf("Mystery Award\n");
				book1[a]=1;
			}
		}else if(isprime(book[a])){
			if(book1[a]){
				printf("Checked\n");
			}else{
				printf("Minion\n");
				book1[a]=1;
			}
		}else{
			if(book1[a]){
				printf("Checked\n");
			}else{
				printf("Chocolate\n");
				book1[a]=1;
			}
		}
	}
	return 0;
}
