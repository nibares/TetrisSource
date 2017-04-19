/*
 * Board.h
 *
 *  Created on: Apr 16, 2017
 *      Author: nico
 */

#ifndef GAME_H_
#define GAME_H_

class Board {
public:
    char board[3][3];
    bool hasFallingBlocks;

    bool hasFalling();
	bool isEmpty();
	Board();
    Board(int BoardColumns,int BoardRows);
    virtual ~Board();
};

class Game {
public:
    Board board;

	void start();
	Game();
	virtual ~Game();
};
#endif /* GAME_H_ */
