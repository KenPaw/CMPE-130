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
			price = stoi(str);
		}
		if(i == 3)
		{
			sale = stoi(str);
		}
		if(i == 4)
		{
			wk = str;
		}
		if(i == 5)
		{
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

	cout << "Please choose an option: " << endl;
	int option = 0;
	int end = 0;
	while(end != 1)
	{
		cout << "1. Add skin sale." << endl;
		cout << "2. Search for skin." << endl;
		cout << "3. Display list of skins." << endl;
		cout << "0. End Program." << endl;
		cin >> option;
		if(option == 1)
		{
			string skinName;
			string champName;
			string weekDate;
			int ogPrice;
			int year;

			cout << "Please type in the name of the skin." << endl;
			cin.ignore();
			getline(cin, skinName);

			cout << "Please type in the name of the champion." << endl;
			getline(cin, champName);

			cout << "Please type in the original price of the skin." << endl;
			cin >> ogPrice;
			string strPrice = to_string(ogPrice);
			string strSale = to_string(ogPrice / 2);

			cout << "Please type in the duration of the sale. (ex. 10/17-10/20)" << endl;
			cin.ignore();
			getline(cin, weekDate);


			cout << "Please type in the year." << endl;
			cin >> year;
			string strYr = to_string(year);

			fstream file;
			file.open("SkinSale.txt", fstream::app);
			if(file.is_open())
			{
				file << "\n" << skinName << ";" << champName << ";" << strPrice << ";" << strSale << ";" << weekDate << ";" << strYr << ";";
				file.close();
			}
			else
			{
				cout << "Unable to open file";
				return 0;
			}
			file.close();

			list[j].addSkinName(skinName);
			list[j].addChampName(champName);
			list[j].addOrigPrice(ogPrice);
			list[j].addSalePrice(ogPrice / 2);
			list[j].addWeek(weekDate);
			list[j].addYear(year);
			list[j].printInfo();
			j++;
			list.resize(j+1);
		}
		if(option == 2)
		{
			string skinNameIn;
			cout << "Please type in the name of the skin." << endl;
			cin >> skinNameIn;
		}
		if(option == 3)
		{
			for(int x=0; x < j; x++)
			{
				list[x].printInfo();
			}
		}
		if(option == 0)
		{
			cout << "Program has ended." << endl;
			end = 1;
		}
	}

	file.close();

	return 0;
}
