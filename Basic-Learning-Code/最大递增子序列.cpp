#include <iostream>
#include <algorithm>
#include <cstring>
#include <windows.h>
using namespace std;

const int MAX = 100+20;
int n;
int a[MAX];
int b[MAX];
//输入一行数 输出最大递增序列中含有元素的个数
//类似于 拦截导弹 那个stupid 问题
 
 
void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
 
int max_increasing_list(int point){
	int ans=0;
	b[0] = 1;
	for(int i=0;i<point;i++){
		b[i] = 1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i] && b[j] + 1>b[i]){
				b[i] = b[j] + 1;
			}
		}
		if(b[i]>ans){
			ans = b[i];
		}
	}
	return ans;
}
		
int main(){
	input();
	int temp = 0;
	memset(b,-1,sizeof(b));
	for(int i=0;i<n;i++){
		temp = max(temp,max_increasing_list(i));
	}
	cout<<temp<<endl;
}
