#ifndef SAMPLE_LOADMODEL
#define SAMPLE_LOADMODEL

#include "BaseSample.hpp"
#include "SimpleModel.h"
#include "Shader.h"

class Sample_LoadModel : public BaseSample
{
public:
	Sample_LoadModel() : BaseSample("Sample_LoadModel")
	{
	}

public:
	bool setup(int argc, char * argv[]) override;
	void render(SimpleCamera& camera, float time) override;
	bool shutdown() override;

private:
	SimpleModel* m_Model;
	Shader* m_RenderShader;
};

#endif // !SAMPLE_LOADMODEL
