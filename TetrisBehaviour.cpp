/*
 * TetrisBehaviour.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: nico
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Board.h"

SCENARIO("Board is empty.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("we create a board."){

			THEN ("The board is empty."){
                REQUIRE(board.isEmpty());
			}
		}
	}
}

SCENARIO("There are no falling blocks in the board.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("we create a board"){

            THEN ("The board has no falling blocks."){
                REQUIRE_FALSE(board.hasFalling());
            }
        }
    }
}

SCENARIO("After droping a block, the block falls.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is dropped to the board"){
            board.drop('X');

            THEN ("The block is falling."){
                REQUIRE(board.hasFalling());
            }
        }
    }
}

SCENARIO("After droping a block, starts falling through the middle top.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is dropped to the board"){
            board.drop('X');

            THEN ("The block starts from the middle top."){
                REQUIRE(board.board[0][1] == 'X');
            }
        }
    }
}

SCENARIO("After a tick the block keep falling through the middle center.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is dropped to the board AND after a tick"){
            board.drop('X');
            board.tick();

            char cellContent = board.board[1][1];

            THEN ("The block is at the middle center."){
                REQUIRE( cellContent == 'X');
            }
        }
    }
}

SCENARIO("At most only one block must fall at the same time.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is falling AND a new block is dropped."){
            board.drop('X');
            board.tick();

            THEN ("I should receive an error for this."){
                REQUIRE_THROWS_WITH(board.drop('Y'), Catch::Matchers::Contains("A block is already falling! Not possible to drop another block."));
            }
        }
    }
}

SCENARIO("When a block reaches the bottom stops.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is falling AND reaches the bottom."){
            board.drop('X');
            board.tick();
            board.tick();

            THEN ("Then the block stops."){
                REQUIRE(!board.hasFalling());
            }
        }
    }
}
