#include <iostream>

using namespace std;

class Clip
{
private:
	int stdWeight, weight, size, load;

public:
	Clip() {}
	Clip(int weight, int size, int load)
	{
		setStdWeight(weight);
		setSize(size);
		setLoad(load);
		updateWeight();
	}

	void redefine(int m, int s, int l)
	{
		setStdWeight(m);
		setSize(s);
		setLoad(l);
		updateWeight();
	}

	void setStdWeight(int weight)
	{
		Clip::stdWeight=weight;
	}

	void setLoad(int load)
	{
		Clip::load=load;
	}

	void updateWeight()
	{
		Clip::weight=Clip::stdWeight+12*Clip::load;
	}

	void setWeight(int m)
	{
		Clip::weight = m;
	}

	void setSize(int Size)
	{
		Clip::size=Size;
	}

	int getWeight() const
	{
		return Clip::weight;
	}

	int getSize() const
	{
		return Clip::size;
	}

	int getLoad()
	{
		return Clip::load;
	}

	void reload()
	{
		Clip::load = Clip::size;
		Clip::updateWeight();
	}

	int unload()
	{
		if(Clip::load>0)
		{
			Clip::load--;
			Clip::updateWeight();
			return 1;
		}
		cout<<"Empty Clip!";
		return 0;
	}
};
