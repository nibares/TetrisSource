#ifndef TETROMINO_H
#define TETROMINO_H

#include "Piece.h"

class Tetromino
{
private:
    const std::vector<std::vector<bool>> T_SHAPE = {
                                                        {1,1,1},
                                                        {0,1,0},
                                                        {0,0,0}
                                                   };
    const std::vector<std::vector<bool>> O_SHAPE = {
                                                        {0,1,1},
                                                        {0,1,1},
                                                        {0,0,0}
                                                    };
    const std::vector<std::vector<bool>> I_SHAPE = {
                                                        {0,0,1,0,0},
                                                        {0,0,1,0,0},
                                                        {0,0,1,0,0},
                                                        {0,0,1,0,0},
                                                        {0,0,0,0,0}
                                                    };
    const std::vector<std::vector<bool>> L_SHAPE = {
                                                        {1,0,0},
                                                        {1,0,0},
                                                        {1,1,1}
                                                    };
    const std::vector<std::vector<bool>> Z_SHAPE = {
                                                        {1,1,0},
                                                        {0,1,1},
                                                        {0,0,0}
                                                    };
    std::vector<std::vector<bool>> currentShape;

public:
    enum Shape {TSHAPE, OSHAPE, ISHAPE, LSHAPE, ZSHAPE};
    Tetromino();
    Tetromino(Shape);
    ~Tetromino();
    const std::vector<std::vector<bool>>& get_T_SHAPE() const;
    const std::vector<std::vector<bool>>& get_O_SHAPE() const;
    const std::vector<std::vector<bool>>& get_I_SHAPE() const;
    const std::vector<std::vector<bool>>& get_L_SHAPE() const;
    const std::vector<std::vector<bool>>& get_Z_SHAPE() const;
    const std::vector<std::vector<bool>>& rotateLeft() const;
    const std::vector<std::vector<bool>>& rotateRight() const;
};

#endif // TETROMINO_H
