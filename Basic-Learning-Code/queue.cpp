#include <iostream>
#include <queue>
using namespace std;
const int MAXROW = 10;
const int MAXCOL = 10;
int board[MAXROW][MAXCOL];

int fx[] = {2,2,1,1,-1,-1,-2,-2};
int fy[] = {-1,1,2,-2,2,-2,-1,1};

int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.front();
	q.back();
	cout<<q.front();
	q.pop();
}
