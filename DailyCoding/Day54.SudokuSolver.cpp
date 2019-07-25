#include<bits/stdc++.h>
using namespace std;

bool solveSudokuCell(int row,int col,vector<vector<char>> &board,vector<int> &filas,vector<int> &columnas,vector<int> &sudokus){
	if(col==board[row].size()){ col=0; row++; }
	if(row==board.size()) return true;
	if(board[row][col]!='.') return solveSudokuCell(row,col+1,board,filas,columnas,sudokus);
	vector<int> indices{0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,3,3,3,4,4,4,5,5,5,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,6,6,6,7,7,7,8,8,8,6,6,6,7,7,7,8,8,8};
	int ind=(9*row)+col;
	for(int k=0;k<9;k++){
		if(((1<<k)&filas[row])!=0&&((1<<k)&columnas[col])!=0&&(sudokus[indices[ind]]&(1<<k))!=0){
			board[row][col]=(k+1)+'0';
			filas[row]-=(1<<k);
			columnas[col]-=(1<<k);
			sudokus[indices[ind]]-=(1<<k);
			if(solveSudokuCell(row,col+1,board,filas,columnas,sudokus)){ return true; }
			filas[row]+=(1<<k);
			columnas[col]+=(1<<k);
			sudokus[indices[ind]]+=(1<<k);
		}
	}
	board[row][col]='.';
	return false;
}

bool solveSudoku(vector<vector<char>> &board){
	vector<int> sudokus(9,(1<<9)-1);
	vector<int> filas(9,(1<<9)-1);
    vector<int> columnas(9,(1<<9)-1);
    vector<int> indices{0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,3,3,3,4,4,4,5,5,5,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,6,6,6,7,7,7,8,8,8,6,6,6,7,7,7,8,8,8};
    int ind=0;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		if(board[i][j]!='.'){
    			int num=board[i][j]-'0';
    			filas[i]-=(1<<(num-1));
    			columnas[j]-=(1<<(num-1));
    			sudokus[indices[ind]]-=(1<<(num-1));
    		}
    		ind++;
    	}
    }
	return solveSudokuCell(0,0,board,filas,columnas,sudokus);
}



void sudokuSolver(vector<vector<char>> &board){
	vector<int> sudokus(9,(1<<10)-1);
	vector<int> filas(9,(1<<10)-1);
    vector<int> columnas(9,(1<<10)-1);
    vector<int> indices{0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,3,3,3,4,4,4,5,5,5,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,6,6,6,7,7,7,8,8,8,6,6,6,7,7,7,8,8,8};
    int ind=0;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		if(board[i][j]!='.'){
    			int num=board[i][j]-'0';
    			filas[i]-=(1<<(num-1));
    			columnas[j]-=(1<<(num-1));
    			sudokus[indices[ind]]-=(1<<(num-1));
    		}
    		ind++;
    	}
    }
    ind=0;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		if(board[i][j]=='.'){
	    		for(int k=0;k<9;k++){
	    			if(((1<<k)&filas[i])!=0&&((1<<k)&columnas[j])!=0&&(sudokus[indices[ind]]&(1<<k))!=0){
	    				board[i][j]=(k+1)+'0';
	    				filas[i]-=(1<<k);
	    				columnas[j]-=(1<<k);
	    				sudokus[indices[ind]]-=(1<<k);
	    				break;
	    			}
	    		}
    		}
    		ind++;
    	}
    }
}

int main(){
	vector<vector<char>> board(9);
	for(int i=0;i<9;i++){
		board[i]=vector<char>(9);
		for(int j=0;j<9;j++){
			cin>>board[i][j];
		}
	}

	bool b=solveSudoku(board);
	cout<<b<<"\n";
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}

}