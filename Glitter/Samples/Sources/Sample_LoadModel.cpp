﻿#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Sample_LoadModel.h"
#include "Common.h"
#include "BaseSample.hpp"
#include "SimpleCamera.hpp"

bool Sample_LoadModel::setup(int argc, char * argv[])
{
	std::string modelpath = path_res_model;
	modelpath = modelpath + +"helmet/helmet.obj";

	m_Model = new SimpleModel(modelpath);

	std::string texturepath = path_res_textures;
	std::string path = path_res_shader;

	std::string diffuse = path_res_model + "helmet/helmet_basecolor.tga";
	unsigned int diffuseId = g_LoadTexture(diffuse.c_str());
	Texture diffuseTexture;
	diffuseTexture.id = diffuseId;
	diffuseTexture.path = diffuse;
	diffuseTexture.type = "texture_diffuse";

	std::string normal = path_res_model + "helmet/helmet_normal.tga";
	unsigned int normalid = g_LoadTexture(normal.c_str());
	Texture normalTexture;
	normalTexture.id = normalid;
	normalTexture.path = normal;
	normalTexture.type = "texture_normal";

	std::string specular = path_res_model + "helmet/helmet_metalness.tga";
	unsigned int specularid = g_LoadTexture(specular.c_str());
	Texture specularTexture;
	specularTexture.id = specularid;
	specularTexture.path = specular;
	specularTexture.type = "texture_specular";

	std::vector<Texture> loadedTexture{ diffuseTexture, normalTexture };
	m_Model->SetUpTextures(loadedTexture);

	// init shaders
	std::string vspath = path + "sample_load_model_light.vert";
	std::string fspath = path + "sample_load_model_light.frag";
	m_RenderShader = new Shader(vspath.c_str(), fspath.c_str());
	return true;
}

void Sample_LoadModel::render(SimpleCamera& camera, float time)
{
	if (m_Model != NULL && m_RenderShader != NULL)
	{
		m_RenderShader->use();

		// view/projection transformations
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)mWidth / (float)mHeight, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		m_RenderShader->setMat4("projection", projection);
		m_RenderShader->setMat4("view", view);

		// render the loaded model
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
		model = glm::rotate(model, (float)glfwGetTime() * 1.2f, glm::vec3(0.0f, 1.0f, 0.0f));
		m_RenderShader->setMat4("model", model);

		// set light input params
		m_RenderShader->setVec3("viewPos", camera.Position);

		// directional light
		m_RenderShader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
		// m_RenderShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
		m_RenderShader->setVec3("dirLight.ambient", 0.5f, 0.5f, 0.5f);
		m_RenderShader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
		// m_RenderShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
		m_RenderShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
		m_RenderShader->setFloat("shininess", 32.0f);

		m_Model->Draw((*m_RenderShader));
	}
}

bool Sample_LoadModel::shutdown()
{
	if (m_Model)
		delete m_Model;
	if (m_RenderShader)
		delete m_RenderShader;
	return true;
}