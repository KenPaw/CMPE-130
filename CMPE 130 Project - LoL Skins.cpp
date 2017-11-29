//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "LoLSkinSaleDatabase.h"
using namespace std;

int main()
{
	Skin RoyalGuardFiora("Royal Guard Fiora", "Fiora", 520, 260, "10/17-10/20", 2017);
//	RoyalGuardFiora.printInfo();

	string skinInfo;
	string skin;
	string champ;
	int price;
	int sale;
	string wk;
	int yr;

	string str;

	ifstream file;

	int i = 0;
	int j = 0;
	int k = 0;
	vector<Skin> list;
	list.resize(1);
	file.open("SkinSale.txt");

	while(getline(file, str, ';'))
	{
		if(i == 0 && k == 1)
		{
			str.erase(0, 1);
		}
		if(i == 0)
		{
			skin = str;
			k = 1;
		}

		if(i == 1)
		{
			champ = str;
		}
		if(i == 2)
		{
//				cout << str2.length() << endl;
//				cout << str2 << endl;
			price = stoi(str);
		}
		if(i == 3)
		{
//				cout << str2.length() << endl;
//				cout << str2 << endl;
			sale = stoi(str);
		}
		if(i == 4)
		{
			wk = str;
		}
		if(i == 5)
		{
//				cout << str2.length() << endl;
//				cout << str2 << endl;
			yr = stoi(str);
			i = -1;

			list[j].addSkinName(skin);
			list[j].addChampName(champ);
			list[j].addOrigPrice(price);
			list[j].addSalePrice(sale);
			list[j].addWeek(wk);
			list[j].addYear(yr);
			j++;
			list.resize(j+1);
		}
		i++;
	}

	for(int x=0; x < j; x++)
	{
		list[x].printInfo();
	}

	file.close();

	return 0;
}
