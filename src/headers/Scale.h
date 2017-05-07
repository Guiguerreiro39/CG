#ifndef __SCALE_H__
#define __SCALE_H__

#include <GL/glut.h>
#include "Operation.h"

class Scale: public Operation{

	public:
		Scale(float,float,float);
		void apply();
		virtual ~Scale();
};

#endif