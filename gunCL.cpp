#include <iostream>
#include "ClipCL.cpp"

using namespace std;

void paint(int n);

class Gun
{
private:
	int totalWeight;
	int ownWeight;
	string model;
	int graphics;
	Clip ownClip;
	static int ammo;
public:
	Gun() {}

	Gun(int m, string n, int g, int mm, int ms, int ml)
	{
		setModel(n);
		setGraphics(g);
		Gun::ownClip.redefine(mm, ms, ml);
		setOwnWeight(m);
		updateWeight();
		//Gun::ammo=0;
	}

	void redefine(int m, string n, int g, int mm, int ms, int ml)
	{
		setOwnWeight(m);
		setModel(n);
		setGraphics(g);
		attachClip(mm, ms, ml);
		updateWeight();
	}

	void attachClip(int m, int s, int l)
	{
		Gun::ownClip.redefine(m, s, l);
		//cout<<"Clip attached. Ammo: "<<Gun::ownClip.getLoad()<<endl;
		updateWeight();
	}

	void setOwnWeight(int m)
	{
		Gun::ownWeight = m;
	}

	void updateWeight()
	{
		Gun::totalWeight = Gun::ownWeight + Gun::ownClip.getWeight();
	}

	void setModel(string n)
	{
		Gun::model=n;
	}

	void setGraphics(int n)
	{
		Gun::graphics=n;
	}

	int getWeight() const
	{
		return Gun::totalWeight;
	}

	string getModel() const
	{
		return Gun::model;
	}

	void shot()
	{
		if(Gun::ownClip.unload()==1)
		{
			cout<<"**BANG**"<<endl;
			updateWeight();
		}
	}

	void reload()
	{
		int temp;
		temp = ownClip.getLoad();
		Gun::ownClip.reload();
		cout<<"Weapon reloaded. Ammo: "<<ownClip.getLoad()<<endl;
		Gun::ammo-=(ownClip.getLoad()-temp);
		updateWeight();
		cout<<"Ammo available in the stock: ";
		cout<<ammo<<endl;

	}

	void drawGun() const
	{
		paint(Gun::graphics);
	}

	static void setAmmo(int x)
	{
		Gun::ammo = x;
	}

	static int getAmmo()
	{
	    return Gun::ammo;
	}

	bool operator >(const Gun & g)
	{
		return this->totalWeight>g.totalWeight;
	}

	bool operator <(const Gun & g)
	{
		return this->totalWeight<g.totalWeight;
	}

	friend ostream & operator<< (ostream &wyjscie, const Gun &g)
	{
	    g.drawGun();
        return wyjscie <<"Name: "<<g.model<<endl<<"Total weight: "<<g.totalWeight<<endl<<"Clip weight: "<<g.ownClip.getWeight()<<endl<<"Clip size: "<<g.ownClip.getSize()<<endl;
    }

    bool test1()
    {
        model="Test";
        if(getModel()=="Test")
            return 0;
        else
            return 1;
    }

    bool test2()
    {
        ownWeight=1;
        ownClip.redefine(2,0,0);
        updateWeight();
        if(getWeight()!=3)
        {
            cout<<getWeight();
            return 1;
        }
        ownClip.redefine(2,1,1);
        updateWeight();
        if(getWeight()!=15)
            return 1;
        else
            return 0;
    }

    bool test3()
    {
        return 0;
    }

    int tester()
    {
        if(test1()==1)
            cout<<"test1 error"<<endl;
        if(test2()==1)
            cout<<"test2 error"<<endl;

        return 0;
    }

};
