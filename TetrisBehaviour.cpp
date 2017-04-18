/*
 * TetrisBehaviour.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: nico
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"

SCENARIO("Have a 1x1 block fall down.", "[TetrisFallingBlocks]"){

	Game game;

	GIVEN("A game board"){

		WHEN("The game start"){
			game.start();

			THEN ("The board is empty."){
				REQUIRE(game.board.isEmpty());
			}
		}
	}

}


