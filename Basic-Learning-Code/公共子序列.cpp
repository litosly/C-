#include <iostream>
#include <algorithm>
#include <cstring>
#include <windows.h>
using namespace std;

const int MAX = 200+20;
string a;
string b;
int board[MAX][MAX];

//longest common subsequence

int lcs(){
	memset(board,0,sizeof(board));
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			if((i==0 || j==0) && a[i] == b[j]) board[i][j] = 1;
			else if(a[i] == b[j] && i>0 && j>0){
				board[i][j] = board[i-1][j-1]+1;
			}
			else{
				board[i][j] = max(board[i-1][j],board[i][j-1]);
			}
			cout<<board[i][j];
		}
		cout<<endl;
		system("pause");
	}
	return board[a.length()-1][b.length()-1];
}

int main(){
	while(cin>>a>>b){
		cout<<lcs()<<endl;	
	}
}
