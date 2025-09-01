#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <thread>
#include <cmath>
// napodobovani scratch pomoci grafiky a funkce line ---- postavicka se heba a kresli za sebou caru

sf::RenderWindow window(sf::VideoMode(1000, 1000), "scratch");
int globalni_x=500;
int globalni_y=500;

int stupne= 0;
sf::CircleShape kruh(40);

std::vector<sf::Vertex> trajektorie;

struct DvaInty {
    int x, y;
};


void pohyb_y(int y1, int y2, int delay){
    int aktualni_y =y1;
    while(aktualni_y != y2){
        if (aktualni_y < y2) aktualni_y++;
        if (aktualni_y > y2) aktualni_y--;
        globalni_y = aktualni_y;
        usleep(delay);

    }
}
void pohyb(int x1, int y1, int x2, int y2){
    trajektorie.push_back(sf::Vertex(sf::Vector2f(x2, y2), sf::Color::Green));
    int aktualni_y =y1;
    float pomer_x_ku_y = 1.00000;
    pomer_x_ku_y = std::abs((x2-x1)) / static_cast<float>(std::abs((y2-y1)));
    std::cout << "pomer x ku y je: " << pomer_x_ku_y << std::endl;
    int delay_x = 10000;
    int delay_y = delay_x * pomer_x_ku_y;
    if(delay_y < 300){
        delay_y =1500;
    }
    std::thread druhy(pohyb_y, y1, y2, delay_y);// --- pohyb v y
    ///pohyb v x:
    int aktualni_x =x1;
    while(aktualni_x != x2 || globalni_y != y2){
        if (aktualni_x < x2) aktualni_x++;
        if (aktualni_x > x2) aktualni_x--;
        kruh.setPosition(aktualni_x, globalni_y);
        globalni_x = aktualni_x;
        window.clear();
        window.draw(kruh);
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(x1, y1), sf::Color::Green),
                        sf::Vertex(sf::Vector2f(aktualni_x, globalni_y), sf::Color::Green)
                };
        window.draw(line, 2, sf::Lines);
        window.display();
        usleep(delay_x);

    }
    druhy.join();
}

DvaInty vypocitat_souradnice(int vzdalenost) {
    

    if(stupne >=0 && stupne < 45){
        int natoceni = stupne;
        float radiany = natoceni * (M_PI / 180);
        int x = std::sin(radiany) * vzdalenost;
        int y = std::cos(radiany) * vzdalenost;
        return {globalni_x + x, globalni_y - y};
    }
    else if(stupne >=45 && stupne < 90){
        int natoceni = 90 - stupne;
        float radiany = natoceni * (M_PI / 180);
        int x = std::cos(radiany) * vzdalenost;
        int y = std::sin(radiany) * vzdalenost;
        return {globalni_x + x, globalni_y - y};
    }
    else if(stupne >=90 && stupne < 135){
        int natoceni = stupne - 90;
        float radiany = natoceni * (M_PI / 180);
        int x = std::cos(radiany) * vzdalenost;
        int y = std::sin(radiany) * vzdalenost;
        return {globalni_x + x, globalni_y + y};
    }
    else if(stupne >=135 && stupne < 180){
        int natoceni = stupne - 135;
        float radiany = natoceni * (M_PI / 180);
        int x = std::sin(radiany) * vzdalenost;
        int y = std::cos(radiany) * vzdalenost;
        return {globalni_x + x, globalni_y + y};
    }
    else if(stupne >=180 && stupne < 225){
        int natoceni = stupne - 180;
        float radiany = natoceni * (M_PI / 180);
        int x = std::cos(radiany) * vzdalenost;
        int y = std::sin(radiany) * vzdalenost;
        return {globalni_x - x, globalni_y + y};
    }
    else if(stupne >=225 && stupne < 270){
        int natoceni = stupne - 225;
        float radiany = natoceni * (M_PI / 180);
        int x = std::sin(radiany) * vzdalenost;
        int y = std::cos(radiany) * vzdalenost;
        return {globalni_x - x, globalni_y + y};
    }
    else if(stupne >=270 && stupne < 315){
        int natoceni = stupne - 270;
        float radiany = natoceni * (M_PI / 180);
        int x = std::cos(radiany) * vzdalenost;
        int y = std::sin(radiany) * vzdalenost;
        return {globalni_x - x, globalni_y - y};
    }
    else if(stupne >=315 && stupne < 360){
        int natoceni = stupne - 315;
        float radiany = natoceni * (M_PI / 180);
        int x = std::sin(radiany) * vzdalenost;
        int y = std::cos(radiany) * vzdalenost;
        return {globalni_x - x, globalni_y - y};
    }
    else{
        return {0, 0};
    }

}

void otoc(){
    std::string prikaz;
    std::cout << "Zadej prikaz (napr. otoc50): ";
    std::cin >> prikaz;
    if (prikaz.rfind("otoc", 0) == 0) { // začíná na "otoc"
        try {
             int hodnota = std::stoi(prikaz.substr(4));
             stupne = (stupne + hodnota) % 360;
            if (stupne < 0) stupne += 360;
            std::cout << "Otoceno o " << hodnota << " stupnu. Aktualni uhel: " << stupne << std::endl;
          } catch (...) {
               std::cout << "Neplatny prikaz!" << std::endl;
         }
    } else {
           std::cout << "Neznamy prikaz!" << std::endl;
     }
}
void posun(){
    std::string prikaz;
    std::cout << "Zadej prikaz (napr. jed50): ";
    std::cin >> prikaz;
    if (prikaz.rfind("jed", 0) == 0) { // začíná na "jed"
        try {
             int hodnota = std::stoi(prikaz.substr(3));
            std::cout << "pojedu " << hodnota << " pixelu. " << std::endl;
            DvaInty vysledky = vypocitat_souradnice(hodnota);
            pohyb(globalni_x, globalni_y, vysledky.x, vysledky.y);
          } catch (...) {
               std::cout << "Neplatny prikaz!" << std::endl;
         }
    } else {
           std::cout << "Neznamy prikaz!" << std::endl;
    }
}


void prekresleni(){
    window.clear();
    window.draw(kruh);
    for(size_t i= 0; i < trajektorie.size()-1; ++i){
        sf::Vertex line[] =
                {
                        trajektorie[i],
                        trajektorie[i + 1]
                };
        window.draw(line, 2, sf::Lines);
    }
    window.display();
}


int main(){
    //window.clear();
    kruh.setFillColor(sf::Color::Red);
    kruh.setOrigin(40, 40);
    kruh.setPosition(500, 500);

    trajektorie.push_back(sf::Vertex(sf::Vector2f(globalni_x, globalni_y), sf::Color::Green));

    // DvaInty vysledky = vypocitat_souradnice(500);
    // std::cout << "Vysledky: " << vysledky.x << ", " << vysledky.y << std::endl;

    // pohyb(500, 500, vysledky.x, vysledky.y);
    window.draw(kruh);
    window.display();
    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) window.close();

        }
        prekresleni();
        otoc();
        posun();
    }
}


// g++ main.cpp -o hra -lsfml-graphics -lsfml-window -lsfml-system && ./hra