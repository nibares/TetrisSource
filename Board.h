/*
 * Board.h
 *
 *  Created on: Apr 16, 2017
 *      Author: nico
 */

#ifndef BOARD_H_
#define BOARD_H_

class Board {
private:
    const char EMPTY = ' ';
    const int MAXROW=3, MAXCOLUMN=3;
    const int FALLINGBLOCKCOLUMN=1;


    char currentBlock;

    bool hasFallingBlocks;

public:
    char board[3][3];

    bool hasFalling();
    bool isEmpty();
    void drop(char oneBlock);
    void tick();

	Board();
    virtual ~Board();
};




#endif /* BOARD_H_ */
