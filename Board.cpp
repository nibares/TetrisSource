/*
 * Board.cpp
 *
 *  Created on: Apr 16, 2017
 *      Author: nico
 */

#include "Board.h"
#include <string.h>

Board::Board() {
	// TODO Auto-generated constructor stub

    for(int row=0;row<MAXROW;row++){
        for(int col=0;col<MAXCOLUMN;col++){
            board[row][col]= EMPTY;
        }
    } //Cerramos el i

    hasFallingBlocks = false;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

bool Board::isEmpty() {
    bool result = true;

    for(int row=0;row<MAXROW;row++){
        for(int col=0;col<MAXCOLUMN;col++){
            if(board[row][col]!= EMPTY){
                result = false;
            };
        }
    }

    return result;

}

bool Board::hasFalling(){

    return hasFallingBlocks;
}

void Board::drop(char oneBlock){
    int row=0,col=1;
    hasFallingBlocks = true;

    board[row][col] = oneBlock;

}

void Board::tick(){
    int previousRow;

    for (int row=(MAXROW-1);row >= 1; row--){
        previousRow = row - 1;

        for (int col=0; col < MAXCOLUMN; col++){

            board[row][0] = board[previousRow][0];
            board[row][1] = board[previousRow][1];
            board[row][2] = board[previousRow][2];
        }

    }

    *board[0] = EMPTY;
}
