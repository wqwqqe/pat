#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int red,green,blue;
	scanf("%d %d %d",&red,&green,&blue);
	vector<char> result;
	int temp1=red%13;
	red/=13;
	int temp2=red%13;
	char a;
	if(temp2>=10){
		a=temp2-10+'A';
	}else{
		a=temp2-0+'0';
	}
	result.push_back(a);
	if(temp1>=10){
		a=temp1-10+'A';
	}else{
		a=temp1-0+'0';
	}
	result.push_back(a);
	
	temp1=green%13;
	green/=13;
	temp2=green%13;
	if(temp2>=10){
		a=temp2-10+'A';
	}else{
		a=temp2-0+'0';
	}
	result.push_back(a);
	if(temp1>=10){
		a=temp1-10+'A';
	}else{
		a=temp1-0+'0';
	}
	result.push_back(a);
	
	temp1=blue%13;
	blue/=13;
	temp2=blue%13;
	if(temp2>=10){
		a=temp2-10+'A';
	}else{
		a=temp2-0+'0';
	}
	result.push_back(a);
	if(temp1>=10){
		a=temp1-10+'A';
	}else{
		a=temp1-0+'0';
	}
	result.push_back(a);
	printf("#");
	for(int i=0;i<6;i++) printf("%c",result[i]);
	return 0;
}
