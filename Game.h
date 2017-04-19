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
public:
    Board board;

	void start();
	Game();
	virtual ~Game();
};
#endif /* GAME_H_ */
