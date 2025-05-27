#include "Serializer.hpp"

static Data *initData()
{
	Data *data = new Data;

	data->data1 = 10;
	data->data2 = 20;
	data->data3 = 30;
	data->data4 = 40;

	return (data);
}

static void printData(Data *data)
{
	std::cout << "data1 -> " << data->data1 << std::endl;
	std::cout << "data2 -> " << data->data2 << std::endl;
	std::cout << "data3 -> " << data->data3 << std::endl;
	std::cout << "data4 -> " << data->data4 << std::endl << std::endl;
}

int main()
{
	Data *data = initData();

	std::cout << "*****************************" << std::endl;
	std::cout << "| DATA BEFORE SERIALIZATION |" << std::endl;
	std::cout << "*****************************" << std::endl << std::endl;
	printData(data);

	uintptr_t ptr = Serializer::serialize(data);
	Data *newData = Serializer::deserialize(ptr);

	std::cout << "****************************" << std::endl;
	std::cout << "| DATA AFTER SERIALIZATION |" << std::endl;
	std::cout << "****************************" << std::endl << std::endl;
	printData(newData);

	delete newData;
}

