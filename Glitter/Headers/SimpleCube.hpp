#ifndef  SIMPLE_CUBE
#define SIMPLE_CUBE

#include "glitter.hpp"
#include <iostream>

#include <glm/glm.hpp>
#include "Shader.h"

class CubeModel
{
private:
	unsigned int VBO;
	unsigned int VAO;
	glm::vec3 position;

public:
	CubeModel(const glm::vec3& inputpos)
	{
		position = inputpos;
	}

	void setUp()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GlitterConfig::data_cube_vertices), GlitterConfig::data_cube_vertices, GL_STATIC_DRAW);

		//  3 attributes(position , color, texture coord)
		// sizeof 8 float [0,0,0|0,0,0|0,0]
		// input vertex layout
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		
		// vertex color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}

	void Render(Shader& shader, float angle)
	{
		glBindVertexArray(VAO);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		shader.setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	void ShutDown()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
};
#endif // ! SIMPLE_CUBE
