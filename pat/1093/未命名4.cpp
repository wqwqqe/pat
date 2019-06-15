#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size();
	int i,j,k,l,m,o;
	long long num=0,cp,ca,ct;
	for(i=0;i<n;i++){
		cp=0,ca=0,ct=0;
		if(s[i]=='P'){
			for(j=i;j<n;j++){
				if(s[j]=='P') cp++;
				else break;
			}
			i=j;
			for(k=j;j<n;j++){
				if(s[k]=='A'){
					for(l=k;l<n;l++){
						if(s[l]=='A') ca++;
						else break;
					}
					k=l;
					for(m=l;m<n;m++){
						if(s[m]=='T'){
							for(o=m;o<n;o++){
								if(s[o]=='T') ct++;
								else break;
							}
							m=o;
						}
					}
				}
			}
		}
		//cout<<cp<<' '<<ca<<" "<<ct<<" ";
		//cout<<i<<' '<<k<<" "<<m<<" ";
		num+=cp*ca*ct;
	}
	cout<<num%1000000007;
	return 0;
}
