#ifndef BASE_SAMPLE_H
#define BASE_SAMPLE_H

#include <iostream>
class SimpleCamera;

class BaseSample
{
public:
	BaseSample(const std::string des) : _sampleName(des)
	{
	}

	virtual bool setup(int argc, char * argv[]) = 0;
	virtual void render(SimpleCamera& camera, float time) = 0;
	virtual bool shutdown() = 0;

public:
	std::string _sampleName;
};

#endif // !BASE_SAMPLE_H
