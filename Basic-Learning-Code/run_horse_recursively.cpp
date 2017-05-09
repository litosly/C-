#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include<cstring>
#include<windows.h>

using namespace std;
const int MAXROW = 10;
const int MAXCOL = 10;
int board[MAXROW][MAXCOL];

int fx[] = {2,2,1,1,-1,-1,-2,-2};
int fy[] = {-1,1,2,-2,2,-2,-1,1};

bool check(int x,int y){
	if(x<1 || y<1 || x>8 || y>8 || board[x][y] != 0){
		return false;
	}
	return true;
}

void output(){
	for(int i=1;i<=8;i++){
		cout<<endl;
		for(int j=1;j<=8;j++){
			cout<<setw(3)<<board[i][j];
		}
	}
	cout<<endl;
	system("pause");
}

void run_table(int a, int b, int number){
	if(number == 64){
		output();
	}
	for(int i=0; i<8; i++){
		if(check(a+fx[i],b+fy[i])){
			int x = a+fx[i];
			int y = b+fy[i];
			
			board[x][y] = number+1;
		/*	for (int j = 1;j <= 8;++j){
				for (int k = 1;k <= 8;++k)
					cout<<board[j][k]<<" ";
				cout<<endl;
			}*/
		//	system("pause");
			run_table(x,y,number+1);
			board[x][y] = 0; //trace back
		}
	}
}

void run_horse(int x, int y){
	int number = 1; //start from (1,1)
	board[x][y] = number;
	run_table(x,y,number);
}

int main(){
	cout<<"the size of the table is "<<MAXROW<<" times "<<MAXCOL<<endl;
	int x,y;
	cout<<"the start point is";
	cin>>x>>y;
	memset(board,0,sizeof(board));
	run_horse(x,y);

	return 0;
}
