#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream> 

using namespace std;
using namespace System;
using namespace System::Drawing;

// ↓ namespace de constantes.
namespace C {
	// ↓ — Colores para ser llamados en Form → Color::FromArgb(COLORES::MATRIZ_1)
	namespace COLORES {
		extern INT32 FONDO;
		extern INT32 MATRIZ_0;
		extern INT32 MATRIZ_1;
	};
	// ↓ - Formatos estándar de los nodos del Diagrama gráfico
	namespace NODO {
		extern int DIAMETRO;
		extern int Y_MARGIN;
		extern int X_MARGIN;
	}
	// ↓ - Otras constantes
	namespace OTROS {
		/*Rango max para la generación de valores aleatorios.
		A mayor el rango, menos niveles en el Hasse y más vecinos.*/
		extern int RANGO_PESOS;
		extern int MAXP;
		extern int MAXI;
	}
	// ↓ - Constantes del form input, el inicial.
	namespace FI {
		extern int in_x;	//93
		extern int in_y;	//100
		extern int itxt_x;	//105
		extern int itxt_y;	//75
		extern int i_dx;	//45
		extern int p_x;		//19
		extern int p_y;		//100
		extern int p_dy;	//26
	}
};
class nodo {
public:
	int x, y;
	string text;
	nodo(int x, int y, string t);
	~nodo() {};
};

// ↓ - Operaciones misceláneas
namespace miscOps {
	// ↓ - devuelve true si el vector no tiene 1's.
	bool isMinimal(vector<bool> &c);
	// ↓ - devuelve true si el nivel actual ya tiene a c registrado.
	bool isRepeated(int c, vector<int> &nivel);
};