/**
* CS-273 Exam 2 Fall 2014
* Who doesn't like parties ?!
*
* @authors Everyone!
*/
/*
Dinner Party add, list, remove          27/30 -- push_front should have try/catch
                                            -- list() would be cleaner as a for loop
BirthdayParty                           20/20
BirthdayPartyTicket                     20/20
PartyFactory::factory                   10/10
Well-designed and commented code        17/20 -- dinnerparty in comments for BirthdayPartyTicket

TOTAL                                   /100
*/
#include <iostream>
#include <string>
#include "Party.h"
#include "PartyTicket.h"
#include "PartyFactory.h"

using std::cout;
using std::endl;

int main() // PLEASE DO NOT MODIFY THE MAIN FUNCTION
{
	Party *myparty = PartyFactory::factory("dinner"); // Create a dinner party with the party factory

													  // Let's add a couple of people to the dinner party, and store their tickets in variables
	PartyTicket *ticket1 = myparty->add("Mike");
	PartyTicket *ticket2 = myparty->add("Jane");
	PartyTicket *ticket3 = myparty->add("Antonio");
	PartyTicket *ticket4 = myparty->add("Sue");

	cout << "Party before Jane leaves\n";
	myparty->list(); // List the people currently in the dinner party

					 // Jane decides to leave the party. Darn!  She was really fun to have around!
	ticket2->leave();

	cout << "Party after Jane leaves:\n";
	myparty->list(); // List the people left in the dinner party

}
