//
//  Camera.h
//  Assignment7
//
//  Created by Charles Circlaeys on 30/04/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__Camera__
#define __Assignment7__Camera__

#include <GLUT/GLUT.h>

#include <iostream>
#include <math.h>

#define ASPECT_RATIO 1.5f

const GLfloat INITIAL_VIEWER_DISTANCE    = 10;
const GLfloat INITIAL_VIEWER_AZIMUTH     = 0.0;
const GLfloat INITIAL_VIEWER_ZENITH      = M_PI / 2.0;
const GLfloat LOOK_AT_POSITION[] = { 0.0, 0.0, 0.0 };

class Camera
{
public:
    Camera(int viewportWidth, int viewportHeight);
    ~Camera();
    void update(void);
    void resize(int w, int h);
    
private:
    int _viewportWidth;
    int _viewportHeight;
    GLfloat _viewerDistance;
    GLfloat _viewerAzimuth;
    GLfloat _viewerZenith;

};

#endif /* defined(__Assignment7__Camera__) */
