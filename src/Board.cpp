/*
 * Board.cpp
 *
 *  Created on: Apr 16, 2017
 *      Author: nico
 */

#include "Board.h"
#include <string.h>

Board::Board() {

    for(int row=0;row<MAXROW;row++){
        for(int col=0;col<MAXCOLUMN;col++){
            board[row][col]= EMPTY;
        }
    }

    hasFallingBlocks = false;

    currentBlock.changeStatus(currentBlock.stopped);
    currentColumn = 0;
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

    if (currentColumn == MAXCOLUMN){
        hasFallingBlocks = false;
    }

    return hasFallingBlocks;
}

void Board::drop(char oneBlock){
    int row=0,col=FALLINGBLOCKCOLUMN;

    if ((oneBlock != currentBlock.blockChar) and !currentBlock.isMoving()){
        hasFallingBlocks = false;
    }

    if (hasFallingBlocks == false){
        currentBlock.blockChar = oneBlock;
        currentBlock.changeStatus(currentBlock.moving);

        hasFallingBlocks = true;
        board[row][col] = oneBlock;
    }
    else {
            throw "A block is already falling! Not possible to drop another block.";
    }
}

void Board::tick(){
    int previousRow;

    for (int row=(MAXROW-1);row >= 1; row--){
        previousRow = row - 1;

        for (int col=0; col < MAXCOLUMN; col++){
           board[row][FALLINGBLOCKCOLUMN] = board[previousRow][FALLINGBLOCKCOLUMN];
        }
    }

    *board[0] = EMPTY;

    currentColumn++;
    if (currentColumn == MAXCOLUMN){
        currentBlock.changeStatus(currentBlock.stopped);
    }

}
