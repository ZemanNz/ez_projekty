#include <iostream>
#include <cmath>  

std::string kvadraticka_rovnice(double a, double b, double c){
    float diskriminant = (b * b )- (4* a* c);
    if(diskriminant < 0){
        return "zadne realne koreny";
    } else if(diskriminant == 0){
        return "jeden dvojity koren";
    } else {
        return "dva realne koreny";
    }
}




int main(){
    std::cout << "zadej a" << std::endl;
    double a, b, c;
    std::cin >> a;
    std::cout << "zadej b" << std::endl;
    std::cin >> b;
    std::cout << "zadej c" << std::endl;
    std::cin >> c;
    std::cout << kvadraticka_rovnice(a, b, c) << std::endl;
    return 0;
}