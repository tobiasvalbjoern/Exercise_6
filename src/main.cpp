//============================================================================
// Name        : Exercise4.cpp
// Author      : Tobias Valbjørn
// Version     :
// Copyright   : Free for all
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Options.h"

using namespace std;

Options opt;
int main(int argc, char** argv)
{
	string validOpt = "abo";

	//create a pointer to an object
	Options *obj;
	Options opt2(argc, (const char**) argv);
	//Allocate memory in the heap and make obj point to it.
	obj = new Options(argc, (const char**) argv);

	//copy the dynamic object to the global object, so we can use the global
	//object in a greater scope.
	opt = *obj;

	//send the information about valid options
	opt.setOptstring(validOpt);
	cout << "Number of valid options on command line: "
			<< opt.numopt() << endl;

	//we save the number of valid options on the command line here,
	//so we don't have to run through numopt in every iteration in our for
	//loop
	int cnt = opt.numopt();

	//
	for (int i = 0; i < cnt; i++)
	{
		//prints the matches.
		cout << "Found match: -" << (char) opt.getopt() << endl;
	}

	//For the alternative use of getopt
	opt2.setOptstring(validOpt);
	cout << "Alternative Number of valid options on command line: "
			<< opt2.numopt() << endl;

	//we save the number of valid options on the command line here,
	//so we don't have to run through numopt in every iteration in our for
	//loop
	cnt = opt.numopt();

	for (int i = 0; i < cnt; i++)
	{
		//prints the matches.
		cout << "Found match: -" << (char) opt2.getopt("abo") << endl;
	}

	//because we have defined the comparison operator,
	//we can now compare two classes.
	//we test it down here. Try failing the test by entering
	//argc-1 in the constructor for one of the classes
	if (opt == opt2)
		cout << "Equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}
