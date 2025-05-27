#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::SetContactsNumber(int i)
{
	if (i > 7)
	{
		i = 0;
		this->ContactsNumber = 0;
	}
	this->ContactsNumber = i;
}

int	PhoneBook::GetContactsNumber()
{
	return (this->ContactsNumber);
}

void	PhoneBook::EnterNewContact(Contact NewContact)
{
	this->Contacts[this->ContactsNumber] = NewContact;
	this->SetContactsNumber(this->ContactsNumber + 1);
}

Contact	PhoneBook::GetContactByIndex(int index)
{
	return (this->Contacts[index]);
}
