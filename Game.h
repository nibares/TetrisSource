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
	bool isEmpty();
	Board();
	virtual ~Board();
};

class Game {
private:
	Board board;

public:
	void start();
	Game();
	virtual ~Game();
    bool boardIsEmpty();
};
#endif /* GAME_H_ */
