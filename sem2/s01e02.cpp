#include <iostream>
#include <vector>

void min_max(std::vector<double> &vec, double &arg_min, double &arg_max){
    arg_min = vec[0];
    arg_max = vec[0];
    for(unsigned int i =0; i<vec.size(); i++){
        if(vec[i] > arg_max){
            arg_max = vec[i];
        }
        if(vec[i] < arg_min){
            arg_min = vec[i];
        }
    }
}

int main()
{
    double min;
    double max;
    std::vector<double> values = {-1.0, 100, 3.14, -999.9, 21.37};

    min_max(values, min, max);
    std::cout << "Min: " << min << std::endl << "Max: " << max << std::endl;
    return 0;
}
