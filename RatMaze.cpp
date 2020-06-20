#include<iostream>
using namespace std;
#define N 5

int isSafe(int x,int y,int A[N][N]){
  if(x<N && x>=0 && y<N && y>=0 && A[x][y]==1)
  return 1;
  return 0;
}

int solveMaze(int x,int y,int endx,int endy,int xmove[],int ymove[],int a[N][N]){
  if(x==endx && y==endy)
      return 1;
  int nextx,nexty;
  for(int i=0;i<4;i++){
    nextx=x+xmove[i];
    nexty=y+ymove[i];
    if(isSafe(nextx,nexty,a)){
      a[nextx][nexty]=9;
      if(solveMaze(nextx,nexty,endx,endy,xmove,ymove,a))
            return 1;
      else
        a[nextx][nexty]=1;
    }
  }
  return 0;
}

int main(){
  int A[N][N]={ { 1, 0, 1, 1,1 },
                       { 1, 1, 1, 0,1 },
                       { 0, 0, 1, 0,1 },
                       { 1, 1, 1, 1,1 },
                       {1,1,1,1,1}};

  int xmove[]={0,1,0,-1};
  int ymove[]={1,0,-1,0};

  int startx=0;
  int starty=0;
  int endx=4;
  int endy=4;
  A[startx][starty]=9;
  if(solveMaze(startx,starty,endx,endy,xmove,ymove,A)==1)
  cout<<"solution exists"<<endl;
  else cout<<"no solution"<<endl;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<A[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
