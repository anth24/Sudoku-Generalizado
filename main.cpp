#include <iostream>
#include "Sudoku.h"
#include <ctime>
#include <cstdlib>

void presentacion () {

    srand(time(0));

    std::cout << "Ingrese la opcion:\n" << "1: Sudoku 2x2\n" << "2: Sudoku 3x3\n"  << "3: Sudoku 4x4\n";

    int entrada = 0;
    bool continuar;
    do {
        std::cin >> entrada;
        if (entrada == 1) {
            Sudoku(4);
            continuar = false;
        } else {
            if (entrada == 2) {
                Sudoku(9);
                continuar = false;
            } else {
                if (entrada == 3){
                    Sudoku(16);
                    continuar =false;
                }else {
                    std::cout << "Error vuelve a intentar" << "\n";
                    continuar = true;
                }
            }
        }
    }while (continuar);
};

int main() {
    int repetir=0;
    presentacion();
    std :: cout << "1: Sí\n" << "2: No\n";
    std :: cin >> repetir;
    while(repetir == 1){
        presentacion();
    }//exit(1);
    return 0;
}