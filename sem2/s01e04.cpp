#include <iostream>
#include <vector>

uint64_t factorial_r(int x){
    uint64_t silnia;
    for(int i = 0; i<=x; i++){
        if(i == 0){
            silnia = 1;
        }
        else {
            silnia *= i;
        }
    }
    return silnia;
}

int main()
{
    uint64_t result = factorial_r(15);
    std::cout << result << std::endl;
    return 0;
}
