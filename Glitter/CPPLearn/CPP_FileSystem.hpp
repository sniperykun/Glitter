#ifndef CPP_FILESYSTEM_H
#define CPP_FILESYSTEM_H

#include "glitter.hpp"
#include "Shader.h"
#include <iostream>

class CPP_FileSystemSample
{
	//string executepathstr = argv[0];
	//fs::path executePath = executepathstr;
	//cout << executePath.root_path() << endl;
	//cout << executePath.root_directory() << endl;
	//cout << executePath.parent_path() << endl;
	//cout << executePath.has_filename() << endl;
	//cout << executePath.filename() << endl;
	//cout << executePath.relative_path() << endl;
	//cout << executePath.is_absolute() << endl;

	//cout << fs::exists(executePath) << endl;
	//cout << fs::is_directory(executePath) << endl;
    
//    float floatarray[10];
//    int myint = 100;
//    std::cout << "input vertices count:" << verticecount << std::endl;
//    std::cout << sizeof(int) << std::endl;
//    std::cout << sizeof(float) << std::endl;
//    std::cout << sizeof(floatarray) << std::endl;
//    std::cout << sizeof(floatarray[0]) << std::endl;
//    std::cout << sizeof(&(floatarray[0])) << std::endl;
//    std::cout << sizeof(&floatarray[0]) << std::endl;
//    std::cout << sizeof(&myint) << std::endl;
//    std::cout << sizeof(int*) << std::endl;
};

class CubeModel
{
private:
	unsigned int VBO;
	unsigned int VAO;
	glm::vec3 position;
	float *vertices;
	int verticecount;

public:
	CubeModel(const glm::vec3& inputpos, float inputvertices[], int len)
	{
		position = inputpos;
		vertices = inputvertices;
		verticecount = len;
        
        // 64-bit 8
        // inputvertices:sizeof on array function parameter will return size of "float *"
        // instead of float[]
        // std::cout << sizeof(inputvertices) << std::endl;
	}

	void setUp()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, verticecount, vertices, GL_STATIC_DRAW);

		// 5 attributes(position and texture coord)
		// input vertex layout
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// texture coord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
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

#endif // !CPP_FILESYSTEM_H
