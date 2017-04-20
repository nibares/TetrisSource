/*
 * Board.h
 *
 *  Created on: Apr 16, 2017
 *      Author: nico
 */

#ifndef BOARD_H_
#define BOARD_H_

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




#endif /* BOARD_H_ */
