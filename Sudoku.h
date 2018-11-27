#ifndef SUDOKU_H
#define SUDOKU_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using matrix2d = std::vector<std::vector<int>>; // Simplemente es para poder acortar el código

class Sudoku {

private:
    matrix2d tablero;    // Es el tablero del sudoku
    int tamano;          // Es el tamaño del tablero
    int cuadrantes;      // Son la cantidad de cuadrantes por el tablero
    int p;               // Es la raíz cuadrada del tamaño

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

        //Verifica las columnas
        for (int i = 0; i < this->tamano; i++){
            if (valor == ( this-> tablero)[fila][i]){
                std::cout << "fallo con fila"<< std::endl;
                return true;
            }
        }

        //Verifica las filas
        for (int j=0; j < this->tamano; j++){
            if (valor == ( this-> tablero)[j][columna]){
                std::cout << "fallo con columna"<< std::endl;

                return true;
            }
        }

        // Verifica el cuadrante
        // Se usan limites para poder determinar el cuadrante al que pertenece el valor
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

        for (int cuadrante = 1; cuadrante <= this->cuadrantes; ++cuadrante) {

            for (int numero = 0; numero < p; ++numero) {
                int random_fila = rand() % this->cuadrantes;
                int random_columna = rand() % this->cuadrantes;
                int random_numero = (rand() % tamano) + 1;
                //std::cout << "fila: " << random_fila << "    columna: " << random_columna << '\n';
                while (this ->doble(random_fila, random_columna, random_numero)){
                    random_numero=(rand() % tamano) +1;
                }
                this->tablero[random_fila][random_columna]=random_numero;
            }
        }
    }

    //Esta funcion se encarga de imprimir el tablero
    void imprimir_tablero() const {

        //borde
            // Coordenadas
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
            //  Son coordenadas
        for (int i = 0; i < this->tamano; ++i) {
            std :: cout << i << " | ";
            //Son los bordes
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

        //Se calcula el numero de recuadros llenos que hay en el sudoku
        for(int i=0; i<tamano; i++){
            for (int j=0; j<tamano; j++){
                if (this->tablero[i][j] != 0){
                    c_llenos++;
                }
            }
        }

        for (int c_vacio=0;c_vacio<((tamano*tamano)-c_llenos);c_vacio){
            //Se solicita el ingreso de las variables
            //Para cada valor esta delimitado para que no pueda ingresar valores erroneos
            do {
                std::cout << "Ingrese la fila \n";
                std::cin >> fila_c;
            }while(fila_c >= tamano);
            do {
                std::cout << "Ingrese la columna \n";
                std::cin >> col_c;
            }while (col_c >= tamano);
            do {
                std::cout << "Ingrese el valor\n";
                std::cin >> valor_c;
            }while (valor_c > tamano);

            // Sí cumple con los parametros anteriores recien se verifica el valor
            if (this->doble(fila_c, col_c, valor_c) == false) {
                    this->tablero[fila_c][col_c] = valor_c;
                    this->imprimir_tablero();
                    c_vacio++;
            } else {
                    std::cout << "El valor es invalido\n";
                    this->imprimir_tablero();
                    c_vacio;
            }
        }

        //Al acabar el juego se felicita al jugador y se le consulta si desea jugar otra vez
        std :: cout << "Felicidades Completaste el sudoku exitosamente\n";
        std :: cout << "¿Quisieras volver a jugar?\n";
    }
};

#endif