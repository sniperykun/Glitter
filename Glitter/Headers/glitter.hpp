// Preprocessor Directives
#pragma once
#ifndef GLITTER
#define GLITTER

// System Headers
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
// Not Include bullet physic Engine
// #include <btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
//     #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Common.h"
#include "SimpleCamera.hpp"

//
// https://github.com/gulrak/filesystem
// https://en.cppreference.com/w/cpp/filesystem
// make interface for C++17 filesystem
//

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || (defined(__cplusplus) && __cplusplus >= 201703L)) && defined(__has_include)
#if __has_include(<filesystem>) && (!defined(__MAC_OS_X_VERSION_MIN_REQUIRED) || __MAC_OS_X_VERSION_MIN_REQUIRED >= 101500)
#define GHC_USE_STD_FS
#include <filesystem>
namespace fs = std::filesystem;
#endif
#endif
#ifndef GHC_USE_STD_FS
#include <filesystem.hpp>
namespace fs = ghc::filesystem;
#endif


#endif //~ Glitter Header
