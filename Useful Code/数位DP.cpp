#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 15
#define S 205
int f[N][S],a[N];
int work(int x){
	if (x<=0)return 0;
	int l=0,sum=0,ans=0;
	while (x)a[++l]=x%10,x/=10;
	for (int i=l;i;--i){
		for (int j=0;j<a[i];++j)
			if (i&1)ans+=f[i-1][101-sum+j];
			else ans+=f[i-1][101-sum-j];
		if (i&1)sum-=a[i];
		else sum+=a[i];
	}
	return ans+(sum==1);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	memset(f,0,sizeof(f));
	f[0][100]=1;
	for (int i=1;i<=9;++i)
		for (int k=100-45;k<=100+45;++k)
			for (int j=0;j<=9;++j)
				if (i&1) f[i][k]+=f[i-1][k+j];
				else f[i][k]+=f[i-1][k-j];
	int T,l,r;scanf("%d",&T);
	while (T--){
		scanf("%d%d",&l,&r);
		printf("%d\n",work(r)-work(l-1));
	}
	system("pause");for (;;);
	return 0;
}


