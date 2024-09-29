#include<iostream>
#include<math.h>
using namespace std;

void Print(int board[][9], int n) // Print the solved Sudoku
{
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++)  
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isValid(int board[][9], int i, int j, int num, int n) 
{
    //Row Check and Column check.
    for(int x = 0; x<n; x++) 
    {
        if(board[i][x]==num or board[x][j]==num) 
        {
            return false;
        }
    }

    //SubMatrix Check
    int rn = sqrt(n);
    int si = i - i%rn;
    int sj = j - j%rn;

    for(int x = si; x<si+rn; x++)
    {
        for(int y = sj; y<sj+rn; y++)
        {
            if(board[x][y] == num) 
            {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver(int board[][9], int i, int j, int n) 
{
    //Base Case 
    if(i==n)
    {
        Print(board, n);
        return true;
    }

    //If we are not inside the board.
    if(j==n) 
    {
        return SudokuSolver(board, i+1, 0, n);
    }

    //if cell is already filled -> just move forward
    if(board[i][j] != 0) 
    {
        return SudokuSolver(board, i, j+1, n);
    }

    //fill the cell with appropriate number.

    for(int num = 1; num<=9; num++) 
    {
        //Check if number is valid?
        if(isValid(board, i, j, num, n)) 
        {
            board[i][j] = num;
            bool subAns = SudokuSolver(board, i, j+1, n);
            if(subAns) return true;

            //Backtacking -> undo the changes

            board[i][j] = 0;
        }
    }
    return false;
}


int main() 
{
    int t = 4;
    while(t--){
        int n = 9;
        int board[9][9];
        for(int i=0; i<9;i++) {
            for(int j=0; j<9; j++) {
                cin>>board[i][j];
            }
        }
    
        SudokuSolver(board, 0, 0, n);
        
    }
    return 0;
}