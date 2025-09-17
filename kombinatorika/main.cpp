#include <iostream>
#include <cmath>  


int kombinace(int zkolika, int kolik){ // 5 dni a 3 z nich chceme --- kolik bude kombinaci...
    if(kolik > zkolika){
        return 0;
    }
    int vysledek =1;
    for(int i = 0; i < kolik ; i++){
        vysledek *= (zkolika - i);
    }

    int faktorial_kolika =0;
    for(int i = kolik; i > 0; i--){
        if(faktorial_kolika == 0){
            faktorial_kolika = i;
        } else {
            faktorial_kolika *= i;
        }
    }
    return vysledek / faktorial_kolika;

}



int main(){
    std::cout << "zadej kolik dni mas celkem" << std::endl;
    int zkolika;
    std::cin >> zkolika;
    std::cout << "zadej kolik z nich chces vybrat" << std::endl;
    int kolik;
    std::cin >> kolik;
    std::cout << "je to " << kombinace(zkolika, kolik) << " kombinaci" << std::endl;
    return 0;
}