#ifndef UNTITLED_SUDOKU_H
#define UNTITLED_SUDOKU_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

// esto es lo mismo que typedef std::vector<<std::vector<int>> matrix2d;
// busca info sobre templates, typedef y programación generica

using matrix2d = std::vector<std::vector<int>>;

class Sudoku {

private:
    matrix2d tablero;
    matrix2d replica = tablero;
    int tamano;
    int cuadrantes;
    int p;

public:
    Sudoku(int n) {

        this-> tamano = n;
        //this-> cuadrantes = n;
        this -> p = sqrt(tamano);

        this-> tablero.resize(n, std::vector<int>(n));
        std::cout << "inicializando random"<<std::endl;
        this-> inicializar_random2();
        this -> imprimir_tablero();
        this -> doble_sudoku();
        this -> imprimir_duplicado();
    }

    bool doble(int fila, int columna, int valor){

        //verifico las columna
            for (int i = 0; i < this->tamano; i++){
                if (valor == ( this-> tablero)[fila][i]){
                    std::cout << "fallo con fila"<< std::endl;
                    return true;
                }
            }

        //verifico la fila
            for (int j=0; j < this->tamano; j++){
                if (valor == ( this-> tablero)[j][columna]){
                    std::cout << "fallo con columna"<< std::endl;

                    return true;
                }
            }

         // verifico cuadrante
            int Lu = fila - (fila % p);
            int Ld = (Lu + p - 1);
            int Ll = columna - (columna % p);
            int Lr = (Ll + p - 1);

            for (int columna_=Ll; columna_ <= Lr; ++columna_){
                for (int fila_ = Lu; fila_ <= Ld; ++fila_){
                    if ( valor == ( this-> tablero)[fila_][columna_] ){
                        std::cout << "fallo con cuadrante"<< std::endl;

                        return true;
                    }
                }
            }
            return false;
    }

    //Se inicia a dar valores random al tablero;
    void inicializar_random2(){
        int random_numero = 0;
        for (int fila = 0; fila < tamano ; fila++){
            for (int columna = 0; columna < tamano; ++columna){
                random_numero = (rand() % tamano) +1;
                while (this ->doble(fila, columna, random_numero)){
                    std::cout << "encontre colision con fila y columna : "<<fila << " "<< columna << " y valor: "<< random_numero << std::endl;
                    this->imprimir_tablero();
                   random_numero=(rand() % tamano) +1;
                }
                (this->tablero)[fila][columna] = random_numero;

                //(this->tablero)[fila][columna] = random_numero;
                /*if (this ->doble(fila, columna, random_numero)==false){
                    (this->tablero)[fila][columna] = random_numero;
                }else{
                    //this->tablero)[fila][columna] = 0;
                    //columna--;

                }*/
                std::cout<<"seteando la posicion "<<fila <<", "<<columna << " con el valor " << random_numero << " con respuesta de colision " << this ->doble(fila, columna, random_numero) << "\n";
            }
        }
        imprimir_tablero();
    }

    /*int operator()(int filaRelativa, int columnaRelativa, int cuadrante) const {
        int n = sqrt(this->tamano);
        int filaAbsoluta = (floor(cuadrante - 1 / n) * n) + filaRelativa;
        int columnaAbsoluta = ((cuadrante - 1) % n) * n + columnaRelativa;
        return this->tablero[filaAbsoluta][columnaAbsoluta];
    }


    // reforzar en internet, buscar operator assignment overload()
    int &operator()(int filaRelativa, int columnaRelativa, int cuadrante) {
        int n = sqrt(this->tamano);
        int filaAbsoluta = (floor((cuadrante - 1) / n) * n) + filaRelativa;
        int columnaAbsoluta = ((cuadrante - 1) % n) * n + columnaRelativa;

        std::cout << "fila: " << filaAbsoluta << "    columna: " << columnaAbsoluta
                  << "\n\n";
        return this->tablero[filaAbsoluta][columnaAbsoluta];
    }*/

    void imprimir_tablero() const {

        //borde
        for (int j = 0; j < (sqrt(tamano)); j++) {
            std::cout << "+ ";
            for (int i = 0; i < (sqrt(tamano)); i++) {
                std::cout << "- ";
            }
        }std::cout << "+";
        std::cout <<"\n";

        //numeros
        for (int i = 0; i < this->tamano; ++i) {
            std :: cout << "| ";
            for (int j = 0; j < this->tamano; ++j) {
                if (this->tablero[i][j] == 0) {
                    std::cout << ". ";
                } else {
                    std::cout << this->tablero[i][j] << " ";
                }
                if ((j + 1) % int(sqrt(this->tamano)) == 0) {
                    std::cout << "| ";
                }
            }

            if ((i + 1) % int(sqrt(this->tamano)) == 0 && !(i + 1 == this->tamano)) {
                std::cout << '\n';
                for (int k = 0; k < sqrt(this->tamano); ++k) {
                    if ((k + 1) % int(sqrt(this->tamano)) == 0) {
                        for (int j = 0; j < (sqrt(tamano)); j++) {
                            std::cout << "+ ";
                            for (int i = 0; i < (sqrt(tamano)); i++) {
                                std::cout << "- ";
                            }
                        }std::cout << "+";
                    }
                }
            }
            std::cout << '\n';
        }

        //borde
        for (int j = 0; j < (sqrt(tamano)); j++) {
            std::cout << "+ ";
            for (int i = 0; i < (sqrt(tamano)); i++) {
                std::cout << "- ";
            }
        }std::cout << "+";
        std::cout <<"\n";
    }


     //Crear duplicado de tablero
     void doble_sudoku(){
        int fila_ran=0;
        int col_ran=0;
        for (int i=0; i <(p*tamano); i++){
            fila_ran = rand()%tamano;
            col_ran = rand()%tamano;
            this->replica [fila_ran][col_ran]=0;
        }
     }

     //Funcion para imprimir el duplicado
     void imprimir_duplicado() const {

         //borde
         for (int j = 0; j < (sqrt(tamano)); j++) {
             std::cout << "+ ";
             for (int i = 0; i < (sqrt(tamano)); i++) {
                 std::cout << "- ";
             }
         }
         std::cout << "+";
         std::cout << "\n";

         //numeros
         for (int i = 0; i < this->tamano; ++i) {
             std::cout << "| ";
             for (int j = 0; j < this->tamano; ++j) {
                 if (this->replica[i][j] == 0) {
                     std::cout << ". ";
                 } else {
                     std::cout << this->replica[i][j] << " ";
                 }
                 if ((j + 1) % int(sqrt(this->tamano)) == 0) {
                     std::cout << "| ";
                 }
             }

             if ((i + 1) % int(sqrt(this->tamano)) == 0 && !(i + 1 == this->tamano)) {
                 std::cout << '\n';
                 for (int k = 0; k < sqrt(this->tamano); ++k) {
                     if ((k + 1) % int(sqrt(this->tamano)) == 0) {
                         for (int j = 0; j < (sqrt(tamano)); j++) {
                             std::cout << "+ ";
                             for (int i = 0; i < (sqrt(tamano)); i++) {
                                 std::cout << "- ";
                             }
                         }
                         std::cout << "+";
                     }
                 }
             }
             std::cout << '\n';
         }
     }

     /*
     void ingreso_valor(){
        int pos_x=0,pos_y=0,cambio=0,cont=0;
        std::cout<< "Ingrese la fila\n";
        std::cin>> pos_x;
        std::cout<< "Ingrese la volumna\n";
        std::cin>> pos_y;
        std::cout<< "Ingrese el numero\n";
        std::cin>> cambio;

        bool numero_correcto{
            if(this->tablero[pos_x][pos_y]==cambio){
                return true;
            }else{
                return false;
            }
        }

        while(cont=(p*tamano)){
            if (numero_correcto==true){
                replica [fila_ran][col_ran] = cambio;
                imprimir_tablero();
                cont++;
            }
        }
    }
     */
};

#endif //UNTITLED_SUDOKU_H