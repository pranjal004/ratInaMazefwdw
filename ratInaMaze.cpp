#include<iostream>
#include<math.h>
#include<conio.h>

#define N 4

using namespace std;

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]);

//constraint boolian
bool isSafe(int maze[N][N], int x, int y)
{
  // bas maze se bahar na jaye aur 0 na ho
  if(x>=0 && y>=0 && x<N && y<N && maze[x][y]==1)
  return true;

  else
  return false;

}
// solution matrix, because solution cannot be edited within question
bool solution(int maze[N][N])
{
  int sol[N][N]= { { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 } };

    if(solveMaze(maze, 0, 0, sol) == false){
    cout<<"Sorry! Rat remains trapped!!"<<endl;
    return false;
    }
    else
    {

    for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
      {
        if(sol[i][j]==1)
        {
          cout<<"R ";
        }
        else
        {
          cout<<"_ ";

        }
      }
      cout<<endl;
    }
    cout<<endl<<"*******"<<endl;
  }
    return true;

}



bool solveMaze(int maze[N][N], int x, int y, int sol[N][N])
{
  // already at dest
   if(x== N-1 && y== N-1)
   {
     sol[x][y]=1;
     return true;
   }

   // constraints
   if(isSafe(maze, x, y)== true)
   {
     sol[x][y]=1;

   // row wise
   if(solveMaze(maze, x+1, y, sol)==true)
   return true;

   // downword
   if(solveMaze(maze, x, y+1, sol)==true)
   return true;

   // if no position
   sol[x][y]=0;
   return false;
  }
return false;

}
int main()
{
  // given maze
  int maze[N][N]= { {1,0,0,0},
                    {1,1,0,1},
                    {0,1,0,0},
                    {1,1,1,1} };
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      cout<<maze[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<"******"<<endl;

  solution(maze);

  return 0;
}
