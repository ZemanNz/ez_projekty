#include <iostream>

void nakresli_x(int n) {
    for(int i =0 ; i < n; i++){
        for(int j=0 ;j < n; j++){
            if(i == j){
                std::cout << "*";
            }
            else if(n-i - 1 == j){
                std::cout << "*";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void nakresli_troj(int vyska){
    int sloupce= 2*vyska -1;
    for ( int i = 0; i <vyska - 1; i++){
        for(int j = 0; j <sloupce;j++){
            if(((sloupce / 2+ 1 - i) == j)|| ((sloupce / 2+ 1 + i) == j)){
                std::cout << "*";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << " ";
    for(int i = 0; i < sloupce; i++){
        std::cout << "*";
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    nakresli_x(7);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    nakresli_troj(9);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}