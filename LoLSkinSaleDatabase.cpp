/*
 * LoLSkinSaleDatabase.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Kagem
 */
#include "LoLSkinSaleDatabase.h"

Skin::Skin()
{
	skinName = "skin";
	champName = "champ";
	origPrice = 0;
	salePrice = 0;
	week = "week";
	year = 0;
}

Skin::Skin(string skin, string champ, int orig, int sale, string wk, int yr)
{
	skinName = skin;
	champName = champ;
	origPrice = orig;
	salePrice = sale;
	week = wk;
	year = yr;
}

string Skin::getSkinName()
{
	return skinName;
}

void Skin::addSkinName(string name)
{
	skinName = name;
}

string Skin::getChampName()
{
	return champName;
}

void Skin::addChampName(string name)
{
	champName = name;
}

int Skin::getOrigPrice()
{
	return origPrice;
}

void Skin::addOrigPrice(int price)
{
	origPrice = price;
}

int Skin::getSalePrice()
{
	return salePrice;
}

void Skin::addSalePrice(int price)
{
	salePrice = price;
}

string Skin::getWeek()
{
	return week;
}

void Skin::addWeek(string wk)
{
	week = wk;
}

int Skin::getYear()
{
	return year;
}

void Skin::addYear(int yr)
{
	year = yr;
}

void Skin::printInfo()
{
	cout << "Skin Name: " << skinName << endl;
	cout << "Champion Name: " << champName << endl;
	cout << "Original Price: " << origPrice << endl;
	cout << "Sale Price: "  << salePrice << endl;
	cout << "Days on sale: "  << week << endl;
	cout << "Year on sale: " << year << endl;
}
