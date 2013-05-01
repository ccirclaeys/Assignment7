//
//  Sun.h
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__Sun__
#define __Assignment7__Sun__

#include <iostream>
#include "Model.h"

const float SUN_RADIUS = 1.0;

class Sun : public Model
{

public:
    Sun();
    ~Sun();
    virtual void draw();
};

#endif /* defined(__Assignment7__Sun__) */
