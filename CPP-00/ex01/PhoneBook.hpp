#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int ContactsNumber;
		Contact Contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	SetContactsNumber(int);
		int		GetContactsNumber();
		void	EnterNewContact(Contact);
		Contact	GetContactByIndex(int index);
};

