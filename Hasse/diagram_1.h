#pragma once
#include "stdafx.h"

/*
Diagrama jerárquico de niveles
*/
class diagram { //objeto gráfico
public:
	vector<vector<int>> j; //vector de jerarquía de nodos
	int x, y, w, h; //w:width, h:height
	string str;
	vector<vector<nodo>> nodos;

	/*Constructor recibe matriz y crea el vector de niveles con elementos(nodos)*/
	diagram(cmatrix &m) :x(0), y(0),h(500),w(400) {
		//creacion de jerarquía
		int cnodos = 0; //contador de nodos registrados (max: tamaño 1D de matriz)
		//llenar nivel 0 con minimales
		vector<int> nivel0;
		for (unsigned int c = 0; c < m.M.size(); c++)
			if (miscOps::isMinimal(m.M[c])) {
				nivel0.push_back(c);
				cnodos++;
			}
		j.push_back(nivel0);
		//para cada otro nivel:
		int nactual = 1;
		while (cnodos < m.d) {	//hasta que todos los nodos hayan sido registrados
			vector<int> niveln;
			for (unsigned int c = 0; c < j[nactual - 1].size(); c++) { //para el nivel previo
				for (int f = 0; f < m.d; f++) {
					if (m.M[f][j[nactual - 1][c]] == 1)
						if (!miscOps::isRepeated(f, niveln)) {
							niveln.push_back(f);
							cnodos++;
						}
					//chekar en fila c 1's y registrarlos en nivel actual
				}
			}
			j.push_back(niveln);
			nactual++;
		}
		int h = j.size()*C::NODO::Y_MARGIN;
		//nodos
		for (unsigned int c = 0; c < j.size(); c++) {
			vector<nodo> nivelActual;
			for (unsigned int f = 0; f < j[c].size(); f++) {
				nivelActual.push_back(nodo(f*C::NODO::X_MARGIN, h-(c*C::NODO::Y_MARGIN), std::to_string(j[c][f])));
			}
			nodos.push_back(nivelActual);
		}
		int maxFila = 0;
		for (int c = 0; (unsigned)c < nodos.size(); c++) {
			if (nodos[c].size() > maxFila) maxFila = nodos[c].size();
		}
		for (unsigned int c = 0; c < nodos.size(); c++) {
			int dx = (maxFila - nodos[c].size())*C::NODO::X_MARGIN / 2;
			for (unsigned int f = 0; f < nodos[c].size(); f++) {
				nodos[c][f].x += dx;
			}
		}
	}

	string to_string() {
		str.clear();
		for (int n = 0; (unsigned)n < j.size(); n++) {
			for (int e = 0; (unsigned)e < j[n].size(); e++) {
				str += std::to_string(j[n][e]);
				str += " - ";
			}
			str += '\n';
		}
		return str;
	};
	// ↓ dibuja las aristas de una matriz m.
	void draw(cmatrix &m, Graphics ^g, Font ^font, SolidBrush ^brush0, SolidBrush ^brush1, Pen ^pen) {
		for (int n = 0; (unsigned)n < nodos.size(); n++) {			//por cada nivel
			for (int e = 0; (unsigned)e < nodos[n].size(); e++) {	//para cada elemento
				for (int em = 0; em < m.d; em++) {	//para cada nodo
					//checkear las aristas de cada nodo (1's en su fila matricial)
					if (m.M[em][j[n][e]])
						g->DrawLine(pen, nodos[n][e].x + x + (C::NODO::DIAMETRO / 2),
							nodos[n][e].y + y + (C::NODO::DIAMETRO / 2),
							getNodo(em)->x + x + (C::NODO::DIAMETRO / 2),
							getNodo(em)->y + y + (C::NODO::DIAMETRO / 2));
				}
				g->FillEllipse(brush0, nodos[n][e].x + x, nodos[n][e].y + y, C::NODO::DIAMETRO, C::NODO::DIAMETRO);
				g->DrawString(gcnew String(nodos[n][e].text.c_str()), font, brush1, nodos[n][e].x + x, nodos[n][e].y + y);
			}
		}

	}

	// ↓ devuelve el nodo en j que tiene el mismo indice i.
	nodo *getNodo(int i) {
		for (int n = 0; (unsigned)n < nodos.size(); n++) {			//por cada nivel
			for (int e = 0; (unsigned)e < nodos[n].size(); e++) {	//para cada elemento
				if (j[n][e] == i) {
					return &nodos[n][e];
				}
			}
		}
	}
	~diagram() {}
};