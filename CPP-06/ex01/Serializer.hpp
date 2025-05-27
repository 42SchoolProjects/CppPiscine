#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int data1;
	int data2;
	int data3;
	int data4;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &assign);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
