#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	if(a<0){
		printf("Fu ");
		a=-a;
	}
	if(a==0){
		cout<<"ling";
		return 0;
	}
	vector<string> result;
	string s[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string s1[4]={"Shi","Bai","Qian"};
	string s2[3]={"Wan","Yi"};
	int count=0,count2=0;
	int flag;
	while(a!=0){
		int b=a%10;
		if(b==0){
			if(count%4==0&&count!=0){
				if(flag&&count2!=4){
					result.push_back("ling");
				}
				result.push_back(s2[count/4-1]);
				count++;
				count2=1;
				flag=false;
				a/=10;
				continue;
			}else{
				count2++;
				count++;
				flag=true;
				a/=10;
				continue;
			}
		}
		if(flag){
			if(count2!=count%4&&count2!=4){
				result.push_back("ling");
			}
			count2=0;
			flag=false;
		}
		if(count%4==0&&count!=0){
			result.push_back(s2[count/4-1]);
		}else if(count!=0){
			result.push_back(s1[count%4-1]);
		}
		result.push_back(s[b]);
		a=a/10;
		count++;
	}
	int t=result.size();
	for(int i=t;i>0;i--){
		cout<<result[i-1];
		if(result[i-1]=="Yi"){
			if(result[i-2]=="Wan"){
				i--;
			}
		}
		if(i!=1) cout<<" ";
	}
	return 0;
} 
