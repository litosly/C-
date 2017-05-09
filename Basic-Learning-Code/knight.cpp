#include <iostream>
#include <queue>
using namespace std;


const int MAXROW=100;
const int MAXCOL=100;


int board[MAXROW][MAXCOL];
int sx = 0;
int sy = 0; 


int fx[] = {2,2,1,1,-1,-1,-2,-2};
int fy[] = {-1,1,2,-2,2,-2,-1,1};

queue<int> x;
queue<int> y;


bool check(int n, int m, int a, int b){
	if(a<0 || b<0 || a>=n || b>=m || board[a][b] != 0){
		return false;
	}
	return true;
}


void knight(int n, int m, int i, int j){
	x.push(sx);
	y.push(sy);


 	
	while(!x.empty()){
		
		if(x.front()==i-1 && y.front()==j-1) break;
	
		for(int k=0;k<8;k++){
			
			int x_next = x.front()+fx[k];
			int y_next = y.front()+fy[k];
			
			if(check(n,m,x_next,y_next)){
				x.push(x_next);
				y.push(y_next);
				board[x_next][y_next] = board[x.front()][y.front()] + 1;
			}
		}
		x.pop();
		y.pop();
	}
	if(board[i-1][j-1]!= 0){
		cout<<board[i-1][j-1]<<endl;
	}
	else{
		cout<<"NEVAR"<<endl;
	}
}

int main(){
	int n,m,i,j;
	cin>>n>>m>>i>>j;
	knight(n,m,i,j);
}

