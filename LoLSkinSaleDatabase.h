/*
 * LoLSkinSaleDataBase.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Kagem
 */

#ifndef LOLSKINSALEDATABASE_H_
#define LOLSKINSALEDATABASE_H_

#include <iostream>
#include <string>
using namespace std;

class Skin
{
private:
	string skinName;
	string champName;
	int origPrice;
	int salePrice;
	string week;
	int year;
public:
	Skin();
	Skin(string skin, string champ, int orig, int sale, string wk, int yr);
	string getSkinName();
	void addSkinName(string name);
	string getChampName();
	void addChampName(string name);
	int getOrigPrice();
	void addOrigPrice(int price);
	int getSalePrice();
	void addSalePrice(int price);
	string getWeek();
	void addWeek(string wk);
	int getYear();
	void addYear(int yr);
	void printInfo();
};




#endif /* LOLSKINSALEDATABASE_H_ */
