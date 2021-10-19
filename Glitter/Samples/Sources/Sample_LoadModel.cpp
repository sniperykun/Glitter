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
	modelpath = modelpath + +"backpack/backpack.obj";

	m_Model = new SimpleModel(modelpath);
	// init shader
	std::string path = path_res_shader;
	std::string vspath = path + "sample_load_model.vert";
	std::string fspath = path + "sample_load_model.frag";
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
		m_RenderShader->setMat4("model", model);

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