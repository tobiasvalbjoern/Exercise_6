/*
 * Options.cpp
 *
 *  Created on: 29 Aug 2017
 *      Author: Tobias
 */

#include "Options.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>


using namespace std;
Options::Options()
{
	//the default constructor needs all the private attributes
	//initialized to safe values.
	argC=0;
	argV=NULL;
	optstring = "";
	count = 1;
}

Options::Options(int argc, const char **argv)
{
	argC = argc;
	argV = (char**) argv;
	optstring = "";
	count = 1;
}

//in the copy constructor, all the attributes are copied from
//the object on the right hans side (rhs)
Options::Options(const Options &rhs)
{
	argC=rhs.argC;
	argV=rhs.argV;
	optstring=rhs.optstring;
	count=rhs.count;
}

Options::~Options()
{
}

void Options::setOptstring(string validopt)
{
	optstring = validopt;
}

int Options::getopt(void)
{
	//move through each argument on the command line until a valid option
	//is found. Then return it. Count keeps track of our progress through
	//the commandline.
	for (; count < argC; count++)
	{
		//this for loop traverses through the valid options
		for (size_t j = 0; j < optstring.size(); j++)
		{
			//if there is a - and two characters, as in "-a"
			if (argV[count][0] == '-' && strlen(argV[count])==2 )
			{
			//compare the letters.
			if(argV[count][1]==optstring[j])
					{
				count++;
				return optstring[j];
					}
				}

			}
		}

	return 0;
}

int Options::getopt(string validopt)
{
	//move through each argument on the command line until a valid option
	//is found. Then return it. Count keeps track of our progress through
	//the commandline.
	for (; count < argC; count++)
	{
		//this for loop traverses through the valid options
		for (size_t j = 0; j < validopt.size(); j++)
		{
			//if there is a - and two characters, as in "-a"
			if (argV[count][0] == '-' && strlen(argV[count])==2 )
			{
			//compare the letters.
			if(argV[count][1]==validopt[j])
					{
				cout << "Overloaded getopt working:"<<endl;
				count++;
				return validopt[j];
					}
				}

			}
		}

	return 0;
}


//move through all the arguments on the commandline
//and save the number of valid options found.
int Options::numopt(void)
{
	int number = 0;

	for (int i = 1; i < argC; i++)
	{
		for (size_t j = 0; j < optstring.size(); j++)
		{
			if (argV[i][0] == '-' && strlen(argV[i])==2 )
			{
			if(argV[i][1]==optstring[j])
					{
				number++;
					}
				}

			}
		}

		return number;
	}
