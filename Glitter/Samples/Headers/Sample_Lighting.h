#ifndef SAMPLE_LIGHTING
#define SAMPLE_LIGHTING

#include "Common.h"
#include "BaseSample.hpp"

// 
// Sample Basic Lighting
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

};


#endif // !SAMPLE_LIGHTING
