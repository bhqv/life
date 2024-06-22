#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define X 50
#define Y 100

int matrix[X][Y] = {0};

void setRandomMatrix(){
   
    srand(time(NULL));
    for(size_t i = 0; i < X; ++i){
        for(size_t j = 0; j < Y; ++j){
            int randbit = rand() % 2; 
            
            matrix[i][j] = randbit;
        }
    }

}



void prin(int matrix[X][Y]){
    for(size_t i = 0; i < X; ++i){
        
        for(size_t j = 0; j < Y; ++j){
            // printf("%d ", matrix[i][j]);
            if(matrix[i][j] == 1) printf("*");
            if(matrix[i][j] == 0) printf(" ");
            
        }
    
        printf("\n");
    } 
    // printf("\n\n\n\n");

}







/*
 *
 * {{1, 1, 0, 1, 0, 0, 0, 0}, 
 * { 1, 0, 0, 0, 0, 1, 1, 1}, 
 * { 0, 1, 1, 0, 1, 0, 0, 0}, 
 * { 1, 0, 1, 0, 0, 1, 0, 1}}
 *
 *
 * */

/*
int countNeighbors(int x, int y, int matrix[X][Y]){
    int count = 0;

    for(size_t i = 0; i < X; ++i){
        for(size_t j = 0; j < Y; ++j){
            if((i == x && j == y) || i < 0 || j < 0 || i == X || j == Y){
                continue;
            }
            
            count += matrix[i][j];
                
        }
    }
    return count;
}

// creates a copy of matrix O(X*Y) space complexity
void incrimentState(){

    int matrix_prev[X][Y] = matrix;
    for(size_t i = 0; i < X; ++i){
        for(size_t j = 0; j < Y; ++j){

            int neighbors = countNeighbors(i, j, matrix_prev);

            if ( matrix_prev[i][j] ){
                if( !( neighbors == 2 || neighbors == 3 ) ){
                    matrix[i][j] = 0; // kill the cell if neighbors != (2 or 3)
            
                } else if( neighbors == 3 ){
                    matrix[i][j] = 1; // dead cell with 3 neighbors, now alive
                } 
            }
        
        }
    }
}

*/



int countNeighborsOpt(int x, int y){
    int count = 0;

    for(size_t i = x - 1; i < x + 2; ++i){
        for(size_t j = y - 1; j < y + 2; ++j){
            if((i == x && j == y) || i < 0 || j < 0 || i == X || j == Y){
                continue;
            }
            if( matrix[i][j] == 1 || matrix[i][j] == 3){
                count++;
            }
        }
    } 
    return count;
}


// with O(1) space complexity
void incrementStateOptimized(){
    /*
     * old s  new s  state
     *  0      0      1
     *  1      1      2
     *  0      1      3
     *  1      0      4
     *
     * */

    for(size_t i = 0; i < X; ++i){
        for(size_t j = 0; j < Y; ++j){
            int neighbors = countNeighborsOpt(i, j);

            if ( matrix[i][j] ){
                if ( neighbors == 2 || neighbors == 3){
                    matrix[i][j] = 3;
                }
            } else if ( neighbors == 3 ) {
                matrix[i][j] = 2;
            } 
        }
    }


    for(size_t i = 0; i < X; ++i){    
        for(size_t j = 0; j < Y; ++j){

            if(matrix[i][j] == 1){
                matrix[i][j] = 0;
            }else if( matrix[i][j] == 2 || matrix[i][j] == 3){
                matrix[i][j] = 1; 
            }
        }
    }



}




void play(){

    setRandomMatrix();
    int t = 100;
//    while(t--){
    while(1){
        prin(matrix);
        incrementStateOptimized();
       
        // sleep(1); // uses sec 
        usleep(200000); // 1000000 micro sec -> 1s
    }


}


int main(void){
   
    // setRandomMatrix();
    // int c;  
    // c = countNeighborsOpt(2, 4);
    // printf("%d\n", c);
    // prin(matrix);
    play();

    



    return 0;
}
