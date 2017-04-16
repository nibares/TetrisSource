/*
 * TetrisBehaviour.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: nico
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

SCENARIO("Have a 1x1 block fall down.", [TetrisFallingBlocks]){

	Board board;

	GIVEN("A game board"){

		WHEN("The game start"){

			THEN ("The board is empty."){

			}
		}
	}

}


