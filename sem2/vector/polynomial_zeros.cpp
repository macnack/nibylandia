#include <iostream>
#include <vector>
#include <cmath>
std::vector<double> get_poly(int n)
{
    std::vector<double> tmp;
    double wsp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> wsp;
        tmp.emplace_back(wsp);
    }
    return tmp;
}

double poly(double x, const std::vector<double> &p)
{
    double result = 0;
    for (size_t i = 0; i < p.size(); i++)
    {
        result += p[i] * pow(x, i);
    }
    return result;
}
double zero_r(double bottom, double top, const std::vector<double> &p)
{
    double mid = (bottom + top) / 2;
    if (top - bottom < 1e-9)
    {
        return mid;
    }
    else
    {
        double p_bottom = poly(bottom, p);
        if (p_bottom == 0)
        {
            return bottom;
        }
        double p_mid = poly(mid, p);
        if (p_mid == 0)
        {
            return mid;
        }
        double p_top = poly(top, p);
        if (p_top == 0)
        {
            return top;
        }
        if (p_bottom * p_mid < 0)
        {
            return zero_r(bottom, mid, p);
        }
        else
        {
            return zero_r(mid, top, p);
        }
    }
}
std::vector<double> zero(double x_min, double x_max, const std::vector<double> &p, double step)
{
    std::vector<double> zeros;
    for (double x1 = x_min; x1 < x_max; x1 += step)
    {
        double x2 = x1 + step;
        if (x2 > x_max)
        {
            x2 = x_max;
        }
        if (poly(x1, p) * poly(x2, p) < 0)
        {
            zeros.emplace_back(zero_r(x1, x2, p));
        }
    }
    return zeros;
}
int main()
{
    int n;
    std::cout << "Podaj liczbe wspolczynnikow";
    std::cin >> n;
    std::cout << "\npo wpisaniu wspolczynnika zatwierdz wciskajac enter" << std::endl;
    std::vector<double> p = get_poly(n);
    //std::vector<double> p = {-30, 6, 10, 1};
    std::cout << "Podaj min: \n";
    double min=-15, max=5;
    std::cin >> min;
    std::cout << "Podaj max: \n";
    std::cin >> max;
    std::vector<double> z = zero(min, max, p, 0.5);
    for (double zi : z)
    {
        std::cout << zi << std::endl;
    }
    return 0;
}
