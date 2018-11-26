#ifndef SUDOKU_H
#define SUDOKU_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

// esto es lo mismo que typedef std::vector<<std::vector<int>> matrix2d;
// busca info sobre templates, typedef y programación generica

using matrix2d = std::vector<std::vector<int>>;

class Sudoku {

private:
    matrix2d tablero;
    int tamano;
    int cuadrantes;
    int p;

public:
    //Declaramos el constructor y los métodos que se utilizaran en el programa
    Sudoku(int n) {

        this->tamano = n;       //Tamaño del Sudoku
        this->cuadrantes = n;       //Numero de cuadrantes del sudoku
        this->p = sqrt(n);          //Numero de cuadrantes por fila / columna
        this->tablero.resize(n, std::vector<int>(n));        //Se refine el tablero para que sea de tamaño "n"
        this->inicializarRandom();          //Inicializa la obtención de los número aleatorios
        this->imprimir_tablero();           //Imprime el tablero
        this->rellenar_valor();             //Solicita al usuario los datos para rellenar el tablero
    }

    //Se encarga de poder verifivcar que el número random sea correcto
    bool doble(int fila, int columna, int valor){

        //verifica las columnas
        for (int i = 0; i < this->tamano; i++){
            if (valor == ( this-> tablero)[fila][i]){
                std::cout << "fallo con fila"<< std::endl;
                return true;
            }
        }

        //verifica las filas
        for (int j=0; j < this->tamano; j++){
            if (valor == ( this-> tablero)[j][columna]){
                std::cout << "fallo con columna"<< std::endl;

                return true;
            }
        }

        // verifica el cuadrante
        int Lu = fila - (fila % p);    //Limite inferior de la fila
        int Ld = (Lu + p - 1);          //Limite superior de la fila
        int Ll = columna - (columna % p);       //Limite inferior de la columna
        int Lr = (Ll + p - 1);              //Limitte superior de la columna

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

    //Se encarga de iniciar el aleatorizado de las variables
    void inicializarRandom() {
        int n = sqrt(this->tamano);

        for (int cuadrante = 1; cuadrante <= this->cuadrantes; ++cuadrante) {

            for (int numero = 0; numero < n; ++numero) {
                int random_fila = rand() % this->cuadrantes;
                int random_columna = rand() % this->cuadrantes;
                int random_numero = (rand() % tamano) + 1;
                //std::cout << "fila: " << random_fila << "    columna: " << random_columna << '\n';
                while (this ->doble(random_fila, random_columna, random_numero)){
                    //std::cout << "encontre colision con fila y columna : "<<random_fila << " "<< random_columna << " y valor: "<< random_numero << std::endl;
                    //this->imprimir_tablero();
                    random_numero=(rand() % tamano) +1;
                }
                this->tablero[random_fila][random_columna]=random_numero;
            }
            //this->imprimir_tablero();
        }
    }

    /*
    // overload operator()
    // funcion const
    int operator()(int filaRelativa, int columnaRelativa, int cuadrante) const {
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
    }
    */

    //Esta funcion se encarga de imprimir el tablero
    void imprimir_tablero() const {

        //borde
        std :: cout << "    ";
        for (int s=0; s < tamano; s++){
            std :: cout << s << " ";
            if (s % p == (p-1)){
                std :: cout << "  ";
            }
        }std :: cout << "\n";

        std:: cout << "  ";
        for (int j = 0; j < (sqrt(tamano)); j++) {
            std::cout << "+ ";
            for (int i = 0; i < (sqrt(tamano)); i++) {
                std::cout << "- ";
            }
        }std::cout << "+";
        std::cout <<"\n";

        //numeros
        for (int i = 0; i < this->tamano; ++i) {
            std :: cout << i << " | ";
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
                std:: cout << "  ";
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
        std:: cout << "  ";
        for (int j = 0; j < (sqrt(tamano)); j++) {
            std::cout << "+ ";
            for (int i = 0; i < (sqrt(tamano)); i++) {
                std::cout << "- ";
            }
        }std::cout << "+";
        std::cout <<"\n";
    }

    //Se solicita la posición y el valor a reemplazar
    void rellenar_valor(){
        //Se define las respectivas variables
        int fila_c=0, col_c=0, valor_c=0, c_vacio=0, c_llenos=0;

        //Se calcula el numero de datos que hay en el sudoku
        for(int i=0; i<tamano; i++){
            for (int j=0; j<tamano; j++){
                if (this->tablero[i][j] != 0){
                    c_llenos++;
                }
            }
        }

        for (int c_vacio=0;c_vacio<((tamano*tamano)-c_llenos);c_vacio){
            //Se solicita el ingreso de las variables
            std:: cout << "Ingrese la fila \n";
            std:: cin >> fila_c;
            std:: cout << "Ingrese la columna \n";
            std:: cin >> col_c;
            std:: cout << "Ingrese el valor\n";
            std:: cin >> valor_c;
            std:: cout << fila_c << " " << col_c << valor_c << "\n";

            if(this->doble(fila_c, col_c, valor_c) == false){
                this->tablero[fila_c][col_c] = valor_c;
                this->imprimir_tablero();
                c_vacio++;
                std::cout << c_vacio <<"\n";
            }else{
                std::cout << "El valor es invalido\n";
                this->imprimir_tablero();
                c_vacio;
            }
        }

    }
};

#endif