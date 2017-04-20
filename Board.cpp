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
    for(int i=0;i==3;i++){
        for(int j=0;j==3;j++){
            board[i][j]=' ';
        }
    } //Cerramos el i
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

bool Board::isEmpty() {
    bool result = true;

    for(int i=0;i==3;i++){
        for(int j=0;j==3;j++){
            if(board[i][j]!=' '){
                result = false;
            };
        }
    }

    return result;

}

bool Board::hasFalling(){
    hasFallingBlocks = false;
    return hasFallingBlocks;
}
