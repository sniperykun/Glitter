#ifndef SAMPLE_LIGHTING
#define SAMPLE_LIGHTING

#include "Common.h"
#include "BaseSample.hpp"

class Shader;

// 
// Multi Lights(Directional,Point,Spot Lights) Basic
//

class Sample_Lighting : public BaseSample
{
public:
	Sample_Lighting() : BaseSample("Sample Lighting")
	{
	}
	bool setup(int argc, char * argv[]) override;
	void render(SimpleCamera& camera, float time) override;
	bool shutdown() override;
private:
	Shader* m_LightCubeShader;
	Shader* m_CubeShader;
private:
	unsigned int cubeVAO;
	unsigned int VBO;
	unsigned int lightCubeVAO;
	unsigned int diffuseMap;
	unsigned int specularMap;

	std::vector<glm::vec3> pointLightPositions;
	std::vector<glm::vec3> cubePositions;
};


#endif // !SAMPLE_LIGHTING
