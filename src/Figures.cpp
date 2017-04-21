#include "headers/Figures.h"

vector<Vertex*> createPlane(float size){

	vector<Vertex*> vertex_list;
	float h = size/2; // para o plano ficar centrado na origem do referencial.

	vertex_list.push_back(new Vertex(h,0,h));
	vertex_list.push_back(new Vertex(h,0,-h));
	vertex_list.push_back(new Vertex(-h,0,h));

	vertex_list.push_back(new Vertex(-h,0,h));
	vertex_list.push_back(new Vertex(h,0,-h));
	vertex_list.push_back(new Vertex(-h,0,-h));

	return vertex_list;

}

vector<Vertex*> createBox(float cX, float cY, float cZ, int div){

	vector<Vertex*> vertex_list;
	float x = cX/2;
	float y = cY/2;
	float z = cZ/2;
	float shiftX = (float)cX/div;
	float shiftY = (float)cY/div;
	float shiftZ = (float)cZ/div;

	for(int i=0;i<div;i++){
		for(int j=0;j<div;j++){
			//Face da frente
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),z));

			//Face traseira
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y + (i*shiftY),-z));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));

			//Face direita
			vertex_list.push_back(new Vertex(x,-y + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
			vertex_list.push_back(new Vertex(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			
			vertex_list.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Vertex(x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Vertex(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			
			//Face esquerda
			vertex_list.push_back(new Vertex(-x,-y + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
			
			vertex_list.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Vertex(-x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));

			//Topo
			vertex_list.push_back(new Vertex(-x + (j*shiftX),y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));
			
			vertex_list.push_back(new Vertex(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));
			
			//Base
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));

			vertex_list.push_back(new Vertex(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Vertex((-x+shiftX) + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));	
		}
	}
	return vertex_list;
}

vector<Vertex*> createCone(float radius, float height, int slice, int stack){

	vector<Vertex*> vertex_list;

	float alfa,x,z;
	float h = height;
	float l = sqrt(pow(h,2) + pow(radius,2))/stack;
	float t = radius/stack;
	float dimSide = (2*M_PI)/slice;

	for (int i = 0; i < stack; i++) {		
		for (int j = 0; j < slice; j++) {
			alfa = j * dimSide;
			if (i == 0){
				// desenhar a base
				vertex_list.push_back(new Vertex(0,0,0));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,0,z));

				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Vertex(x,0,z));
			}
			if (i < stack - 1) {
				// desenhar 2 triangulos para um lado (slice)
				x = (radius - ((i+1)*t)) * sin(alfa + dimSide);
				z = (radius - ((i+1)*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				
				x = (radius - ((i+1)*t)) * sin(alfa);
				z = (radius - ((i+1)*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				vertex_list.push_back(new Vertex(x,i*l,z));
				
				x = (radius - (i*t)) * sin(alfa + dimSide);
				z = (radius - (i*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,i*l,z));
				
				x = (radius - ((i+1)*t)) * sin(alfa + dimSide);
				z = (radius - ((i+1)*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
			}
			else {
				// desenhar o topo do cone
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				x = (radius - (i*t)) * sin(alfa + dimSide);
				z = (radius - (i*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,i*l,z));

				vertex_list.push_back(new Vertex(0,(i+1)*l,0));
			}
		}
	}
	return vertex_list;
}

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

vector<Vertex*> createCylinder(float radius, float height, int slice, int stack){

	vector<Vertex*> vertex_list;

	float alfa,x,z;
	float h = height;
	float l = sqrt(pow(h,2) + pow(radius,2))/stack;
	float t = radius/stack;
	float dimSide = (2*M_PI)/slice;

	for (int i = 0; i < stack; i++) {		
		for (int j = 0; j < slice; j++) {
			alfa = j * dimSide;
			if (i == 0){
				// desenhar a base
				vertex_list.push_back(new Vertex(0,0,0));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,0,z));

				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Vertex(x,0,z));
			}
			if (i < stack - 1) {
				// desenhar 2 triangulos para um lado (slice)
				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));

				x = radius  * sin(alfa);
				z = radius  * cos(alfa);
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
				vertex_list.push_back(new Vertex(x,i*l,z));
				
				vertex_list.push_back(new Vertex(x,i*l,z));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,i*l,z));
				vertex_list.push_back(new Vertex(x,(i+1)*l,z));
			}
			else {
				// desenhar o topo do cilindro
				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Vertex(x,i*l,z));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Vertex(x,i*l,z));
				vertex_list.push_back(new Vertex(0,i*l,0));
			}
		}
	}
	return vertex_list;
}

vector<Vertex*> createTorus(float radiusIn, float radiusOut, int sides, int rings){

	vector<Vertex*> vertex_list;

	float dimSide = (2*M_PI)/sides;
	float dimRing = (2*M_PI)/rings;

	for (int i = 0; i < rings; i++) {		
		double a0 = i*dimRing;
		double a1 = a0 + dimRing;

		float x0 = cos(a0);
		float y0 = sin(a0);
		float x1 = cos(a1);
		float y1 = sin(a1);

		for (int j = 0; j < sides+1; j++){

			//pontos actuais
			float c = cos(j*dimSide);
			float r = radiusIn * c + radiusOut;
			float z = radiusIn * sin(j*dimSide);
			
			//proximos pontos
			float nc = cos((j+1)*dimSide);
			float nr = radiusIn * nc + radiusOut;
			float nz = radiusIn * sin((j+1)*dimSide);

			vertex_list.push_back(new Vertex(x0*r,y0*r,z));
			vertex_list.push_back(new Vertex(x1*r,y1*r,z));
			vertex_list.push_back(new Vertex(x0*nr,y0*nr,nz));

			vertex_list.push_back(new Vertex(x0*nr,y0*nr,nz));
			vertex_list.push_back(new Vertex(x1*r,y1*r,z));
			vertex_list.push_back(new Vertex(x1*nr,y1*nr,nz));		
		}
	}
		
	return vertex_list;
}

Vertex* evalBezierCurve(float t, Vertex* p1, Vertex* p2, Vertex* p3, Vertex* p4) {

	float result_point[3];

	float it = 1.0 - t;

	float b0 = it * it * it;
	float b1 = 3 * t * it * it;
	float b2 = 3 * t * t * it;
	float b3 = t * t * t;

	result_point[0] = b0*p1->getX() + b1*p2->getX() + b2*p3->getX() + b3*p4->getX();
	result_point[1] = b0*p1->getY() + b1*p2->getY() + b2*p3->getY() + b3*p4->getY();
	result_point[2] = b0*p1->getZ() + b1*p2->getZ() + b2*p3->getZ() + b3*p4->getZ();

	Vertex* new_point = new Vertex(result_point[0], result_point[1], result_point[2]);
	return new_point;
}
 
Vertex* evalBezierPatch(float u, float v, vector<Vertex*> control_points){

	Vertex* points[4];

	for(int i=0,j=0; i<16; i+=4,j++)
		points[j] = evalBezierCurve(u, control_points[i], control_points[i+1], control_points[i+2], control_points[i+3]);
	
	return evalBezierCurve(v, points[0], points[1], points[2], points[3]);
}

vector<Vertex*> renderBezierPatch(int divs, vector<Patch*> patch_list){

	vector<Vertex*> result_list;
	float u, u2, v, v2;

	for(int n_patches = 0; n_patches < patch_list.size(); n_patches++){

		vector<Vertex*> control_points = patch_list[n_patches]->getControlPoints();

		for(int j=0; j <= divs ; j++){
			for(int i=0; i <= divs; i++){

				u = i/(float) divs;
				v = j/(float) divs;
				u2 = (i+1)/(float) divs;
				v2 = (j+1)/(float) divs;

				result_list.push_back(evalBezierPatch(u, v, control_points));
				result_list.push_back(evalBezierPatch(u, v2, control_points));
				result_list.push_back(evalBezierPatch(u2, v2, control_points));

				result_list.push_back(evalBezierPatch(u, v, control_points));
				result_list.push_back(evalBezierPatch(u2, v2, control_points));
				result_list.push_back(evalBezierPatch(u, v2, control_points));
			}
		}
	}

	return result_list;
}




