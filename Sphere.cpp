#include "Sphere.h"

vector<Vertex*> createSphere(float radius, int slice, int stack){

	vector<Vertex*> vertex_list;

	int i, j;
	float actX, actZ, nexX, nexZ, cimaActX, cimaActZ, cimaNexX, cimaNexZ;
	float passoH = (2 * M_PI) / slice;
	float passoV = (M_PI) / stack;
	float altura = radius* sin((M_PI / 2) - passoV);
	float alturaCima = radius;

	for (i = 0; i < slice; i++) {

		float actualX = radius*sin(i*passoH);
		float actualZ = radius*cos(i*passoH);
		float nextX = radius*sin((i+1)*passoH);
		float nextZ = radius*cos((i+1)*passoH);

		for (j = 1; j < stack + 2; j++){

			float aux = cos(asin(altura / radius));
			actX = actualX * aux;
			actZ = actualZ * aux;
			nexX = nextX * aux;
			nexZ = nextZ * aux;

			aux = cos(asin(alturaCima / radius));
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

			alturaCima = altura;
			altura = radius * sin((M_PI/2) - (passoV*j));
		}
		altura = radius * sin((M_PI/2) - passoV);
		alturaCima = radius;

		actualX = nextX;
		actualZ = nextZ;
	}
	return vertex_list;
}
