/*<3**return*void*~*-std=c++0x*~*return*void*~*-std=c++11*~*return*void**<3*\
* Name        : NoSpam													*
* Authors     : Brandon Zhen, Edward Huang, Kevin Lai						*
* Version     : 0.0.0														*
* Copyright   : Borders � BZhen 2014										*
* Description : 															*
\*<3**return*void*~*-pthread<3*~*return*void*~*>linux_gcc*~*return*void**<3*/

/*																			*\
TODO:	Project Abstract due Thursday, October 9
			(a) Title of your project
					NoSpam
			(b) Names and student IDs of the members
					Brandon Zhen
					Edward Huang
					Kevin Lai
			(C) One paragraph describing what you will do in the project

			(d) A weekly schedule of what you will accomplish
					Week 0	(T:10-7) : Create Dummy Email Commence Operation GETSPAM
							(R:10-9) : Project Abstract Due

					Week 1	(T:10-14): Obtain, set up, and research all necessary software tools for project
							(R:10-16): (Full Gmail API, OAuth, ClientKeys, Etc..)

					Week 2	(T:10-21): Develop String Matching Algorithm (C++)
							(R:10-23):

					Week 3	(T:10-28): Create Java framework utilizing our string matching algorithm [Java]
							(R:10-30):

					Week 4	(T:11-4) : Implementing C++ String Matching Algorithm into the Gmail Java API
							(R:11-6) :

					Week 5	(T:11-11): Testing, Debugging, and Improving and Finalizing Code
							(R:11-13):

					Week 6	(T:11-18): Project Report Due
							(R:11-20):

					Week 7	(T:11-25): Creating PowerPoint
							(R:11-27):

					Week 8	(T:12-2) : Project Presentations Begin Now

					Notes: If needed, some steps may be extended
\* 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 		*/

/*																			*\
TODO:	Proposed Project and Ideas
			SPAM Filter, Automated Detection and Deletion
				1. Gmail Java API will be used to read SPAM tagged emails in
					target gmail account and send email body string to 2.
				2. C++ executable will be created to parse whether email
					body strings are deletable and return results back to 1.
				1. Gmail Java API will either delete or keep SPAM based on
					the C++ execuable parser's results.
			Kevin determines details to be inadequate.
			We will start planning things out this Friday.
\*																			*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
	cout << __cplusplus << endl;
	return EXIT_SUCCESS;
}