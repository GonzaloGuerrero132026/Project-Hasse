#include "background.h"
#include "stdafx.h"
// ↓ — Definición de colores
INT32 C::COLORES::FONDO = 0xFF808080;
INT32 C::COLORES::MATRIZ_0 = 0xffA7A7A7;
INT32 C::COLORES::MATRIZ_1 = 0xFF222222;

// ↓ — Definiciones para gráficos de diagramas
int C::NODO::DIAMETRO = 20;
int C::NODO::Y_MARGIN = 50;
int C::NODO::X_MARGIN = 50;

// ↓ — Ver .h
int C::OTROS::RANGO_PESOS = 20;
int C::OTROS::MAXP= 50;
int C::OTROS::MAXI = 20;

int C::FI::in_x = 93;
int C::FI::in_y = 100;
int C::FI::itxt_x = 105;
int C::FI::itxt_y = 75;
int C::FI::i_dx = 45;
int C::FI::p_x = 19;
int C::FI::p_y = 100;
int C::FI::p_dy = 26;

nodo::nodo(int x, int y, string t) {
	this->x = x;
	this->y = y;
	text = t;
};


bool miscOps::isMinimal(vector<bool> &c) {		//devuelve true si el vector no tiene 1's.
	for (unsigned int i = 0; i < c.size(); i++) {
		if (c[i] == 1) return false;
	}
	return true;
};
bool miscOps::isRepeated(int c, vector<int> &nivel) {	//devuelve true si el vector ya tiene a c registrado.
	for (unsigned int i = 0; i < nivel.size(); i++) {
		if (nivel[i] == c)
			return true;
	}
	return false;
};
