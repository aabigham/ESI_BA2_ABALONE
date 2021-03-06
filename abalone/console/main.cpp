#include <iostream>
#include "Color.h"
#include "Cell.h"

int main()
{
    std::string str;
    str.append(" ____ ");
    str.append("\n/    \\");
    str.append("\n\\____/");
    std::cout << str << std::endl;

    return 0;
}
