#pragma once

//matriz cuadrada
class cmatrix {			 
public:
	vector<vector<bool>> M;
	int d;			//d: dimension de matriz
	int w, h;		//width, height - ancho y alto en pixeles
	int x, y;		//posición
	string str;		//matriz en texto

	//creación de matriz (t:vector de totales de suma de indicadores
	cmatrix(vector<int> &t);

	//constructor opcional para matriz aleatoria tamaño dxd
	cmatrix(int d);

	//constructor opcional para matriz vacía (c=0) tamaño dxd
	cmatrix(int d, bool c);

	//setear propiedades w y h (ancho y alto) de la matriz en píxeles
	void set_WH(Graphics ^g, Font ^font);

	//devuelve la matriz en texto (std::string)
	string to_string();

	//devuelve std::string con ¬c's convertidos a ' '.
	string getChar(char c);

	void draw(Graphics ^g, Font ^font, SolidBrush ^brush0, SolidBrush ^brush1,int X, int Y);

	~cmatrix();
};

namespace cmatrixOps {
	//devuelve la matriz al cuadrado
	cmatrix *alCuadrado(cmatrix &mi);
	//devuelve matriz1 - matriz2, (truncado, -1=0).
	cmatrix *resta(cmatrix &m1, cmatrix &m2);
	//compara columna con fila como parte de multiplicación de matrices
	bool AND(vector<bool> &a, vector<bool> &b);
	//devuelve un vector de length elementos con int aleatorios de 0 a range.
	vector<int> getRandomVector(int length, int range);
}
