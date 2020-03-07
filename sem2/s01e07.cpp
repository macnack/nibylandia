#include <iostream>

using namespace std;
void draw_square(int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!((i==0)||(i==N-1))&&!((j==0)||(j==N-1))){
                std::cout << " ";}
            else{
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }
}
void draw_square(int N, bool l_przekatna, bool p_przekatna){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(l_przekatna&&p_przekatna){
                if(!(((i==0)||(i==N-1))||(i==j))&&!(((j==0)||(j==N-1))||(j==N-1-i))){
                    std::cout << " ";}
                else{
                    std::cout << "#";
            }}
            else{
            if(l_przekatna){
                if(!(((i==0)||(i==N-1))||(i==j))&&!((j==0)||(j==N-1))){
                    std::cout << " ";}
                else{
                    std::cout << "#";
                }
            }
            if(p_przekatna){
                if(!((i==0)||(i==N-1))&&!(((j==0)||(j==N-1))||(j==N-1-i))){
                    std::cout << " ";}
                else{
                    std::cout << "#";
                }
            }}
        }
        std::cout << std::endl;
    }
}

int main()
{
    draw_square(100);
    draw_square(100,true,true);
    draw_square(100,false,true);
    draw_square(100,true,false);
    return 0;
}
