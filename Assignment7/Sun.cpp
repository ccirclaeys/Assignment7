//
//  Sun.cpp
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Sun.h"

Sun::Sun()
: Model(0)
{
    this->MakeImage("Bitmaps/sunmap.bmp", this->_textureName, false);
}

Sun::~Sun()
{
    
}

void Sun::draw()
{
    GLUquadricObj* quadro = gluNewQuadric();
	gluQuadricNormals(quadro, GLU_SMOOTH);
	gluQuadricTexture(quadro, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glRotatef( -90.0, 1.0, 0.0, 0.0 );
    glBindTexture(GL_TEXTURE_2D, this->_textureName);
    gluSphere(quadro, SUN_RADIUS, 48, 48);
    glPopMatrix();
    glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);
}
