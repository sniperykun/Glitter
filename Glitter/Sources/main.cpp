// Local Headers
#include "glitter.hpp"
#include "RenderEnginePassion.hpp"
#include "Shader.h"
#include "SimpleCamera.hpp"
#include "SampleDefine.hpp"

// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <stb_image.h>

#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

// Camera
SimpleCamera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = mWidth / 2.0f;
float lastY = mHeight / 2.0f;
bool firstMouse = true;
// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main(int argc, char * argv[]) {

	// Load GLFW and Create a Window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	auto mWindow = glfwCreateWindow(mWidth, mHeight, "OpenGL", nullptr, nullptr);
	RenderEnginePassion::SayPassion();

	// Check for Valid Context
	if (mWindow == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return EXIT_FAILURE;
	}

	// Create Context and Load OpenGL Functions
	glfwMakeContextCurrent(mWindow);
	// Set GLFW Windows Callback
	glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);
	glfwSetCursorPosCallback(mWindow, mouse_callback);
	glfwSetScrollCallback(mWindow, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "OpenGL :" << glGetString(GL_VERSION) << std::endl;

	for (int i = 0; i < argc; i++)
	{
		std::cout << "args:" << argv[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Current Work Path:" << fs::current_path() << std::endl;
	std::string path = GlitterConfig::path_res_shader;
	std::cout << "Resources path:" << path << std::endl;

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	BaseSample *sample = NULL;
	sample = new Sample_CubeRender();
	sample->setup(argc, argv);

	// Rendering Loop
	while (glfwWindowShouldClose(mWindow) == false) {

		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		processInput(mWindow);

		// Background Fill Color
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ------------------------------------
		sample->render(camera, deltaTime);
		// ------------------------------------

		// Flip Buffers and Draw
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	// sample shutdown
	sample->shutdown();

	glfwTerminate();
	std::cout << "Exit GLFW Window " << std::endl;
	return EXIT_SUCCESS;
}

//
// From LearnOpenGL.com
//
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		camera.ProcessKeyboard(GLFW_KEY_LEFT_SHIFT, 1);
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
		camera.ProcessKeyboard(GLFW_KEY_LEFT_SHIFT, 0);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboardMovement(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboardMovement(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboardMovement(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboardMovement(RIGHT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		camera.ProcessKeyboardMovement(UP, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboardMovement(DOWN, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}
