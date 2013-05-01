//
//  Model.h
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__Model__
#define __Assignment7__Model__

#include <GLUT/GLUT.h>
#include <iostream>

const char filePath[] = "/Users/furyfeuille/Dev/Assignment7/Assignment7/";

class Model
{
protected:
    unsigned int _textureName;
    
public:
    Model(unsigned int textureName);
    virtual ~Model() {}
    virtual void draw() {};
    virtual void update() {};
    virtual void accelerateRotation() {}
    virtual void decelerateRotation() {}
    
    void MakeImage(const char bitmapFilename[], GLuint &textureName, bool hasAlpha);
};

#endif /* defined(__Assignment7__Model__) */
