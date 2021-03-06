#include <iostream>
#include "Color.h"
#include "Cell.h"
using namespace std;

int main()
{

    Color color=Color::BLACK;
    std::string cell;

    if(color==Color::BLACK){
        cell.append(BLACKCOLOR);
    }else if (color==Color::WHITE){
        cell.append(WHITECOLOR);
    }

    cell.append(" ____ ");
    cell.append("\n/    \\");
    cell.append("\n----");
    cell.append(RESET);
    std::cout<<cell<<std::endl;
    return 0;
}
