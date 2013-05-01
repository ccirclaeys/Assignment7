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
#include <vector>

#include "Model.h"

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
    std::vector<Model*> _modelArray;
    GLfloat _sdepth;
    GLfloat _sphi;
    GLfloat _stheta;
    
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
    
    GLfloat getSphi() { return _sphi; }
    void setSphi(GLfloat sphi) { _sphi = sphi; }
    GLfloat getStheta() { return _stheta; }
    void setStheta(GLfloat stheta) { _stheta = stheta; }

};

#endif /* defined(__Assignment7__Scene__) */
