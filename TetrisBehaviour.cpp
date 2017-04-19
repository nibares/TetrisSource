/*
 * TetrisBehaviour.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: nico
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"

SCENARIO("Have a 3x3 Board.", "[TetrisFallingBlocks]"){

	Game game;

    GIVEN("A 3 by 3 game board"){

		WHEN("The game start"){
			game.start();

			THEN ("The board is empty."){
				REQUIRE(game.board.isEmpty());
			}
		}
	}
}
