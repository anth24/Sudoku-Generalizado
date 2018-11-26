#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "Sudoku.h"

void presentacion () {

  srand(time(0));

  std::cout << "Ingrese la opcion:\n" << "1: Sudoku 2x2\n" << "2: Sudoku 3x3\n";

  int entrada = 0;
  bool continuar;
  do {
      std::cin >> entrada;
      if (entrada == 1) {
          Sudoku(4);
          std :: cout <<"s4"<<"\n";
          continuar = false;
      } else {
          if (entrada == 2) {
              std::cout << "s9" << "\n";
              Sudoku(9);
              continuar = false;
          } else {
              std::cout << "error vuelve a intentar" << "\n";
              continuar = true;
          }
      }
  }while (continuar);
};

int main() {
    presentacion();
    return 0;
}