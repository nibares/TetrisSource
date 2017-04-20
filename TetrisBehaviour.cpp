/*
 * TetrisBehaviour.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: nico
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Board.h"

SCENARIO("Have a 3x3 Board.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){

        WHEN("we create a board."){
             Board board;

			THEN ("The board is empty."){
                REQUIRE(board.isEmpty());
			}
		}
	}
}

SCENARIO("There are no falling blocks in the board.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){

        WHEN("we create a board"){
            Board board;

            THEN ("The board has no falling blocks."){
                REQUIRE(board.hasFalling()==false);
            }
        }
    }
}
