#include "headers/Sphere.h"

vector<Vertex*> createSphere(float radius, int slice, int stack){

	vector<Vertex*> vertex_list;

	int i, j;
	float actX, actZ, nexX, nexZ, cimaActX, cimaActZ, cimaNexX, cimaNexZ;
	float passoH = (2*M_PI)/slice; // deslocamento na horizontal (angulo)
	float passoV = M_PI/stack; // deslocamento na vertical (angulo)
	float altura = radius * sin((M_PI/2) - passoV); // altura das camadas (stacks) (começa por cima)
	float alturaCima = radius;

	for (i = 0; i < slice; i++) {
		//A esfera é desenhada fatia a fatia (slice)

		//Ponto actual (coord X e Z)
		float actualX = radius * sin(i*passoH);
		float actualZ = radius * cos(i*passoH);

		//Ponto seguinte (coord X e Z)
		float nextX = radius * sin((i+1)*passoH);
		float nextZ = radius * cos((i+1)*passoH);

		for (j = 1; j < stack + 2; j++){
			// Inicia-se por desenhar os triangulos do topo da esfera, até ao fundo, seguindo uma "fatia" (slice)

			// Pontos inferiores do triangulo
			float aux = cos(asin(altura/radius));
			actX = actualX * aux;
			actZ = actualZ * aux;
			nexX = nextX * aux;
			nexZ = nextZ * aux;

			//valor do cos vai aumentado (e certa altura diminuir), com a interaçao do ciclo, fazendo a fatia ganhar uma curvatura.

			//Pontos superiores do triangulo
			aux = cos(asin(alturaCima/radius));
			cimaActX = actualX * aux;
			cimaActZ = actualZ * aux;
			cimaNexX = nextX * aux;
			cimaNexZ = nextZ * aux;

			vertex_list.push_back(new Vertex(actX,altura,actZ));
			vertex_list.push_back(new Vertex(nexX,altura,nexZ));
			vertex_list.push_back(new Vertex(cimaActX,alturaCima,cimaActZ));

			vertex_list.push_back(new Vertex(cimaActX,alturaCima,cimaActZ));
			vertex_list.push_back(new Vertex(nexX,altura,nexZ));
			vertex_list.push_back(new Vertex(cimaNexX,alturaCima,cimaNexZ));

			//Passa o valor de altura para alturaCima, e actualiza o valor de altura, para desenhar os triangulos abaixo.
			alturaCima = altura;
			altura = radius * sin((M_PI/2) - (passoV*j));
		}
		//Repoes as alturas iniciais iniciais 		
		altura = radius * sin((M_PI/2) - passoV);
		alturaCima = radius;
	}
	return vertex_list;
}
