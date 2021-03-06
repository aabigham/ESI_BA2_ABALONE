#include <iostream>
#include "Color.h"
#include "Cell.h"

int main()
{

    Cell cell{Position(0, 0), Color::BLACK};

    std::cout << cell << std::endl;

    return 0;
}
