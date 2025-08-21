#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>    // pokud chceš používat math funkce
#include <string>
#include <sstream>

struct karta{
    int hodnota;
    std::string barva;
};

std::string barvy[4] = {"srdce", "kříže", "káry", "piky"};
// 1 = eso 
// 2 = dvojka
// 3 = trojka
// 4 = čtyřka
// 5 = pětka
// 6 = šestka
// 7 = sedmička
// 8 = osmička
// 9 = devítka
// 10 = desítka
// 11 = kluk
// 12 = dáma
// 13 = král

karta aktualne_karty[7] = {
    {1, "srdce"},
    {2, "káry"},
    {3, "srdce"},
    {10, "piky"},
    {1, "káry"},
    {5, "srdce"},
    {13, "piky"}
};


bool is_it_royale_flush(karta nase_karty[7]){
    //pokud je to kralovska postupka, vratime true
    karta hodnoty_se_stejnou_barvou[14] = {};
    for(int i = 0 ; i < 4 ; i++){
        std::string nase_barva = barvy[i];
        int kolik = 0;
        for(int j = 0; j < 7; j++){
            if(nase_karty[j].barva == nase_barva){
                kolik++;
            }
            if (kolik>4){
                for(int j = 0; j < 7; j++){
                    if(nase_karty[j].barva == nase_barva){
                        hodnoty_se_stejnou_barvou[nase_karty[j].hodnota] = nase_karty[j];
                    }
                }
            }
        }
        
    }

    if(hodnoty_se_stejnou_barvou[1].barva == hodnoty_se_stejnou_barvou[10].barva &&
       hodnoty_se_stejnou_barvou[10].barva == hodnoty_se_stejnou_barvou[11].barva &&
       hodnoty_se_stejnou_barvou[11].barva == hodnoty_se_stejnou_barvou[12].barva &&
       hodnoty_se_stejnou_barvou[12].barva == hodnoty_se_stejnou_barvou[13].barva) {
        // pokud jsou všechny karty stejné barvy a obsahují eso, krále, dámu, kluka a desítku
        if(hodnoty_se_stejnou_barvou[1].hodnota == 1 && 
           hodnoty_se_stejnou_barvou[10].hodnota == 10 && 
           hodnoty_se_stejnou_barvou[11].hodnota == 11 && 
           hodnoty_se_stejnou_barvou[12].hodnota == 12 && 
           hodnoty_se_stejnou_barvou[13].hodnota == 13) {
            return true;
        }
    }
     return false;
}
bool is_it_straight_flush(karta nase_karty[7]){
    //pokud je to postupka, vratime true
    karta hodnoty_se_stejnou_barvou[14] = {};
    for(int i = 0 ; i < 4 ; i++){
        std::string nase_barva = barvy[i];
        int kolik = 0;
        for(int j = 0; j < 7; j++){
            if(nase_karty[j].barva == nase_barva){
                kolik++;
            }
            if (kolik>4){
                for(int j = 0; j < 7; j++){
                    if(nase_karty[j].barva == nase_barva){
                        hodnoty_se_stejnou_barvou[nase_karty[j].hodnota] = nase_karty[j];
                    }
                }
            }
        }
        
    }
    for(int i = 0 ; i < 9; i++){
        if(hodnoty_se_stejnou_barvou[i].hodnota != 0 &&
           hodnoty_se_stejnou_barvou[i+1].hodnota != 0 &&
           hodnoty_se_stejnou_barvou[i+2].hodnota != 0 &&
           hodnoty_se_stejnou_barvou[i+3].hodnota != 0 &&
           hodnoty_se_stejnou_barvou[i+4].hodnota != 0) {
            // pokud máme pět karet v řadě
            return true;
        }
    }
    
     return false;
}

bool ctvericka(karta nase_karty[7]){
    for(int i = 0; i < 7; i++){
        int pocet= 0;
        int aktualni_hodnota = nase_karty[i].hodnota;
        for(int j = 0; j < 7; j++){
            if(nase_karty[j].hodnota == aktualni_hodnota){
                pocet++;
            }
        }
        if (pocet == 4) {
            return true;
        }
    }
    return false;
}

bool full_house(karta nase_karty[7]){
    //pokud je to full house, vratime true
    int hodnoty[14] = {0}; // pole pro počítání výskytu hodnot karet
    for(int i = 0; i < 7; i++){
        hodnoty[nase_karty[i].hodnota]++;
    }
    bool trojka = false;
    bool dvojka = false;
    for(int i =0; i < 14; i++){
        if(hodnoty[i] == 3) {
            trojka = true;
        } else if(hodnoty[i] == 2) {
            dvojka = true;
        }
    }
    if (dvojka && trojka){
        return true;
    }
    return false;
}

bool barva(karta nase_karty[7]){
    //pokud je to barva, vratime true
    karta hodnoty_se_stejnou_barvou[14] = {};
    for(int i = 0 ; i < 4 ; i++){
        std::string nase_barva = barvy[i];
        int kolik = 0;
        for(int j = 0; j < 7; j++){
            if(nase_karty[j].barva == nase_barva){
                kolik++;
            }
            if (kolik>4){
                return true;
            }
        }
    }
    return false;
}

bool postupka(karta nase_karty[7]){
    karta hodnoty[14] = {};
    for(int i = 0; i < 7; i++){
        hodnoty[nase_karty[i].hodnota] = nase_karty[i];
    }
    for(int i = 0; i < 9; i++){
        if(hodnoty[i].hodnota != 0 &&
           hodnoty[i+1].hodnota != 0 &&
           hodnoty[i+2].hodnota != 0 &&
           hodnoty[i+3].hodnota != 0 &&
           hodnoty[i+4].hodnota != 0) {
           return true;
        }
    }
    return false;
}

bool trojicka(karta nase_karty[7]){
    for(int i = 0; i < 7; i++){
        int pocet= 0;
        int aktualni_hodnota = nase_karty[i].hodnota;
        for(int j = 0; j < 7; j++){
            if(nase_karty[j].hodnota == aktualni_hodnota){
                pocet++;
            }
        }
        if (pocet == 3) {
            return true;
        }
    }
    return false;
}

bool pár_dvojicek(karta nase_karty[7]){
    //pokud je to pár dvojicek, vratime true
    int hodnoty[14] = {0}; // pole pro počítání výskytu hodnot karet
    for(int i = 0; i < 7; i++){
        hodnoty[nase_karty[i].hodnota]++;
    }
    int pocet_dvojicek = 0;
    for(int i = 0; i < 14; i++){
        if(hodnoty[i] == 2) {
            pocet_dvojicek++;
        }
    }
    if (pocet_dvojicek == 2) {
        return true;
    }
    return false;
}

bool dvojicka(karta nase_karty[7]){
    //pokud je to pár dvojicek, vratime true
    int hodnoty[14] = {0}; // pole pro počítání výskytu hodnot karet
    for(int i = 0; i < 7; i++){
        hodnoty[nase_karty[i].hodnota]++;
    }
    int pocet_dvojicek = 0;
    for(int i = 0; i < 14; i++){
        if(hodnoty[i] == 2) {
            pocet_dvojicek++;
        }
    }
    if (pocet_dvojicek == 1) {
        return true;
    }
    return false;
}


int main() {
    if(is_it_royale_flush(aktualne_karty)) {
        std::cout << "Je to královská postupka!" << std::endl;
    } else if (is_it_straight_flush(aktualne_karty)) {
        std::cout << "Je to barevna postupka!" << std::endl;
    } else if(ctvericka(aktualne_karty)) {
        std::cout << "Je to čtverka!" << std::endl;
    } else if(full_house(aktualne_karty)) {
        std::cout << "Je to full house!" << std::endl;
    } else if(barva(aktualne_karty)) {
        std::cout << "Je to barva!" << std::endl;
    } else if(postupka(aktualne_karty)) {
        std::cout << "Je to postupka!" << std::endl;
    } else if(trojicka(aktualne_karty)) {
        std::cout << "Je to trojicka!" << std::endl;
    } else if(pár_dvojicek(aktualne_karty)) {
        std::cout << "Je to pár dvojicek!" << std::endl;
    } else if(dvojicka(aktualne_karty)) {
        std::cout << "Je to dvojicka!" << std::endl;
    } else {
        std::cout << "Není to královská postupka, postupka ani čtverka." << std::endl;
    }
    return 0;
}
// g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o poker && ./poker