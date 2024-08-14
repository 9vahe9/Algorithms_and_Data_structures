#include <iostream>

void foo(int& x)
{
    x = 0;
}

int main()
{
    int x = 19;
    foo(x);
    std::cout << "x= " << x;
}