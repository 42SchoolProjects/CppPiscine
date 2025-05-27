#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <csignal>

void PrintContact(Contact contact)
{
	std::cout << "First Name        -> " + contact.GetFirstName() << std::endl;
	std::cout << "Last Name         -> " + contact.GetLastName() << std::endl;
	std::cout << "Nickname          -> " + contact.GetNickname() << std::endl;
	std::cout << "Phone Number      -> " + contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret    -> " + contact.GetDarkestSecret() << std::endl;
}

void	SignalError()
{
	std::cout << "\033[1;31m" << "\nError -> " << "EOF signal called, closing the program !" << "\033[0m" << std::endl;
	exit(EXIT_FAILURE);
}

void	PrintError(std::string error)
{
	std::cout << "\033[1;31m" << "PhoneBook -> " << error << "\033[0m" << std::endl;
}

void	BookIsTalking(std::string message)
{
	std::cout << "\033[1;32m" << "PhoneBook -> " << message << "\033[0m" << std::flush;
	return ;
}

void	AsciiDisplayer(std::string ascii)
{
	if (ascii == "HOME")
	{
		system("clear");
		system("bat ascii/welcome");
	}
	else if (ascii == "HELP")
	{
		system("clear");
		system("bat ascii/help");
	}
	else if (ascii == "CONTACT")
	{
		system("clear");
		system("bat ascii/contact");
	}
	else if (ascii == "EXIT")
	{
		system("clear");
		system("bat ascii/exit");
	}
	else if (ascii == "SEARCH")
	{
		system("clear");
		system("bat ascii/search");
	}
}

void HandleExit()
{
	AsciiDisplayer("EXIT");
	std::cout << "\n";
	BookIsTalking("kaveO's PhoneBook closing in 3...\n\n");
	sleep(1);
	BookIsTalking("kaveO's PhoneBook closing in 2...\n\n");
	sleep(1);
	BookIsTalking("kaveO's PhoneBook closing in 1...\n\n");
	sleep(1);
	exit(EXIT_SUCCESS);
}

void	DisplayBook(PhoneBook Book, int index)
{
	std::string	WhiteSpace;
	std::string FirstName	= Book.GetContactByIndex(index).GetFirstName();
	std::string LastName	= Book.GetContactByIndex(index).GetLastName();
	std::string Nickname	= Book.GetContactByIndex(index).GetNickname();

	if (FirstName.size() > 10)
	{
		FirstName = FirstName.substr(0, 9) + ".";
	}
	else
	{
		for (size_t i = 0; i < (10 - FirstName.size()); i++)
		{
			WhiteSpace += " ";
		}
		FirstName = WhiteSpace + FirstName;
	}
	if (LastName.size() > 10)
	{
		LastName = LastName.substr(0, 9) + ".";
	}
	else
	{
		WhiteSpace = "";
		for (size_t i = 0; i < (10 - LastName.size()); i++)
		{
			WhiteSpace += " ";
		}
		LastName = WhiteSpace + LastName;
	}
	if (Nickname.size() > 10)
	{
		Nickname = Nickname.substr(0, 9) + ".";
	}
	else
	{
		WhiteSpace = "";
		for (size_t i = 0; i < (10 - Nickname.size()); i++)
		{
			WhiteSpace += " ";
		}
		Nickname = WhiteSpace + Nickname;
	}

	std::cout << "|     " << index + 1 << "|" + FirstName + "|" + LastName + "|" + Nickname + "|" << std::endl;
}

void	HandleSearch(PhoneBook Book)
{
	AsciiDisplayer("SEARCH");
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "| index|first name| last name|  nickname|" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		DisplayBook(Book, i);
	}
	std::cout << "-----------------------------------------\n" << std::endl;

	int	i = 0;
	std::string str;
	do
	{
		BookIsTalking("Enter contact index or 'HOME' : ");
		if (!getline(std::cin, str))
		{
			SignalError();
		}
		std::stringstream(str) >> i;
		if (str.empty())
		{
			PrintError("Please enter contact index or HOME");
		}
		else if (str.compare("HOME") == 0)
		{
			system("clear");
			AsciiDisplayer("HOME");
			break;
		}
		else if (str < "1" || str > "8")
		{
			PrintError("Contact array size is between 1 and 8");
		}
		else if (i >= 1 && i <= 8)
		{
			if (Book.GetContactByIndex(i - 1).GetFirstName() == "")
			{
				PrintError("The index is corresponding to an empty contact");
			}
			else
			{
				PrintContact(Book.GetContactByIndex(i - 1));
			}
		}
	} while (true);
}

void AddContact(Contact *Contact)
{
	std::string str;

	AsciiDisplayer("CONTACT");
	do
	{
		BookIsTalking("First Name : ");
		if (!getline(std::cin, str))
		{
			SignalError();
		}
		if (str.empty())
		{
			PrintError("First name is empty, please try again !");
		}
	} while (str.empty());
	Contact->SetFirstName(str);

	do
	{
		BookIsTalking("Last Name : ");
		if (!getline(std::cin, str))
		{
			SignalError();
		}
		if (str.empty())
		{
			PrintError("First name is empty, please try again !");
		}
	} while (str.empty());
	Contact->SetLastName(str);

	do
	{
		BookIsTalking("Nickname : ");
		if (!getline(std::cin, str))
		{
			SignalError();
		}
		if (str.empty())
		{
			PrintError("First name is empty, please try again !");
		}
	} while (str.empty());
	Contact->SetNickname(str);

	bool IsValid;
	do
	{
		IsValid = true;
		BookIsTalking("Phone Number : ");
		if (!getline(std::cin, str))
		{
			SignalError();
		}
		if (str.size() != 10)
		{
				PrintError("Phone number should be composed of 10 digits !");
				IsValid = false;
		}
		for (size_t i = 0; i < str.size(); i++)
		{
			if (!isdigit(str[i]))
			{
				PrintError("Phone number should be composed of digits only !");
				IsValid = false;
				break;
			}
		}
		if (str.empty())
		{
			PrintError("First name is empty, please try again !");
		}
	} while (str.empty() || !IsValid);
	Contact->SetPhoneNumber(str);

	do
	{
		BookIsTalking("Darkest Secret : ");
		if (!getline(std::cin, str))
		{
			SignalError();
		}
		if (str.empty())
		{
			PrintError("First name is empty, please try again !");
		}
	} while (str.empty());
	Contact->SetDarkestSecret(str);

	system("clear");
	AsciiDisplayer("HOME");
}

int main()
{
	Contact		contact = Contact();
	PhoneBook	phonebook = PhoneBook();

	system("clear");
	phonebook.SetContactsNumber(0);
	AsciiDisplayer("HOME");
	while (true)
	{
		BookIsTalking("Enter a command : ");
		std::string entry;
		if (!getline(std::cin, entry))
		{
			SignalError();
		}
		if (entry.compare("ADD") == 0)
		{
			AddContact(&contact);
			phonebook.EnterNewContact(contact);
		}
		else if (entry == "SEARCH")
		{
			HandleSearch(phonebook);
		}
		else if (entry == "EXIT")
		{
			HandleExit();
		}
		else if (entry == "HELP")
		{
			AsciiDisplayer("HELP");
		}
		else if (entry == "HOME")
		{
			AsciiDisplayer("HOME");
		}
		else
		{
			PrintError("Invalid command enter 'HELP' to get commands list !");
		}
	}
}

