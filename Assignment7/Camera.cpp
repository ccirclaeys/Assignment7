//
//  Camera.cpp
//  Assignment7
//
//  Created by Charles Circlaeys on 30/04/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#if defined(_WIN32)
    #include "glut.h"
    #include <windows.h>
#else
    #include <GLUT/glut.h>
#endif

#include "Camera.h"

Camera::Camera(int viewportWidth, int viewportHeight)
: _viewportWidth(viewportWidth), _viewportHeight(viewportHeight)
{
    glViewport(0, 0, _viewportWidth, _viewportWidth);
}

Camera::~Camera()
{
    
}

void Camera::update()
{
    // Set up the properties of the viewing camera.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(60.0, ASPECT_RATIO, 0.2, 100.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT| GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Camera::resize(int w, int h)
{    
	if (ASPECT_RATIO > w / h)
	{
		_viewportWidth = w;
		_viewportHeight = w / ASPECT_RATIO;
	}
	else
	{
		_viewportHeight = h;
		_viewportWidth = h * ASPECT_RATIO;
	}
    
	glViewport(0.5 * (w - _viewportWidth), 0.5 * (h - _viewportHeight), _viewportWidth, _viewportHeight);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}