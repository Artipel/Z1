#include <iostream>
#include "gunCL.cpp"
#include <vector>
#include <algorithm>
//#include "ClipCL.cpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Gun::ammo = 0;

void paint(int n)
{
	switch(n)
	{
		case 0:
			cout<<" ,________________________________       "<<endl;
			cout<<"|__________,----------._ [____]  \"\"-,__  __...-----===\""<<endl;
			cout<<"        (_(||||||||||||)___________/   \"\"             |"<<endl;
			cout<<"           `----------'        [ ))\"-,                |"<<endl;
			cout<<"                                \"\"    `,  _,--...___  |"<<endl;
			cout<<"                                        `/          \"\"\""<<endl;
			break;
		case 1:
			cout<<"                           ______"<<endl;
			cout<<"        |\\_______________ (_____\\\\______________"<<endl;
			cout<<"HH======#H###############H#######################"<<endl;
			cout<<"        ' ~\"\"\"\"\"\"\"\"\"\"\"\"\"\"`##(_))#H\\\"\"\"\"\"Y########"<<endl;
			cout<<"                          ))    \\#H\\       `\"Y###"<<endl;
			cout<<"                          \"      }#H)"<<endl;
			break;
		case 2:
			cout<<"+--^----------,--------,-----,--------^-,"<<endl;
			cout<<"| |||||||||   `--------'     |          O"<<endl;
			cout<<"`+---------------------------^----------|"<<endl;
			cout<<"  `\\_,---------,---------,--------------'"<<endl;
			cout<<"     / XXXXXX /'|       /'"<<endl;
			cout<<"    / XXXXXX /  `\\    /'"<<endl;
			cout<<"   / XXXXXX /`-------'"<<endl;
			cout<<"  / XXXXXX /"<<endl;
			cout<<" / XXXXXX /"<<endl;
			cout<<"(________(         "<<endl;
			cout<<" `------'    "<<endl;
			break;
	}
}

void showMainMenu()
{
	cout<<"Main Menu:"<<endl<<"1. Enter arsenal."<<endl;
}

void presentArsenal(vector <Gun> arsenal)
{
	unsigned i;
	for(i=0;i<arsenal.size();++i)
	{
		arsenal[i].drawGun();
		cout<<arsenal[i].getModel()<<endl<<"Weights: "<<arsenal[i].getWeight()<<"g."<<endl;
	}
}

vector <Gun> createVArsenal()
{
	vector < Gun > arsenal;
	Gun * Gun1 = new Gun(3500,"Shotgun",0, 120, 8, 4);
	arsenal.push_back(*Gun1);
	Gun1->redefine(3400,"M16",1, 240, 30, 24);
	arsenal.push_back(*Gun1);
	Gun1->redefine(775,"Pistol",2, 150, 12, 10);
	arsenal.push_back(*Gun1);
	Gun::setAmmo(100);
	return arsenal;
}

int arsenalMenu()
{
	int c=10;
	cout<<"Type corresponding number:"<<endl<<"1. Equip one of the weapons"<<endl<<"2. Check details of a weapon."<<endl;
	cout<<"3. Sort weapons by total weight and display"<<endl<<"4. Display weapons"<<endl<<"5. Craft new weapon"<<endl;
	do{
        cin>>c;
	}while(c>9);
	return c;
}

int lookfor(string model, vector <Gun> arsenal, int size)
{
	int i;
	for(i=0;i<size;++i)
	{
		if(arsenal[i].getModel()==model)
		{
			cout<<"Model found"<<endl;
			return i;
		}
	}
	cout<<"Weapon does not exist"<<endl;
	return -1;
}

Gun craftGun()
{
    cout<<"Welcome to the workshop. Type name of the new model: ";
    string name;
    cin>>name;
    cout<<"What kind of a weapon you want it to be?"<<endl<<"1. Shotgun"<<endl<<"2. Rifle"<<endl<<"3. Pistol"<<endl;
    unsigned graphics;
    cin>>graphics;
    cout<<"What is the mass of the weapon without clip?"<<endl;
    unsigned mass;
    cin>>mass;
    cout<<"What is the mass of the clip?"<<endl;
    unsigned clipMass;
    cin>>clipMass;
    cout<<"What is the size of the clip?"<<endl;
    unsigned clipSize;
    cin>>clipSize;
    Gun temporary(mass, name, graphics-1, clipMass, clipSize, 0);
    cout<<temporary;
    return temporary;
}

void Arsenal()
{
	//Gun * test = new Gun();
	//Gun::setAmmo();
	vector <Gun> arsenal = createVArsenal();
	Gun::setAmmo(100);
	//Gun::getAmmo();
	cout<<"You are in the arsenal. These are the weapons available:"<<endl;
	presentArsenal(arsenal);
	cout<<"Ammo available in the stock: ";
	cout<<arsenal[0].getAmmo()<<endl;
	int choice = arsenalMenu();
	string selection;
	Gun * equiped2;
	do
	{
		switch(choice)
		{
			case 1:
				cout<<"Select weapon by typing its name. ";
				cin>>selection;
				int i;
				i=lookfor(selection, arsenal, arsenal.size());
				if(i!=-1)
				{
					equiped2 = &arsenal[i];
				}
				else
				{
                    break;
				}

				cout<<"You are holding: "<<equiped2->getModel()<<endl<<"Type f to fire. Type u to unequip. Type r to reload."<<endl;

				char move;
				do
				{
					cin>>move;
					if(move=='f')
						equiped2->shot();
					if(move=='u')
						break;
					if(move=='r')
						equiped2->reload();
				}while(1);
				break;
			case 2:
				cout<<"Select weapon by typing its name. ";
				cin>>selection;
				i=lookfor(selection, arsenal, arsenal.size());
				if(i!=-1)
					cout<<arsenal[i];
				break;
            case 3:
                sort(arsenal.begin(),arsenal.end());
                break;
            case 4:
                presentArsenal(arsenal);
                break;
            case 5:
                arsenal.push_back(craftGun());
                break;
            case 6:
                cout<<"Type name of the weapon you want to destroy: ";
                cin>>selection;
                i=lookfor(selection, arsenal, arsenal.size());
				if(i!=-1){
					cout<<arsenal[i];
					arsenal.erase(arsenal.begin()+i);
				}
				break;

            case 0:
                return;
		}
	choice = arsenalMenu();
	}while(1);
}

int main()
{
    Gun testGun(1,"TestGun",1,1,1,1);
    testGun.tester();
    cout<<testGun.tester()<<endl;
	while(1)
	{
		int choice = 0;
		showMainMenu();
		cin>>choice;
		switch(choice)
		{
			case 1:
				Arsenal();
				break;
			case 2:
				return 0;
				break;
			default:
				cout<<"Again";
		}
	}
	return 0;
}
