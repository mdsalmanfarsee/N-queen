// N queens
#include <bits/stdc++.h>
using namespace std;

bool flag=false;

bool isSafe(vector<vector<int>>&board,int row,int col,int n)
{
    //check top
    for(int i=row-1; i>=0; i--)
    {
        if(board[i][col]==1) return false;
    }
    
    //check top left corner
    for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j]==1) return false;
    }
    
    //check top right corner
    for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++)
    {
        if(board[i][j]==1) return false;
    }
    
    return true;
}

void solve(vector<vector<int>>&board,int row,int n)
{
    if(row==n)
    {
        //found a solution
        flag=true;
        //print the board
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<board[i][j]<<"  ";
            }
            cout<<endl;
            
        }
        cout<<"///////////////"<<endl;
        return;
    }
    
    for(int col=0; col<n; col++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]=1;
            
            solve(board,row+1,n);
            
            //backtrack
            board[row][col]=0;
        }
    }
}

int main() {
    int n=4;
  vector<vector<int>>board(n,vector<int>(n,0));
  solve(board,0,n);
  if(!flag)
  {
      cout<<"no arrangement exist"<<endl;
  }
  return 0;
}
