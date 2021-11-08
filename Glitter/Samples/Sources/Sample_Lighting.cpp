#include "Sample_Lighting.h"
#include "Common.h"


bool Sample_Lighting::setup(int argc, char * argv[])
{
	float vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};

	pointLightPositions = {
		 glm::vec3(0.7f,  0.2f,  2.0f),
		 glm::vec3(2.3f, -3.3f, -4.0f),
		 glm::vec3(-4.0f,  2.0f, -12.0f),
		 glm::vec3(0.0f,  0.0f, -3.0f)
	};

	cubePositions = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(cubeVAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glGenVertexArrays(1, &lightCubeVAO);
	glBindVertexArray(lightCubeVAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// note that we update the lamp's position attribute's stride to reflect the updated buffer data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// init shader
	std::string path = path_res_shader;
	std::string vspath = path + "light_cube.vert";
	std::string fspath = path + "light_cube.frag";
	m_LightCubeShader = new Shader(vspath.c_str(), fspath.c_str());

	vspath = path + "lighting_sample.vert";
	fspath = path + "lighting_sample.frag";
	m_CubeShader = new Shader(vspath.c_str(), fspath.c_str());

	std::string texture1path = path_res_textures + "container2.png";
	std::string texture2path = path_res_textures + "container2_specular.png";

	stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

	diffuseMap = g_LoadTexture(texture1path.c_str());
	specularMap = g_LoadTexture(texture2path.c_str());

	m_CubeShader->use();
	// set texture uniform position
	// 0 -> GL_TEXTURE0
	// 1 -> GL_TEXTURE1
	m_CubeShader->setInt("material.diffuse", 0);
	m_CubeShader->setInt("material.specular", 1);
	return true;
}

void Sample_Lighting::render(SimpleCamera& camera, float time)
{
	m_CubeShader->use();
	m_CubeShader->setVec3("viewPos", camera.Position);
	m_CubeShader->setFloat("material.shininess", 32.0f);
	/*
		Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
		the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
		by defining light types as classes and set their values in there, or by using a more efficient uniform approach
		by using 'Uniform buffer objects', but that is something we'll discuss in the 'Advanced GLSL' tutorial.
	*/
	// directional light
	m_CubeShader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
	m_CubeShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	m_CubeShader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
	m_CubeShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
	// point light 1
	m_CubeShader->setVec3("pointLights[0].position", pointLightPositions[0]);
	m_CubeShader->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
	m_CubeShader->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
	m_CubeShader->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
	m_CubeShader->setFloat("pointLights[0].constant", 1.0f);
	m_CubeShader->setFloat("pointLights[0].linear", 0.09);
	m_CubeShader->setFloat("pointLights[0].quadratic", 0.032);
	// point light 2
	m_CubeShader->setVec3("pointLights[1].position", pointLightPositions[1]);
	m_CubeShader->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
	m_CubeShader->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
	m_CubeShader->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
	m_CubeShader->setFloat("pointLights[1].constant", 1.0f);
	m_CubeShader->setFloat("pointLights[1].linear", 0.09);
	m_CubeShader->setFloat("pointLights[1].quadratic", 0.032);
	// point light 3
	m_CubeShader->setVec3("pointLights[2].position", pointLightPositions[2]);
	m_CubeShader->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
	m_CubeShader->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
	m_CubeShader->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
	m_CubeShader->setFloat("pointLights[2].constant", 1.0f);
	m_CubeShader->setFloat("pointLights[2].linear", 0.09);
	m_CubeShader->setFloat("pointLights[2].quadratic", 0.032);
	// point light 4
	m_CubeShader->setVec3("pointLights[3].position", pointLightPositions[3]);
	m_CubeShader->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
	m_CubeShader->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
	m_CubeShader->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
	m_CubeShader->setFloat("pointLights[3].constant", 1.0f);
	m_CubeShader->setFloat("pointLights[3].linear", 0.09);
	m_CubeShader->setFloat("pointLights[3].quadratic", 0.032);
	// spotLight
	m_CubeShader->setVec3("spotLight.position", camera.Position);
	m_CubeShader->setVec3("spotLight.direction", camera.Front);
	m_CubeShader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
	m_CubeShader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
	m_CubeShader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
	m_CubeShader->setFloat("spotLight.constant", 1.0f);
	m_CubeShader->setFloat("spotLight.linear", 0.09);
	m_CubeShader->setFloat("spotLight.quadratic", 0.032);
	m_CubeShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	m_CubeShader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

	// view/projection transformations
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)mWidth / (float)mHeight, 0.1f, 100.0f);
	glm::mat4 view = camera.GetViewMatrix();
	m_CubeShader->setMat4("projection", projection);
	m_CubeShader->setMat4("view", view);

	glm::mat4 model = glm::mat4(1.0f);
	m_CubeShader->setMat4("model", model);

	// bind diffuse map
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, diffuseMap);
	// bind specular map
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, specularMap);

	glBindVertexArray(cubeVAO);
	for (unsigned int i = 0; i < 10; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		m_CubeShader->setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	// draw light cube
	m_LightCubeShader->use();
	m_LightCubeShader->setMat4("projection", projection);
	m_LightCubeShader->setMat4("view", view);

	glBindVertexArray(lightCubeVAO);
	for (unsigned int i = 0; i < 4; i++)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, pointLightPositions[i]);
		model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
		m_LightCubeShader->setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

bool Sample_Lighting::shutdown()
{
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &lightCubeVAO);
	glDeleteBuffers(1, &VBO);
	glDeleteTextures(1, &diffuseMap);
	glDeleteTextures(1, &specularMap);

	delete m_CubeShader;
	delete m_LightCubeShader;
	return true;
}