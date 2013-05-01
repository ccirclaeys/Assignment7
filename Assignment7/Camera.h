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

typedef enum {
    ZPOS,
    ZNEG,
    XPOS,
    XNEG,
    YPOS,
    YNEG
} CameraMoveType;

// Viewer Positioning Constants
const GLfloat MAXIMUM_VIEWER_DISTANCE    = 20;
const GLfloat MINIMUM_VIEWER_DISTANCE    = 2;
const GLfloat INITIAL_VIEWER_DISTANCE    = 10;
const GLfloat VIEWER_DISTANCE_INCREMENT  = 0.1;
const GLfloat INITIAL_VIEWER_AZIMUTH     = 0.0;
const GLfloat INITIAL_VIEWER_ZENITH      = M_PI / 2.0;
const GLfloat VIEWER_ANGLE_INCREMENT     = M_PI / 60.0;
const GLfloat LOOK_AT_POSITION[] = { 0.0, 0.0, 0.0 };

class Camera
{
public:
    Camera(int viewportWidth, int viewportHeight);
    ~Camera();
    void update(void);
    void resize(int w, int h);
    void move(CameraMoveType move);
    
private:
    int _viewportWidth;
    int _viewportHeight;
    GLfloat _viewerDistance;
    GLfloat _viewerAzimuth;
    GLfloat _viewerZenith;
};

#endif /* defined(__Assignment7__Camera__) */
