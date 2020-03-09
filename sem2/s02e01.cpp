#include <iostream>
#include <cstring>
#include <cctype>
/*(const std::string &input)*/
bool is_palindrome(std::string slowo){
    char tmp[slowo.size()];
    strcpy(tmp,slowo.c_str());
    std::string owols;
    for(int i = slowo.size()-1 ; i >= 0; i--){
        owols += tmp[i];
    }
    if(owols == slowo){
        return true;
    }
    return false;
}
bool is_palindrome1(std::string slowo){
    char c_slowo[slowo.size()];
    strcpy(c_slowo, slowo.c_str());
    char *pch;
    pch = strtok(c_slowo, " ");
    std::string tmp ;
    while (pch != NULL) {
        tmp += pch;
        pch = strtok(NULL, " ");
    }
    strcpy(c_slowo, tmp.c_str());
    std::string owols;
    std::string slowo_l;
    for(int i = tmp.size()-1; i>= 0; i--){
        owols += tolower(c_slowo[i]);
        slowo_l += tolower(c_slowo[tmp.size()-i-1]);
    }
    if(owols == slowo_l){
        return true;
    }
    return false;
}
int main()
{
    std::string word = "racecar";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    } else {
        std::cout << "Nope" << std::endl;
    }
    std::string sentence = "Never odd or even";
    if (is_palindrome1(sentence)) {
        std::cout << "To palindrom!" << std::endl;
    } else {
        std::cout << "Nope" << std::endl;
    }
    return 0;
}
