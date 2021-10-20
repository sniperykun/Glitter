#ifndef SIMPLE_MESH
#define SIMPLE_MESH

#include <string>
#include <vector>
#include <Shader.h>

using namespace std;

#define MAX_BONE_INFLUENCE  4

struct Vertex {
	// position
	glm::vec3 Position;
	// normal
	glm::vec3 Normal;
	// texcoords
	glm::vec2 TexCoords;
	// tangent
	glm::vec3 Tangent;
	// bitangent
	glm::vec3 Bitangent;
	// bones index
	int m_BoneIds[MAX_BONE_INFLUENCE];
	// weights from each bone
	float m_Weights[MAX_BONE_INFLUENCE];
};

struct Texture {
	unsigned int id;
	string type;
	string path;
};

class SampleMesh
{
public:
	// mesh data
	vector<Vertex> m_Vertices;
	vector<unsigned int> m_Indices;
	vector<Texture> m_Textures;
	unsigned int mVAO;

	// contructor
	SampleMesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures)
	{
		this->m_Vertices = vertices;
		this->m_Indices = indices;
		this->m_Textures = textures;

		setupMesh();
	}

	// draw mesh
	void Draw(Shader& shader)
	{
		// bing textures to shader uniform
		unsigned int diffuseNumber = 1;
		unsigned int specularNumber = 1;
		unsigned int normalNumber = 1;
		unsigned int heightNumber = 1;

		for (unsigned int i = 0; i < m_Textures.size(); i++)
		{
			// active proper texture unit before binding
			glActiveTexture(GL_TEXTURE0 + i);
			string number;
			string name = m_Textures[i].type;
			if (name == "texture_diffuse")
			{
				number = std::to_string(diffuseNumber++);
			}
			else if (name == "texture_specular")
			{
				number = std::to_string(specularNumber++);
			}
			else if (name == "textue_normal")
			{
				number = std::to_string(normalNumber++);
			}
			else if (name == "texture_height")
			{
				number = std::to_string(heightNumber++);
			}

			// now set the sampler to the correct texture unit
			glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
			// and finally bind the texture
			glBindTexture(GL_TEXTURE_2D, m_Textures[i].id);
		}

		// draw mesh
		glBindVertexArray(mVAO);
		glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// always good practice to set everything back to defaults once configured.
		glActiveTexture(GL_TEXTURE0);
	}

private:
	unsigned int mVBO;
	unsigned int mEBO;

	void setupMesh()
	{
		// create buffer object to describe this mesh
		glGenVertexArrays(1, &mVAO);
		glGenBuffers(1, &mVBO);
		glGenBuffers(1, &mEBO);

		glBindVertexArray(mVAO);
		// load data to vertext buffers
		// 1. bind
		// 2. load data layout stream
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0], GL_STATIC_DRAW);

		// set the vertex attribute pointers
		// vertex Positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		// vertex normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
		// vertex texture coords
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
		// vertex tangent
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
		// vertex bitangent
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
		// ids
		glEnableVertexAttribArray(5);
		glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIds));

		// weights
		glEnableVertexAttribArray(6);
		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));

		glBindVertexArray(0);
	}
};


#endif // !SIMPLE_MESH
