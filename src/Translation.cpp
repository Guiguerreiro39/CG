#include "headers/Translation.h"

Translation::Translation(){
}

Translation::Translation(float a, float b, float c,float t){
	x = a;
	y = b;
	z = c;
	time = t;
	up[0] = 0;
	up[1] = 1;
	up[2] = 0;
}

vector<Vertex*> Translation::getPointsCurv(){
	return points_curv;
}

void getCatmullRomPoint(float t, int *indices, float *res, float *deriv, vector<Vertex*> pontos) {
	float res_aux[4];
	float deriv_aux[4];

	float m[4][4] = { 
	{ -0.5f, 1.5f, -1.5f, 0.5f },
	{ 1.0f, -2.5f, 2.0f, -0.5f },
	{ -0.5f, 0.0f, 0.5f, 0.0f },
	{ 0.0f, 1.0f, 0.0f, 0.0f } 
	};

	res[0] = 0.0; 
	res[1] = 0.0; 
	res[2] = 0.0;
	deriv[0] = 0.0;
	deriv[1] = 0.0;
	deriv[2] = 0.0;

	float t3 = t*t*t, t2 = t*t;

	//T*M
	res_aux[0] = t3*m[0][0] + t2*m[1][0] + t*m[2][0] + m[3][0];
	res_aux[1] = t3*m[0][1] + t2*m[1][1] + t*m[2][1] + m[3][1];
	res_aux[2] = t3*m[0][2] + t2*m[1][2] + t*m[2][2] + m[3][2];
	res_aux[3] = t3*m[0][3] + t2*m[1][3] + t*m[2][3] + m[3][3];

	deriv_aux[0] = (3*t2)*m[0][0] + (2*t)*m[1][0] + m[2][0];
	deriv_aux[1] = (3*t2)*m[0][1] + (2*t)*m[1][1] + m[2][1];
	deriv_aux[2] = (3*t2)*m[0][2] + (2*t)*m[1][2] + m[2][2];
	deriv_aux[3] = (3*t2)*m[0][3] + (2*t)*m[1][3] + m[2][3];

	int i0 = indices[0]; 
	Vertex* p0 = pontos[i0];
	int i1 = indices[1]; 
	Vertex* p1 = pontos[i1];
	int i2 = indices[2]; 
	Vertex* p2 = pontos[i2];
	int i3 = indices[3]; 
	Vertex* p3 = pontos[i3];

	//T*M*P = res
	res[0] = res_aux[0] * p0->getX() + res_aux[1] * p1->getX() + res_aux[2] * p2->getX() + res_aux[3] * p3->getX();
	res[1] = res_aux[0] * p0->getY() + res_aux[1] * p1->getY() + res_aux[2] * p2->getY() + res_aux[3] * p3->getY();
	res[2] = res_aux[0] * p0->getZ() + res_aux[1] * p1->getZ() + res_aux[2] * p2->getZ() + res_aux[3] * p3->getZ();

	deriv[0] = deriv_aux[0] * p0->getX() + deriv_aux[1] * p1->getX() + deriv_aux[2] * p2->getX() + deriv_aux[3] * p3->getX();
	deriv[1] = deriv_aux[0] * p0->getY() + deriv_aux[1] * p1->getY() + deriv_aux[2] * p2->getY() + deriv_aux[3] * p3->getY();
	deriv[2] = deriv_aux[0] * p0->getZ() + deriv_aux[1] * p1->getZ() + deriv_aux[2] * p2->getZ() + deriv_aux[3] * p3->getZ();
}

void Translation::getGlobalCatmullRomPoint(float gt, float *res,float *deriv, vector<Vertex*> pontos) {
	int tam = pontos.size();

	float t = gt * tam; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment

	// indices store the points
	int indices[4]; 
	indices[0] = (index + tam-1)%tam;	
	indices[1] = (indices[0]+1)%tam;
	indices[2] = (indices[1]+1)%tam; 
	indices[3] = (indices[2]+1)%tam;

	getCatmullRomPoint(t, indices, res, deriv, pontos);
}

vector<Vertex*> Translation::genPointsCurv(){
	float res[3];
	float deriv[3];

	for (float t = 0; t<1; t += 0.01){
		getGlobalCatmullRomPoint(t, res, deriv, points_list);

		Vertex* v = new Vertex(res[0], res[1], res[2]);
		points_curv.push_back(v);
	}
	return points_curv;
}

void renderCatmullRomCurve(vector<Vertex*> pontos) {
	int tam = pontos.size();
	float p[3];

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < tam; i++) {
		p[0] = pontos[i]->getX(); 
		p[1] = pontos[i]->getY(); 
		p[2] = pontos[i]->getZ();
		glVertex3fv(p);
	}
	glEnd();
}

void normalize(float *a) {

	float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] = a[0]/l;
	a[1] = a[1]/l;
	a[2] = a[2]/l;
}

void cross(float *a, float *b, float *res) {

	res[0] = a[1]*b[2] - a[2]*b[1];
	res[1] = a[2]*b[0] - a[0]*b[2];
	res[2] = a[0]*b[1] - a[1]*b[0];
}


void curveRotation(float *der, float *up){

	float left[3];

	cross(der,up,left);
	cross(left, der, up);
	
	normalize(der);
	normalize(up);
	normalize(left);
	
	float m[4][4] = { {der[0], der[1], der[2], 0}, 
					  {up[0], up[1], up[2], 0}, 
					  {left[0], left[1], left[2], 0},
					  {0.0f,0.0f,0.0f, 1}
					};
	glMultMatrixf((float*)m);
}	

float Translation::getX(){
	return x;
}

float Translation::getY(){
	return y;
}

float Translation::getZ(){
	return z;
}

float Translation::getTime(){
	return time;
}

vector<Vertex*> Translation::getPoints(){
	return points_list;
}

void Translation::setX(float a){
	x = a;
}

void Translation::setY(float b){
	y = b;
}

void Translation::setZ(float c){
	z = c;
}

void Translation::setTime(float t){
	time = t;
}

void Translation::setPoints(vector<Vertex*> v){
	points_list = v;
}

void Translation::addPoint(Vertex* v){
	points_list.push_back(v);
}

Translation* Translation::clone() const{
	return new Translation(x,y,z,time);
}

void Translation::apply(){
	float te, gt;
	float res[3];
	float deriv[3];

	if(time!=0){
		te = glutGet(GLUT_ELAPSED_TIME) % (int)(time * 1000);
		gt = te / (time * 1000);
		vector<Vertex*> vp2 = genPointsCurv();
		renderCatmullRomCurve(vp2);
		getGlobalCatmullRomPoint(gt,res,deriv,points_list);
		points_curv.clear();
		glTranslatef(res[0], res[1], res[2]);
		curveRotation(deriv,up);
	}
	else {
		glTranslatef(x,y,z);
	}
}

Translation::~Translation(){
}