#include <cstdlib>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
   //initialize GLFW
	if (glfwInit() == GL_FALSE)
	{
		std::cerr << "Can't initialize GLFW" << std::endl;
		return 1;
	}

	//terminate GLFW at the end of program
	atexit(glfwTerminate);


	//set version 2.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	

	//create window
	GLFWwindow *const window = glfwCreateWindow(640, 480, "practice", NULL, NULL);
	if (!window)
	{
		std::cerr << "Can't create GLFW window." << std::endl;
		return 1;
	}

	//set window to be the current context
	glfwMakeContextCurrent(window);


	//set the background color
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);


	//frame loop
	while (glfwWindowShouldClose(window) == GL_FALSE)
	{
	    //clear the window
		glClear(GL_COLOR_BUFFER_BIT);

		//drawing
		glColor3d(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, 0.5);
		glEnd();


		//swap the color buffers
		glfwSwapBuffers(window);

		//check if any events have been activated
		glfwWaitEvents();

	}

	//terminate GLFW
	glfwTerminate();

	return 0;
}