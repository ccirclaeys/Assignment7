//
//  Scene.h
//  Assignment7
//
//  Created by Charles Circlaeys on 30/04/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__Scene__
#define __Assignment7__Scene__

#include <GLUT/GLUT.h>
#include <iostream>
#include <math.h>
#include <vector>

#include "Model.h"

const GLfloat INITIAL_VIEWER_DISTANCE    = 10;
const GLfloat INITIAL_VIEWER_AZIMUTH     = 0.0;
const GLfloat INITIAL_VIEWER_ZENITH      = M_PI / 2.0;
const GLfloat LOOK_AT_POSITION[] = { 0.0, 0.0, 0.0 };

// Lighting Constants
const GLfloat LIGHT_0_POSITION[]    = { 1.0, 0.0, 0.0, 0.0};
const GLfloat LIGHT_1_POSITION[]    = { -1.0, 0.0, 0.0, 0.0};
const GLfloat LIGHT_2_POSITION[]    = { 0.0, 0.0, 1.0, 0.0};
const GLfloat LIGHT_3_POSITION[]    = { 0.0, 0.0, -1.0, 0.0};
const GLfloat LIGHT_AMBIENT[]       = { 0.8, 0.8, 0.8, 1.0};
const GLfloat LIGHT_DIFFUSE[]       = { 0.9, 0.9, 0.9, 1.0};
const GLfloat LIGHT_SPECULAR[]      = { 1.0, 1.0, 1.0, 1.0};
const GLfloat LIGHT_MODEL_AMBIENT[] = { 0.2, 0.2, 0.2, 1.0};

class Scene
{
    
private:
    GLfloat _viewerDistance;
    GLfloat _viewerAzimuth;
    GLfloat _viewerZenith;
    
    std::vector<Model*> _modelArray;
    
    void init(void);
    
public:
    Scene();
    ~Scene();
    void draw(void);
    void setLights(void);
    void updateLight(void);
    void update(void);
    
    void accelerateRotation();
    void decelerateRotation();
};

#endif /* defined(__Assignment7__Scene__) */
