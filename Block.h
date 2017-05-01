#ifndef BLOCK_H
#define BLOCK_H

class Block {
private:



public:
    enum status {moving, stopped};
    status blockStatus;

    char blockChar;
    bool isMoving(){
        if (blockStatus == moving){
            return true;
        }
        else {
            return false;
        }
    }

    bool isStopped(){
        if (blockStatus == stopped){
            return true;
        }
        else {
            return false;
        }
    }

    void changeStatus (status newStatus){
        switch (newStatus) {
            case moving:
                blockStatus = moving;
                break;
            case stopped:
                blockStatus = stopped;
                break;
        }
    }
};



#endif // BLOCK_H
