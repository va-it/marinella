#pragma once
class Boat
{
private:
	
	float lenght, depth;

public:
	Boat();
	
	Boat(float childLenght, float childDepth)
	{
		lenght = childLenght;
		depth = childDepth;
	};

	~Boat();

	float getLenght()
	{
		return lenght;
	}

	float getDepth()
	{
		return depth;
	}
};

