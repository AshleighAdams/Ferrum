#include "Base.h"
#include "Geometry/Octant.h"
#include "Camera/Camera.h"

#include <iostream>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()
{
	IrrlichtDevice* device = createDevice(video::EDT_OPENGL,  dimension2d<u32>(640, 480), 32, false, false, true, 0);
	
	if(!device)
	{
		printf("Failed to create 32 bit device.  Trying 16 bit\n");
		device = createDevice(video::EDT_OPENGL,  dimension2d<u32>(640, 480), 16, false, false, true, 0);
		
		if(!device)
		{
			printf("Failed to create 16 bit device.  Exiting\n");
			return 1;
		}
	}
	
	printf("Created device\n");
	
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	
	smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
	
	IAnimatedMesh* mesh = smgr->getMesh( "models/player.obj" );
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );
	
	if(!mesh)
	{
		printf("Failed to load mesh!\n");
		return 1;
	}
	
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	
	scene::ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS(0,  100.0f, 0.01f);
	camera->setPosition(Vector(10.0,  10.0, 0.0));
	camera->setTarget(Vector(0.0, 0.0, 0.0));
	camera->setFOV(1.f);
	camera->setNearValue(0.01f);
	
	device->getCursorControl()->setVisible(false);
	
	while(device->run())
	{
		driver->beginScene(true, true, SColor(0,0,0,0));
		
		smgr->drawAll();
		guienv->drawAll();
		
		driver->endScene();
	}
	
	device->drop(); // Refrence counted.
	
	return 0;
}
