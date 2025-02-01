#include <iostream>
import module1;
import module2;
import structural_eq;

int main() {
    auto A = a();
    auto B = b();
    if (A == B)
        std::cout << "A and B are equal" << std::endl;
    else
        std::cout << "A and B are not equal" << std::endl;
}
