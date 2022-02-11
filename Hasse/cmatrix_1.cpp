#include "stdafx.h"
#include "cmatrix.h"

//matriz cuadrada

cmatrix::cmatrix(vector<int> &t) :x(0), y(0), d(t.size()) {
	//lenar matriz con 0's
	for (int f = 0; f < d; f++) {		//por cada fila
		vector<bool> newFila;
		for (int c = 0; c < d; c++) {	//por cada columna
			newFila.push_back(0);
		}
		M.push_back(newFila);			//agregar nueva fila a la matriz
	}
	//llenar los 1's
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			if (t[i] > t[j])
				M[i][j] = 1;
	str = to_string();
};

//constructor opcional para matriz aleatoria tamaño dxd
cmatrix::cmatrix(int d) :cmatrix::cmatrix(cmatrixOps::getRandomVector(d, 20)) {};
//constructor opcional para matriz vacía tamaño dxd
cmatrix::cmatrix(int d, bool c) :cmatrix::cmatrix(cmatrixOps::getRandomVector(d, c)) {};

//setear h y w de la matriz en píxeles
void cmatrix::set_WH(Graphics ^g, Font ^font) {
	SizeF size = g->MeasureString(gcnew String(str.c_str()), font);
	h = (int)size.Height;
	w = (int)size.Width;
};

//devuelve la matriz en texto (std::string)
string cmatrix::to_string() {
	str.clear();
	for (int f = 0; f < d; f++) {
		for (int c = 0; c < d; c++) {
			str += (M[c][f])? "1" : "0";
			str += ' ';
		}
		str += '\n';
	}
	return str;
}

//devuelve std::string con ¬c's convertidos a ' '.
string cmatrix::getChar(char c) {
	string s = str;
	for (int i = 0; (unsigned)i < s.length(); i++) {
		if (s[i] != c && s[i] != '\n')
			s[i] = ' ';
	};
	return s;
}

void cmatrix::draw(Graphics ^g, Font ^font, SolidBrush ^brush0, SolidBrush ^brush1,int X, int Y) {
	g->DrawString(gcnew String(getChar('0').c_str()), font, brush0, x+X, y+Y);
	g->DrawString(gcnew String(getChar('1').c_str()), font, brush1, x+X, y+Y);
}

cmatrix::~cmatrix() {};


cmatrix* cmatrixOps::alCuadrado(cmatrix &mi) {			//devuelve la matriz al cuadrado
	cmatrix *mo = new cmatrix(mi.d,0);
	vector<bool>vc;
	vector<bool>vf;
	for (int c = 0; c < mi.d; c++) {
		for (int f = 0; f < mi.d; f++) {
			for (int v=0; v < mi.d; v++) {
				vc.push_back(mi.M[c][v]);
				vf.push_back(mi.M[v][f]);
			}
			mo->M[c][f] = AND(vc, vf);
			vc.clear();
			vf.clear();
		}
	}
	mo->str = mo->to_string();
	return mo;
};

cmatrix* cmatrixOps::resta(cmatrix &m1, cmatrix &m2) {	//devuelve matriz1 - matriz2, truncado: -1=0.
	cmatrix *mo = new cmatrix(m1.d,0);
	for (int oc = 0; oc < m1.d; oc++) {
		for (int of = 0; of < m1.d; of++) {
			if (m1.M[oc][of] == 1 && m2.M[oc][of] == 0)
				mo->M[oc][of] = 1;
			else mo->M[oc][of] = 0;
		}
	}
	mo->str = mo->to_string();
	return mo;
};

bool cmatrixOps::AND(vector<bool> &a, vector<bool> &b) {	//compara columna con fila como parte de multiplicación de matrices
	for (unsigned int i = 0; i < a.size(); i++) {
		if (a[i] && b[i])							//equivalente a (X^Y): 1 si ambos son 1, 0 caso contrario
			return 1;
	}
	return 0;
};

vector<int> cmatrixOps::getRandomVector(int length, int range) {	//devuelve un vector de length elementos con int aleatorios de 0 a range.
	vector<int> vo;
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		if (range > 0)
			vo.push_back(rand() % range);
		else
			vo.push_back(0);
	}
	return vo;
};