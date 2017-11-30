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
	month = 0;
	day = 0;
	year = 0;
	priority = 0;
	status = " ";
}

Skin::Skin(const Skin& obj)
{
	skinName = obj.skinName;
	champName = obj.champName;
	origPrice = obj.origPrice;
	salePrice = obj.salePrice;
	month = obj.month;
	day = obj.day;
	year = obj.year;
	priority = obj.priority;
	status = obj.status;
}

Skin::Skin(string skin, string champ, int orig, int sale, int m, int d, int yr, string stat)
{
	skinName = skin;
	champName = champ;
	origPrice = orig;
	salePrice = sale;
	month = m;
	day = d;
	year = yr;
	priority = 0;
	status = stat;
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

int Skin::getMonth()
{
	return month;
}

void Skin::addMonth(int m)
{
	month = m;
}

int Skin::getDay()
{
	return day;
}

void Skin::addDay(int d)
{
	day = d;
}

int Skin::getYear()
{
	return year;
}

void Skin::addYear(int yr)
{
	year = yr;
}

string Skin::getStatus()
{
	return status;
}

void Skin::addStatus(string stat)
{
	status = stat;
}

void Skin::printInfo()
{
	cout << "Skin Name: " << skinName << endl;
	cout << "Champion Name: " << champName << endl;
	cout << "Original Price: " << origPrice << endl;
	cout << "Sale Price: "  << salePrice << endl;
	cout << "Date of sale: " << month << "/" << day << "/" << year << endl;
	cout << "Days since last sale: " << priority << endl;
	if(priority >= 365)
	{
		cout << "Probability of skin sale is extremely high." << endl;
	}
	else if(priority > 182 && status != "Never")
	{
		cout << "Probability of skin sale is possible." << endl;
	}
	else if(priority < 365 && status == "Never")
	{
		cout << "Skin is fairly new has not been released for over a year yet." << endl;
		cout << "Skin will not go on sale until a year has passed." << endl;
	}
	else if(priority < 182)
	{
		cout << "Probability of skin sale is unlikely." << endl;
	}
}

int Skin::calculatePriority()
{
	Date dt1 = {day, month, year};

	int diff = getDifference(dt1, dt2);

	return diff;
}

int Skin::getPriority()
{
	return priority;
}

void Skin::changePriority(int prior)
{
	priority = prior;
}


int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

// This function returns number of days between two given
// dates
int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = dt1.y*365 + dt1.d;

    // Add days for months in given date
    for (int i=0; i<dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

    long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}
