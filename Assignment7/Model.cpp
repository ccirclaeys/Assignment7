//
//  Model.cpp
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#include "Model.h"
#include "RGBpixmap.h"

Model::Model(unsigned int textureName)
: _textureName(textureName)
{
    
}

// Convert the bitmap with the parameterized name into an OpenGL texture. //
void Model::MakeImage(const char bitmapFilename[], GLuint &textureName, bool hasAlpha)
{
    char *filename = NULL;
    if (filePath)
    {
        filename = (char*)malloc(strlen(bitmapFilename) + strlen(filePath) + 1);
        strcpy(filename, filePath);
        filename = strcat(filename, bitmapFilename);
    }
    
	RGBpixmap pix;
	pix.readBMPFile(filename, hasAlpha);
	pix.setTexture(textureName);
    
    if (filePath)
    {
        free(filename);
    }
    
	return;
}