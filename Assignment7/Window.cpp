//
//  Window.cpp
//  Assignment7
//
//  Created by Charles Circlaeys on 30/04/13.
//  Copyright (c) 2013 Charles Circlaeys. All rights reserved.
//

#if defined(_WIN32)
    #include "glut.h"
    #include <windows.h>
#else
    #include <GLUT/glut.h>
#endif

#include "Window.h"

#define kMillisec 20

Window *Window::_currentInstance = 0;

Window::Window(float posX, float posY, float width, float height, const char *title)
: _posX(posX), _posY(posY), _width(width), _height(height), _title(title), _animationOn(true)
{
}

Window::~Window()
{
    if (_camera)
    {
        delete _camera;
        _camera = 0;
    }
    
    if (_scene)
    {
        delete _scene;
        _scene = 0;
    }
}

bool Window::setup(int *ac, char **av)
{
    _currentInstance = this;
    
    glutInit (ac, av);

	// Set up the display window.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL | GLUT_DEPTH);
    glutInitWindowPosition(_posX, _posY);
	glutInitWindowSize(_width, _height);
    glutCreateWindow(_title);
    
    // Specify the resizing and refreshing routines.
	glutReshapeFunc(Window::reshape);
    glutDisplayFunc(Window::display);
	glutKeyboardFunc(Window::keyboardPress);
    glutSpecialFunc(Window::nonASCIIKeyboardPress);
	glutTimerFunc(kMillisec, Window::timerFunction, 1);
    glutMouseFunc(Window::mouseCallback);
    glutMotionFunc(Window::motionCallback);
    
    _camera = new Camera(_width, _height);
    _scene = new Scene();
    
    return true;
}

void Window::mouseCallback(int button, int state, int x, int y)
{
    _currentInstance->_downX = x;
    _currentInstance->_downY = y;
    _currentInstance->_leftButton = ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN));
    glutPostRedisplay();
}

void Window::motionCallback(int x, int y)
{
    if (_currentInstance->_leftButton)
    {
        GLfloat newSphi = _currentInstance->_scene->getSphi() + (float)(x - _currentInstance->_downX) / 4.0;
        GLfloat newStheta = _currentInstance->_scene->getStheta() + (float)(_currentInstance->_downY - y) / 4.0;
        
        _currentInstance->_scene->setSphi(newSphi);
        _currentInstance->_scene->setStheta(newStheta);
    } // rotate
    
    _currentInstance->_downX = x;
    _currentInstance->_downY = y;
    
    glutPostRedisplay();
}

void Window::run(void)
{
    glutMainLoop();
}

void Window::reshape(int width, int height)
{
    _currentInstance->_width = width;
    _currentInstance->_height = height;
    
    _currentInstance->_camera->resize(width, height);
}

void Window::display(void)
{
    _currentInstance->_camera->update();
    _currentInstance->_scene->draw();
}

void Window::nonASCIIKeyboardPress(int pressedKey, int mouseXPosition, int mouseYPosition)
{
	glutIgnoreKeyRepeat(false);
    
    switch(pressedKey)
	{
		case GLUT_KEY_UP:
        {
            _currentInstance->_scene->accelerateRotation();
            break;
        }
		case GLUT_KEY_DOWN:
        {
            _currentInstance->_scene->decelerateRotation();
            break;
        }
            
        default:
            break;
    }
}

void Window::keyboardPress(unsigned char pressedKey, int mouseXPosition, int mouseYPosition)
{
    switch(pressedKey)
	{
        case 27: // ESCAPE
            exit(1);
            
        case 'r':
            _currentInstance->_animationOn = !_currentInstance->_animationOn;
            break;
            
        case 's':
            break;
            
        case 'x':
        {
            _currentInstance->_camera->move(XPOS);
            break;
        }
            
        case 'X':
        {
            _currentInstance->_camera->move(XNEG);
            break;
        }
            
        case 'y':
        {
            _currentInstance->_camera->move(YPOS);
            break;
        }
            
        case 'Y':
        {
            _currentInstance->_camera->move(YNEG);
            break;
        }
            
        case 'z':
        {
            _currentInstance->_camera->move(ZPOS);
            break;
        }
		
        case 'Z':
        {
            _currentInstance->_camera->move(ZNEG);
            break; 
        }
        
        default:
            break;
    }
}

void Window::timerFunction(int value)
{
    if (_currentInstance->_animationOn)
    {
        _currentInstance->_scene->update();
    }
    
	glutPostRedisplay();
	glutTimerFunc(kMillisec, Window::timerFunction, 1);
}