#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){
	return b==0?abs(a):gcd(b,a%b);
}
int main(){
	long long a1,a2,b1,b2;
	long long a[4],b[4];
	long long gcd1,gcd2;
	char c[4]={'+','-','*','/'};
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	//printf("%lld,%lld,%lld,%lld",a1,a2,b1,b2);
	gcd1=gcd(a1,b1);
	//printf("%lld",gcd1);
	gcd2=gcd(a2,b2);
	//printf("%lld",gcd2);
	a1=a1/gcd1;
	b1=b1/gcd1;
	a2=a2/gcd2;
	b2=b2/gcd2;
	//printf("%lld,%lld,%lld,%lld",a1,a2,b1,b2);
	long long k1=0,k2=0;
	k1=a1/b1;
	k2=a2/b2;
	long long c1,c2;
	if(k1>=0){
		c1=a1-(k1*b1);
	}else{
		c1=(k1*b1)-a1;
	}
	if(k2>=0){
		c2=a2-(k2*b2);
	}else{
		c2=(k2*b2)-a2;
	}
	//printf("%lld,%lld",c2,k2);
	
	a[0]=a1*b2+a2*b1;
	b[0]=b1*b2;
	a[1]=a1*b2-a2*b1;
	b[1]=b1*b2;
	//printf("%lld,%lld",a[0],b[0]);
	a[2]=a1*a2;
	b[2]=b1*b2;
	a[3]=a1*b2;
	b[3]=b1*a2;
	//printf("%lld,%lld\n",a[2],b[2]);
	if(a[3]<0&&b[3]<0){
		a[3]=abs(a[3]);
		b[3]=abs(b[3]);
		//printf("%lld,%lld",a[3],b[3]);
	}else if(a[3]>0&&b[3]<0){
		a[3]=-a[3];
		b[3]=-b[3];
	}
	long long n,m;
	long long gcdv;
	for(int i=0;i<4;i++){
		gcdv=gcd(a[i],b[i]);
		a[i]=a[i]/gcdv;
		b[i]=b[i]/gcdv;
		if(b[i]!=0){
			n=a[i]/b[i];	
		}
		if(n>=0){
			m=a[i]-(n*b[i]);
		}else{
			m=(n*b[i])-a[i];
			}
		if(k1>0&&c1!=0){
			printf("%lld %lld/%lld ",k1,c1,b1);
		}else if(k1<0&&c1!=0){
			printf("(%lld %lld/%lld) ",k1,c1,b1);
		}else if(k1==0&&c1>0){
			printf("%lld/%lld ",c1,b1);
		}else if(k1==0&&c1<0){
			printf("(%lld/%lld) ",c1,b1);
		}else if(c1==0){
			if(k1==0){
				printf("0 ");
			}else if(k1>0){
				printf("%lld ",k1);	
			}else{
				printf("(%lld) ",k1);
			}
		}
		printf("%c ",c[i]);
		if(k2>0&&c2!=0){
			printf("%lld %lld/%lld = ",k2,c2,b2);
		}else if(k2<0&&c2!=0){
			printf("(%lld %lld/%lld) = ",k2,c2,b2);
		}else if(k2==0&&c2>0){
			printf("%lld/%lld = ",c2,b2);
		}else if(k2==0&&c2<0){
			printf("(%lld/%lld) = ",c2,b2);
		}else if(c2==0){
			if(k2==0){
				printf("0 = ");
			}else if(k2>0){
				printf("%lld = ",k2);	
			}else{
				printf("(%lld) = ",k2);
			}
		}
			if(i!=3){
				if(n>0&&m!=0){
				printf("%lld %lld/%lld\n",n,m,b[i]);
			}else if(n<0&&m!=0){
				printf("(%lld %lld/%lld)\n",n,m,b[i]);
			}else if(n==0&&m>0){
				printf("%lld/%lld\n",m,b[i]);
			}else if(n==0&&m<0){
				printf("(%lld/%lld)\n",m,b[i]);
			}else if(m==0){
				if(n==0){
					printf("0\n");
				}else if(n>0){
					printf("%lld\n",n);	
				}else{
					printf("(%lld)\n",n);
				}
			}
		}
	}
		if(c2==0&&k2==0){
			printf("Inf");
		}else if(c2!=0||k2!=0){
			if(n>0&&m!=0){
				printf("%lld %lld/%lld",n,m,b[3]);
			}else if(n<0&&m!=0){
				printf("(%lld %lld/%lld)",n,m,b[3]);
			}else if(n==0&&m>0){
				printf("%lld/%lld",m,b[3]);
			}else if(n==0&&m<0){
				printf("(%lld/%lld)",m,b[3]);
			}else if(m==0){
				if(n==0){
					printf("0");
				}else if(n>0){
					printf("%lld",n);	
				}else{
					printf("(%lld)",n);
				}
			}
		}
	
	
	return 0;
}
