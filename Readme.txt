main.cpp

1. Se declara a funci�n "presentaci�n"; para poder iniciar la interfaz del programa.

Sudoku.h
2. En el header Sudoku.h; la clase sudoku, posee los atributos privados 
	matrix2d tablero
	int tamano, cuadrantes y p

El constructor de la clase, usa los atributos tamano, cuadrantes, "p" que viene a ser la ra�z cuadradrada del n�mero base y la funcion que reestablece el tama�o del tablero
por otra parte usa los metodos inicializarRandom, doble (este m�todo se encarga de verificar de que los valores randomizados sean correctos y no se repitan en fila, columna
ni cuadrante), imprimir_tablero y rellenar_valores.

3. Cada funci�n esta comentada en la parte superior (Menciona que funci�n cumple en el programa) de su declaraci�n