#include <glew.h>
#include <GLFW/glfw3.h>
#include<iostream>

#include <vld.h>

using namespace std;

//DeltaTime: States the difference in time since previous and current frame
double d_Time;

double cur_Time;
double fin_Time;

//Globals
GLFWwindow* Main_Window;
//Shader
//CShaderLoader* ShaderLoader;

GLuint Default_Shader;
GLuint	Light_Shader;


//Objs
//CCube *Cubo;
//CCamera* Camara;
//btDiscreteDynamicsWorld* m_world;
//btRigidBody* test;

bool Lightshaded = false;

//DebugBug Enabler. //Make this fancier later... Might want to look into making a virtual console
bool debugMode = false;


void DestroyerofWorlds()
{
	glfwTerminate();

	//delete Cubo;
	//delete Camara;
}
//In case of Exit
void KeyboardInput(GLFWwindow *_window, int _key, int _scancode, int _action, int mods)
{
	if (_key == GLFW_KEY_ESCAPE && _action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(_window, true);
	}

	if (_key == GLFW_KEY_0 && _action == GLFW_PRESS)
	{
		Lightshaded = !Lightshaded;
	}


	if (_key == GLFW_KEY_F1 && _action == GLFW_PRESS)
	{
		debugMode = !debugMode;
	}

}

void WindowResizeCall(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}

int init()
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

}

int OnBeginPlay()
{
	//std::cout << "COMPILING SHADERS..." << std::endl;
	//Default_Shader = shaderloader.loadShaders("Assets/Shaders/default.vs", "Assets/Shaders/default.fs");
	//Light_Shader = shaderloader.loadShaders("Assets/Shaders/lit.vs", "Assets/Shaders/lit.fs");

	return 1;
}

//RenderLoop
void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	//if (false == Lightshaded)
	//{
	//	Cubo->Render(Light_Shader, *Camara);

	//}
	//else
	//{
	//	Cubo->Render(Default_Shader, *Camara);
	//}

}

bool b_doOnce = false;

//Logic For what is happening in scene
void Update()
{
	fin_Time = cur_Time;
	cur_Time = glfwGetTime();
	d_Time = cur_Time - fin_Time;

	if (debugMode)
	{
		if (b_doOnce == false)
		{
			//Camara->Observe(glm::vec3(0, 0, -2.0f));
			b_doOnce = true;
		}
		//Cubo->update(d_Time);
	}

}


int main()
{
	init();
	OnBeginPlay();
	while (!glfwWindowShouldClose(Main_Window))
	{
		//Update();
		//Render();
		glfwSwapBuffers(Main_Window);
		glfwPollEvents();
	}
	//you need this to avoid memory leaks 6 of them to be precise
	DestroyerofWorlds();
	return 0;
}
