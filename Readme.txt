main.cpp

1. Se declara a función "presentación"; para poder iniciar la interfaz del programa.

Sudoku.h
2. En el header Sudoku.h; la clase sudoku, posee los atributos privados 
	matrix2d tablero
	int tamano, cuadrantes y p

El constructor de la clase, usa los atributos tamano, cuadrantes, "p" que viene a ser la raíz cuadradrada del número base y la funcion que reestablece el tamaño del tablero
por otra parte usa los metodos inicializarRandom, doble (este método se encarga de verificar de que los valores randomizados sean correctos y no se repitan en fila, columna
ni cuadrante), imprimir_tablero y rellenar_valores.

3. Cada función esta comentada en la parte superior (Menciona que función cumple en el programa) de su declaración