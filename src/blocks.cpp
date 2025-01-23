#include"block.h"
#include"position.h"
#include <cmath>

class Lblock: public block {
    public:
        Lblock() {
            id = 1;
            cells[0] = {position(0, 2), position(1, 0), position(1, 1), position(1, 2)};
            cells[1] = {position(0, 1), position(1, 1), position(2, 1), position(2, 2)};
            cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 0)};
            cells[3] = {position(0, 0), position(0, 1), position(1, 1), position(2, 1)};
            move(0, 3);
        }
};

class Jblock: public block {
    public:
        Jblock() {
            id = 2;
            cells[0] = {position(0, 0), position(1, 0), position(1, 1), position(1, 2)};
            cells[1] = {position(0, 1), position(0, 2), position(1, 1), position(2, 1)};
            cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 2)};
            cells[3] = {position(0, 1), position(1, 1), position(2, 0), position(2, 1)};
            move(0, 3);
        }
};

class Iblock: public block {
    public:
        Iblock() {
            id = 3;
            cells[0] = {position(1, 0), position(1, 1), position(1, 2), position(1, 3)};
            cells[1] = {position(0, 2), position(1, 2), position(2, 2), position(3, 2)};
            cells[2] = {position(2, 0), position(2, 1), position(2, 2), position(2, 3)};
            cells[4] = {position(0, 1), position(1, 1), position(2, 1), position(3, 1)};
            move(-1, 3);
        }
        
};

class Oblock: public block {
    public:
        Oblock() {
            id = 4;
            cells[0] = {position(0, 0), position(0, 1), position(1, 0), position(1, 1)};            
            cells[1] = {position(0, 0), position(0, 1), position(1, 0), position(1, 1)};
            cells[2] = {position(0, 0), position(0, 1), position(1, 0), position(1, 1)};
            cells[3] = {position(0, 0), position(0, 1), position(1, 0), position(1, 1)};
            move(0, 4);
        }
};

class Sblock: public block {
    public:
        Sblock() {
            id = 5;
            cells[0] = {position(0, 1), position(0, 2), position(1, 0), position(1, 1)};
            cells[1] = {position(0, 1), position(1, 1), position(1, 2), position(2, 2)};
            cells[3] = {position(1, 1), position(1, 2), position(2, 0), position(2, 1)};
            cells[3] = {position(0, 0), position(1, 0), position(1, 1), position(2, 1)};
            move(0, 3);
        }
};

class Tblock: public block {
    public:
        Tblock() {
            id = 6;
            cells[0] = {position(0, 1), position(1, 0), position(1, 1), position(1, 2)};
            cells[1] = {position(0, 1), position(1, 1), position(1, 2), position(2, 1)};
            cells[2] = {position(1, 0), position(1, 1), position(1, 2), position(2, 1)};
            cells[3] = {position(0, 1), position(1, 0), position(1, 1), position(2, 1)};
            move(0, 3);
        }
};

class Zblock: public block {
    public:
        Zblock() {
            id = 7;
            cells[0] = {position(0, 0), position(0, 1), position(1, 1), position(1, 2)};
            cells[1] = {position(0, 2), position(1, 1), position(1, 2), position(2, 1)};
            cells[2] = {position(1, 0), position(1, 1), position(2, 1), position(2, 2)};
            cells[3] = {position(0, 1), position(0, 1), position(1, 1), position(2, 0)};
            move(0, 3);
            
        }
};

