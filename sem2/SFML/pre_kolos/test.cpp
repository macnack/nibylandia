#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

int main(){
	cout << "hello" << std::endl;
	srand(time(NULL));
	for(int i = 0 ; i < 10; i++){
		std::cout << rand()%3 - 1  << " ";
	}
	return 1;
}
