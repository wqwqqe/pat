#include<iostream>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int book[256]={0};
	for(int i=0;i<a.size();i++){
		book[a[i]]++;
	}
	int result=0;
	for(int i=0;i<b.size();i++){
		if(book[b[i]]>0){
			book[b[i]]--;
		}else{
			result++;
		}
	}
	if(result>0){
		printf("No %d",result);
	}else{
		printf("Yes %d",a.length()-b.length());
	}
	return 0;
} 
