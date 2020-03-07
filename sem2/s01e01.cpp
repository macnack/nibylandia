#include <iostream>
#include <vector>

void fill_progressive(std::vector<int> &vec){
    for(unsigned int i =0; i < vec.size(); i++){
        vec[i] = i + 1;
    }
}
void print_vector(std::vector<int> &vec){
    for(unsigned int i =0; i < vec.size(); i++){
        std::cout << vec[i] << ", ";
    }
}

int main()
{
    std::vector<int> vec(6);
    fill_progressive(vec);
    print_vector(vec);
    return 0;
}
