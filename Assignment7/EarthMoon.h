//
//  EarthMoon.h
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__EarthMoon__
#define __Assignment7__EarthMoon__

#include <GLUT/GLUT.h>

#include <iostream>
#include "Model.h"

const GLfloat LUNAR_CYCLE       = 30.0;
const GLfloat EARTH_INCLINATION   = 7;
const GLfloat EARTH_ORBIT_DUR=		365;
const GLfloat EARTH_ORBIT_RADIUS = 	 3.0;
const GLfloat EARTH_RADIUS      = 0.18;
const GLfloat MOON_ORBIT_RADIUS = 0.50;
const GLfloat MOON_RADIUS       = 0.04;

class EarthMoon : public Model
{
private:
    float _earthDayIncrement;
    float _earthDaysTranspired;
    float _currentEarthRotation;
    int _moonTextureName;
    
public:
    EarthMoon();
    ~EarthMoon(){}
    virtual void draw();
    virtual void update();
    virtual void accelerateRotation();
    virtual void decelerateRotation();
};

#endif /* defined(__Assignment7__EarthMoon__) */
