#include "Stack.h"

int main()
{
    Stack stack{ 1, 2, 3, 4, 5 };
    std::cout << "operator<< (write): " << stack << std::endl;

    std::cout << "Peek: " << stack.Peek() << std::endl;

    std::cout << "Pop: " << std::endl;
    stack.Pop();
    std::cout << "operator<< (write): " << stack << std::endl;

    std::cout << "Peek: " << stack.Peek() << std::endl;

    Stack copyStack(stack);
    std::cout << "copy ctor: " << copyStack << std::endl;

    Stack moveStack{ std::move(stack) };
    std::cout << "move ctor: " << moveStack << std::endl;

    auto c = copyStack;
    std::cout << "operator= (copy): " << c << std::endl;

    auto m = std::move(copyStack);
    std::cout << "operator= (move): " << m << std::endl;

    std::istringstream buffer{ "1 2 3 4 5" };
    Stack stackFromBuffer{};
    buffer >> stackFromBuffer;
    std::cout << "operator>> (read): " << stackFromBuffer << std::endl;

    return 0;
}
