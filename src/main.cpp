#include "Base.h"
#include "Geometry/Octant.h"
#include "Camera/Camera.h"

#include <iostream>

// http://www.opengl.org/wiki/MinGW do this

unsigned int _Identifier;
unsigned int _Identifier2;
void LoadTestObject()
{
	Vertex pvertex[3];
	//VERTEX 0
	pvertex[0].x = 0.0;
	pvertex[0].y = 0.0;
	pvertex[0].z = 0.0;
	pvertex[0].nx = 0.0;
	pvertex[0].ny = 0.0;
	pvertex[0].nz = 1.0;
	pvertex[0].s0 = 0.0;
	pvertex[0].t0 = 0.0;
	//VERTEX 1
	pvertex[1].x = 1.0;
	pvertex[1].y = 0.0;
	pvertex[1].z = 0.0;
	pvertex[1].nx = 0.0;
	pvertex[1].ny = 0.0;
	pvertex[1].nz = 1.0;
	pvertex[1].s0 = 1.0;
	pvertex[1].t0 = 0.0;
	//VERTEX 2
	pvertex[2].x = 0.0;
	pvertex[2].y = 1.0;
	pvertex[2].z = 0.0;
	pvertex[2].nx = 0.0;
	pvertex[2].ny = 0.0;
	pvertex[2].nz = 1.0;
	pvertex[2].s0 = 0.0;
	pvertex[2].t0 = 1.0;
	
	glGenBuffers(1, &_Identifier2);
	glBindBuffer(GL_ARRAY_BUFFER, _Identifier2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*3, &pvertex[0].x, GL_STATIC_DRAW);
	
	unsigned short pindices[3];
	pindices[0] = 0;
	pindices[1] = 1;
	pindices[2] = 2;
	
	glGenBuffers(1, &_Identifier);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _Identifier);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short)*3, pindices, GL_STATIC_DRAW);

	//Define this somewhere in your header file
	#define BUFFER_OFFSET(i) ((char *)NULL + (i))
	
	glBindBuffer(GL_ARRAY_BUFFER, _Identifier2);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));   //The starting point of the VBO, for the vertices
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));   //The starting point of normals, 12 bytes away
	glClientActiveTexture(GL_TEXTURE0);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(24));   //The starting point of texcoords, 24 bytes away

	#undef BUFFER_OFFSET
}

void DrawTestObject()
{
	#define BUFFER_OFFSET(i) ((char *)NULL + (i))
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _Identifier);
	//To render, we can either use glDrawElements or glDrawRangeElements
	//The is the number of indices. 3 indices needed to make a single triangle
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));   //The starting point of the IBO
	//0 and 3 are the first and last vertices
	//glDrawRangeElements(GL_TRIANGLES, 0, 3, 3, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));   //The starting point of the IBO
	//glDrawRangeElements may or may not give a performance advantage over glDrawElements
	#undef BUFFER_OFFSET
}

void FreeTestObject()
{
	glDeleteBuffers(1, &_Identifier);
	glDeleteBuffers(1, &_Identifier2);
}

int main()
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ferrum");
	glewInit();
	
	glEnable(GL_DEPTH_TEST);
	
	Camera* cam = new Camera();
	
	
	LoadTestObject();
	
	while (App.IsOpened())
	{
		sf::Event Event;
		while (App.GetEvent(Event))
			if (Event.Type == sf::Event::Closed || (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape))
			{
				App.Close();
				break;
			}
		
		App.Clear();
		
		cam->Position.x = 10.0;
		//cam->Position.y = 10.0;
		cam->UpdateMatrix();
		DrawTestObject();
		
		App.Display();
	}
	
	FreeTestObject();
	delete cam;
	
	return 0;
}
