//
//  Scene.cpp
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

#include "Scene.h"
#include "Sun.h"
#include "EarthMoon.h"

Scene::Scene()
: _sphi(90), _stheta(45), _sdepth(1)
{
    this->init();
}

Scene::~Scene()
{
    std::vector<Model*>::iterator itr;
	for (itr = _modelArray.begin(); itr < _modelArray.end(); ++itr)
	{
        delete *itr;
        *itr = 0;
    }
}

void Scene::init(void)
{
    // Set up standard lighting, shading, and depth testing.
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_NORMALIZE);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
	this->setLights();
    
    Model *sun = new Sun();
    _modelArray.push_back(sun);
    
    Model *earthMoon = new EarthMoon();
    _modelArray.push_back(earthMoon);
}

// Set the two lights to illuminate the scene. //
void Scene::setLights(void)
{
	glLightfv(GL_LIGHT0, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_0_POSITION);
    
	glLightfv(GL_LIGHT1, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT1, GL_POSITION, LIGHT_1_POSITION);
	
	glLightfv(GL_LIGHT2, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT2, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT2, GL_POSITION, LIGHT_2_POSITION);
    
	glLightfv(GL_LIGHT3, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT3, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT3, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT3, GL_POSITION, LIGHT_3_POSITION);
}

// Enable the scene's lighting. //
void Scene::updateLight(void)
{
	glPushMatrix();
    glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_0_POSITION);
    glLightfv(GL_LIGHT1, GL_POSITION, LIGHT_1_POSITION);
    glLightfv(GL_LIGHT2, GL_POSITION, LIGHT_2_POSITION);
    glLightfv(GL_LIGHT3, GL_POSITION, LIGHT_3_POSITION);
	glPopMatrix();
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void Scene::draw(void)
{
    // Initialize lighting.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LIGHT_MODEL_AMBIENT);
	glEnable(GL_LIGHTING);
    
	// Render scene.
	this->updateLight();
    
    glTranslatef(0.0,0.0, -_sdepth);
    glRotatef(-_stheta, 1.0, 0.0, 0.0);
    glRotatef(_sphi, 0.0, 0.0, 1.0);

    std::vector<Model*>::iterator itr;
	for (itr = _modelArray.begin(); itr < _modelArray.end(); ++itr)
	{
        (*itr)->draw();
    }
    
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
	glDisable(GL_LIGHTING);
    
	glutSwapBuffers();
	glFlush();
}

void Scene::update(void)
{
    std::vector<Model*>::iterator itr;
	for (itr = _modelArray.begin(); itr < _modelArray.end(); ++itr)
	{
        (*itr)->update();
    }
}

void Scene::accelerateRotation()
{
    std::vector<Model*>::iterator itr;
	for (itr = _modelArray.begin(); itr < _modelArray.end(); ++itr)
	{
        (*itr)->accelerateRotation();
    }
}

void Scene::decelerateRotation()
{
    std::vector<Model*>::iterator itr;
	for (itr = _modelArray.begin(); itr < _modelArray.end(); ++itr)
	{
        (*itr)->decelerateRotation();
    }
}
