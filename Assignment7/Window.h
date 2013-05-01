//
//  Window.h
//  Assignment7
//
//  Created by Charles Circlaeys on 30/04/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#ifndef __Assignment7__Window__
#define __Assignment7__Window__

#include <iostream>

#include "Camera.h"
#include "Scene.h"

class Window
{
    
public:
    Window(float posX = 0, float posY = 0, float width = 500, float height = 500, const char *title = "No title");
    ~Window();
    bool setup(int *ac, char **av);
    void run(void);
    
    //callback
    static void reshape(int width, int height);
    static void display(void);
    static void keyboardPress(unsigned char pressedKey, int mouseXPosition, int mouseYPosition);
    static void nonASCIIKeyboardPress(int pressedKey, int mouseXPosition, int mouseYPosition);
    static void timerFunction(int value);
    static void mouseCallback(int button, int state, int x, int y);
    static void motionCallback(int x, int y);
    
private:
    static Window *_currentInstance;
    
    float _posX;
    float _posY;
    float _width;
    float _height;
    const char *_title;
    bool _animationOn;
    int _downX;
    int _downY;
    bool _leftButton;
    
    Camera *_camera;
    Scene *_scene;
    
    // private funcs
    void initOpenGL(void);
};

#endif /* defined(__Assignment7__Window__) */
