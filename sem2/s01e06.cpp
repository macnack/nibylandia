#include <iostream>
#include <cmath>

double pi_leibniz(double x){
    double pi_4;
    double j=3, i=1;
    while ((j<1/x)||(i<1/x)) {
        pi_4 += 1/i;
        pi_4 -= 1/j;
        i=i+4;
        j=j+4;
    }
    return pi_4*4;
}
int main()
{
    double stop_at = 0.001;
    double pi_approx = pi_leibniz(stop_at);
    pi_leibniz(0.01);
    std::cout << std::endl;
    std::cout << pi_approx << std::endl;
    std::cout << "error: " << pi_approx - M_PI << std::endl;
    return 0;
}
