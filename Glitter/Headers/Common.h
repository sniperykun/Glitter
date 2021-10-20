
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

extern int g_LoadTexture(char const *path);

#endif // !COMMON_H