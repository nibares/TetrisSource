#include "../include/Tetromino.h"

Tetromino::Tetromino()
{
};

Tetromino::Tetromino(Shape aShape)
{
    if (aShape == Tetromino::Shape::TSHAPE){
        currentStatePiece.createPiece(3,3,Tetromino::get_T_SHAPE());
    } 
};

Tetromino::~Tetromino(){

};


const std::vector<std::vector<bool>>& Tetromino::get_T_SHAPE() const {
    return T_SHAPE;
};
const std::vector<std::vector<bool>>& Tetromino::get_O_SHAPE() const{
    return O_SHAPE;
};
const std::vector<std::vector<bool>>& Tetromino::get_I_SHAPE() const{
    return I_SHAPE;
};

const std::vector<std::vector<bool>>& Tetromino::get_L_SHAPE() const{
    return L_SHAPE;
};

const std::vector<std::vector<bool>>& Tetromino::get_Z_SHAPE() const{
    return Z_SHAPE;
};

const std::vector<std::vector<bool>>& Tetromino::rotateLeft()  const{
    return T_SHAPE;
};

const std::vector<std::vector<bool>>& Tetromino::rotateRight()  {
    currentStatePiece.rotateRight();
    
    return currentStatePiece.pieceCanvas; 
};
