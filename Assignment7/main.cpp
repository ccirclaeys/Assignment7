//
//  main.c
//  Assignment7
//
//  Created by Charles Circlaeys on 01/05/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#include <stdio.h>

#include "Window.h"

int main(int ac, char **av)
{
    GLint currWindowSize[2]   = { 750, (int)(750/ASPECT_RATIO) };
    
    Window window(50, 50, currWindowSize[0], currWindowSize[1], "Assignment 7");
    window.setup(&ac, av);
    window.run();
    return 0;
}
