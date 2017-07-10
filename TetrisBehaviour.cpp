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
#include <vector>

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
        std::vector<std::vector<bool>> pieceRepresentation;

        pieceRepresentation = {
                                {0,1,0},
                                {0,1,0},
                                {0,0,0}
                              };

        Piece piece;

        piece.createPiece(3,3, pieceRepresentation);

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

        std::vector<std::vector<bool>> pieceRepresentation;

        pieceRepresentation = {
                                {0,1,0},
                                {0,1,0},
                                {0,0,0}
                              };

        Piece piece;

        piece.createPiece(3,3, pieceRepresentation);

        WHEN("I rotate the piece to the right."){
            piece.rotateRight();

            pieceRepresentation = {
                                    {0,0,0},
                                    {0,1,1},
                                    {0,0,0}
                                  };

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
        piece.createPiece(3,3);

        std::vector<std::vector<bool>> pieceRepresentation;

        pieceRepresentation = {
                                {0,0,0},
                                {1,1,0},
                                {0,0,0}
                              };

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

//SCENARIO("Having a piece of 5 x 5 blocks.", "[TetrisRotatingPiecesOfBlocks]"){

//    GIVEN("A 5 by 5 piece"){
//        Piece piece;

//        bool pieceRepresentation [5][5];

//        pieceRepresentation[0][0] = false;
//        pieceRepresentation[1][0] = false;
//        pieceRepresentation[2][0] = false;
//        pieceRepresentation[3][0] = false;
//        pieceRepresentation[4][0] = false;

//        pieceRepresentation[0][1] = false;
//        pieceRepresentation[1][1] = false;
//        pieceRepresentation[2][1] = true;
//        pieceRepresentation[3][1] = true;
//        pieceRepresentation[4][1] = true;

//        pieceRepresentation[0][2] = false;
//        pieceRepresentation[1][2] = false;
//        pieceRepresentation[2][2] = true;
//        pieceRepresentation[3][2] = true;
//        pieceRepresentation[4][2] = false;

//        pieceRepresentation[0][3] = false;
//        pieceRepresentation[1][3] = false;
//        pieceRepresentation[2][3] = true;
//        pieceRepresentation[3][3] = false;
//        pieceRepresentation[4][3] = false;

//        pieceRepresentation[0][4] = false;
//        pieceRepresentation[1][4] = false;
//        pieceRepresentation[2][4] = false;
//        pieceRepresentation[3][4] = false;
//        pieceRepresentation[4][4] = false;


//        WHEN("I create the piece."){
//            piece.rotateLeft();

//            THEN ("Piece has many blocks."){

//                for (int column = 0; column < 5; column++){
//                    for (int row = 0; row < 5; row++) {
//                        REQUIRE(piece.pieceCanvas[column][row] == pieceRepresentation[column][row]);
//                    }
//                }

//            }

//        }
//    }
//}

