/*
 * TetrisBehaviour.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: nico
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Board.h"
#include "Piece.h"
#include "stdio.h"

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
                REQUIRE(cellContent == 'X');
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

SCENARIO("When a block reaches the last cell should give the user the choice to move the block.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is falling AND reaches the last row."){
            board.drop('X');
            board.tick();
            board.tick();
            THEN ("The block still can be moved."){
                REQUIRE(board.hasFalling());
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
            board.tick();
            THEN ("Then the block stops."){
                REQUIRE(!board.hasFalling());
            }
        }
    }
}

SCENARIO("When another block falls inside another.", "[TetrisFallingBlocks]"){

    GIVEN("A 3 by 3 board"){
        Board board;

        WHEN("a 1 by 1 block is falling AND then another falls above it."){
            board.drop('X');
            board.tick();
            board.tick();
            board.tick();

            board.drop('Y');
            board.tick();

            THEN ("Then the block stops."){
                REQUIRE(board.hasFalling());
            }
        }
    }
}

SCENARIO("Having a piece to Rotate.", "[TetrisRotatingPiecesOfBlocks]"){

    GIVEN("A 3 by 3 piece"){
        Piece piece;
        bool pieceRepresentation [3][3];
        pieceRepresentation[0][0] = false;
        pieceRepresentation[1][0] = true;
        pieceRepresentation[2][0] = false;
        pieceRepresentation[0][1] = false;
        pieceRepresentation[1][1] = true;
        pieceRepresentation[2][1] = false;
        pieceRepresentation[0][2] = false;
        pieceRepresentation[1][2] = false;
        pieceRepresentation[2][2] = false;

        WHEN("a piece contains two blocks."){
            THEN ("The piece looks like two blocks."){
                for (int column = 0; column < 3; column++){
                    for (int row = 0; row < 3; row++) {
                        REQUIRE(piece.pieceCanvas[column][row] == pieceRepresentation[column][row]);
                    }
                }

            }

        }
    }
}

SCENARIO("Rotate piece right.", "[TetrisRotatingPiecesOfBlocks]"){

    GIVEN("A 3 by 3 piece"){
        Piece piece;
        bool pieceRepresentation [3][3];
        pieceRepresentation[0][0] = false;
        pieceRepresentation[1][0] = false;
        pieceRepresentation[2][0] = false;
        pieceRepresentation[0][1] = false;
        pieceRepresentation[1][1] = true;
        pieceRepresentation[2][1] = true;
        pieceRepresentation[0][2] = false;
        pieceRepresentation[1][2] = false;
        pieceRepresentation[2][2] = false;


        WHEN("I rotate the piece."){
            piece.rotateRight();

            THEN ("Piece looks rotated."){

                for (int column = 0; column < 3; column++){
                    for (int row = 0; row < 3; row++) {
                        REQUIRE(piece.pieceCanvas[column][row] == pieceRepresentation[column][row]);
                    }
                }

            }

        }
    }
}
SCENARIO("Rotate piece left.", "[TetrisRotatingPiecesOfBlocks]"){

    GIVEN("A 3 by 3 piece"){
        Piece piece;
        bool pieceRepresentation [3][3];
        pieceRepresentation[0][0] = false;
        pieceRepresentation[1][0] = false;
        pieceRepresentation[2][0] = false;
        pieceRepresentation[0][1] = true;
        pieceRepresentation[1][1] = true;
        pieceRepresentation[2][1] = false;
        pieceRepresentation[0][2] = false;
        pieceRepresentation[1][2] = false;
        pieceRepresentation[2][2] = false;


        WHEN("I rotate the piece."){
            piece.rotateLeft();

            THEN ("Piece looks rotated."){

                for (int column = 0; column < 3; column++){
                    for (int row = 0; row < 3; row++) {
                        REQUIRE(piece.pieceCanvas[column][row] == pieceRepresentation[column][row]);
                    }
                }

            }

        }
    }
}

