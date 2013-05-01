//
//  EarthMoon.cpp
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#include "EarthMoon.h"

EarthMoon::EarthMoon()
: Model(3), _moonTextureName(4), _earthDaysTranspired(0), _currentEarthRotation(0), _earthDayIncrement(0.01f)
{
    this->MakeImage("Bitmaps/earthmap.bmp", this->_textureName, false);
}

void EarthMoon::draw()
{
    GLfloat MoonRevolution = _earthDaysTranspired / LUNAR_CYCLE;
    
	GLUquadricObj* quadro = gluNewQuadric();
	gluQuadricNormals(quadro, GLU_SMOOTH);
	gluQuadricTexture(quadro, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
    
    glPushMatrix();
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
        glPushMatrix();
            glRotatef(EARTH_INCLINATION, 0.0, 0.0, 1.0);
            glRotatef( 360.0 * (_earthDaysTranspired / EARTH_ORBIT_DUR), 0.0, 1.0, 0.0);
            glTranslatef(EARTH_ORBIT_RADIUS, 0.0, 0.0 );
            glRotatef( 360.0 * _currentEarthRotation, 0.0, 1.0, 0.0 );
            glRotatef( -90.0, 1.0, 0.0, 0.0 );
            glBindTexture(GL_TEXTURE_2D, this->_textureName);
            gluSphere(quadro, EARTH_RADIUS, 48, 48);
        glPopMatrix();
    
        glRotatef(EARTH_INCLINATION, 0.0, 0.0, 1.0);
        glRotatef( 360.0 * (_earthDaysTranspired / EARTH_ORBIT_DUR), 0.0, 1.0, 0.0);
        glTranslatef(EARTH_ORBIT_RADIUS, 0.0, 0.0 );
        glRotatef( 360.0 * MoonRevolution, 0.0, 1.0, 0.0 );
        glTranslatef( MOON_ORBIT_RADIUS  , 0.0, 0.0 );
        glBindTexture(GL_TEXTURE_2D, _moonTextureName);
        gluSphere(quadro, MOON_RADIUS, 48, 48);
    glPopMatrix();
    
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);
}

void EarthMoon::update()
{
    _currentEarthRotation += _earthDayIncrement;
	_earthDaysTranspired += _earthDayIncrement;
	if (_earthDaysTranspired == EARTH_ORBIT_DUR)
		_earthDaysTranspired = 0;
}

void EarthMoon::accelerateRotation()
{
    _earthDayIncrement *= 2.0;
    if (_earthDayIncrement > 10.0)
        _earthDayIncrement = 10.0;
}

void EarthMoon::decelerateRotation()
{
    _earthDayIncrement *= 0.5;
    if (_earthDayIncrement < 0.01)
        _earthDayIncrement = 0.01;
}
