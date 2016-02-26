// Aanklooien.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class mies
{

};
class aap : public mies
{
protected:
	void print(string str);
public:
	static mies* handle();
};

class noot : public aap
{
public:
	void printTest(string str) { this->print(str); };
};

unsigned char calculateCRC(unsigned char* buff, int len)
{
	char crc = 0;
	for (int i = 0; i < len; ++i)
	{
		crc += buff[i];
	}
	return -crc;
}


void toBuffer(unsigned long value, unsigned char * buffer, unsigned int& offset)
{
	int i = 0;
	for (; i < 8; ++i)
	{
		buffer[offset + i] = value & 0xFF;
		value = value >> 8;
	}
	offset += i;
}

void toBuffer(unsigned char* value, int size, unsigned char * buffer, unsigned int& offset)
{
	int i = 0;
	for (; i < size; ++i)
	{
		buffer[offset + i] = value[i];
	}
	offset += i;
}

void updateCRC(unsigned long value, unsigned char& crc)
{
	unsigned int size = sizeof(long);
	for (int i = 0; i < size; ++i)
	{
		crc += value & 0xff;
		value = value >> size;
	}
}


char Range[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

int getmaximum()
{
	
	return Range[sizeof(Range)-1];
}

void getchars(vector<char>& args, int MinID, int MaxID)
{
	for (int i = 0; i < sizeof(Range); ++i)
	{
		if (Range[i] >= MinID && Range[i] < MaxID)
			args.push_back(Range[i]);
	}
}

void CheckRange()
{
	int MaxID = getmaximum() + 1; 
	while (MaxID > 0)
	{

		int MinID = max<int>(0, MaxID-3);
		vector<char> args;

		getchars(args, MinID, MaxID);

		MaxID = MinID;
	}

}

int main()
{
	mies *meisje = aap::handle();
	int i = 0;
	if (!i)
	{
		printf("i is niet 0");
	}

	unsigned char buffer[] = { 1,2,3,4,5,6,7,8 };

	unsigned char crc = calculateCRC(buffer, sizeof(buffer));
	unsigned char buffer2[sizeof(int)];
	unsigned int waarde = 99999;
	for (int i = 0; i < sizeof(int); ++i)
	{
		buffer2[i] = waarde & 0xFF;
		waarde = waarde >> 8;
	}

	CheckRange();

	return 0;
}

void aap::print(string str)
{
	cout << str << "\n";
}

mies * aap::handle()
{
	return new aap();
}
