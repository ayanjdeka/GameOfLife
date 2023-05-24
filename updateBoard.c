/*Ayan Deka: I implemented three functions in this file. The first function that I did was the countLiveNeighbor. Using the algorithym provided in the course page,
I followed the same steps to see if it was within the bounds of the array. Then I checked if it was live, and then added one to the count. The second function that
I did was update board. In this, I went through all of the cells within the board. Using the countneighbor function, I updated the board with new live and dead cells
based on that count. In the alivestable function, I created a new array called newboard. I filled it with all of the oldl valued of board. I then updated the board 
with my updateboard function. After this, I comared this with the old board. If they were not equal, then I returned 0, and otherwise I returned 1.  

*/
int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
  int count = 0;
 

  for(int i = (row-1); i <= (row+1); i++){ //algorithm for checking if the cell is alive or dead 
    if(i >= 0 && i < boardRowSize){ //checking the bounds
          for(int j = (col-1); j <= (col+1); j++){
	    if(j>=0 && j<boardColSize){ //checking the bounds again
	      if(i != row || j != col){//checking it we are checking the current cell or not
		    if(board[i*(boardColSize) + j] == 1){
                      count += 1;//adds one if the current cell is alive, otherwise adds none. 
		    }
                  }
              }
          }
      }
   }
   
  return count;

}

void updateBoard(int* board, int boardRowSize, int boardColSize) {

 
  int size = boardRowSize * boardColSize;//set the size of the array
  int newBoard[size];//where updated board will go

  for(int i = 0;i < boardRowSize;i++){//go through the row of the array

    for(int j = 0;j<boardColSize;j++){//go through the column of the array

      int countOfLiveNeighbors = countLiveNeighbor (board,boardRowSize,boardColSize,i,j);//get the count of live neighbors

      if((*(board+ (i*(boardColSize)) + j)==1)&& ((countOfLiveNeighbors == 2)|| (countOfLiveNeighbors == 3))){//if current cell is live and if countofliveneighbors is
                                                                                                         	//2 or 3, then set newboard to 1

	newBoard[i*boardColSize + j] = 1;

      }else if((*(board+ (i*(boardColSize)) + j)==1)&& ((countOfLiveNeighbors != 2)|| (countOfLiveNeighbors != 3))){//else set it to 0
	newBoard[i*boardColSize + j] = 0;

      }else if((*(board+ (i*(boardColSize)) + j)==0)&& ((countOfLiveNeighbors == 3))){//else if current cell is dead and countofliveneighbors is 0, set newboard to 1

	newBoard[i*boardColSize + j] = 1;

      }else{
	newBoard[i*boardColSize + j] = 0;//else set it to 0

      }

    }

  }

  for(int currRow = 0;currRow < boardRowSize;currRow++){
     for(int currCol = 0;currCol < boardColSize;currCol++){
       *(board+ (currRow*(boardColSize)) + currCol) = newBoard[currRow*boardColSize+currCol];

     }



  }



}


int aliveStable(int* board, int boardRowSize, int boardColSize){

  int size = boardRowSize * boardColSize;
  int newBoard[size];

  for(int currRow = 0;currRow < boardRowSize;currRow++){
     for(int currCol = 0;currCol < boardColSize;currCol++){
       *(board+ (currRow*(boardColSize)) + currCol) = newBoard[currRow*boardColSize+currCol];//set the newboard to the board that was in the parameter

     }
  }
  
  updateBoard(newBoard,boardRowSize,boardColSize);//update the newboard

  for(int currRow = 0;currRow<boardRowSize;currRow++){

    for(int currCol = 0;currCol<boardColSize;currCol++){

      if(newBoard[currRow * boardColSize+currCol] !=  board[currRow*boardColSize+currCol]){//compare each cell and see if they are the same
	return 0;//return 0 if they are different

      }

    }

  }

  return 1;//return 1 if they are equal

}

				
				
			

