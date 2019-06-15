#include<iostream>
#include<string> 
#include<cstring>
using namespace std;
int main(){
	char num[21];
	cin>>num;
	int n=strlen(num);
	int book[10];
	for(int i=0;i<10;i++){
		book[i]=0;
	}
	int temp;
	int flag=0;
	for(int i=n-1;i>=0;i--){
		temp=num[i]-'0';
		book[temp]++;
		temp=temp*2+flag;
		flag=0;
		if(temp>=10){
			temp-=10;
			flag=1;
		}
		num[i]=temp+'0';
		book[temp]--;
	}
	int flag1=0;
	for(int i=0;i<10;i++){
		if(book[i]!=0) flag1=1;
	}
	if(flag==1||flag1==1){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	flag==1?cout<<"1"<<num<<endl:cout<<num<<endl;
	return 0;
}

