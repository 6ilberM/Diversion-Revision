#include <glew.h>
#include <GLFW/glfw3.h>

//Physics Engine
#include "Dependencies/Includes/Box2D/Box2D.h"

//Other
#include<iostream>

//Strange new Vld
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//#include <vld.h>

using namespace std;

//DeltaTime: States the difference in time since previous and current frame
double deltaTime;

double cur_Time;
double fin_Time;

//Globals
GLFWwindow* Main_Window;
//Shader
//CShaderLoader* ShaderLoader;

//GLuint Default_Shader;
//GLuint	Light_Shader;


//Objs
//CCube *Cubo;
//CCamera* Camara;
//btDiscreteDynamicsWorld* m_world;
//btRigidBody* test;


void DestroyerofWorlds()
{
	glfwTerminate();

	//delete Cubo;
	//delete Camara;
}

//In case of Exit
void KeyboardInput(GLFWwindow* _window, int _key, int _scancode, int _action, int mods)
{
	if (_key == GLFW_KEY_ESCAPE && _action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(_window, true);
	}

}

void WindowResizeCall(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}

int Init()
{
	if (!glfwInit())
	{
		//init failed
		return -1;
	}

	Main_Window = glfwCreateWindow(1280, 720, "Season Of Mists", NULL, NULL);

	if (!Main_Window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(Main_Window);

	GLenum GlewChk = glewInit();
	if (GLEW_OK != GlewChk)
	{
		return -1;
		glfwTerminate();
	}

	glEnable(GL_DEPTH_TEST);

	//Why tho?
	glLineWidth(2.0f);

	glfwSetKeyCallback(Main_Window, KeyboardInput);
	glfwSetFramebufferSizeCallback(Main_Window, WindowResizeCall);
	return 0;
}

int OnBeginPlay()
{
	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);
	//std::cout << "COMPILING SHADERS..." << std::endl;
	//Default_Shader = shaderloader.loadShaders("Assets/Shaders/default.vs", "Assets/Shaders/default.fs");
	//Light_Shader = shaderloader.loadShaders("Assets/Shaders/lit.vs", "Assets/Shaders/lit.fs");

	// Construct a world object, which will hold and simulate the rigid bodies.
	if (true)
	{
		return -1;
	}
	return 1;
}

//RenderLoop
void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

}

//Logic For what is happening in scene
void Update()
{
	fin_Time = cur_Time;
	cur_Time = glfwGetTime();
	deltaTime = cur_Time - fin_Time;

}

int main()
{
	Init();
	OnBeginPlay();
	while (!glfwWindowShouldClose(Main_Window))
	{
		Update();
		Render();
		glfwSwapBuffers(Main_Window);
		glfwPollEvents();
	}

	//you need this to avoid memory leaks 6 of them to be precise
	DestroyerofWorlds();

	_CrtDumpMemoryLeaks();
	return 0;
}