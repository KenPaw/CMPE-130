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

void searchSkinName(string str, vector<Skin> list);
void swap(Skin *a, Skin *b);
int partition (vector<Skin> &vec, int low, int high);
void quickSort(vector<Skin> &vec, int low, int high);

int main()
{
//	Skin RoyalGuardFiora("Royal Guard Fiora", "Fiora", 520, 260, 10, 17, 2017, " ");
//	Skin FrostedEzreal("Frosted Ezreal", "Ezreal", 520, 260, 6, 15, 2016, " ");
//
//	RoyalGuardFiora.printInfo();
//	FrostedEzreal.printInfo();
//
//	swap(&RoyalGuardFiora, &FrostedEzreal);
//
//	RoyalGuardFiora.printInfo();
//	FrostedEzreal.printInfo();
////	return 0;
////}

	string skinInfo;
	string skin;
	string champ;
	string stat;
	int price;
	int sale;
	int m;
	int d;
	int yr;

	string str;

	ifstream file;

	int i = 0;
	int j = 0;
	int k = 0;
	vector<Skin> list;
	list.resize(1);
	file.open("SkinSale.txt");

	/* Reads in from database and adds to vector */
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
			m = stoi(str);
		}
		if(i == 5)
		{
			d = stoi(str);
		}
		if(i == 6)
		{
			yr = stoi(str);
		}
		if(i == 7)
		{
			stat = str;
			i = -1;
			list[j].addSkinName(skin);
			list[j].addChampName(champ);
			list[j].addOrigPrice(price);
			list[j].addSalePrice(sale);
			list[j].addMonth(m);
			list[j].addDay(d);
			list[j].addYear(yr);
			list[j].addStatus(str);
			int p = list[j].calculatePriority();
			list[j].changePriority(p);
			j++;
			list.resize(j+1);
		}
		i++;
	}

	int option = 0;
	int end = 0;
	while(end != 1) /* Main Menu */
	{
		cout << "\t League of Legends Skin Searcher" << endl;
		cout << "\t -------------------------------" << endl << endl;
		cout << "1. Add skin sale." << endl;
		cout << "2. Search for skin based on name." << endl;
		cout << "3. Display list of skins." << endl;
		cout << "4. Create Priority Queue" << endl;
		cout << "5. Swap two indexes." << endl;
		cout << "0. End Program." << endl;
		cout << endl << "Please choose an option: " << endl;
		cin >> option;
		if(option == 1) //Adds to the data base
		{
			string skinName;
			string champName;
			string strStat;
			int ogPrice;
			int month;
			int day;
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

			cout << "Please type in the date of the sale (example 11 20 2017)." << endl;
			cin >> month;
			cin >> day;
			cin >> year;

			string strM = to_string(month);
			string strD = to_string(day);
			string strYr = to_string(year);

			cout << "Please type in the status of the skin (type a space unless skin has never been on sale or is Legacy)." << endl;
			cin.ignore();
			getline(cin, strStat);

			fstream file;
			file.open("SkinSale.txt", fstream::app);
			if(file.is_open())
			{
				file << "\n" << skinName << ";" << champName << ";" << strPrice << ";" << strSale << ";" << strM << ";" << strD
						<< ";" << strYr << ";" << strStat << ";";
				file.close();
			}
			else
			{
				cout << "Unable to open file";
				return 0;
			}
			file.close();

			list[j].addSkinName(skinName); //adds info to vector
			list[j].addChampName(champName);
			list[j].addOrigPrice(ogPrice);
			list[j].addSalePrice(ogPrice / 2);
			list[j].addMonth(month);
			list[j].addDay(day);
			list[j].addYear(year);
			list[j].addStatus(strStat);
			j++;
			list.resize(j+1);
		}
		if(option == 2) //search function
		{
			string skinNameIn;
			cout << "Please type in the name of the skin." << endl;
			cin.ignore();
			getline(cin, skinNameIn);
			cout << skinNameIn << endl;
			searchSkinName(skinNameIn, list);
			end = 0;
		}
		if(option == 3) //prints list of skins
		{
			for(int x=0; x < j; x++)
			{
				list[x].printInfo();
				cout << endl;
			}
		}
		if (option == 4)
		{
			int n = list.size() - 1;
			quickSort(list, 0, n);
			cout << "Priority queue: " << endl;
			cout << endl;
			for(int x=0; x < j; x++)
			{
				list[x].printInfo();
				cout << endl;
			}
		}
		if (option == 5)
		{
			cout << "Please input 2 indexes." << endl;
			int a, b;
			cin >> a;
			cin >> b;
			list[a].printInfo();
			list[b].printInfo();
			cout << endl;
			swap(&list[a], &list[b]);
			list[a].printInfo();
			list[b].printInfo();
		}
		if(option == 0) //Ends program
		{
			cout << "Program has ended." << endl;
			end = 1;
		}
	}

	file.close();

	return 0;
}

void searchSkinName(string str, vector<Skin> list)
{
	int j = 0;
	for(int i=0; i < list.size(); i++)
	{
		if(list[i].getSkinName() == str)
		{
			cout << endl << "Skin found!" << endl;
			list[i].printInfo();
			j = 1;
			cout << endl;
		}
	}
	if(j == 0)
	{
		cout << endl << "Skin could not be found." << endl << endl;
	}
}

void swap(Skin *a, Skin *b)
{
     Skin t = *a;
    *a = *b;
    *b = t;
}

int partition (vector<Skin> &vec, int low, int high)
{
    int pivot = vec[low].getPriority();
    int i = low;
    int j;

    for (int j = low + 1; j <= high- 1; j++)
    {
        if (vec[j].getPriority() >= pivot)
        {
            i++;
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[i], &vec[low]);
    return i;
}

void quickSort(vector<Skin> &vec, int low, int high)
{
	int pi;
    if (low < high)
    {
        pi = partition(vec, low, high);

        quickSort(vec, low, pi);
        quickSort(vec, pi + 1, high);
    }
}
