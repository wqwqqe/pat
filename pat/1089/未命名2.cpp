#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int i,j;
	for(i=0;i<n-1&&b[i]<=b[i+1];i++);
	for(j=i+1;j<n&&a[j]==b[j];j++);
	if(j!=n){
		cout<<"Merge Sort"<<endl;
		int flag=1,k=2;
		while(flag){
			flag=0;
			for(int j=0;j<n;j++){
				if(a[j]!=b[j]){
					flag=1;
					break;
				}
			}
			for(int j=0;j<n/k;j++){
				sort(a+j*k,a+(j+1)*k);
			}
			sort(a+n/k*k,a+n);
			k=k*2;
		}
	}else{
		cout<<"Insertion Sort"<<endl;
		sort(a,a+i+2);
	}
	printf("%d",a[0]);
	for(int j=1;j<n;j++){
		printf(" %d",a[j]);
	}
} 
