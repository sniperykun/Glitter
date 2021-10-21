
#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <vector>
// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "SimpleCamera.hpp"

extern const int mWidth;
extern const int mHeight;

extern const std::string path_res_shader;
extern const std::string path_res_model;
extern const std::string path_res_textures;

extern unsigned int g_LoadTexture(char const *path);

enum Render_Texture_Type
{
	Render_Texture_DIFFUSE,
	Render_Texture_NORMALS,
	Render_Texture_SPECULAR
};

#endif // !COMMON_H