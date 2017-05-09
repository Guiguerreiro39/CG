#include "headers/Figures.h"

vector<Point*> createPlane(float size, vector<Point*> *normal_list, vector<Point*> *texture_list){

	vector<Point*> vertex_list;

	float h = size/2; // para o plano ficar centrado na origem do referencial.
	float texV = 1 / (float) size;
	float texH = 1 / (float) size;

	vertex_list.push_back(new Point(h,0,h));
	normal_list->push_back(new Point(0,1,0));
	texture_list->push_back(new Point(1,1,0));

	vertex_list.push_back(new Point(h,0,-h));
	normal_list->push_back(new Point(0,1,0));
	texture_list->push_back(new Point(1,-1,0));

	vertex_list.push_back(new Point(-h,0,h));
	normal_list->push_back(new Point(0,1,0));
	texture_list->push_back(new Point(-1,1,0));

	vertex_list.push_back(new Point(-h,0,h));
	normal_list->push_back(new Point(0,-1,0));
	texture_list->push_back(new Point(-1,1,0));

	vertex_list.push_back(new Point(h,0,-h));
	normal_list->push_back(new Point(0,-1,0));
	texture_list->push_back(new Point(1,-1,0));

	vertex_list.push_back(new Point(-h,0,-h));
	normal_list->push_back(new Point(0,-1,0));
	texture_list->push_back(new Point(-1,-1,0));

	// print vertex_list.size();

	return vertex_list;

}

vector<Point*> createBox(float cX, float cY, float cZ, int div, vector<Point*> *normal_list, vector<Point*> *texture_list){

	vector<Point*> vertex_list;
	float x = cX/2;
	float y = cY/2;
	float z = cZ/2;
	float shiftX = (float)cX/div;
	float shiftY = (float)cY/div;
	float shiftZ = (float)cZ/div;

	for(int i=0;i<div;i++){
		for(int j=0;j<div;j++){
			//Face da frente
			vertex_list.push_back(new Point(-x + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
			normal_list->push_back(new Point(0,0,1));
			normal_list->push_back(new Point(0,0,1));
			normal_list->push_back(new Point(0,0,1));

			vertex_list.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),z));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),z));
			normal_list->push_back(new Point(0,0,1));
			normal_list->push_back(new Point(0,0,1));
			normal_list->push_back(new Point(0,0,1));

			//Face traseira
			vertex_list.push_back(new Point(-x + (j*shiftX),-y + (i*shiftY),-z));
			vertex_list.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));
			normal_list->push_back(new Point(0,0,-1));
			normal_list->push_back(new Point(0,0,-1));
			normal_list->push_back(new Point(0,0,-1));

			vertex_list.push_back(new Point(-x + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),(-y+shiftY) + (i*shiftY),-z));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y + (i*shiftY),-z));
			normal_list->push_back(new Point(0,0,-1));
			normal_list->push_back(new Point(0,0,-1));
			normal_list->push_back(new Point(0,0,-1));

			//Face direita
			vertex_list.push_back(new Point(x,-y + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Point(x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
			vertex_list.push_back(new Point(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			normal_list->push_back(new Point(1,0,0));
			normal_list->push_back(new Point(1,0,0));
			normal_list->push_back(new Point(1,0,0));

			vertex_list.push_back(new Point(x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Point(x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Point(x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			normal_list->push_back(new Point(1,0,0));
			normal_list->push_back(new Point(1,0,0));
			normal_list->push_back(new Point(1,0,0));

			//Face esquerda
			vertex_list.push_back(new Point(-x,-y + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Point(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Point(-x,(-y+shiftY) + (i*shiftY),-z +(j*shiftZ)));
			normal_list->push_back(new Point(-1,0,0));
			normal_list->push_back(new Point(-1,0,0));
			normal_list->push_back(new Point(-1,0,0));

			vertex_list.push_back(new Point(-x,(-y+shiftY) + (i*shiftY),-z + (j*shiftZ)));
			vertex_list.push_back(new Point(-x,-y + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			vertex_list.push_back(new Point(-x,(-y+shiftY) + (i*shiftY),(-z+shiftZ) + (j*shiftZ)));
			normal_list->push_back(new Point(-1,0,0));
			normal_list->push_back(new Point(-1,0,0));
			normal_list->push_back(new Point(-1,0,0));

			//Topo
			vertex_list.push_back(new Point(-x + (j*shiftX),y,-z + (i*shiftZ)));
			vertex_list.push_back(new Point(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));
			normal_list->push_back(new Point(0,1,0));
			normal_list->push_back(new Point(0,1,0));
			normal_list->push_back(new Point(0,1,0));

			vertex_list.push_back(new Point(-x + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),y,-z + (i*shiftZ)));
			normal_list->push_back(new Point(0,1,0));
			normal_list->push_back(new Point(0,1,0));
			normal_list->push_back(new Point(0,1,0));

			//Base
			vertex_list.push_back(new Point(-x + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Point(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
			normal_list->push_back(new Point(0,-1,0));
			normal_list->push_back(new Point(0,-1,0));
			normal_list->push_back(new Point(0,-1,0));

			vertex_list.push_back(new Point(-x + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y,-z + (i*shiftZ)));
			vertex_list.push_back(new Point((-x+shiftX) + (j*shiftX),-y,(-z+shiftZ) + (i*shiftZ)));	
			normal_list->push_back(new Point(0,-1,0));
			normal_list->push_back(new Point(0,-1,0));
			normal_list->push_back(new Point(0,-1,0));
		}
	}
	return vertex_list;
}

vector<Point*> createCone(float radius, float height, int slice, int stack, vector<Point*> *normal_list, vector<Point*> *texture_list){

	vector<Point*> vertex_list;

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
				vertex_list.push_back(new Point(0,0,0));
				normal_list->push_back(new Point(0,-1,0));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,0,z));
				normal_list->push_back(new Point(0,-1,0));

				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Point(x,0,z));
				normal_list->push_back(new Point(0,-1,0));

			}
			if (i < stack - 1) {
				// desenhar 2 triangulos para um lado (slice)
				x = (radius - ((i+1)*t)) * sin(alfa + dimSide);
				z = (radius - ((i+1)*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,(i+1)*l,z));
				normal_list->push_back(new Point(sin(alfa + dimSide),l,cos(alfa + dimSide)));
				
				x = (radius - ((i+1)*t)) * sin(alfa);
				z = (radius - ((i+1)*t)) * cos(alfa);
				vertex_list.push_back(new Point(x,(i+1)*l,z));
				normal_list->push_back(new Point(sin(alfa),l,cos(alfa)));
				
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point(sin(alfa),l,cos(alfa)));

				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point(sin(alfa),l,cos(alfa)));
				
				x = (radius - (i*t)) * sin(alfa + dimSide);
				z = (radius - (i*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point(sin(alfa + dimSide),l,cos(alfa + dimSide)));
				
				x = (radius - ((i+1)*t)) * sin(alfa + dimSide);
				z = (radius - ((i+1)*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,(i+1)*l,z));
				normal_list->push_back(new Point(sin(alfa + dimSide),l,cos(alfa + dimSide)));

			}
			else {
				// desenhar o topo do cone
				x = (radius - (i*t)) * sin(alfa);
				z = (radius - (i*t)) * cos(alfa);
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point(0,-1,0));

				x = (radius - (i*t)) * sin(alfa + dimSide);
				z = (radius - (i*t)) * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point(0,-1,0));

				vertex_list.push_back(new Point(0,(i+1)*l,0));
				normal_list->push_back(new Point(0,-1,0));

			}
		}
	}
	return vertex_list;
}

vector<Point*> createSphere(float radius, int slice, int stack, vector<Point*> *normal_list, vector<Point*> *texture_list){

	vector<Point*> vertex_list;

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
			float aux2 = cos(asin(alturaCima/radius));
			cimaActX = actualX * aux2;
			cimaActZ = actualZ * aux2;
			cimaNexX = nextX * aux2;
			cimaNexZ = nextZ * aux2;

			vertex_list.push_back(new Point(actX,altura,actZ));
			vertex_list.push_back(new Point(nexX,altura,nexZ));
			vertex_list.push_back(new Point(cimaActX,alturaCima,cimaActZ));
			normal_list->push_back(new Point(sin(i*passoH),altura/radius,cos(i*passoH)));
			normal_list->push_back(new Point(sin((i+1)*passoH),altura/radius,cos((i+1)*passoH)));
			normal_list->push_back(new Point(sin(i*passoH),alturaCima/radius,cos(i*passoH)));

			vertex_list.push_back(new Point(cimaActX,alturaCima,cimaActZ));
			vertex_list.push_back(new Point(nexX,altura,nexZ));
			vertex_list.push_back(new Point(cimaNexX,alturaCima,cimaNexZ));
			normal_list->push_back(new Point(sin(i*passoH),alturaCima/radius,cos(i*passoH)));
			normal_list->push_back(new Point(sin((i+1)*passoH),altura/radius,cos((i+1)*passoH)));
			normal_list->push_back(new Point(sin((i+1)*passoH),alturaCima/radius,cos((i+1)*passoH)));

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

vector<Point*> createCylinder(float radius, float height, int slice, int stack, vector<Point*> *normal_list, vector<Point*> *texture_list){

	vector<Point*> vertex_list;

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
				vertex_list.push_back(new Point(0,0,0));
				normal_list->push_back(new Point(0,-1,0));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,0,z));
				normal_list->push_back(new Point(0,-1,0));

				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Point(x,0,z));
				normal_list->push_back(new Point(0,-1,0));
			}
			if (i < stack - 1) {
				// desenhar 2 triangulos para um lado (slice)
				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,(i+1)*l,z));
				normal_list->push_back(new Point( sin(alfa + dimSide), 0, cos(alfa + dimSide)));

				x = radius  * sin(alfa);
				z = radius  * cos(alfa);
				vertex_list.push_back(new Point(x,(i+1)*l,z));
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point( sin(alfa), 0, cos(alfa)));
				normal_list->push_back(new Point( sin(alfa), 0, cos(alfa)));
				
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point( sin(alfa), 0, cos(alfa)));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,i*l,z));
				vertex_list.push_back(new Point(x,(i+1)*l,z));
				normal_list->push_back(new Point( sin(alfa + dimSide), 0, cos(alfa + dimSide)));
				normal_list->push_back(new Point( sin(alfa + dimSide), 0, cos(alfa + dimSide)));

			}
			else {
				// desenhar o topo do cilindro
				x = radius * sin(alfa);
				z = radius * cos(alfa);
				vertex_list.push_back(new Point(x,i*l,z));
				normal_list->push_back(new Point(0,1,0));

				x = radius * sin(alfa + dimSide);
				z = radius * cos(alfa + dimSide);
				vertex_list.push_back(new Point(x,i*l,z));
				vertex_list.push_back(new Point(0,i*l,0));
				normal_list->push_back(new Point(0,1,0));
				normal_list->push_back(new Point(0,1,0));
			}
		}
	}
	return vertex_list;
}

vector<Point*> createTorus(float radiusIn, float radiusOut, int sides, int rings, vector<Point*> *normal_list, vector<Point*> *texture_list){

	vector<Point*> vertex_list;

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

			vertex_list.push_back(new Point(x0*r,y0*r,z));
			vertex_list.push_back(new Point(x1*r,y1*r,z));
			vertex_list.push_back(new Point(x0*nr,y0*nr,nz));
			normal_list->push_back(new Point( 0, 0, sin(j*dimSide)));
			normal_list->push_back(new Point( 0, 0, sin(j*dimSide)));
			normal_list->push_back(new Point( 0, 0, sin((j+1)*dimSide)));

			vertex_list.push_back(new Point(x0*nr,y0*nr,nz));
			vertex_list.push_back(new Point(x1*r,y1*r,z));
			vertex_list.push_back(new Point(x1*nr,y1*nr,nz));
			normal_list->push_back(new Point( 0, 0, sin((j+1)*dimSide)));
			normal_list->push_back(new Point( 0, 0, sin(j*dimSide)));
			normal_list->push_back(new Point( 0, 0, sin((j+1)*dimSide)));
		}
	}
		
	return vertex_list;
}

Point* evalBezierCurve(float t, Point* p1, Point* p2, Point* p3, Point* p4) {

	float x, y, z;

	float it = 1.0 - t;

	float b0 = it * it * it;
	float b1 = 3 * t * it * it;
	float b2 = 3 * t * t * it;
	float b3 = t * t * t;

	x = b0*p1->getX() + b1*p2->getX() + b2*p3->getX() + b3*p4->getX();
	y = b0*p1->getY() + b1*p2->getY() + b2*p3->getY() + b3*p4->getY();
	z = b0*p1->getZ() + b1*p2->getZ() + b2*p3->getZ() + b3*p4->getZ();

	Point* new_point = new Point(x, y, z);
	return new_point;
}

Point* evalBezierPatch(float u, float v, vector<Point*> control_points) {
	float matrix[4][3], result_matrix[4][3];
	int i, j = 0, k=0;

	for (i = 0; i < 16; i ++) {
		matrix[j][0] = control_points[i]->getX();
		matrix[j][1] = control_points[i]->getY();
		matrix[j][2] = control_points[i]->getZ();

		j++;

		if (j % 4 == 0) {
			Point* point = evalBezierCurve(u, 	new Point(matrix[0][0],matrix[0][1],matrix[0][2]),
											new Point(matrix[1][0],matrix[1][1],matrix[1][2]),
											new Point(matrix[2][0],matrix[2][1],matrix[2][2]),
											new Point(matrix[3][0],matrix[3][1],matrix[3][2]));

			result_matrix[k][0] = point->getX();
			result_matrix[k][1] = point->getY();
			result_matrix[k][2] = point->getZ();
			
			k++;
			j = 0;
		}
	} 
	return evalBezierCurve(v, 	new Point(result_matrix[0][0],result_matrix[0][1],result_matrix[0][2]),
							  	new Point(result_matrix[1][0],result_matrix[1][1],result_matrix[1][2]),
			    				new Point(result_matrix[2][0],result_matrix[2][1],result_matrix[2][2]),
								new Point(result_matrix[3][0],result_matrix[3][1],result_matrix[3][2]));
}


vector<Point*> renderBezierPatch(int divs, vector<Patch*> patch_list){

	vector<Point*> result_list;
	float u, u2, v, v2;
	float inc = 1.0 / divs;

	for(int n_patches = 0; n_patches < patch_list.size(); n_patches++){

		vector<Point*> control_points = patch_list[n_patches]->getControlPoints();

		for(int j=0; j <= divs ; j++){
			for(int i=0; i <= divs; i++){

				u = i * inc;
				v = j * inc;
				u2 = (i+1) * inc;
				v2 = (j+1) * inc;

				Point* p0 = evalBezierPatch(u, v, control_points);
				Point* p1 = evalBezierPatch(u, v2, control_points);
				Point* p2 = evalBezierPatch(u2, v, control_points);
				Point* p3 = evalBezierPatch(u2, v2, control_points);

				result_list.push_back(p0);
				result_list.push_back(p2);
				result_list.push_back(p3);

				result_list.push_back(p0);
				result_list.push_back(p3);
				result_list.push_back(p1); 	
			}
		}
	}

	return result_list;
}