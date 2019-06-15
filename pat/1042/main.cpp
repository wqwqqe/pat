#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int begin[55],temp[55],end[55];
	for(int i=1;i<55;i++){
		scanf("%d",&temp[i]);
		end[i]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<55;j++){
			begin[j]=end[j];
		}
		for(int j=1;j<55;j++){
			end[temp[j]]=begin[j];
		}
	}
	char c[6]={"SHCDJ"};
	for(int i=1;i<55;i++){
		end[i]=end[i]-1;
		printf("%c%d",c[end[i]/13],end[i]%13+1);
		if(i!=54) printf(" ");
	}
	return 0;
} 
