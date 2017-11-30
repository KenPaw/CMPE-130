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
#include <ctime>
using namespace std;

struct Date
{
    int d, m, y;
};
const Date dt2 = {30, 11, 2017};
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int countLeapYears(Date d);
int getDifference(Date dt1, Date dt2);


class Skin
{
private:
	string skinName;
	string champName;
	int origPrice;
	int salePrice;
	int month;
	int day;
	int year;
	int priority;
	string status;
public:
	Skin();
	Skin(const Skin& obj);
	Skin(string skin, string champ, int orig, int sale, int m, int d, int yr, string stat);
	string getSkinName();
	void addSkinName(string name);
	string getChampName();
	void addChampName(string name);
	int getOrigPrice();
	void addOrigPrice(int price);
	int getSalePrice();
	void addSalePrice(int price);
	int getMonth();
	void addMonth(int m);
	int getDay();
	void addDay(int d);
	int getYear();
	void addYear(int yr);
	string getStatus();
	void addStatus(string stat);
	void printInfo();
	int calculatePriority();
	int getPriority();
	void changePriority(int prior);
};




#endif /* LOLSKINSALEDATABASE_H_ */
