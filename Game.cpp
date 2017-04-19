/*
 * Board.cpp
 *
 *  Created on: Apr 16, 2017
 *      Author: nico
 */

#include "Game.h"
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
    return true;
}

void Game::start(){


}

Game::Game(){

};

Game::~Game(){

};
