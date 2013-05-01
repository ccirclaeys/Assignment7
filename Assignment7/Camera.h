//
//  Camera.h
//  Assignment7
//
//  Created by Charles Circlaeys on 30/04/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__Camera__
#define __Assignment7__Camera__

#include <iostream>

#define ASPECT_RATIO 1.5f

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

};

#endif /* defined(__Assignment7__Camera__) */
